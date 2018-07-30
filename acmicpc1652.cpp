// 누울 자리를 찾아라.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
char room[100][100];
int vacant[5001];

int main() {
    int horizontal, vertical;
    // 배열 초기화.
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            room[i][j] = 'O';
    for (int i = 0; i < 5001; i++)
        vacant[i] = 0;

    // 방을 입력받는다.
    cin >> n;
    string lineInput;
    for (int i = 0; i < n; i++) {
        cin >> lineInput;
        for (int j = 0; j < n; j++) {
            room[i][j] = lineInput.at(j);
        }
    }

    // 배열 가로부분 계산.
    int index = 1;
    int before = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (room[i][j] == 'X' && before != -1) {
                index++;
                before = -1;
            } else if (room[i][j] == '.') {
                vacant[index]++;
                before = index;
            }
        }
        if (before != -1) {
            index++;
            before = -1;
        }
    }

    int solo = 0;
    for (int i = 0; i < min(index + 1, 5001); i++) {
        if (vacant[i] == 1)
            solo++;
    }
    horizontal = index - 1 - solo;

    // 배열 세로 부분 계산.
    for (int i = 0; i < 5001; i++)
        vacant[i] = 0;
    index = 1;
    before = -1;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (room[i][j] == 'X' && before != -1) {
                index++;
                before = -1;
            } else if (room[i][j] == '.') {
                vacant[index]++;
                before = index;
            }
        }
        if (before != -1) {
            index++;
            before = -1;
        }
    }

    solo = 0;
    for (int i = 0; i < min(index + 1, 5001); i++) {
        if (vacant[i] == 1)
            solo++;
    }
    vertical = index - 1 - solo;

    cout << horizontal << " " << vertical << endl;

    return 0;
}