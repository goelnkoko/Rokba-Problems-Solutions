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
vector<ll> path[MAX];

void dijkstra(int n, int k){

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});

    while(!pq.empty()){

        auto [val, u] = pq.top();
        pq.pop();

        if(path[u].size() < k) path[u].push_back(val);
        else continue;

        for(auto& [v, w]: adj[u]){

            if(path[v].size() == k) continue;
            
            pq.push({w + val, v});
        }
    }
}

int main(){

    ll n, m, k; 
    cin >> n >> m >> k;

    while(m--){
        ll a, b, w;
        cin >> a >> b >> w;
        
        adj[a].push_back({b, w});
    }

    dijkstra(n, k);

    sort(all(path[n]));

    for(auto i: path[n]) cout << i << ' '; cout << endl;

}

