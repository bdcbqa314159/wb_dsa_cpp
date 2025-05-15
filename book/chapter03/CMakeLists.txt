project(chapter03)

set(includes ./)

set(sources_stack  mainStack.cpp)
add_executable(stack_main ${sources_stack})
target_include_directories(stack_main PUBLIC ${includes})

# set(sources_node_simple Node.cpp mainNodeSimple.cpp)
# add_executable(node_simple_main ${sources_node_simple})
# target_include_directories(node_simple_main PUBLIC ${includes})

# set(sources_node_template mainNodeTemplate.cpp)
# add_executable(node_template_main ${sources_node_template})
# target_include_directories(node_template_main PUBLIC ${includes})

# set(sources_linked_list mainLinkedList.cpp)
# add_executable(linked_list_main ${sources_linked_list})
# target_include_directories(linked_list_main PUBLIC ${includes})

# set(sources_doubly_linked_list mainDoublyLinkedList.cpp)
# add_executable(doubly_linked_list_main ${sources_doubly_linked_list})
# target_include_directories(doubly_linked_list_main PUBLIC ${includes})

# add_executable(std_vector_main mainStdVector.cpp)

# add_executable(std_list_main mainStdList.cpp)
