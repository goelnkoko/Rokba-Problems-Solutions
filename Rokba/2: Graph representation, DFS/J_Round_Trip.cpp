#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 100010;

vector<int> adj[MAX];
vector<int> v(MAX, 0);

int r = -1;

void dfs(int root, int pai, vector<int>& res){
    v[root] = 1;

    res.push_back(root);

    for(const auto& i: adj[root]){
        if(v[i] != 0 && r == -1) {
            if(i != pai) r = i;
            continue;
        }
        if(r == -1)
        dfs(i, root, res);
    }

    if(r != -1) return;
    res.pop_back();
}

int main(){

    Nkumbo

    int n, m;
    cin >> n >> m;

    for(int i=1; i <= m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);    
    }
    
    vector<int> res;

    for(int i=1; i <= n; i++){
        res.clear();
        if(v[i] == 0) dfs(i, i, res);
        if(r != -1) break;
    }

    if(r == -1) {cout << "IMPOSSIBLE" << endl; return 0;}

    bool f = false;
    for(int i=0; i < res.size(); i++){
        if(res[i] == r && i != res.size()-1){
            cout << (res.size() - i + 1) << endl;
            f = true;
        } 
        if(f) cout << res[i] <<  ' ';
    }
    cout << r << endl;
}