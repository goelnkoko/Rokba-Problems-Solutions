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
 
const int MAX = 3005;
const int MOD = 1e9+7;

vi tb(MAX);
vector<vi> dp(MAX, vi(MAX));

int deq(int i, int j){
    if(i > j) 
        return 0;

    if(dp[i][j] != 0) return dp[i][j];
    
    int l = tb[i] + min(deq(i+2, j), deq(i+1, j-1));
    int r = tb[j] + min(deq(i, j-2), deq(i+1, j-1));

    return dp[i][j] = max(l, r);;
}
 
signed main(){
    
    int n; cin >> n;
    for(int i=0; i < n; i++)
        cin >> tb[i];
    
    int sum = accumulate(tb.begin(), tb.begin() + n + 1, 0LL);
    int fir = deq(0, n-1);
    int sec = sum - fir;
    int ans = fir - sec;
    cout << ans << endl;
}