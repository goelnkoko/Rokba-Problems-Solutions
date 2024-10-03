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
 
const int MAX = 5001;
const int MOD = 1e9+7;
const int INF = INT_MAX;

int dp[MAX][MAX];
int tb[MAX];

int score(int i, int j){

    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int l = tb[i] + min(score(i+2, j), score(i+1, j-1));
    int r = tb[j] + min(score(i, j-2), score(i+1, j-1));
    
    return dp[i][j] = max(l, r);
}


signed main(){
 
    int n; cin >> n; 
    for(int i=0; i < n; i++)
        cin >> tb[i];

    memset(dp, -1, sizeof(dp));

    int x = score(0, n-1);
    cout << x << endl;
}