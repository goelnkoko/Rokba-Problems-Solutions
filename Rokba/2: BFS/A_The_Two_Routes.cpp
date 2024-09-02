#include <bits/stdc++.h> 

#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 410;

int adj[MAX][MAX];
vector<int> v(MAX, -1);

void bfs(int x, int n){
    
    queue<int> q;
    q.push(1);
    v[1] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i = 1; i <= n; i++){
            if(adj[node][i] == x && v[i] == -1){
                v[i] = v[node] + 1;
                q.push(i);
            }
        }
    }
}

void init(int n){
    for(int i=1; i <= n; i++)
        for(int j=i+1; j <= n; j++)
            adj[i][j] = 0;
}

int main(){

    Nkumbo

    int n, m;
    cin >> n >> m;

    init(n);

    int traverse = 1; //Meening the train with traverse the graph

    for(int i=1; i <= m; i++){
        int a, b; cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;

        if((a == 1 && b == n) || (a == n && b == 1)) traverse = 0;
    }   

    bfs(traverse, n);

    cout << v[n] << endl;
}