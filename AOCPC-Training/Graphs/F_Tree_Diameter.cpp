#include <bits/stdc++.h>

#define MAX 200010

using namespace std;

vector<int> graph[MAX];
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

    int n;
    cin >> n;

    for(int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);

    int m = 0, v = 0;
    for(int i=1; i <= n; i++){
        if(dist[i] > m){
            v = i;
            m = dist[i];
        }
    }

    bfs(v);

    m = 0;
    for(int i=1; i <= n; i++){
        m = max(m, dist[i]);
    }

    cout << m << endl;

    return 0;
}
