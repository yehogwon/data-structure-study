set(CH06_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)

include_directories(${CH06_ROOT}/include)
add_executable(stack.out stack.main.cc)
add_executable(calculator.out calculator.main.cc)

target_link_libraries(calculator.out calc.lib)