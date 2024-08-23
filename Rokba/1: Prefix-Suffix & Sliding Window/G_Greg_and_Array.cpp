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

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);

    for(ll i=0; i < n; i++)
        cin >> a[i];

    vector<ll> ps(n+5, 0);

    vector<pair<pair<ll, ll>, ll>> op;

    for(int i=0; i < m; i++){
        ll l, r, d;
        cin >> l >> r >> d;

        op.push_back({{l, r}, d});
    }

    vector<ll> exec(m+5, 0); 

    while(k--){
        ll x, y;
        cin >> x >> y;

        exec[x-1]++;
        exec[y]--;
    }

    for(int i = 1; i <= m; i++){
        exec[i] += exec[i-1];
    }

    for(int i=0; i < m; i++) {
        ps[op[i].first.first-1] += exec[i]*op[i].second;
        ps[op[i].first.second]-= exec[i]*op[i].second;
    }

    for(ll i=1; i < n; i++){
        ps[i] += ps[i-1];
    }

    for(ll i=0; i < n; i++){
        a[i] += ps[i];
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}