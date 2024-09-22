#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 998244353;
const int MAX = 3e5+10;

vector<int> prime(MAX, 1);

void sieve(){
    for(int i=2; i * i < MAX; i++){
        if(prime[i])
        for(int j=i*i; j < MAX; j+=i){
            prime[j] = 0;
        }
    }
}

ll binPow(ll a, ll b, ll m){
    a %= m;
    ll r = 1;

    while(b > 0){
        if(b & 1) r = (r * a) % m;

        b >>= 1;
        a = (a * a)%m;
    }

    return r;
}

int main(){

    sieve();

    ll a, b;
    cin >> a >> b;

    ll m = (b%MOD * (binPow(b, a, MOD)-1))%MOD;
    m = (m * binPow(b-1, MOD-2, MOD))%MOD;
    if(b == 1) m = a;

    ll cur = 1, cnt = 1;

    for(ll i=1; i <= a; i++){
        if(cur > b) continue;
        if(prime[i]) cur *= i;
        cnt = (cnt * ((b/cur)%MOD))%MOD;
        m = (m - cnt + MOD)%MOD;
    } 

    cout << m << endl;
}

