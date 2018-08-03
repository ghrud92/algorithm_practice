// DFS와 BFS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > edge;
vector<int> dfsResult;
vector<int> bfsResult;
bool isVisited[1000];
void visitedRefresh();
void dfsSearch(int vertex);
void bfsSearch(int vertex);

int main() {
    // 전역변수 초기화
    edge.resize(1000);
    visitedRefresh();

    priority_queue<int> temp_heap[1000];

    // 입력받기
    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        temp_heap[a - 1].push(-1 * (b - 1));
        temp_heap[b - 1].push(-1 * (a - 1));
    }
    for (int i = 0; i < n; i++) {
        while (!temp_heap[i].empty()) {
            edge[i].push_back(-1 * temp_heap[i].top());
            temp_heap[i].pop();
        }
    }

    dfsSearch(v - 1);
    visitedRefresh();
    bfsSearch(v - 1);

    // dfs 출력.
    for (int i = 0; i < dfsResult.size(); i++) {
        cout << dfsResult.at(i) + 1;
        if (i != dfsResult.size() - 1)
            cout << " ";
    }
    cout << endl;

    // bfs 출력.
    for (int i = 0; i < bfsResult.size(); i++) {
        cout << bfsResult.at(i) + 1;
        if (i != bfsResult.size() - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}

void visitedRefresh() {
    for (int i = 0; i < 1000; i++)
        isVisited[i] = false;
}

void dfsSearch(int vertex) {
    if (isVisited[vertex])
        return;
    isVisited[vertex] = true;
    dfsResult.push_back(vertex);

    vector<int>::iterator it = edge[vertex].begin();
    while (it != edge[vertex].end()) {
        dfsSearch(*it);
        it++;
    }
}

void bfsSearch(int vertex) {
    isVisited[vertex] = true;
    bfsResult.push_back(vertex);
    vector<int> queue;
    queue.push_back(vertex);
    while (!queue.empty()) {
        vertex = queue.at(0);
        queue.erase(queue.begin());
        for (int i = 0; i < edge[vertex].size(); i++) {
            int target = edge[vertex].at(i);
            if (isVisited[target])
                continue;
            isVisited[target] = true;
            bfsResult.push_back(target);
            queue.push_back(target);
        }
    }
}