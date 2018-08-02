// 바이러스
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int> > edge;
    bool visit[101];
    vector<int> queue;

    // 입력받기.
    int n, m;
    cin >> n >> m;
    edge.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    // 방문 배열 초기화.
    for (int i = 0; i < 101; i++) {
        visit[i] = false;
    }

    int index, target;
    index = target = 1;
    visit[1] = true;
    queue.push_back(1);
    while (!queue.empty()) {
        int number = queue.front();
        queue.erase(queue.begin());
        while (!edge[number].empty()) {
            int next = edge[number].front();
            edge[number].erase(edge[number].begin());
            if (!visit[next]) {
                visit[next] = true;
                index++;
                queue.push_back(next);
            }
        }
    }

    cout << index - 1 << endl;
    
    return 0;
}