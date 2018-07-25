#include <iostream>
using namespace std;

int n, m;
bool friends[10][10];
void cleanUp();
void insertFriends();
int countFriends(bool taken[10]);

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> n >> m;
        cleanUp();
        insertFriends();
        bool taken[10];
        for (int j = 0; j < 10; j++)
            taken[j] = false;
        cout << countFriends(taken) << endl;
    }
}

void cleanUp() {
    // 친구여부 배열 초기화.
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            friends[i][j] = false;
}

void insertFriends() {
    // 친구여부를 배열에 저장.
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends[a][b] = true;
        friends[b][a] = true;
    }
}

int countFriends(bool taken[10]) {
    // 짝이 없는 아이 중 가장 작은 번호를 저장.
    int first = -1;
    for (int i = 0; i < n; i++) {
        if (taken[i] == false) {
            first = i;
            break;
        }
    }

    // 모든 아이들이 짝을 가진 경우.
    if (first == -1) {
        return 1;
    }

    int result = 0;
    for (int i = first + 1; i < n; i++) {
        // first와 친구이면서 짝이 없는 i가 있는 경우.
        if (!taken[i] && friends[first][i]) {
            taken[first] = true;
            taken[i] = true;
            result += countFriends(taken);
            taken[first] = false;
            taken[i] = false;
        }
    }
    return result;
}