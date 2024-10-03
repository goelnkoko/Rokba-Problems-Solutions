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
 
const int MAX = 501;
const int MOD = 1e9+7;
const int INF = INT_MAX;

int dp[MAX][MAX];

int cut(int a, int b){
    
    if(a == b) return 0;
    
    if(dp[a][b] != -1) return dp[a][b];

    int mini = INF;

    for(int i = 1; i <= a/2; i++)
        mini = min(mini, 1 + cut(i, b) + cut(a-i, b));
    
    for(int i=1; i <= b/2; i++)
        mini = min(mini, 1 + cut(a, i) + cut(a, b-i));
    
    return dp[a][b] = mini;
}

signed main(){
 
    int a, b; cin >> a >> b;

    memset(dp, -1, sizeof(dp));

    cout << cut(a, b) << endl;
}