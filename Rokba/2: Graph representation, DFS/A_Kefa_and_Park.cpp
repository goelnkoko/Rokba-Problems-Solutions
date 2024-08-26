#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll MAX = 100010;
const ll MOD = 1e9+7;

vector<int> tree[MAX];
vector<int> cat(MAX, 0);
vector<int> v(MAX, 0);

bool ans = true;
int c = 0, m;

void dfs(int root, int ct){

    v[root] = 1;

    if(cat[root] == 1) ct++;
    else ct = 0;

    if(ct > m) return;

    if(tree[root].size() == 1 && root != 1) c++;

    for(auto i: tree[root]){
        if(v[i] == 1) continue;
        dfs(i, ct);
    }
}

int main() {

    int n, a, b;
    cin >> n >> m;

    for(int i=1; i <= n; i++) cin >> cat[i];

    for(int i=1; i < n; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    cout << c << endl;

    return 0;
}