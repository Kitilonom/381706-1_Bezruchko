file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${List_on_arrayTest} ${srcs} ${hdrs})
target_link_libraries(${List_on_arrayTest} ${List_on_arrayLib} gtest)
