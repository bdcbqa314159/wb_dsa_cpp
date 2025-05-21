project(chapter04)

set(includes ./)

set(sources_bubble_sort  bubble_sort.cpp)
add_executable(bubble_sort_main ${sources_bubble_sort})
target_include_directories(bubble_sort_main PUBLIC ${includes})

set(sources_selection_sort  selection_sort.cpp)
add_executable(selection_sort_main ${sources_selection_sort})
target_include_directories(selection_sort_main PUBLIC ${includes})

# set(sources_parenthesis_stack parenthesisValidity.cpp)
# add_executable(parenthesisValidity_main ${sources_parenthesis_stack})
# target_include_directories(parenthesisValidity_main PUBLIC ${includes})

# set(sources_queue mainQueue.cpp)
# add_executable(queue_main ${sources_queue})
# target_include_directories(queue_main PUBLIC ${includes})

# set(sources_deque mainDeque.cpp)
# add_executable(deque_main ${sources_deque})
# target_include_directories(deque_main PUBLIC ${includes})
