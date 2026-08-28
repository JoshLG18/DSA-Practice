#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

std::vector<std::vector<std::string>> group_anagrams(std::vector<std::string> strs){

    std::unordered_map<std::string, std::vector<std::string>> groups;

    for (std::string str : strs){
        std::string original_string = str;

        sort(str.begin(), str.end());

        if (groups.count(str)){
            groups[str].push_back(original_string);
        } else {
            groups[str] = {original_string};
        }
    }

    std::vector<std::vector<std::string>> return_struct;

    for (auto word : groups){
        return_struct.push_back(word.second);
    }

    return return_struct;
}

void print_result(std::vector<std::vector<std::string>>& result) {
    for (auto& group : result) {
        std::cout << "[ ";
        for (auto& word : group) std::cout << word << " ";
        std::cout << "]  ";
    }
    std::cout << std::endl;
}

int main() {
    // Standard case
    std::vector<std::string> strs1 = {"eat","tea","tan","ate","nat","bat"};
    auto result1 = group_anagrams(strs1);
    std::cout << "Test 1: ";
    print_result(result1);

    // Empty string
    std::vector<std::string> strs2 = {""};
    auto result2 = group_anagrams(strs2);
    std::cout << "Test 2: ";
    print_result(result2);

    // Single word
    std::vector<std::string> strs3 = {"a"};
    auto result3 = group_anagrams(strs3);
    std::cout << "Test 3: ";
    print_result(result3);

    // No anagrams at all
    std::vector<std::string> strs4 = {"abc", "def", "ghi"};
    auto result4 = group_anagrams(strs4);
    std::cout << "Test 4: ";
    print_result(result4);

    return 0;
}