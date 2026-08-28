#include <string>
#include <unordered_map>
#include <iostream>


bool valid_anagram(std::string s1, std::string s2){

    std::unordered_map<char, int> letter_counts_1;
    std::unordered_map<char, int> letter_counts_2;

    for (char c : s1){
        if (letter_counts_1.count(c)){
            letter_counts_1[c] +=1;
        } else {
            letter_counts_1[c] = 1;
        }
    }

    for (char c : s2){
        if (letter_counts_2.count(c)){
            letter_counts_2[c] +=1;
        } else {
            letter_counts_2[c] = 1;
        }
    }

    return (letter_counts_1 == letter_counts_2);
}

int main() {
    // Standard anagram
    std::cout << "Test 1 (expect true): " << valid_anagram("anagram", "nagaram") << std::endl;

    // Not an anagram
    std::cout << "Test 2 (expect false): " << valid_anagram("rat", "car") << std::endl;

    // Different lengths
    std::cout << "Test 3 (expect false): " << valid_anagram("aa", "a") << std::endl;

    // Empty strings
    std::cout << "Test 4 (expect true): " << valid_anagram("", "") << std::endl;

    // Same string
    std::cout << "Test 5 (expect true): " << valid_anagram("abc", "abc") << std::endl;

    // Repeated letters, different counts
    std::cout << "Test 6 (expect false): " << valid_anagram("aabbcc", "aabbc") << std::endl;

    return 0;
}