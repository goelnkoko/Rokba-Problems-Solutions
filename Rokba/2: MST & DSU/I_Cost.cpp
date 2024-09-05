#include <bits/stdc++.h> 

#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<ll> 
#define f first 
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll MAX = 100010;
const ll MOD = 1e9;

ll par[MAX], tam[MAX];
pair<pii, ll> edge[MAX];
vi ps(MAX, 0);

bool comp(const pair<pii, ll>& a, const pair<pii, ll>& b){
    return a.s > b.s;
}

ll find(ll x){
    if(par[x] < 0) return x;
    return par[x] = find(par[x]);
}

void merge(ll a, ll b, ll w, ll& sum){

    ll x = find(a);
    ll y = find(b);

    if(x == y) return;

    sum = (sum%MOD +  (ps[w]%MOD * (tam[x]%MOD * tam[y]%MOD)%MOD)%MOD)%MOD;

    if(tam[x] < tam[y]) {
        par[x] = y;
        tam[y] += tam[x];
    } else {
        par[y] = x;
        tam[x] += tam[y];
    }
}

int main(){

    int n, m; 
    cin >> n >> m;

    memset(par, -1, sizeof(par));
    for(int i=0; i <= n; i++) tam[i] = 1;

    ll maj = 0;
    for(int i=0; i < m; i++){
        cin >> edge[i].f.f >> edge[i].f.s >> edge[i].s;
        ps[edge[i].s] = edge[i].s;
        maj = max(maj, edge[i].s);
    }

    sort(edge, edge + m, comp);
    for(int i=1; i <= maj; i++)
        ps[i] += ps[i-1];

    ll sum = 0;
    for(int i=0; i < m; i++)
        merge(edge[i].f.f, edge[i].f.s, edge[i].s, sum);

    cout << sum << endl;
}