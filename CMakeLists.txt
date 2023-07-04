project("C++ Data Structures with Yoon's Book")
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

function(add_ch ch_name)
    set(${ch_name}_ROOT ${PROJECT_SOURCE_DIR}/${ch_name} CACHE INTERNAL "chroots")
    add_subdirectory(${ch_name})
endfunction(add_ch)

add_ch(CH02)
add_ch(CH03)
add_ch(CH04)
add_ch(CH05)
add_ch(CH06)
add_ch(CH07)
add_ch(CH08)
