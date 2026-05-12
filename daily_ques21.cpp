// 1665 minimum-initial-energy-to-finish-tasks

// You are given an array tasks where tasks[i] = [actuali, minimumi]:

// actuali is the actual amount of energy you spend to finish the ith task.
// minimumi is the minimum amount of energy you require to begin the ith task.
// For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.

// You can finish the tasks in any order you like.

// Return the minimum initial amount of energy you will need to finish all the tasks.

 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int inten = 0;
        int curen = 0;

        for (const auto& task : tasks) {
            int act = task[0];
            int min = task[1];

            if (curen < min) {

                inten += (min - curen);
                curen = min;
            }
            
            curen -= act;
        }

        return inten;
    }
};

int main() {
    Solution sol;
    

    vector<vector<int>> tasks = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};
    
    cout << "Minimum Initial Energy Required: " << sol.minimumEffort(tasks) << endl;
    

    return 0;
}