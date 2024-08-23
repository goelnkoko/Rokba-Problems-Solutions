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

int main() {
    Nkumbo

    int t;
    cin >> t;

    while (t--) {
        ll x, y, k;
        cin >> x >> y >> k;

        vector<pair<ll, ll>> a;
        ll s1 = 0, s2 = 0;

        for (int i = 0; i < k - 1; ++i) {
            ll xi = i * 2000 - 1000000;
            ll yi = i * 2000 - 1000000;
            a.push_back({xi, yi});
            s1 += xi;
            s2 += yi;
        }

        ll lx = x * k - s1;
        ll ly = y * k - s2;
        a.push_back({lx, ly});

        for (auto p : a) {
            cout << p.f << " " << p.s << endl;
        }
    }

    return 0;
}