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

    int n;
    cin >> n;

    int tb[n+1], ps[n+1];
    ps[0] = 0;
    for(int i=1; i <= n; i++){
        cin >> tb[i];
        ps[i] = ps[i-1] + tb[i];
    }

    int dp[ps[n]+1];
    for(int i=0; i <= ps[n]; i++) dp[i] = 0;
    dp[0] = 1;

    for(int i=1; i <= n; i++){
        for(int j = ps[i]; j >= tb[i]; j--){
            if(dp[j] || dp[j-tb[i]] == 0) continue;
            dp[j] = 1;
        }
    }

    set<int> st;
    for(int i=1; i <= ps[n]; i++)
        if(dp[i]) st.insert(i);
    
    cout << st.size() << endl;
    for(auto i: st) cout << i << ' ';
    cout << endl;
}
