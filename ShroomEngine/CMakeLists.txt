project(ShroomEngine)

file(GLOB_RECURSE SOURCES 
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/Components/*.cpp"
)

add_library(${PROJECT_NAME}
        ${SOURCES}
)

add_library(ShroomEngine::library ALIAS ${PROJECT_NAME})

#set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

# Project's own include folders (all platforms)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include/
        "${PROJECT_SOURCE_DIR}/include/Components"
)

set(SDL2_DIR_WIN "${CMAKE_SOURCE_DIR}/externalDependencies/SDL2-2.32.10")
set(GLEW_DIR_WIN "${CMAKE_SOURCE_DIR}/externalDependencies/glew-2.3.1")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${GLEW_DIR_WIN}/bin/Release/x64/glew32.dll"
    "${SDL2_DIR_WIN}/lib/x64/SDL2.dll"
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

target_link_libraries(${PROJECT_NAME} PUBLIC Render::library)