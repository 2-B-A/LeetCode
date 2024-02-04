// 704. Binary Search

// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

// Example 2:

// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1

// Constraints:

//     1 <= nums.length <= 104
//     -104 < nums[i], target < 104
//     All the integers in nums are unique.
//     nums is sorted in ascending order.


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
    public:
        /* Complexity O(n) */
        int bruteForceSearch(vector<int> &nums, int target) {
            for (size_t i = 0; i < nums.size(); i++) {
                if (nums[i] == target)
                    return i;
                else if (nums[i] < target)
                    continue;
                else
                    break;
            }

            return -1;
        };
        /* Complexity O(log(n)) */
        int binarySearch(vector<int> &nums, int target) {
            int idx_mid = 0;
            int idx_left = 0;
            int idx_right = nums.size() - 1;

            while (idx_left <= idx_right) {
                idx_mid = (idx_left + idx_right) / 2;
                if (nums[idx_mid] == target)
                    return idx_mid;
                else if (target > nums[idx_mid])
                    idx_left = idx_mid + 1;
                else
                    idx_right = idx_mid - 1;
            }
        
            return -1;
        };
        /* Complexity O(log(n)) */
        int binarySearchRecursive(vector<int> &nums, int l, int r, int target) {
            int idx_mid = 0;

            while (l <= r) {
                idx_mid = (l + r) / 2;
                if (nums[idx_mid] == target)
                    return idx_mid;
                else if (target > nums[idx_mid])
                    return binarySearchRecursive(nums, idx_mid + 1, r, target);
                else
                    return binarySearchRecursive(nums, l, idx_mid - 1, target);
            }

            return -1;
        };
        int binarySearchRecursiveWrap(vector<int> &nums, int target) {
            return binarySearchRecursive(nums, 0, nums.size() - 1, target);
        };
};

int main()
{
    Solution instance;
    vector<int> vec1 = {-1, 2, 4, 5, 6};
    assert(instance.binarySearch(vec1, 4) == 2);
    assert(instance.binarySearchRecursiveWrap(vec1, 4) == 2);
    assert(instance.bruteForceSearch(vec1, 4) == 2);

    assert(instance.binarySearch(vec1, 0) == -1);
    assert(instance.binarySearchRecursiveWrap(vec1, 0) == -1);
    assert(instance.bruteForceSearch(vec1, 0) == -1);

    return 0;
}