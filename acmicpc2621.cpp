// 카드게임
#include <iostream>
using namespace std;

char color[5];
int number[10];

int main() {

    bool sameColor = true;
    bool continuous = false;
    bool sameFour = false;
    bool sameThree = false;
    bool sameTwo = false;
    bool sameTwoTwice = false;

    for (int i = 0; i < 10; i++) {
        number[i] = 0;
    }

    // 카드 입력 받기
    for (int i = 0; i < 5; i++) {
        cin >> color[i];
        int card;
        cin >> card;
        number[card]++;
    }

    for (int i = 0; i < 4; i++) {
        if (color[i] != color[i + 1])
            sameColor = false;
    }

    int count = 0;
    for (int i = 1; i < 9; i++) {
        if (number[i] == 1 && number[i] == number[i + 1]) {
            count++;
        }
    }
    if (count == 4)
        continuous = true;

    for (int i = 1; i < 10; i++) {
        if (number[i] == 4)
            sameFour = true;
    }

    for (int i = 1; i < 10; i++) {
        if (number[i] == 3)
            sameThree = true;
    }

    for (int i = 1; i < 10; i++) {
        if (number[i] == 2 && sameTwo)
            sameTwoTwice = true;
        else if (number[i] == 2)
            sameTwo = true;
    }

    // 조건 하나씩 확인
    if (sameColor && continuous) {
        int max;
        for (int i = 1; i < 10; i++) {
            if (number[i] > 0)
                max = i;
        }
        cout << max + 900 << endl;
    } else if (sameFour) {
        for (int i = 1; i < 10; i++) {
            if (number[i] == 4) {
                cout << i + 800 << endl;
            }
        }
    } else if (sameThree && sameTwo) {
        int three, two;
        for (int i = 1; i < 10; i++) {
            if (number[i] == 3)
                three = i;
            if (number[i] == 2)
                two = i;
        }
        cout << three * 10 + two + 700 << endl;
    } else if (sameColor) {
        int max;
        for (int i = 1; i < 10; i++) {
            if (number[i] > 0)
                max = i;
        }
        cout << max + 600 << endl;
    } else if (continuous) {
        int max;
        for (int i = 1; i < 10; i++) {
            if (number[i] > 0)
                max = i;
        }
        cout << max + 500 << endl;
    } else if (sameThree) {
        for (int i = 1; i < 10; i++) {
            if (number[i] == 3)
                cout << i + 400 << endl;
        }
    } else if (sameTwoTwice) {
        int first = 0;
        int second;
        for (int i = 1; i < 10; i++) {
            if (number[i] == 2 && first == 0) {
                first = i;
            } else if (number[i] == 2) {
                second = i;
            }
        }
        cout << second * 10 + first + 300 << endl;
    } else if (sameTwo) {
        for (int i = 1; i < 10; i++) {
            if (number[i] == 2) {
                cout << i + 200 << endl;
            }
        }
    } else {
        int max;
        for (int i = 1; i < 10; i++) {
            if (number[i] > 0)
                max = i;
        }
        cout << max + 100 << endl;
    }

    return 0;
}