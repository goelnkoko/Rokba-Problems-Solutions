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
 
const int MAX = 105;
const int MOD = 1e9+7;

int n;

vi dp(MAX);

double sushi(int idx, double z, vi tb, int x){

    if(idx < 0) return 0;

    if(x != -1)
        tb[x]--;

    double sol = 1 / (z/n);


    for(int i=0; i < n; i++){
        if(tb[i] - 1 == 0)
            dp[idx] += sushi(idx - 1, z - 1, tb, i);
        else 
            dp[idx] += sushi(idx - 1, z, tb, i);
    }

    return sol; 
}


signed main(){

    cin >> n;
    vi tb(n);
    for(auto& i: tb) cin >> i;

    int total = accumulate(all(tb), 0);

    double ans = sushi(total, (double)n, tb, -1);

    cout << ans << endl;

}