#include <iostream>
#include <vector>

std::pair<int, int> searchInsertPosition(const std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return std::make_pair(1, mid); 
        } else if (nums[mid] < target) {
            left = mid + 1;
            index = mid + 1; 
        } else {
            right = mid - 1;
            index = mid; 
        }
    }

    return std::make_pair(-1, index);
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the sorted elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int target;
    std::cout << "Enter the target value: ";
    std::cin >> target;

    std::pair<int, int> result = searchInsertPosition(nums, target);

    std::cout << result.first << " " << result.second << std::endl;

    return 0;
}
