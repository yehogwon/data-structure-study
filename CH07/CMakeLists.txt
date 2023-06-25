set(CH07_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${CH07_ROOT}/include)
add_subdirectory(src)

add_executable(queue.main.out queue.main.cc)
add_executable(hamburger.main.out hamburger.main.cc)

target_link_libraries(hamburger.main.out hamburger.lib)