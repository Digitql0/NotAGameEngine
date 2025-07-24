cmake_minimum_required(VERSION 3.16)
project(YourProjectName LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your own include folder
include_directories(${PROJECT_SOURCE_DIR}/include)

# Get all first-level directories inside external/
file(GLOB EXTERNAL_LIB_DIRS LIST_DIRECTORIES true "${PROJECT_SOURCE_DIR}/external/*")

foreach(dir ${EXTERNAL_LIB_DIRS})
    if(IS_DIRECTORY ${dir})
        message(STATUS "Adding external library subdirectory: ${dir}")
        add_subdirectory(${dir})
    endif()
endforeach()

# Collect your own source files
file(GLOB_RECURSE SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.c"
)

# Now add your executable target
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Now link MiniGL and other libraries to your executable target
target_link_libraries(${PROJECT_NAME} PRIVATE MiniGL)
