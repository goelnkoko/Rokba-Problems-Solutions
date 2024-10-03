#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long
#define w first 
#define v second

using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 1e5+7;
const int MOD = 1e9+7;
const int INF = INT_MAX;
 
signed main(){

    int n, W;
    cin >> n >> W;

    vector<pii> tb(n+1);

    for(int i=1; i <= n; i++){
        cin >> tb[i].w >> tb[i].v;
    }
    
    vector<vi> dp(n+1, vi(W+1));

    for(int i=1; i <= n; i++){
        for(int j=1; j <= W; j++){
            if(tb[i].w <= j){
                dp[i][j] = max(dp[i-1][j], tb[i].v + dp[i-1][j - tb[i].w]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << dp[n][W] << endl;
}