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

vector<ll> dijkstra(int source, vector<pii>* adj){

    vi dist(MAX, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, source});
    dist[source] = 0;

    while(!pq.empty()){

        pii no = pq.top();
        pq.pop();

        if(no.f > dist[no.s]) continue;

        for(pii& i: adj[no.s]){

            if(no.f + i.s < dist[i.f]){
                dist[i.f] = no.f + i.s;
                pq.push({dist[i.f], i.f});
            }
        }
    }

    return dist;
}

int main(){

    ll n, m, ans = INF; 
    cin >> n >> m;

    vector<pii> adj[MAX];
    vector<pii> r_adj[MAX];

    while(m--){
        ll a, b, w;
        cin >> a >> b >> w;
        
        adj[a].push_back({b, w});
        r_adj[b].push_back({a, w});
    }

    vi dist1 = dijkstra(1, adj);
    vi dist2 = dijkstra(n, r_adj);
    
    for(int i=1; i <= n; i++){
        for(auto [j, c]: adj[i]){
            if(dist1[i] < INF && dist2[j] < INF){
                ans = min(ans, dist1[i] + c/2 + dist2[j]);
            }
        }
    }

    cout << ans << endl;
}

