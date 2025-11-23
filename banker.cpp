// banker.cpp (Banker's Algorithm)

#include <iostream>
#include <vector>
#include <fstream>

int main() {
    
    std::ifstream fin("input.txt");
    if (!fin) {
        std::cout << "Error: Could not open file." << std::endl;
        return 1;
    }

    int n, r;
    fin >> n >> r;

    std::vector<std::vector<int>> alloc(n, std::vector<int>(r));
    std::vector<std::vector<int>> max(n, std::vector<int>(r));
    std::vector<std::vector<int>> need(n, std::vector<int>(r));
    std::vector<int> avail(r);

    // allocation
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < r; ++j) {
            fin >> alloc[i][j];
        }
    }

    // max
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < r; ++j) {
            fin >> max[i][j];
        }
    }

    // available
    for (int j = 0; j < r; ++j) {
        fin >> avail[j];
    }

    // need
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < r; ++j) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    std::vector<int> safe_seq;
    std::vector<bool> done(n, false);

    int finished_count = 0;

   while(finished_count < n) {
        
        bool found = false;

        for (int i = 0; i < n; ++i) {
            if (!done[i]) {
                bool can_run = true;

                for (int j = 0; j < r; ++j) {
                    if (need[i][j] > avail[j]) {
                        can_run = false;
                        break;
                    }
                }

                if (can_run) {
                    for (int j = 0; j < r; ++j) {
                        avail[j] += alloc[i][j];
                    }

                    safe_seq.push_back(i);
                    done[i] = true;
                    finished_count++;
                    found = true;
                }
            }
        }

        if (!found) {
            std::cout << "System is not in a Safe State. " << std::endl;
            return 0;
        }
   }
   
   std::cout << "System is in a Safe State." << std::endl;
   std::cout << "Safe sequence: ";
   for (int p : safe_seq) {
        std::cout << "P" << p << " ";
   }
   std::cout << std::endl;

   return 0;
}