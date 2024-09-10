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

int n;

ll dijkstra(int ini, int fim, vector<pii>* adj){

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dist(n+1, INF);

    pq.push({0, ini});
    dist[ini] = 0;

    while(!pq.empty()){

        auto [w, u] = pq.top();
        pq.pop();

        if(w > dist[u]) continue;

        for(auto [v, p] : adj[u]){
            if(w + p < dist[v]){
                dist[v] = w + p;
                if(v != fim) pq.push({dist[v], v});
            }
        }
    }

    return dist[fim];
}


int main(){

    int t;
    cin >> t;
    
    for(int i=1; i <= t; i++){

        int m, ini, fim; 
        cin >> n >> m >> ini >> fim;

        vector<pii> adj[n+1];

        while(m--){
            ll a, b, w;
            cin >> a >> b >> w;

            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        ll res = dijkstra(ini, fim, adj);

        cout << "Case #" << i << ": ";
        if (res == INF) cout <<  "unreachable"  << endl;
        else cout << res << endl;
    }
}

