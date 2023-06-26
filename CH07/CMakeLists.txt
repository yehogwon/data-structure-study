set(CH07_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${CH07_ROOT}/include)

add_executable(queue.out queue.main.cc)
add_executable(hamburger.out hamburger.main.cc)
add_executable(deque.out deque.main.cc)
