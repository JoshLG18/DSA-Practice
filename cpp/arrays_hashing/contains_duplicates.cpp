#include <vector>
#include <unordered_set>
#include <iostream>


bool contains_duplicate(std::vector<int> nums){

    std::unordered_set<int> seen;

    for (int idx = 0; idx < nums.size(); idx++){
        if (seen.count(nums[idx])){
            return true;
        }

        seen.insert(nums[idx]);
    }


    return false;
}

int main() {
    // Has a duplicate
    std::vector<int> nums1 = {1, 2, 3, 1};
    std::cout << "Test 1 (expect true): " << contains_duplicate(nums1) << std::endl;

    // All distinct
    std::vector<int> nums2 = {1, 2, 3, 4};
    std::cout << "Test 2 (expect false): " << contains_duplicate(nums2) << std::endl;

    // All same value
    std::vector<int> nums3 = {1, 1, 1, 1};
    std::cout << "Test 3 (expect true): " << contains_duplicate(nums3) << std::endl;

    // Empty array
    std::vector<int> nums4 = {};
    std::cout << "Test 4 (expect false): " << contains_duplicate(nums4) << std::endl;

    // Single element
    std::vector<int> nums5 = {7};
    std::cout << "Test 5 (expect false): " << contains_duplicate(nums5) << std::endl;

    return 0;
}