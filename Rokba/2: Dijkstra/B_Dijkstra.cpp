#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define endl '\n'
#define f first
#define s second
#define vi vector<ll> 

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int MAX = 100010;
const int MOD = 1e9+7;
const ll INF = LLONG_MAX;

vector<pii> adj[MAX];
vi par(MAX);
vi res;

bool dikstra(ll n){

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dist(n+1, INF);

    pq.push({0, 1});
    dist[1] = 0;
    par[1] = 1LL;

    while(!pq.empty()){

        auto [w, u] = pq.top();
        pq.pop();

        if(w > dist[u]) continue;

        for(auto [v, p] : adj[u]){
            if(w + p < dist[v]){
                dist[v] = w + p;
                pq.push({dist[v], v});
                par[v] = u;
            }
        }
    }

    return dist[n] == INF;
}

ll find(ll n){
    res.push_back(n);
    if(par[n] == n) return n;
    return find(par[n]);
}

int main(){

    int n, m; 
    cin >> n >> m;

    while(m--){
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    if(dikstra(n)) cout << -1 << endl;
    else {
        find(n);
        for(int i=res.size()-1; i >= 0; i--)
            cout << res[i] << ' '; cout << endl;
    }
}

