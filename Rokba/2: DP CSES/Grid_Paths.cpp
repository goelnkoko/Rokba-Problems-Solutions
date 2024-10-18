#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e6+7;
const int MOD = 1e9+7;

signed main(){

    int n; cin >> n;
    int dp[n+2][n+2];
    memset(dp, 0, sizeof(dp));
    char tb[n+1][n+1];

    for(int i=1; i <= n; i++) 
        for(int j=1; j <= n; j++) 
            cin >> tb[i][j];

    if(tb[n][n] != '*')
        dp[n][n] = 1;

    for(int i=n; i >= 1; i--){
        for(int j=n; j >= 1; j--){
            if(tb[i][j] == '*') continue;

            if(i == n) dp[i][j] = (dp[i][j] + dp[i][j+1])%MOD;
            else if(j == n) dp[i][j] = (dp[i][j] + dp[i+1][j])%MOD;  
            else dp[i][j] = (dp[i][j] + dp[i][j+1] + dp[i+1][j])%MOD;
        }
    }

    cout << dp[1][1] << endl;
}