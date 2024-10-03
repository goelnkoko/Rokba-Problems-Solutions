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
 
const int MAX = 1e6+7;
const int MOD = 1e9+7;
const int INF = INT_MAX;
 
signed main(){
    
    int n, k;
    cin >> n >> k;

    vi tb(n);
    for(auto& i: tb) cin >> i;

    vi dp(n, INF);
    dp[0] = 0;
    for(int i=1; i < n; i++){
        for(int j=1;j <= k; j++){
            if(i >= j){
                dp[i] = min(dp[i], abs(tb[i]-tb[i-j]) + dp[i-j]);
            }
        }
    }
    cout << dp[n-1] << endl;
}