#include <iostream>
using namespace std;

int h, w;
bool board[20][20];
int blockDirection[4][2][2] = {{{0, 1}, {1, 1}}, {{1, -1}, {1, 0}}, {{1, 0}, {1, 1}}, {{0, 1}, {1, 0}}};
void initializeBoard();
void insertBoard();
int countBlocks();
bool isAvailableDirection(int currentH, int currentW, int direction);
void coverBoard(int currentH, int currentW, int direction, bool color);

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> h >> w;
        initializeBoard();
        insertBoard();
        cout << countBlocks() << endl;
    }
}

void initializeBoard() {
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            board[i][j] = false;
}

void insertBoard() {
    string line;
    for (int i = 0; i < h; i++) {
        cin >> line;
        for (int j = 0; j < w; j++) {
            // 검은 칸은 true, 흰 칸은 false로 입력.
            if (line[j] == '#')
                board[i][j] = true;
            else
                board[i][j] = false;
        }
    }
}

int countBlocks() {
    int currentH = -1;
    int currentW = -1;
    // 맨 왼쪽 맨 위의 흰칸을 찾는다.
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!board[i][j]) {
                currentH = i;
                currentW = j;
                break;
            }
        }
        if (currentH != -1)
            break;
    }

    // 남은 흰칸이 없을 경우
    if (currentH == -1)
        return 1;
    
    int result = 0;
    for (int i = 0; i < 4; i++) {
        if (isAvailableDirection(currentH, currentW, i)) {
            coverBoard(currentH, currentW, i, true);
            result += countBlocks();
            coverBoard(currentH, currentW, i, false);
        }
    }
    return result;
}

bool isAvailableDirection(int currentH, int currentW, int direction) {
    for (int i = 0; i < 2; i++) {
        int tempH = currentH + blockDirection[direction][i][0];
        int tempW = currentW + blockDirection[direction][i][1];
        if (tempH < 0 || tempH > h - 1 || tempW < 0 || tempW > w - 1 || board[tempH][tempW]) {
            return false;
        }
    }
    return true;
}

void coverBoard(int currentH, int currentW, int direction, bool color) {
    board[currentH][currentW] = color;
    for (int i = 0; i < 2; i++) {
        int tempH = currentH + blockDirection[direction][i][0];
        int tempW = currentW + blockDirection[direction][i][1];
        board[tempH][tempW] = color;
    }
}