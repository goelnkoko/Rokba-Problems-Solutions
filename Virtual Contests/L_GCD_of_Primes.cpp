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
const int INF = LLONG_MAX;

ll binPow(int a, int b){
    ll r = 1; 
    while(b > 0){
        if(b & 1){
            r *= a;
        }
        b >>= 1;
        a *= a;
    }
    return r;
}

signed main(){
    Nkumbo

    int n;
    cin >> n; 

    pii tb[n];

    for(int i = 0; i < n; i++){
        cin >> tb[i].ff >> tb[i].ss;
    }   

    ll res = INF;

    for(int i = 1; i < (1 << n); i++){
        ll pr1 = 1, pr2 = 1;
        
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                pr1 *= binPow(tb[j].ff, tb[j].ss);
            } else {
                pr2 *= binPow(tb[j].ff, tb[j].ss);
            }
        }
        res = min(res, max(pr1, pr2));
    }

    cout << res << endl;
}
