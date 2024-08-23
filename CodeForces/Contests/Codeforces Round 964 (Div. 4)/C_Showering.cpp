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

    while(t--){
        ll n, s, m;
        cin >> n >> s >> m;
        
        vector<pair<ll, ll>> a;
        a.push_back({0,0});

        for(ll i=0; i < n; i++){
            ll l, r; 
            cin >> l >> r;

            a.push_back({l, 1});
            a.push_back({r, -1});
        }

        sort(all(a));
        ll c = 0, M = 0;
        for(int i=1; i < a.size(); i++){
            if(a[i].s == 1){
                c = a[i].f - a[i-1].f;
                M = max(M, c);
            }
        }

        if(a[a.size()-1].f != m){
            M = max((m - a[a.size()-1].f), M);
        }

        if(M >= s) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}