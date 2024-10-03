#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>
// #define int long long
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 1e6+7;
const int MOD = 1e9+7;
 
signed main(){
 
    int n, x;
    cin >> n >> x;
 
    int pri[n+1], pag[n+1];
    pri[0] = pag[0] = 0;
    for(int i=1; i <= n; i++) cin >> pri[i];
    for(int j=1; j <= n; j++) cin >> pag[j];
 
    int dp[n+1][x+1];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=x; j++)
            dp[i][j] = 0;
 
    for(int i=1; i <= n; i++){
        for(int  j=1; j <= x; j++){
            if(j >= pri[i])
                dp[i][j] = max(dp[i-1][j], pag[i]+dp[i-1][j-pri[i]]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
 
    cout << dp[n][x] << endl;
}