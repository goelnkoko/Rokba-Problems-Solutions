#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 1e5+7;
const int MOD = 1e9+7;
 
vector<int> adj[MAX];

vi dp(MAX, 0);

int dfs(int r){

    if(dp[r] != 0) return dp[r];

    for(int i: adj[r]){
        dp[r] = max(dp[r], 1 + dfs(i));
    }

    return dp[r];
}

signed main(){
    
   int n, m; cin >> n >> m;

    for(int i=0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=1; i <= n; i++){
        if(dp[i] == 0)
            dfs(i);
    }

    int ans = *max_element(dp.begin(), dp.begin() + n + 1);

    cout << ans << endl;
}