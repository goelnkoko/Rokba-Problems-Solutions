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

    int n, k; 
    cin >> n >> k;

    vector<pair<ll, ll>> op;
    vector<ll> ps(n+5, 0);

    for(int i=0; i < n; i++){
        int a, b;
        cin >> a >> b;

        op.push_back({a, b});
    }

    sort(all(op));

    ps[0] = op[0].s;
    for(int i=1; i < n; i++){
        ps[i] = ps[i-1] + op[i].s;
    }

    ll l = 0, r = 0, m = 0;
    while(r < n){
        if(op[r].f - op[l].f < k && r < n){
            r++;
        } else {
            if(l == 0)
                m = max(ps[r-1], m);
            else 
                m = max(ps[r-1]-ps[l-1], m);
            l++;
            if(l > r) r = l;
        }
    }

    if(l == 0)
        m = max(ps[r-1], m);
    else 
        m = max(ps[r-1]-ps[l-1], m);

    cout << m << endl;

    return 0;
}

