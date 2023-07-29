cmake_minimum_required(VERSION 3.26)

project(WebsiteGenerator)

# message(PROJECT_BINARY_DIR=${PROJECT_BINARY_DIR})

file(COPY scripts DESTINATION ${PROJECT_BINARY_DIR})
file(COPY resources DESTINATION ${PROJECT_BINARY_DIR})

add_subdirectory(libs)

add_executable(WebsiteGenerator main.cpp)

target_link_libraries(WebsiteGenerator PUBLIC GeneratorLibs)
target_include_directories(WebsiteGenerator PUBLIC "${PROJECT_BINARY_DIR}" "{PROJECT_BINARY_DIR}/libs")
