#include <bits/stdc++.h>

#define MAX 200010

using namespace std;

int graph[MAX][MAX];
vector<int> v(MAX, 0);
vector<int> dist(MAX, 0);


void bfs(int root) {
    
    for(int i=0; i <= MAX; i++){
        v[i] = 0;
        dist[i] = 0;
    }
    
    queue<int> q;

    q.push(root);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        v[node] = 1;

        for (int i : graph[node]) {
            if (v[i] == 0) {
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    for(int i=0; i< n; i++){
        for(int j=0; j < m; j++){

        }
    }

    for(int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;


    }

    for(int i=0; i < n; i++){

    }

    return 0;
}
