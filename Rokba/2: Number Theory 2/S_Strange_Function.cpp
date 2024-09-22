#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 2e5+10;

inline int __lcm(int a, int b){
    return a*b/gcd(a, b);
}

signed main(){

    int t; cin >> t;
    
    while(t--){
        ll n; cin >> n;

        ll res = 0, lcm = 1;
        
        for(int i=2; ; ++i){
            if(lcm > n) break;
            
            ll L = n / lcm;
            lcm = __lcm(lcm, i);
            ll R = n / lcm;

            res = (res + ((L-R) * i)%MOD)%MOD;
        }

        cout << res << endl;
    }
}