#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>


struct ElementFrequency {
    int element;
    int frequency;

    ElementFrequency(int el, int freq) : element(el), frequency(freq) {}


    bool operator<(const ElementFrequency& other) const {
        return frequency < other.frequency;
    }
};


std::vector<int> topKFrequentElements(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> frequencyMap;


    for (int num : nums) {
        frequencyMap[num]++;
    }


    std::priority_queue<ElementFrequency> maxHeap;


    for (auto& pair : frequencyMap) {
        maxHeap.push(ElementFrequency(pair.first, pair.second));
    }


    std::vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(maxHeap.top().element);
        maxHeap.pop();
    }

    return result;
}


int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int k;
    std::cin >> k;

    std::vector<int> topKFrequent = topKFrequentElements(nums, k);

    std::cout << "The k most frequent elements are: ";
    for (int i = 0; i < topKFrequent.size(); ++i) {
        std::cout << topKFrequent[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}