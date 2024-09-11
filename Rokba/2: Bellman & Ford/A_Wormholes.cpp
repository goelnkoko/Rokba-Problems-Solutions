#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define endl '\n'

using namespace std;

typedef long long ll;

const int MAX = 1001;
const int MOD = 1e9+7;
const ll INF = LLONG_MAX;

struct Edge {
    int a, b;
    ll w;
};

vector<Edge> edges;

bool bellman_ford(int n){

    vector<ll> dist(n+1, INF);
    dist[0] = 0;

    int x;
    for(int i=0; i < n; i++){
        x = -1; 
        for(Edge& e: edges){
            if(dist[e.a] < INF)
                if(dist[e.b] > dist[e.a] + e.w){
                    dist[e.b] = max(-INF, dist[e.a] + e.w);
                    x = e.b;
                }
        }
    }

    return x != -1;
}


int main(){

    int t; 
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        edges.clear();

        for(int i=0; i < m; i++){
            int a, b; ll w;
            cin >> a >> b >> w;
            edges.push_back(Edge{a, b, w});
        }

        cout << (bellman_ford(n) ? "possible":"not possible") << endl;
    }
}