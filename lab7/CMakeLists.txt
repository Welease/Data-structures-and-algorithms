cmake_minimum_required(VERSION 3.17)
project(lab7)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab7 lab7.cpp ft_list.h)

add_executable(lab8 ../lab8/main8.cpp ../lab8/listOfLists.cpp ../lab8/listOfLIsts.h)

add_executable(lab9 ../lab9/lab9.cpp ../lab9/Tree.h)

add_executable(lab10 ../lab10/lab10.cpp ../lab10/Tree.h ../lab10/Stack.cpp ../lab10/Stack.h)

add_executable(lab11 ../lab11/lab11.cpp ../lab11/Tree.h ../lab11/Stack.cpp ../lab11/Stack.h)

add_executable(lab12 ../lab12/lab12.cpp ../lab12/TreeNode.h)