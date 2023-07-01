include_directories(${CH06_ROOT}/include)
include_directories(${CH08_ROOT}/include)
add_subdirectory(src)

add_executable(binary.tree.out binary.tree.main.cc)
add_executable(binary.tree.traverse.out binary.tree.traverse.main.cc)
add_executable(tree.calc.out tree.calc.main.cc)

target_link_libraries(tree.calc.out tree.calc.lib)