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
 
const int MAX = 501;
const int MOD = 1e9+7;
const int INF = INT_MAX;

signed main(){
    
    int t; cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vi tb(n+10);
        int M = -1;
        int total = 0;
        for(int i=0; i < n; i++){
            cin >> tb[i];
            total += tb[i];
            M = max(M, tb[i]);
        }

        for(int i=n; i >= 1; i--){
            ll v = (total + k) / i;
            if(v * i < total) continue;
            if(v < M) continue;
            cout << i << endl;
            break;
        }
    }
}