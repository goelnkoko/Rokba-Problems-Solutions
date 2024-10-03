#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mk make_pair 
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long
#define ff first 
#define ss second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 501;
const int MOD = 1e9+7;
const int INF = INT_MAX;

signed main(){
    
    int n; cin >> n; 

    int total = ((n+1) * n) / 2;

    if(total % 2) {
        cout << 0 << endl;
        return 0;
    }

    int setSum = total / 2;
    int dp[n+1][setSum+1];
    dp[0][0] = 1;
    for(int i=1; i <= setSum; i++) dp[0][i] = 0;

    for(int i=1; i <= n; i++){
        for(int j = 0; j <= setSum; j++){
            if(j >= i)
                dp[i][j] = (dp[i-1][j-i] + dp[i-1][j])%MOD;
            else 
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << (dp[n][setSum] * ((MOD+1)/2))%MOD << endl;
}