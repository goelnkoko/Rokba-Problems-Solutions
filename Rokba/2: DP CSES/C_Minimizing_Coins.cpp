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
 
    int n, s;
    cin >> n >> s;
 
    int dp[s+1];
 
    for(int i=0; i <= s; i++) dp[i] = MAX;
    dp[0] = 0;
    
    int tb[n];
    for(int i=0; i < n; i++) 
        cin >> tb[i];

    for(int i=1; i <= s; i++)
        for(int& j: tb)
            if(i >= j)
                dp[i] = min(dp[i], 1 + dp[i-j]);
    
    if(dp[s] == MAX) cout << -1 << endl;
    else cout << dp[s] << endl;
}