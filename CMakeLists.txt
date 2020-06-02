cmake_minimum_required(VERSION 3.13)

project(dze_type_traits)

add_library(dze_type_traits INTERFACE)
target_include_directories(dze_type_traits INTERFACE include)
add_library(dze::type_traits ALIAS dze_type_traits)
