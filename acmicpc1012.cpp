// 유기농 배추
#include <iostream>
#include <list>
using namespace std;

int field[50][50];
list<int> queueX;
list<int> queueY;
int result, m, n;
void initialize();

int main() {
    int t;
    cin >> t;
    while (t--) {
        initialize();
        int k;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }
        
        bool isChanged = true;
        while (isChanged) {
            isChanged = false;
            // 큐가 비었을 경우 : 처음 시작 || 한 뭉치를 다 확인 했을 경우 > 새로운 시작점을 찾는다.
            if (queueX.empty()) {
                result += 2;
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        if (field[i][j] == 1) {
                            field[i][j] = result;
                            queueX.push_back(i);
                            queueY.push_back(j);
                            isChanged = true;
                            break;
                        }
                    }
                    if (isChanged)
                        break;
                }
            } else {
                isChanged = true;
                int x = queueX.front();
                int y = queueY.front();
                queueX.pop_front();
                queueY.pop_front();
                
                // (x, y)의 인근 지점에 배추가 있는지 확인.
                if (x != 0 && field[x - 1][y] == 1) {
                    field[x - 1][y] = result;
                    queueX.push_back(x - 1);
                    queueY.push_back(y);
                }
                if (y != n - 1 && field[x][y + 1] == 1) {
                    field[x][y + 1] = result;
                    queueX.push_back(x);
                    queueY.push_back(y + 1);
                }
                if (x != m - 1 && field[x + 1][y] == 1) {
                    field[x + 1][y] = result;
                    queueX.push_back(x + 1);
                    queueY.push_back(y);
                }
                if (y != 0 && field[x][y - 1] == 1) {
                    field[x][y - 1] = result;
                    queueX.push_back(x);
                    queueY.push_back(y - 1);
                }
            }
        }

        cout << result / 2 - 1 << endl;
    }

    return 0;
}

void initialize() {
    // 전역 변수 초기화
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            field[i][j] = 0;
        }
    }
    result = 0;
}