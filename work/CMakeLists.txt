project(work)

set(includes ./ ../libraries/data_structures/includes)

add_executable(work main.cpp)
target_include_directories(work PUBLIC ${includes})
target_link_libraries(work data_structures)

add_executable(work1 main1.cpp)
target_include_directories(work1 PUBLIC ${includes})
target_link_libraries(work1 data_structures)

add_executable(work2 main2.cpp)
target_include_directories(work2 PUBLIC ${includes})
target_link_libraries(work2 data_structures)

