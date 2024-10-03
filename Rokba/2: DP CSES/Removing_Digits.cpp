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
 
    int n; cin >> n;
    int dp[n+10];
    
    for(int i=0; i <= 9; i++) dp[i] = 1;
    for(int i=10; i <= n; i++) dp[i] = MAX;

    for(int i=1; i <= n; i++){
        for(int j=1; j <= i; j *= 10){
            int k = i / j % 10;
            dp[i] = min(dp[i], 1 + dp[i-k]);
        }
    }

    cout << dp[n] << endl;
}