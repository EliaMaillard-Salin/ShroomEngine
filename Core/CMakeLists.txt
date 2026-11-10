project(Core)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
	cmake_policy(SET CMP0141 NEW)
	set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

#include(GenerateExportHeader)
#generate_export_header(${PROJECT_NAME})
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE CACHE BOOL "Export all symbols")

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${SOURCES})


add_library(Core::library ALIAS ${PROJECT_NAME})

# Project's own include folders (all platforms) (.h)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include/"
)

#(.inl)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        "${PROJECT_SOURCE_DIR}/inline/"
)



set(SDL2_DIR_WIN "${CMAKE_SOURCE_DIR}/externalDependencies/SDL2-2.32.10")
set(GLEW_DIR_WIN "${CMAKE_SOURCE_DIR}/externalDependencies/glew-2.3.1")

target_include_directories(${PROJECT_NAME} PUBLIC
        "${SDL2_DIR_WIN}/include"
        "${GLEW_DIR_WIN}/include"
)
target_link_directories(${PROJECT_NAME} PUBLIC
        "${SDL2_DIR_WIN}/lib/x64"
        "${GLEW_DIR_WIN}/lib/Release/x64"
)
target_link_libraries(${PROJECT_NAME} PUBLIC glu32 glew32 opengl32 SDL2)

if(MSVC)
    target_link_options(${PROJECT_NAME} PUBLIC /ENTRY:mainCRTStartup)
endif()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${GLEW_DIR_WIN}/bin/Release/x64/glew32.dll"
        "${SDL2_DIR_WIN}/lib/x64/SDL2.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
#else()
#  find_package(SDL2 REQUIRED)
#  find_package(GLEW REQUIRED)
#
#  target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2 GLEW::GLEW)
#
#  if(APPLE)
#    target_link_libraries(${PROJECT_NAME} PUBLIC "-framework OpenGL")
#  else()
#    find_package(OpenGL REQUIRED)
#    target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL::GL)
#  endif()
#endif()

install(
    TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)    
