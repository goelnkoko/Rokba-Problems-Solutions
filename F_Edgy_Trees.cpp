#include <bits/stdc++.h> 

#define all(x) x.begin(), x.end()
#define endl '\n'
#define f first 
#define s second
#define vi vector<ll>
#define pii pair<ll, ll>

typedef long long ll;

const int MAX = 100010;
const int MOD = 1e9+7;

using namespace std;

int par[MAX];
int tam[MAX];

int find(int x){
    return par[x] < 0 ? x : par[x] = find(par[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(tam[x] > tam[y]){
        tam[x] += tam[y];
        par[y] = x;
    } else {
        tam[y] += tam[x];
        par[x] = y;
    }
}

ll binPow(ll n, ll k){
    ll r = 1;
    ll temp = n;
    n %= MOD;

    while(k > 0){
        if(k & 1) r = (r * n) % MOD;

        k >>= 1;
        n = n * n % MOD;
    }

    r = (r - temp + MOD) % MOD;
    return r;
}

int main(){

    ll n, k;
    cin >> n >> k;

    memset(par, -1, sizeof(par));
    for(int i=1; i < MAX; i++) tam[i] = 1;

    for(int i=1; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;

        if(!c) merge(a, b);
    }

    ll sum = binPow(n, k);

    for(int i=1; i <= n; i++){
        if(par[i] < 0) {
            sum = (sum - binPow(tam[i], k) + MOD) % MOD;
        }
    }

    cout << sum << endl;
}