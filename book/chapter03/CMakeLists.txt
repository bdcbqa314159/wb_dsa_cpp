project(chapter03)

set(includes ./)

set(sources_stack  mainStack.cpp)
add_executable(stack_main ${sources_stack})
target_include_directories(stack_main PUBLIC ${includes})

set(sources_parenthesis_stack parenthesisValidity.cpp)
add_executable(parenthesisValidity_main ${sources_parenthesis_stack})
target_include_directories(parenthesisValidity_main PUBLIC ${includes})

set(sources_queue mainQueue.cpp)
add_executable(queue_main ${sources_queue})
target_include_directories(queue_main PUBLIC ${includes})

# set(sources_linked_list mainLinkedList.cpp)
# add_executable(linked_list_main ${sources_linked_list})
# target_include_directories(linked_list_main PUBLIC ${includes})

# set(sources_doubly_linked_list mainDoublyLinkedList.cpp)
# add_executable(doubly_linked_list_main ${sources_doubly_linked_list})
# target_include_directories(doubly_linked_list_main PUBLIC ${includes})

# add_executable(std_vector_main mainStdVector.cpp)

# add_executable(std_list_main mainStdList.cpp)
