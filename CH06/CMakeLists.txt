set(CH06_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)

include_directories(${CH06_ROOT}/include)
add_executable(stack.main.out stack.main.cc)
add_executable(calculator.out calculator.cc)

target_link_libraries(calculator.out calc.lib)