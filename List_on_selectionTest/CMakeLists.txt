file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${List_on_selectionTest} ${srcs} ${hdrs})
target_link_libraries(${List_on_selectionTest} ${List_on_selectionLib} gtest)
