// banker.cpp (Banker's Algorithm)

#include <iostream>
#include <vector>

int main() {
    int n = 5;      // # of processes
    int r = 3;      // # of resources
    std::vector<std::vector<int>> alloc = {
        {0, 1, 0},  // P0   // Allocation Matrix
        {2, 0, 0},  // P1
        {3, 0, 2},  // P2
        {2, 2, 1},  // P3
        {0, 0, 2}   // P4
    };  

    std::vector<std::vector<int>> max = {
        {7, 5, 3},  // P0   // Max Matrix
        {3, 3, 2},  // P1
        {9, 0, 2},  // P2
        {2, 2, 2},  // P3
        {4, 3, 3}   // P4
    };   

    std::vector<int> avail = {3, 2, 2};                         // Available Resources

    std::vector<int> f(n, 0);   // Finished flags
    std::vector<int> ans(n);    // Safe seq
    int ind = 0;

    // Need matrix
    std::vector<std::vector<int>> need(n, std::vector<int>(r));

    // Calculate Need = Max - Allocation
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < r; ++j) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Banker's Algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (f[i] == 0) {
                bool flag = true;
                for (int j = 0; j < r; ++j) {
                    if (need[i][j] > avail[j]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    for (int j = 0; j < r; ++j) {
                        avail[j] += alloc[i][j];
                    }
                    ans[ind++] = i;
                    f[i] = 1;
                }
            }
        }
    }

    // Check if safe
    bool safe = true;
    for (int i = 0; i < n; ++i) {
        if (f[i] == 0) {
            safe = false;
            break;
        }
    }

    if (safe) {
        std::cout << "System is in a Safe State " << std::endl;
        std::cout << "Safe sequence: ";
        for (int i = 0; i < n; ++i) {
            std::cout << "P" << ans[i] << (i == n - 1 ? "" : " -> ");
        }
        std::cout << std::endl;
    } else {
        std::cout << "System is not in a Safe State." << std::endl;
    }

    return 0;
}