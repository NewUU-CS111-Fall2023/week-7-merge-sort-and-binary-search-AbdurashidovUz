#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

std::vector<int> findMissingNumber(const std::vector<int>& nums, int arraySize) {
    int n = nums.size();
    std::unordered_set<int> numSet(nums.begin(), nums.end());
    std::vector<int> missing;

    for (int i = 0; i < arraySize; ++i) {
        if (numSet.find(i) == numSet.end()) {
            missing.push_back(i);
        }
    }

    return missing;
}

int main() {
    int arraySize;
    std::cout << "Enter the size of the array: ";
    std::cin >> arraySize;

    std::vector<int> nums;
    std::cout << "Enter the elements of nums (enter -1 to finish input): ";
    int num;
    while (std::cin >> num && num != -1) {
        nums.push_back(num);
    }

    std::vector<int> missingNumbers = findMissingNumber(nums, arraySize);

    if (!missingNumbers.empty()) {
        std::cout << "Missing numbers: ";
        for (int num : missingNumbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No missing numbers." << std::endl;
    }

    return 0;
}
