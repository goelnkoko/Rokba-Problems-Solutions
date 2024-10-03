#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>
// #define int long long
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 1000001;
const int MOD = 1e9+7;
 
signed main(){
 
    int n;
    cin >> n;
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    for(int i=1; i <= n; i++){
        for(int j=1; j <= 6; j++){
            if(i >= j)
                dp[i] = (dp[i] + dp[i-j])%MOD;
        }
    }

    cout << dp[n] << endl;
}