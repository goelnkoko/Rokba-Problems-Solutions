#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define llmp map<ll, ll> mp
#define vi vector<int>
#define endl '\n'
#define f first 
#define s second

using namespace std;

ll calc(ll v, ll n, ll k){
    ll i = 0;
    while(n > 0){
        ll d = pow(k, i);
        ll res = v/d;
        if(res == 0) break; 
        n -= res;
        i++;
    }

    if(n > 0) return -1;
    else return i-1;
}

int main() {

    Nkumbo

    int n, k;
    cin >> n >> k;

    ll l = 0, r = 1e9, ans = 0;

    while(l < r){
        ll mid = (l+r)/2;

        if(calc(mid, n, k) >= 0){
            r = mid;
            ans = mid;
        } else {
            l = mid+1;
        }
    }

    cout << ans << endl;

    return 0;
}

