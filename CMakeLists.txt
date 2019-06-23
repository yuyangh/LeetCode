cmake_minimum_required(VERSION 3.13)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

add_executable(LeetCode
        main.cpp LongestPalindromicSubstring.h)

add_executable(LeetCode003
        LeetCodeLib.h 003LongestSubstringWithoutRepeatingCharacters.cpp)

add_executable(LeetCode008
        LeetCodeLib.h 008StringtoInteger\(atoi\).cpp)

add_executable(LeetCode015
        LeetCodeLib.h 015_3Sums.cpp)

add_executable(LeetCode017
        LeetCodeLib.h 017LetterCombinationsofaPhoneNumber.cpp)

add_executable(LeetCode019
        LeetCodeLib.h 019RemoveNthNodeFromEndofList.cpp)

add_executable(LeetCode020
        LeetCodeLib.h 020ValidParentheses.cpp)

add_executable(LeetCode021
        LeetCodeLib.h 021MergeTwoSortedLists.cpp)

add_executable(LeetCode022
        LeetCodeLib.h 022GenerateParentheses.cpp)

add_executable(LeetCode023
        LeetCodeLib.h 023MergeKSortedLists.cpp)

add_executable(LeetCode024
        LeetCodeLib.h 024SwapNodesinPairs.cpp)

add_executable(LeetCode026
        LeetCodeLib.h 026RemoveDuplicatesfromSortedArray.cpp)

add_executable(LeetCode027
        LeetCodeLib.h 027RemoveElement.cpp)

add_executable(LeetCode028
        LeetCodeLib.h 028ImplementstrStr\(\).cpp)

add_executable(LeetCode029
        LeetCodeLib.h 029DivideTwoIntegers.cpp)

add_executable(LeetCode033
        LeetCodeLib.h 033SearchinRotatedSortedArray.cpp)

add_executable(LeetCode034
        LeetCodeLib.h 034FindFirstandLastPositionofElementinSortedArray.cpp)

add_executable(LeetCode035
        LeetCodeLib.h 035SearchInsertPosition.cpp)

add_executable(LeetCode039
        LeetCodeLib.h 039CombinationSum.cpp)

add_executable(LeetCode043
        LeetCodeLib.h 043MultiplyStrings.cpp)

add_executable(LeetCode045
        LeetCodeLib.h 045JumpGameII.cpp)

add_executable(LeetCode046
        LeetCodeLib.h 046Permutations.cpp)

add_executable(LeetCode049
        LeetCodeLib.h 049GroupAnagrams.cpp)

add_executable(LeetCode050
        LeetCodeLib.h 050Pow\(x,\ n\).cpp)

add_executable(LeetCode053
        LeetCodeLib.h 053MaximumSubarray.cpp)

add_executable(LeetCode055
        LeetCodeLib.h 055JumpGame.cpp)

add_executable(LeetCode056
        LeetCodeLib.h 056MergeIntervals.cpp)

add_executable(LeetCode057
        LeetCodeLib.h 057InsertInterval.cpp)

add_executable(LeetCode062
        LeetCodeLib.h 062UniquePaths.cpp)

add_executable(LeetCode063
        LeetCodeLib.h 063UniquePathsII.cpp)

add_executable(LeetCode064
        LeetCodeLib.h 064MinimumPathSum.cpp)

add_executable(LeetCode067
        LeetCodeLib.h 067AddBinary.cpp)

add_executable(LeetCode069
        LeetCodeLib.h 069Sqrt\(x\).cpp)

add_executable(LeetCode070
        LeetCodeLib.h 070ClimbingStairs.cpp)

add_executable(LeetCode072
        LeetCodeLib.h 072Searcha2DMatrix.cpp)

add_executable(LeetCode073
        LeetCodeLib.h 073SetMatrixZeroes.cpp)

add_executable(LeetCode077
        LeetCodeLib.h 077Combinations.cpp)

add_executable(LeetCode078
        LeetCodeLib.h 078Subsets.cpp)

add_executable(LeetCode079
        LeetCodeLib.h 079WordSearch.cpp)

add_executable(LeetCode081
        LeetCodeLib.h 081SearchinRotatedSortedArrayII.cpp)

