// 토마토
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    vector<int> ripenM;
    vector<int> ripenN;

    int m, n;
    cin >> m >> n;
    int box[m][n];  // 생각하기 쉽게 가로 세로를 뒤집는다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &box[j][i]);
            if (box[j][i] == 1) {
                ripenM.push_back(j);
                ripenN.push_back(i);
            }
        }
    }

    int date = 0;
    while (!ripenM.empty()) {
        date++;
        int currentLength = ripenM.size();
        for (int i = 0; i < currentLength; i++) {
            int x = ripenM.at(0);
            int y = ripenN.at(0);
            ripenM.erase(ripenM.begin());
            ripenN.erase(ripenN.begin());

            if (x != 0 && box[x - 1][y] == 0) {
                box[x - 1][y] = 1;
                ripenM.push_back(x - 1);
                ripenN.push_back(y);
            }
            if (y != n - 1 && box[x][y + 1] == 0) {
                box[x][y + 1] = 1;
                ripenM.push_back(x);
                ripenN.push_back(y + 1);
            }
            if (x != m - 1 && box[x + 1][y] == 0) {
                box[x + 1][y] = 1;
                ripenM.push_back(x + 1);
                ripenN.push_back(y);
            }
            if (y != 0 && box[x][y - 1] == 0) {
                box[x][y - 1] = 1;
                ripenM.push_back(x);
                ripenN.push_back(y - 1);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (box[i][j] == 0) {
                date = 0;   
            }
        }
    }
    
    cout << date - 1 << endl;
    
    return 0;
}