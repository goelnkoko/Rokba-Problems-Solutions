#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl '\n'
#define vi vector<ll>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX = 501;
const ll INF = 1e15;

struct Edge {
    int a, b;
    ll w;
};

vector<Edge> edges;

vector<vector<ll>> dist(MAX, vector<ll>(MAX, INF));

void floyed_warshall(int n){

    for(int i=1; i <= n; i++) dist[i][i] = 0;

    for(Edge& e: edges){
        dist[e.a][e.b] = min(e.w, dist[e.a][e.b]); 
        dist[e.b][e.a] = min(e.w, dist[e.b][e.a]);
    }

    for(int k=1; k <= n; ++k){
        for(int i=1; i <= n; ++i){
            for(int j=1; j <= n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }


}

int main(){

    int n, m, q;
    cin >> n >> m >> q;

    for(int i=0; i < m; i++){
        int a, b; ll w;
        cin >> a >> b >> w;

        edges.push_back(Edge{a, b, w});
    }

    floyed_warshall(n);

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << endl;
    }

}