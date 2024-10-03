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
 
signed main(){
    
    int n, m; cin >> n >> m;

    char grid[n][m];
    vector<vi> dp(n, vi(m, 0));

    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i=0; i < n; i++)
        if(grid[i][0] == '.') dp[i][0] = 1;
        else break;
    
    for(int j=0; j < m; j++)
        if(grid[0][j] == '.') dp[0][j] = 1;
        else break;
    
    for(int i=1; i < n; i++){
        for(int j=1; j < m; j++){
            if(grid[i][j] != '#'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
            } 
        }
    }
    
    cout << dp[n-1][m-1] << endl;
}