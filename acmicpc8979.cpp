// 올림픽
#include <iostream>
#include <vector>
using namespace std;

int n, target;
int gold[1002];
int silver[1002];
int copper[1002];
vector<int> checkList;
int goldCount();
int silverCount();
int copperCount();

int main() {
    // 배열 초기화.
    for (int i = 0; i < 1002; i++) {
        gold[i] = silver[i] = copper[i] = 0;
    }

    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        cin >> gold[m] >> silver[m] >> copper[m];
    }

    cout << goldCount() + 1 << endl;

    return 0;
}

int goldCount() {
    int count = 0;
    for (int i = 1; i < n + 1; i++) {
        if (i == target)
            continue;
        else if (gold[i] > gold[target]) {
            count++;
        }
        else if (gold[i] == gold[target]) {
            checkList.push_back(i);
        }
    }
    count += silverCount();
    return count;
}

int silverCount() {
    int count = 0;
    int size = checkList.size();
    for (int i = 0; i < size; i++) {
        int temp = checkList.at(0);
        checkList.erase(checkList.begin());
        if (silver[temp] > silver[target]) {
            count++;
        }
        else if (silver[temp] == silver[target]) {
            checkList.push_back(temp);
        }
    }
    count += copperCount();
    return count;
}

int copperCount() {
    int count = 0;
    for (int i = 0; i < checkList.size(); i++) {
        int temp = checkList.at(0);
        if (copper[temp] > silver[target])
            count++;
    }
    return count;
}