// 연결 요소의 개수
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > edge;
int visit[1001];
vector<int> queue;

int main() {
    // 배열들 초기화.
    for (int i = 0; i < 1001; i++) {
        visit[i] = -1;
    }

    int n, m;
    cin >> n >> m;
    edge.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        // 숫자 시작을 1로 통일.
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    // BFS
    int index = 0;
    int check = -1;
    bool isChanged;
    do {
        isChanged = false;
        if (!queue.empty()) {
            int target = queue.at(0);
            queue.erase(queue.begin());
            // visit[target] = index;
            while (!edge[target].empty()) {
                int number = edge[target].front();
                if (visit[number] == -1) {
                    visit[number] = index;
                    queue.push_back(number);
                }
                edge[target].erase(edge[target].begin());
            }
            isChanged = true;
        }
        if (!isChanged) {
            index++;
            int target = -1;
            int i;
            if (check == -1)
                i = 1;
            else i = check + 1;
            for (; i < n + 1; i++) {
                if (visit[i] == -1) {
                    target = i;
                    check = i;
                    break;
                }
            }
            if (target != -1) {
                visit[target] = index;
                queue.push_back(target);
                isChanged = true;
            }
        }
    } while (isChanged);
        
    cout << index - 1 << endl;

    return 0;
}