add_executable(LeetCode082
        LeetCodeLib.h 082RemoveDuplicatesfromSortedListII.cpp)

add_executable(LeetCode083
        LeetCodeLib.h 083RemoveDuplicatesfromSortedList.cpp)

add_executable(LeetCode086
        LeetCodeLib.h 086PartitionList.cpp)

add_executable(LeetCode091 LeetCodeLib.h
        091DecodeWays.cpp)

add_executable(LeetCode092 LeetCodeLib.h
        092ReverseLinkedListII.cpp)

add_executable(LeetCode093 LeetCodeLib.h
        093RestoreIPAddresses.cpp)

add_executable(LeetCode094 LeetCodeLib.h
        094BinaryTreeInorderTraversal.cpp)

add_executable(LeetCode098 LeetCodeLib.h
        098ValidateBinarySearchTree.cpp)

add_executable(LeetCode102
        LeetCodeLib.h 102BinaryTreeLevelOrderTraversal.cpp)

add_executable(LeetCode103
        LeetCodeLib.h 103BinaryTreeZigzagLevelOrderTraversal.cpp)

add_executable(LeetCode105
        LeetCodeLib.h 105ConstructBinaryTreefromPreorderandInorderTraversal.cpp)

add_executable(LeetCode113
        LeetCodeLib.h 113PathSumII.cpp)

add_executable(LeetCode114
        LeetCodeLib.h 114FlattenBinaryTreetoLinkedList.cpp)

add_executable(LeetCode120
        LeetCodeLib.h 120Triangle.cpp)

add_executable(LeetCode125
        LeetCodeLib.h 125ValidPalindrome.cpp)

add_executable(LeetCode127
        LeetCodeLib.h 127WordLadder.cpp)

add_executable(LeetCode129
        LeetCodeLib.h 129SumRoottoLeafNumbers.cpp)

add_executable(LeetCode131
        LeetCodeLib.h 131PalindromePartitioning.cpp)

add_executable(LeetCode155
        LeetCodeLib.h 155MinStack.cpp)

add_executable(LeetCode174
        LeetCodeLib.h 174DungeonGame.cpp)

add_executable(LeetCode187
        LeetCodeLib.h 187RepeatedDNASequences.cpp)

add_executable(LeetCode198
        LeetCodeLib.h 198HouseRobber.cpp)

add_executable(LeetCode199
        LeetCodeLib.h 199BinaryTreeRightSideView.cpp)

add_executable(LeetCode206
        LeetCodeLib.h 206ReverseLinkedList.cpp)

add_executable(LeetCode207
        LeetCodeLib.h 207CourseSchedule.cpp)

add_executable(LeetCode215
        LeetCodeLib.h 215KthLargestElementInAnArray.cpp)

add_executable(LeetCode224
        LeetCodeLib.h 224BasicCalculator.cpp)

add_executable(LeetCode225
        LeetCodeLib.h 225ImplementStackUsingQueues.cpp)

add_executable(LeetCode232
        LeetCodeLib.h 232ImplementQueueUsingStacks.cpp)

add_executable(LeetCode236
        LeetCodeLib.h 236LowestCommonAncestorofABinaryTree.cpp)

add_executable(LeetCode290
        LeetCodeLib.h 290WordPattern.cpp)

add_executable(LeetCode295
        LeetCodeLib.h 295FindMedianfromDataStream.cpp)

add_executable(LeetCode300
        LeetCodeLib.h 300LongestIncreasingSubsequence.cpp)

add_executable(LeetCode315
        LeetCodeLib.h 315CountofSmallerNumbersAfterSelf.cpp)

add_executable(LeetCode322
        LeetCodeLib.h 322CoinChange.cpp)

add_executable(LeetCode376
        LeetCodeLib.h 376WiggleSubsequence.cpp)

add_executable(LeetCode402
        LeetCodeLib.h 402RemoveKDigits.cpp)

add_executable(LeetCode409
        LeetCodeLib.h 409LongestPalindrome.cpp)

add_executable(LeetCode449
        LeetCodeLib.h 449SerializeandDeserializeBST.cpp)