#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mk make_pair 
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first 
#define ss second
#define int long long
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 1e6;
const int MOD = 1e9+7;
const int INF = INT_MAX;

vector<int> d(int n){
    vector<int> dv;
    ll c = 0;
    for(ll i=1; i*i <= n; i++){
        if(n % i == 0){
            dv.push_back(i);
            if(n/i != i)
                dv.push_back(n/i);
        }
    }

    sort(all(dv));
    return dv;
}

signed main(){

    Nkumbo

    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vi dv = d(n); 

        int ans = -1;
        for(int i=0; i < dv.size(); i++){
            int res = 1;

            vector<int> aux = d(dv[i]);
            for(int i=0; i < aux.size(); i++){
                res *= aux[i];
            }

            if(res == n){
                ans = dv[i];
                break;
            }
        }

        cout << ans << endl;
    }

}