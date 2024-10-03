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
 
const int MAX = 3e3+10;
const int MOD = 1e9+7;

int n; 
vector<double> tb(MAX);
vector<vi> vis(MAX, vi(MAX, 0));
vector<vector<double>> dp(MAX, vector<double>(MAX));

double coins(int i, int car){

    if(i >= n){
        int cor = n - car;
        if(cor >= car) return 0.0;
        else return 1.0;
    }

    if(vis[i][car]) return dp[i][car];
    vis[i][car] = 1;

    dp[i][car] = (1 - tb[i]) * coins(i+1, car);
    dp[i][car] += (tb[i] * coins(i+1, car+1));

    return dp[i][car];
}


signed main(){

    cin >> n; 
    for(auto& i: tb) cin >> i;

    double ans = coins(0, 0);

    cout << setprecision(12) << fixed << endl;
    cout << ans << endl;
}