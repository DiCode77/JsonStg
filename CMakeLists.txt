cmake_minimum_required(VERSION 3.25)
project(JsonStg)

set(SRC "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(EXA "${CMAKE_CURRENT_SOURCE_DIR}/examples")

find_package(nlohmann_json REQUIRED)

#// Settings for library compilation.

set(PROJ_LIB_NAME "${PROJECT_NAME}Lib")

file(GLOB_RECURSE SRC_FILES_LIB "${SRC}/*.hpp" "${SRC}/*.cpp")

add_library(${PROJ_LIB_NAME} STATIC ${SRC_FILES_LIB})

target_include_directories(${PROJ_LIB_NAME} PUBLIC ${SRC})

target_link_libraries(${PROJ_LIB_NAME} PUBLIC nlohmann_json::nlohmann_json)

set_target_properties(${PROJ_LIB_NAME} PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON)

source_group("src" FILES ${SRC_FILES_LIB})

#// Example of use.

set(EXA_FILES "${EXA}/main.cpp")

add_executable(${PROJECT_NAME} ${EXA_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${SRC})

target_link_libraries(${PROJECT_NAME} PUBLIC nlohmann_json::nlohmann_json ${PROJ_LIB_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON)

source_group("examples" FILES ${EXA_FILES})