project(chapter04)

set(includes ./)

set(sources_bubble_sort  bubble_sort.cpp)
add_executable(bubble_sort_main ${sources_bubble_sort})
target_include_directories(bubble_sort_main PUBLIC ${includes})

set(sources_selection_sort  selection_sort.cpp)
add_executable(selection_sort_main ${sources_selection_sort})
target_include_directories(selection_sort_main PUBLIC ${includes})

set(sources_insertion_sort  insertion_sort.cpp)
add_executable(insertion_sort_main ${sources_insertion_sort})
target_include_directories(insertion_sort_main PUBLIC ${includes})

set(sources_merge_sort  merge_sort.cpp)
add_executable(merge_sort_main ${sources_merge_sort})
target_include_directories(merge_sort_main PUBLIC ${includes})

set(sources_quick_sort  quick_sort.cpp)
add_executable(quick_sort_main ${sources_quick_sort})
target_include_directories(quick_sort_main PUBLIC ${includes})

set(sources_counting_sort  counting_sort.cpp)
add_executable(counting_sort_main ${sources_counting_sort})
target_include_directories(counting_sort_main PUBLIC ${includes})

