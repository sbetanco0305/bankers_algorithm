// banker.cpp (Banker's Algorithm)

#include <iostream>
#include <vector>

int main() {
    int n = 5;      // # of processes
    int r = 3;      // # of resources
    std::vector<std::vector<int>> alloc = {{0, 1, 0},   // P0   // Allocation Matrix
                                           {2, 0, 0},   // P1
                                           {3, 0, 2},   // P2
                                           {2, 2, 1},   // P3
                                           {0, 0, 2}};  // P4

    std::vector<std::vector<int>> max = {{7, 5, 3},     // P0   // Max Matrix
                                         {3, 3, 2},     // P1
                                         {9, 0, 2},     // P2
                                         {2, 2, 2},     // P3
                                         {4, 3, 3}};    // P4

    std::vector<int> avail = {3, 2, 2};                         // Available Resources

    std::vector<int> f(n, 0);
    std::vector<int> ans(n);

    std::vector<std::vector<int>> need(n, std::vector<int>(r));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < r; ++j) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    
}