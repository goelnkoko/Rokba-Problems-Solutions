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
const int MAX = 1e6+10;

int fact[MAX];

inline ll binPow(ll a, ll b, ll m){

    a %= m;
    ll r = 1;

    while(b > 0){
        if(b & 1) r = (a * r) % m;

        b >>= 1;
        a = (a * a) % m;
    }

    return r;
}

signed main(){

    int n; cin >> n;

    int catNum[n/2 + 1];
    catNum[0] = 1;

    for(int i=1; i <= n/2; i++){
        catNum[i] = (((4 * i - 2)%MOD * binPow(i+1, MOD-2, MOD))%MOD * catNum[i-1]) % MOD;
    }

    if(n % 2 == 0)
        cout << catNum[n/2] << endl;
    else 
        cout << 0 << endl;
}   