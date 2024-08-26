#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll MAX = 10010;
const ll MOD = 1e9+7;

vector<int> tree[MAX];
vector<int> v(MAX, 0);

bool ans = true;

void dfs(int root, int pai){
    v[root]++;

    for(auto i: tree[root]){
        if(v[i] != 0) {
            if(i != pai) ans = false;
            continue;
        } 
        dfs(i, root);
    }
}

int main() {

    int n, m, a, b;
    cin >> n >> m;

    while(m--){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    if(n == 1) {cout << "NO" << endl; return 0;}

    dfs(1, 1);

    for(int i=1; i <= n; i++)
        if(v[i] == 0) ans = false;

    cout << (ans ? "YES":"NO") << endl;

    return 0;
}