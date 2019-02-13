cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-1_Bezruchko) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(ost ost)

set(Vector Vector) #Переменная с именем библиотеки
set(VectorLib VectorLib)
set(VectorTest VectorTest)


set(Stack Stack)
set(StackLib StackLib)
set(StackTest StackTest)

set(Queue Queue)
set(QueueLib QueueLib)
set(QueueTest QueueTest)

set(List_on_selection List_on_selection)
set(List_on_selectionLib List_on_selectionLib)
set(List_on_selectionTest List_on_selectionTest)

set(List_on_array List_on_array)
set(List_on_arrayLib List_on_arrayLib)
set(List_on_arrayTest List_on_arrayTest)

set(Multistack Multistack)
set(MultistackLib MultistackLib)
set(MultistackTest MultistackTest)

set(Polynom Polynom)
set(PolynomLib PolynomLib)
set(PolynomTest PolynomTest)

set(Stack_on_list Stack_on_list)
set(Stack_on_listLib Stack_on_listLib)
set(Stack_on_listTest Stack_on_listTest)

set(Polish Polish)
set(PolishLib PolishLib)
set(PolishTest PolishTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
# Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" 
# и меткой/разделом Configs, переменная сохраниется в специальном файле доступном 
# из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .h


# add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) 
# Создаем проект с именем из переменной ${PROJECT_NAME},
# в него добавляются файлы из переменных ${srcs} и ${hdrs}

# ${CMAKE_CURRENT_SOURCE_DIR}

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib 
${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ost)
add_subdirectory(ost)

add_subdirectory(Vector)
add_subdirectory(VectorLib)
add_subdirectory(VectorTest)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StackTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
add_subdirectory(Queue)
add_subdirectory(QueueLib)
add_subdirectory(QueueTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/List_on_selectionLib)
add_subdirectory(List_on_selection)
add_subdirectory(List_on_selectionLib)
add_subdirectory(List_on_selectionTest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/List_on_arrayLib)
add_subdirectory(List_on_array)
add_subdirectory(List_on_arrayLib)
add_subdirectory(List_on_arrayTest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MultistackLib)
add_subdirectory(Multistack)
add_subdirectory(MultistackLib)
add_subdirectory(MultistackTest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolynomLib)
add_subdirectory(Polynom)
add_subdirectory(PolynomLib)
add_subdirectory(PolynomTest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Stack_on_listLib)
add_subdirectory(Stack_on_list)
add_subdirectory(Stack_on_listLib)
add_subdirectory(Stack_on_listTest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolishLib)
add_subdirectory(Polish)
add_subdirectory(PolishLib)
add_subdirectory(PolishTest)

# target_link_libraries(${PROJECT_NAME} ${MyLib1}) 
# Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}