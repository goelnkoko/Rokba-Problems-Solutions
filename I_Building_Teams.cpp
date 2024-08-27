#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 100000 + 20;

vector<int> graph[MAX];
vector<int> col(MAX, 0);

bool ans = true;

void dfs(int root, int pai){
    col[root] = (col[pai] == 1 ? 2:1);

    for(const auto& i: graph[root]){
        if(col[i] != 0){
            if(col[root] == col[i]) ans = false;
            continue;
        }
        dfs(i, root);
    }
}

int main(){

    Nkumbo

    int n, m, a, b;
    cin >> n >> m;

    for(int i=0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i <= n; i++){
        if(col[i] == 0){
            dfs(i, i);
        }
    }

    if(ans){
        for(int i=1; i <= n; i++) cout << col[i] << ' '; cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    
}