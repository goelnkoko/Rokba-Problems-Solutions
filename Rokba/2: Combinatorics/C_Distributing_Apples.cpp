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
const int MAX = 2e6+10;

int fact[MAX];

inline ll binPow(int a, int b){
    ll r = 1;
    a %= MOD;

    while(b > 0){
        if(b & 1) r = (r * a) % MOD;

        b >>= 1;
        a = (a * a) % MOD;
    }

    return r;
}

signed main(){

    int n, m;
    cin >> m >> n;

    vector<int> fact(MAX);

    fact[0] = 1;
    for(int i=1; i < MAX; i++){
        fact[i] = (fact[i-1] * i)%MOD;
    }

    int x = n + m - 1;
    int res = fact[x] * binPow(fact[n] * fact[m-1], MOD-2);
    cout << res%MOD << endl;
}   