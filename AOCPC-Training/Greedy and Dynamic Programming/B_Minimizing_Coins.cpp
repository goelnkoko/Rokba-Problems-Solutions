#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 200001
#define MOD 100000000
#define ll long long
#define llmp map<ll, ll> mp
#define vi vector<int>
#define vll vector<ll> 
#define vpll vector<pair<ll, ll>>

using namespace std;

void solve() {

    ll n, s;
    cin >> n >> s;

    set<ll> c;

    for(int i=0; i < n; i++){
        ll a;
        cin >> a;

        c.insert(a);
    }

    vector<ll> dp(s+1);

    dp[0] = 0;

    for(int i=1; i <= s; i++){
        dp[i] = INT_MAX;
        for(int j: c){
            if(j <= i && dp[i-j] != -1)
                dp[i] = min(dp[i], 1 + dp[i-j]);
        }

        if(dp[i] == INT_MAX) dp[i] = -1;
    }

    cout << dp[s] << endl;
}

int main() {

    Nkumbo

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t=1; 
    // cin >> t; 

    while(t--) {
        solve();
    }

    return 0;
}