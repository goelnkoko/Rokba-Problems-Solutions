#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 200001
#define MOD 100000000
#define ll long long
#define llmp map<ll, ll> mp
#define vi vector<int>
#define endl '\n'

using namespace std;

int main() {

    Nkumbo

     ll n, m; 
     cin >> n >> m;

    vector<ll> a(n);
    for(int i=0; i < n ; i++){
        cin >> a[i];
    }

    sort(all(a));

    vector<ll> ps(n+5, 0);

    ll s = 0;
    for(int i=0; i < n; i++){
        s += a[i];
        
    }

    if(s <= m) {
        cout << "infinite" << endl;
        return 0;
    }

    ll l = 0, r = 1e15;
    ll ans = 0;
    while(l < r) {
        ll mid = l + (r - l) / 2;

        ll sum = 0;
        for(int i = 0; i < n; i++) {
            sum += min(mid, a[i]);
            if(sum > m) break;
        }

        if(sum <= m) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid;
        }
    }

    cout << ans << endl;

    return 0;
}