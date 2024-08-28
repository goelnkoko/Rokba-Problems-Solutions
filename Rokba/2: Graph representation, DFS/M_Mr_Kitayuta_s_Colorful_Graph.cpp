#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 100 + 20;

vector<int> adj[MAX][MAX];

void dfs(int root, int c, vector<int>& v){
    v[root] = 1;

    for(const auto& i: adj[root][c]){
        if(v[i] == 1) continue;
        dfs(i, c, v);
    }
}

int main(){

    Nkumbo

    int n, m, q;
    cin >> n >> m;

    for(int i=0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a][c].push_back(b);
        adj[b][c].push_back(a);
    }

    cin >> q;
    while(q--){

        int a, b, co = 0;
        cin >> a >> b;

        for(int c=1; c <= m; c++){
            vector<int> v(n+1, 0);
            dfs(a, c, v);
            if(v[b] == 1) co++;
        }

        cout << co << endl;
    }


}