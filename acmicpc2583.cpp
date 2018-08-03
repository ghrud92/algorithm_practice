// 영역 구하기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    int field[m][n];
    // 초기화.
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            field[i][j] = 0;
    // 입력 받기.
    while (k--) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        for (int i = y; i < v; i++) {
            for (int j = x; j < u; j++) {
                field[i][j] = -1;
            }
        }
    }

    int mass = 0;
    bool isChanged = true;
    vector<int> queueX;
    vector<int> queueY;
    while (isChanged) {
        isChanged = false;
        if (queueX.empty()) {   // 큐가 비었으면 mass가 하나 끝난 것이므로 새로운 시작점을 찾는다.
            mass++;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (field[i][j] == 0) {
                        field[i][j] = mass;
                        queueX.push_back(i);
                        queueY.push_back(j);
                        isChanged = true;
                        break;
                    }
                }
                if (isChanged)
                    break;
            }
        } else {    // 현재 큐에 들어있는 지점들과 이어지는 부분을 채크한다.
            int x = queueX.at(0);
            int y = queueY.at(0);
            queueX.erase(queueX.begin());
            queueY.erase(queueY.begin());
            
            if (x != 0 && field[x - 1][y] == 0) {
                field[x - 1][y] = mass;
                queueX.push_back(x - 1);
                queueY.push_back(y);
            }
            if (y != 0 && field[x][y - 1] == 0) {
                field[x][y - 1] = mass;
                queueX.push_back(x);
                queueY.push_back(y - 1);
            }
            if (x != m - 1 && field[x + 1][y] == 0) {
                field[x + 1][y] = mass;
                queueX.push_back(x + 1);
                queueY.push_back(y);
            }
            if (y != n - 1 && field[x][y + 1] == 0) {
                field[x][y + 1] = mass;
                queueX.push_back(x);
                queueY.push_back(y + 1);
            }

            isChanged = true;
        }
    }

    // mass별 넓이 기록
    int area[mass];
    for (int i = 0; i < mass; i++)
        area[i] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j] != -1) {
                area[field[i][j]]--;    // max_heap을 min_heap으로 사용하기 위해 반대로 저장
            }
        }
    }

    // sorting
    priority_queue<int> result;
    for (int i = 1; i < mass; i++) {
        result.push(area[i]);
    }
    
    // 결과 출력.
    cout << mass - 1 << endl;
    while (!result.empty()) {
        cout << -1 * result.top();
        result.pop();
        if (!result.empty()) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}