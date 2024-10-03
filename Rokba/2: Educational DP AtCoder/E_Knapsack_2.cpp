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
const int INF = 1e18;

vector<pii> tb(105);
vector<vi> dp(105, vi(MAX));

int kp(int i, int val){
    if(val < 0) 
        return INF;
    if(val == 0)
        return 0;
    if(i == 0)
        return INF;

    if(dp[i][val] != 0)
        return dp[i][val];

    int take = tb[i].w + kp(i-1, val - tb[i].v);
    int utake = kp(i-1, val);

    return dp[i][val] = min(take, utake);
}
 
signed main(){

    int n, W;
    cin >> n >> W;

    for(int i=1; i <= n; i++){
        cin >> tb[i].w >> tb[i].v;
    }

    int ans = 0;
    for(int i=1e5; i >= 0; i--){
        if(kp(n, i) <= W){
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}