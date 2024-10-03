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
 
    int t; cin >> t;

    vvi dp(MAX, vi(8, 0));
    for(int i=0; i < 8; i++) dp[0][i] = 1;

    for(int i=1; i < MAX; i++){
        for(int j=0; j < 8; j++){
            if(j == 0 || j == 2 || j == 3 || j == 4 || j == 5){
                dp[i][j] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5])%MOD;
            } else {
                dp[i][j] = (dp[i-1][6] + dp[i-1][3] + dp[i-1][7])%MOD;
            }
        }
    }

    
    while(t--){
        int n; cin >> n; 

        int res = dp[n-1][2] + dp[n-1][6];
        cout << res%MOD << endl;
    }
}