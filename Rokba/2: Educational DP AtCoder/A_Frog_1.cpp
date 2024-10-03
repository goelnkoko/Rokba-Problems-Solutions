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
 
signed main(){
    
    int n; cin >> n;
    vi tb(n);
    for(auto& i: tb) cin >> i;

    vi dp(n);
    dp[1] = abs(tb[1]-tb[0]);
    
    for(int i=2; i < n; i++){
        int val1 = abs(tb[i]-tb[i-1]) + dp[i-1];
        int val2 = abs(tb[i]-tb[i-2]) + dp[i-2];

        dp[i] = min(val1, val2);
    }

    cout << dp[n-1] << endl;
}