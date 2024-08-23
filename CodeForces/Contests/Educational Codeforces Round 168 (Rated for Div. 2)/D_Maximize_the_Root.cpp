#include <bits/stdc++.h>
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
#define ll long long

using namespace std;

const ll MAX = 200010;

vector<ll> graph[MAX];
vector<ll> v(MAX, 0);

bool dfs(ll root, ll val){

    if(graph[root].empty() && v[root] < val) return false;

    if(root == 1) val = max(0ll, val - v[root]);
    else if(v[root] < val) val = min(0ll + INT_MAX, val + val - v[root]);

    for(auto i: graph[root]){
        if(!dfs(i, val)) return false;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;

    for(int i=1; i <= n; i++){
        cin >> v[i];
    }

    for(int i=2; i <= n; i++){
        ll a;
        cin >> a;
        graph[a].push_back(i);
    }

    ll l = 0, r = INT_MAX;

    while(l + 1 < r) {
        ll mid = (l + r)/2;
        if(dfs(1, mid)) l = mid;
        else r = mid;
    }

    cout << l << endl;

    for(int i=1; i <= n; i++) graph[i].clear();
}

int main(){

    Nkumbo

    int t; 
    cin >> t;

    while(t--){
        solve();
    }
    
}