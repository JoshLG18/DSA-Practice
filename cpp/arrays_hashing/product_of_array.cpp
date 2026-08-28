#include <vector>
#include <iostream>

std::vector<int> product(std::vector<int> nums){

    // create the left and right arrays to fill
    std::vector<int> right(nums.size());
    right[nums.size() - 1] = 1;

    std::vector<int> left(nums.size());
    left[0] = 1;
    
    // product of all on the right
    for (int idx = nums.size() - 2; idx >= 0; idx --){
        int product = right[idx + 1] * nums[idx + 1];

        right[idx]= product;
    }

    // product of all on the left
    for (int idx = 1; idx < nums.size(); idx ++){
        int product = left[idx - 1] * nums[idx - 1];

        left[idx] = product;
    }

    // combine the arrays
    for (int idx = 0; idx < nums.size(); idx ++) {
        nums[idx] = left[idx] * right[idx];
    }

    return nums;
}


int main() {
    std::vector<int> nums1 = {1, 2, 3, 4};
    auto result1 = product(nums1);
    std::cout << "Test 1 (expect [24,12,8,6]): ";
    for (int x : result1) std::cout << x << " ";
    std::cout << std::endl;

    std::vector<int> nums2 = {2, 3};
    auto result2 = product(nums2);
    std::cout << "Test 2 (expect [3,2]): ";
    for (int x : result2) std::cout << x << " ";
    std::cout << std::endl;

    std::vector<int> nums3 = {1, 1, 1};
    auto result3 = product(nums3);
    std::cout << "Test 3 (expect [1,1,1]): ";
    for (int x : result3) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}