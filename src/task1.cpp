#include <iostream>
#include <vector>
#include <algorithm>

int calculateMedian(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    } else {
        return arr[n / 2];
    }
}


int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        std::vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        int sum = 0;

        for (int i = 0; i < N - 2; ++i) {
            std::vector<int> medians;
            for (int j = i + 2; j < N; ++j) {
                if ((j - i + 1) % 2 != 0) {
                    std::vector<int> subarray(A.begin() + i, A.begin() + j + 1);
                    int median = calculateMedian(subarray);
                    medians.push_back(median);
                }
            }

            int minMedian = *std::min_element(medians.begin(), medians.end());
            A.erase(std::find(A.begin(), A.end(), minMedian));
        }

        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
        }

        std::cout << sum << std::endl;
    }

    return 0;
}