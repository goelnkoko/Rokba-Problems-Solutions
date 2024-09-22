#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 1001;

int main(){

    ll t;
    cin >> t;

    while(t--){
        ll n, m, q;
        cin >> n >> m >> q; 
        vector<ll> pos(m);
        ll mpos = INT_MAX, M = 0;
        for(ll i=0; i < m; i++){
            cin >> pos[i];
            mpos = min(mpos, pos[i]);
            M = max(M, pos[i]);
        }

        sort(all(pos));

        while(q--){
            ll d;
            cin >> d;

            if(d < mpos){
                cout << pos[0]-1 << endl;
            } else if(d > M){
                cout << n - pos[m-1] << endl;
            } else {
                auto it = lower_bound(all(pos), d);
                auto il = it;
                il--;
                ll dist = *it - *il - 1;
                ll res = dist/2 + dist%2; 
                cout << res << endl;
            }
        }
    }
}

