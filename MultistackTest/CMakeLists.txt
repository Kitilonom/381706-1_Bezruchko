file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${MultistackTest} ${srcs} ${hdrs})
target_link_libraries(${MultistackTest} ${MultistackLib} gtest)
