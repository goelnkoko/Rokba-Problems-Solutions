#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define endl '\n'
#define f first
#define s second
#define vi vector<ll> 

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll MAX = 100010;
const ll MOD = 1e9+7;
const ll INF = LLONG_MAX;

vector<pii> adj[MAX];

ll min_cost, min_flight, max_flight, num_paths;
vector<vi> w_mat(MAX, vi(MAX, INF));

void dijkstra(int n){

    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;
    min_cost = min_flight = max_flight = num_paths = INF;

    pq.push({0, {1, 0}});
    w_mat[1][1] = 0;

    while(!pq.empty()){

        auto [w, node] = pq.top();
        auto [u, dist] = node; 
        pq.pop();

        if(u == n) {
            if(min_cost > w){
                min_cost = w;
                min_flight = dist;
                max_flight = dist;
                num_paths = 1;
            } else if(min_cost == w){
                min_flight = min(min_flight, dist);
                max_flight = max(max_flight, dist);
                num_paths++;
            } 
            else {
                continue;
            }
        }

        for(auto [v, p]: adj[u]){
            ll cost = (w%MOD + p%MOD)%MOD;
            if(cost <= w_mat[u][v] && cost <= min_cost){
                w_mat[u][v] = cost;
                pq.push({cost, {v, dist + 1}});
            }
        }
    }
}

int main(){

    int n, m; 
    cin >> n >> m;

    while(m--){
        ll a, b, w;
        cin >> a >> b >> w;
        
        adj[a].push_back({b, w});
    }

    dijkstra(n);

    cout << min_cost << ' ' << num_paths << ' ' << min_flight << ' ' << max_flight << endl;
}

