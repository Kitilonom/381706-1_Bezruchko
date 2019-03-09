file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${Stack_on_listTest} ${srcs} ${hdrs})
target_link_libraries(${Stack_on_listTest} ${Stack_on_listLib} gtest)
