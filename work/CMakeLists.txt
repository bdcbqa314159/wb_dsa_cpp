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

add_executable(work3 main3.cpp)
target_include_directories(work3 PUBLIC ${includes})
target_link_libraries(work3 data_structures)

add_executable(work4 main4.cpp)
target_include_directories(work4 PUBLIC ${includes})
target_link_libraries(work4 data_structures)

add_executable(work5 main5.cpp)
target_include_directories(work5 PUBLIC ${includes})
target_link_libraries(work5 data_structures)

