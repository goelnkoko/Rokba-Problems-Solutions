#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 2000 + 10;

vector<int> adj[MAX];
vector<int> v(MAX, 0);

int m = 0;


void dfs(int root, int pai, int& m){
    v[root] = v[pai] + 1;
    m = max(m, v[root]);

    for(const auto& i: adj[root]){
        if(v[i] != 0) continue;
        dfs(i, root, m);
    }
}

int main(){

    Nkumbo

    int n;
    cin >> n;

    vector<int> root;

    for(int i=1; i <= n; i++){
        int a; cin >> a;

        if(a == -1) root.push_back(i); 
        else adj[a].push_back(i);
    }

    int m = 0; 

    for(const auto& i: root){
        dfs(i, i, m);
    }

    cout << m << endl; 
}