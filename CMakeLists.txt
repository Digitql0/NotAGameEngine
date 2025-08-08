cmake_minimum_required(VERSION 3.16)
project(NotAGameEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

add_subdirectory(external/BitsAndPieces)

# Collect your own source files
file(GLOB_RECURSE SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.c"
)

# Now add your executable target
add_executable(NotAGameEngine ${SRC_FILES})
include(${CMAKE_CURRENT_LIST_DIR}/cmake/imguiSetup.cmake)
add_imgui_with_backend(NotAGameEngine glfw_opengl3)
target_include_directories(NotAGameEngine PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(NotAGameEngine PRIVATE BitsAndPieces)
