#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define vll vector<ll> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

int main() {
	
	ll n;
	cin >> n;

    vll a(n);

	for (ll i = 0; i < n; ++i) cin >> a[i];

    ll val = a[0];

    for(ll i=1; i < n; i++){
        val = __gcd(val, a[i]);
    } 

    ll c = 0;
    for(ll i=1; i*i <= val; i++){
        if(val % i == 0){
            c++;
            if(val/i != i)
                c++;
        }
    }

    cout << c << endl;
	
	return 0;
}