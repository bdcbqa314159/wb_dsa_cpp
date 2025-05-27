project(chapter05)

set(includes ./)

set(sources_linear_search  linear_search.cpp)
add_executable(linear_search_main ${sources_linear_search})
target_include_directories(linear_search_main PUBLIC ${includes})

set(sources_binary_search  binary_search.cpp)
add_executable(binary_search_main ${sources_binary_search})
target_include_directories(binary_search_main PUBLIC ${includes})


