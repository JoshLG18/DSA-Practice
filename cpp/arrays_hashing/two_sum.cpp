#include <vector>
#include <map>
#include <iostream>

std::vector<int> two_sum(std::vector<int> nums, int target){
    std::map<int,int> seen;
    
    for (int idx = 0; idx < nums.size(); idx++){
        int left_over = target - nums[idx];

        if (seen.count(left_over)){
            return {seen[left_over], idx};
        }

        seen[nums[idx]] = idx;

    }
    return {0};
}

int main() {
    // Standard case
    std::vector<int> nums1 = {2, 7, 11, 15};
    auto result1 = two_sum(nums1, 9);
    std::cout << "Test 1: [" << result1[0] << ", " << result1[1] << "]" << std::endl;

    // Answer not at the start
    std::vector<int> nums2 = {3, 2, 4};
    auto result2 = two_sum(nums2, 6);
    std::cout << "Test 2: [" << result2[0] << ", " << result2[1] << "]" << std::endl;

    // Duplicate values
    std::vector<int> nums3 = {3, 3};
    auto result3 = two_sum(nums3, 6);
    std::cout << "Test 3: [" << result3[0] << ", " << result3[1] << "]" << std::endl;

    // Negative numbers
    std::vector<int> nums4 = {-1, -2, -3, -4, -5};
    auto result4 = two_sum(nums4, -8);
    std::cout << "Test 4: [" << result4[0] << ", " << result4[1] << "]" << std::endl;

    return 0;
}

