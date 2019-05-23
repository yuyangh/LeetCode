cmake_minimum_required(VERSION 3.13)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

add_executable(LeetCode
        main.cpp LongestPalindromicSubstring.h)

add_executable(LeetCode021
        LeetCodeLib.h 021MergeTwoSortedLists.cpp)

add_executable(LeetCode023
        LeetCodeLib.h 023MergeKSortedLists.cpp)

add_executable(LeetCode055
        LeetCodeLib.h 055JumpGame.cpp)

add_executable(LeetCode086
        LeetCodeLib.h 086PartitionList.cpp)

add_executable(LeetCode092
        092ReverseLinkedListII.cpp)


add_executable(LeetCode155
        LeetCodeLib.h 155MinStack.cpp)

add_executable(LeetCode215
        LeetCodeLib.h 215KthLargestElementInAnArray.cpp)

add_executable(LeetCode224
        LeetCodeLib.h 224BasicCalculator.cpp)

add_executable(LeetCode225
        LeetCodeLib.h 225ImplementStackUsingQueues.cpp)

add_executable(LeetCode232
        LeetCodeLib.h 232ImplementQueueUsingStacks.cpp)

add_executable(LeetCode295
        LeetCodeLib.h 295FindMedianfromDataStream.cpp)