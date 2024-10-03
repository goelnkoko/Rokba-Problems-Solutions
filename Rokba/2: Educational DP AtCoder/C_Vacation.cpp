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
 
const int MAX = 1e5+7;
const int MOD = 1e9+7;
const int INF = INT_MAX;
 
// int cost(int i, int j){
//     if(i >= n) return 0;
//     if(dp[i][j] != -1) return dp[i][j];

//     if(j == 0)
//         return dp[i][j] = tb[i][j] + max(cost(i+1, 1), cost(i+1, 2));
    
//     if(j == 1)
//         return dp[i][j] = tb[i][j] + max(cost(i+1, 0), cost(i+1, 2));    

//     if(j == 2)
//         return dp[i][j] = tb[i][j] + max(cost(i+1, 0), cost(i+1, 1));
// }

signed main(){

    int n;
    cin >> n;

    vector<vi> dp(n, vi(3, -1)), tb(n, vi(3, 0)); 

    for(int i=0; i < n; i++){
        cin >> tb[i][0] >> tb[i][1] >> tb[i][2];
    }    

    dp[0][0] = tb[0][0];
    dp[0][1] = tb[0][1];
    dp[0][2] = tb[0][2];

    for(int i=1; i < n; i++){
        for(int j=0; j < 3; j++){
            if(j == 0)
                dp[i][j] = tb[i][j] + max(dp[i-1][1], dp[i-1][2]);
            if(j == 1)
                dp[i][j] = tb[i][j] + max(dp[i-1][0], dp[i-1][2]);
            if(j == 2)
                dp[i][j] = tb[i][j] + max(dp[i-1][0], dp[i-1][1]);
        }
    }

    int res = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    
    cout << res << endl;
}