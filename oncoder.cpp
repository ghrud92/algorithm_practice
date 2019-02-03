#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    int T;
    vector<int> requiredTime;

    priority_queue<int> heap;
    for (int i = 0; i < requiredTime.size(); i++)
        heap.push(-1 * requiredTime[i]);
    
    int count = 0;
    int solveTime = 0, panalty = 0;
    while (true) {
        int currentTime = -1 * heap.top();
        T -= currentTime;
        if (heap.empty() || T < 0)
            break;

        solveTime += currentTime;
        panalty += solveTime;
        heap.pop();
        count++;
    }

    return 0;
}