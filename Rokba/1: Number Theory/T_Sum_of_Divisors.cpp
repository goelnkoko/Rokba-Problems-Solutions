#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define ll long long
#define vll vector<ll> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

const int MOD = 1000000007;

int main() {
	
	ll n;
	cin >> n;

    ll sum = 0, last = n, d, i;  

    for(i=1; i * i <= n; i++){

        d = n / i;

        sum += (d % MOD * i % MOD)%MOD;

        ll s = ((d + last + 1) % MOD * ((last - d) % MOD))%MOD;

        s = (s * ((MOD + 1)/2))%MOD;
        
        sum += (s % MOD * (i-1) % MOD) % MOD;

        last = d;
    }

    if(d != i-1) sum += (d % MOD * (i-1) % MOD)%MOD;

    cout << sum%MOD << endl;
	
	return 0;
}