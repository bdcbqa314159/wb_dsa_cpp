project(chapter05)

set(includes ./)

set(sources_linear_search  linear_search.cpp)
add_executable(linear_search_main ${sources_linear_search})
target_include_directories(linear_search_main PUBLIC ${includes})

set(sources_binary_search  binary_search.cpp)
add_executable(binary_search_main ${sources_binary_search})
target_include_directories(binary_search_main PUBLIC ${includes})

set(sources_ternary_search  ternary_search.cpp)
add_executable(ternary_search_main ${sources_ternary_search})
target_include_directories(ternary_search_main PUBLIC ${includes})

set(sources_interpolation_search  interpolation_search.cpp)
add_executable(interpolation_search_main ${sources_interpolation_search})
target_include_directories(interpolation_search_main PUBLIC ${includes})

set(sources_jump_search  jump_search.cpp)
add_executable(jump_search_main ${sources_jump_search})
target_include_directories(jump_search_main PUBLIC ${includes})

