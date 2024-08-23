#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define MAX 1e9
#define MOD 1000000007
#define ll long long

using namespace std;

int main() {

    Nkumbo

    ll n;
    cin >> n;

    ll s1 = 0, s2 = 0;

    for(ll i = 0; i < n; i++){
        ll a; 
        cin >> a; 
        s1 = (s1 + a)%MOD;
        s2 = (s2 + a*a)%MOD;   
    }

    ll res = (s1*s1 - s2)/2;


    s1 = (s1%MOD * s1%MOD)%MOD;

    res = (s1 - s2 + MOD)%MOD;

    res = (res * (MOD + 1)/2) % MOD;
    
    cout << res << endl;
    return 0;
}
