#include <iostream>
#include <algorithm>
using namespace std;

const int INFINITE = 987654321;
int clocks[16];
int switches[10];
int connections[10][5] = {{0, 1, 2, -1, -1}, {3, 7, 9, 11, -1}, {4, 10, 14, 15, -1}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15, -1}, {3, 14, 15, -1, -1}, {4, 5, 7, 14, 15}, {1,2,3,4,5}, {3,4,5, 9, 13}};
int countClicks(int switchNum);
void switchClick(int switchNum);

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        // 배열 초기화
        for (int j = 0; j < 10; j++)
            switches[j] = 0;
        for (int j = 0; j < 16; j++) {
            cin >> clocks[j];
            clocks[j] /= 3;
            clocks[j] %= 4;
        }

        int result = countClicks(0);
        result = (result == INFINITE) ? -1 : result;
        cout << result << endl;
    }
    return 0;
}

int countClicks(int switchNum) {
    // 모든 스위치를 다 지나온 경우.
    if (switchNum == 10) {
        for (int i = 0; i < 16; i++) {
            if (clocks[i] != 0)
                return INFINITE;
        }
        // 스위치 누른 횟수 총 합을 반환.
        int count = 0;
        for (int i = 0; i < 10; i++) {
            count += switches[i];
        }
        return count;
    }

    // 현재 스위치를 누르고 다음 스위치 번호를 파라미터로 넘기면서 countClicks 호출.
    int result = INFINITE;
    for (int i = 0; i < 4; i++) {
        result = min(result, countClicks(switchNum + 1));
        switchClick(switchNum);
    }
    return result;
}

void switchClick(int switchNum) {
    switches[switchNum]++;
    switches[switchNum] %= 4;
    
    for (int i = 0; i < 5; i++) {
        if (connections[switchNum][i] == -1)
            break;
        clocks[connections[switchNum][i]]++;
        clocks[connections[switchNum][i]] %= 4;
    }
}