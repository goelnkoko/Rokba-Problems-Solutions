#include <bits/stdc++.h> 

#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<ll> 
#define f first 
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll MAX = 10001;
const ll MOD = 1e9+7;

ll par[MAX], tam[MAX];
vector<pair<pii, ll>> tree;

bool comp(const pair<pii, ll>& a, const pair<pii, ll>& b){
    return a.s < b.s;
}

ll find(ll x){
    if(par[x] < 0) return x;

    return par[x] = find(par[x]);
}

void merge(ll x, ll y){

    if(tam[x] < tam[y]){
        par[x] = y;
        tam[x] += tam[y];
    }   
    else { 
        par[y] = x;
        tam[y] += tam[x];
    }
}

int main(){

    ll t;
    cin >> t;

    while(t--){
        ll n, m, city = 0;
        string s; 
        cin >> n;

        unordered_map<string, ll> mp;
        tree.clear();
        memset(par, -1, sizeof(par));
        memset(tam, 0, sizeof(tam));

        for(ll i=0; i < n; i++){
            cin >> s >> m;

            if(mp[s] == 0) mp[s] = ++city;

            while(m--){
                ll b, w;
                cin >> b >> w;
                tree.push_back({{mp[s], b}, w});
            }
        }

        sort(all(tree), comp);

        ll sum = 0;

        for(ll i=0; i < tree.size(); i++){
            ll x = find(tree[i].f.f);
            ll y = find(tree[i].f.s);

            if(x == y) continue;

            sum += tree[i].s;
            merge(x, y);
        }

        cout << sum << endl;
    }
}