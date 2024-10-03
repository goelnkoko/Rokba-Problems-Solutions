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
    int total = 0;

    int tb[n+1];
    for(int i=1; i <= n; i++){
        cin >> tb[i];
        total += tb[i];
    }

    int dp[n+1][total+1];
    
    for(int i=0; i <= total; i++) dp[0][i] = 0;
    dp[0][0] = 1;

    for(int i=1; i <= n; i++){
        for(int j=0; j <= total; j++){
            if(j < tb[i]) dp[i][j] = dp[i-1][j];
            else {
                int need = j - tb[i];
                if(dp[i-1][j] || dp[i-1][need]){
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
    }

    vector<int> st;
    for(int i=1; i <= total; i++){
        if(dp[n][i]) st.push_back(i);
    }
    cout << st.size() << endl;
    for(int i: st)
        cout << i << ' ';
        cout << endl;
}
