project(data_structures)

set(includes includes/ )
set(sources src/bDynamicArray.cpp
            src/bNode.cpp
            src/bLinkedList.cpp
            src/bDoublyNode.cpp
            src/bDoublyLinkedList.cpp
            src/bStack.cpp
            src/bQueue.cpp
            src/bDeque.cpp)

add_library(${PROJECT_NAME} SHARED ${sources})
target_include_directories(${PROJECT_NAME} PUBLIC ${includes} ${common_includes_dir})