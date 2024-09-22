#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 2e5+10;

vector<int> tree[MAX];

void dfs(int root, int pai, vector<int>& v){
    v[root] += 1;
    for(int i: tree[root]){
        v[i] += 1;
        if(i == pai) continue;
        dfs(i, root, v);
    }
}

signed main(){

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        for(int i=0; i < n-1; i++){
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        vector<int> v(n+1, 0);
        bool ans = true;
        for(int i=1; i <= n; i++)
            if(tree[i].size() > 3) ans = false;
        
        if(ans) {
            v[1] = 1;
            dfs(1, -1, v);
            for(int i = 1; i <= n; i++){
                if(v[i] > 3) ans = false;
            }
        }

        cout << (ans ? "YES":"NO") << endl;
    }

}   