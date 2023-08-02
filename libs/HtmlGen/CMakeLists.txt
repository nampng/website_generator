cmake_minimum_required(VERSION 3.26)

project(HtmlGen)

add_library(HtmlGen htmlGen.cpp htmlGen.h element.h)

target_include_directories(HtmlGen PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
