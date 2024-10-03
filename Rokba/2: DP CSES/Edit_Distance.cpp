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
 
    string a, b;
    cin >> a >> b;

    a = " " + a;
    b = " " + b;
    
    int dp[a.size()+1][b.size()+1];
    dp[0][0] = 0;

    for(int i=1; i <= a.size(); i++) dp[i][0] = 1 + dp[i-1][0];
    for(int j=1; j <= b.size(); j++) dp[0][j] = 1 + dp[0][j-1];

    for(int i=1; i <= a.size(); i++){
        for(int j=1; j <= b.size(); j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }

    cout << dp[a.size()][b.size()] << endl;
}