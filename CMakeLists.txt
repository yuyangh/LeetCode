cmake_minimum_required(VERSION 3.13)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

add_executable(LeetCode
        main.cpp LongestPalindromicSubstring.h)

add_executable(LeetCode92
        092ReverseLinkedListII.cpp)

add_executable(LeetCode86
        LeetCodeLib.h 086PartitionList.cpp)

add_executable(LeetCode21
        LeetCodeLib.h 021MergeTwoSortedLists.cpp)

add_executable(LeetCode23
        LeetCodeLib.h 023MergeKSortedLists.cpp)

add_executable(LeetCode155
        LeetCodeLib.h 155MinStack.cpp)