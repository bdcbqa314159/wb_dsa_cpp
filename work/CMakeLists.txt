project(work)

set(includes ./ ../libraries/data_structures/includes)

add_executable(work main.cpp)
target_include_directories(work PUBLIC ${includes})
target_link_libraries(work data_structures)

# add_executable(cards_test cards_test.cpp)
# target_include_directories(cards_test PUBLIC ${includes})
# target_link_libraries(cards_test utils cards)
