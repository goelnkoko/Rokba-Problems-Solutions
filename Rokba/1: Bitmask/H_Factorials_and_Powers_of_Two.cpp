#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

map<ll, ll> mp; 

const int MAX = 20000;

inline void generateVector(){
    vector<ll> a(15, 1);
    for(ll i=1; i < 15; i++) a[i] = a[i-1]*i;
    vector<ll> fact(a.begin()+3, a.end());

    ll n = 12;
    for(ll i = 1 ; i < (1ll << n); i++){
        ll sum = 0, c = 0;
        for(ll j=0; j < n; j++){
            if(i & (1ll << j)){
                sum += fact[j];
                c++;
            }
        }
        mp[sum] = mp[sum] ? min(mp[sum], c) : c;
    }
}

int main() {

    Nkumbo

    generateVector();

    int t;
    cin >> t;

    map<ll, ll> vp(all(mp));

    while(t--){
        ll n; cin >> n;
        int m = __builtin_popcountll(n);

        for(const auto& v: vp){
            if(v.first > n) break;
            int c = v.second + __builtin_popcountll(n - v.first);
            m = min(c, m);
        }

        cout << m << endl;
    }

    return 0;
}