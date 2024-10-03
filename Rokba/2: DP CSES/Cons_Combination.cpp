#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e6+7;
const int MOD = 1e9+7;

signed main(){

    int n, s;
    cin >> n >> s;

    int dp[MAX];
    memset(dp, 0, sizeof(dp));

    int tb[n];
    for(int i=0; i < n; i++) {
        cin >> tb[i];
        dp[tb[i]] = 1;
    }

    for(int i=1; i <= s; i++){
        for(int j: tb){
            if(j <= i) dp[i] = (dp[i] + dp[i-j])%MOD;
        }
    }

    cout << dp[s] << endl;
}
