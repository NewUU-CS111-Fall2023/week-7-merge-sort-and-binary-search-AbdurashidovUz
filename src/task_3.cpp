#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> mergeArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> mergedArray;
    int i = 0, j = 0;
    int n = arr1.size();
    int m = arr2.size();

    while (i < n && j < m) {
        if (arr1[i] >= arr2[j]) {
            mergedArray.push_back(arr1[i]);
            i++;
        } else {
            mergedArray.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n) {
        mergedArray.push_back(arr1[i]);
        i++;
    }

    while (j < m) {
        mergedArray.push_back(arr2[j]);
        j++;
    }

    return mergedArray;
}


int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N, M;
        std::cin >> N >> M;

        std::vector<int> A(N);
        std::vector<int> B(M);

        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        for (int i = 0; i < M; ++i) {
            std::cin >> B[i];
        }

        std::vector<int> mergedArray = mergeArrays(A, B);

        for (int i = 0; i < mergedArray.size(); ++i) {
            std::cout << mergedArray[i] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}