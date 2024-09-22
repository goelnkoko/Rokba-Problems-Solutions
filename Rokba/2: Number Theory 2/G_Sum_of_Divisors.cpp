#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;

int main(){

    ll n; cin >> n;

    ll sum = 0, l = n, k = 1;

    for( ; k * k <= n; k++){

        ll d = n/k; 

        sum += (d % MOD * k % MOD) %MOD;

        ll s = ((d + l +1) % MOD * ((l - d) % MOD)) % MOD;
        s = (s * (MOD + 1)/2) % MOD;

        sum += (s % MOD * (k-1) % MOD) % MOD;

        l = d;
    }

    if(l != k-1)
        sum += (l % MOD * (k-1) % MOD)%MOD;

    cout << sum % MOD << endl;
}

