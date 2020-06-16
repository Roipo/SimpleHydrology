cmake_minimum_required(VERSION 3.17)
project(SimpleHydrology)




add_subdirectory("SDL2")
add_subdirectory("libnoise")
add_subdirectory("glm")
add_subdirectory("glad")
add_subdirectory("glfw")

set(SOURCES SimpleHydrology.cpp)
set(TINY TinyEngine/include/imgui/imgui.cpp TinyEngine/include/imgui/imgui_demo.cpp TinyEngine/include/imgui/imgui_draw.cpp TinyEngine/include/imgui/imgui_widgets.cpp TinyEngine/include/imgui/imgui_impl_opengl3.cpp TinyEngine/include/imgui/imgui_impl_sdl.cpp)


add_executable(${PROJECT_NAME} ${SOURCES} ${TINY})
target_link_libraries(${PROJECT_NAME} noise-static glad SDL2-static)
target_link_libraries(${PROJECT_NAME} 
C:/Dropbox/Miniprojects/SimpleHydrology/SDL2_image/lib/x64/SDL2_image.lib
C:/Dropbox/Miniprojects/SimpleHydrology/SDL2_ttf/lib/x64/SDL2_ttf.lib
C:/Dropbox/Miniprojects/SimpleHydrology/SDL2_mixer/lib/x64/SDL2_mixer.lib)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libnoise/src ${CMAKE_SOURCE_DIR}/SDL2/include ${CMAKE_SOURCE_DIR}/glm ${CMAKE_SOURCE_DIR}/glfw/include ${CMAKE_SOURCE_DIR}/glad/include ${CMAKE_SOURCE_DIR}/SDL2_ttf/include ${CMAKE_SOURCE_DIR}/SDL2_image/include ${CMAKE_SOURCE_DIR}/SDL2_mixer/include)

target_compile_definitions(${PROJECT_NAME} PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)
#target_compile_definitions(SDL2 PUBLIC SDL_SENSOR_DUMMY)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)