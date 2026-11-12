project(App)


add_executable(${PROJECT_NAME} "src/main.cpp" "src/PongScene.cpp"  "src/PlayerScript.cpp")

target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/include/"
)

set(SDL2_DIR_WIN "${CMAKE_SOURCE_DIR}/externalDependencies/SDL2-2.32.10")
set(GLEW_DIR_WIN "${CMAKE_SOURCE_DIR}/externalDependencies/glew-2.3.1")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${GLEW_DIR_WIN}/bin/Release/x64/glew32.dll"
    "${SDL2_DIR_WIN}/lib/x64/SDL2.dll"
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

target_link_libraries(${PROJECT_NAME} PUBLIC ShroomEngine::library)