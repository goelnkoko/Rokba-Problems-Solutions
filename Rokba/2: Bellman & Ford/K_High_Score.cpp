#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define ff first
#define ss second
#define vi vector<int>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX = 1e6+10;
const int MOD = 1e9+7;
const ll INF = LLONG_MIN; 

struct Edge {
    int a, b; 
    ll w;
};

vector<Edge> edges;

ll bellman_ford(int n){

    vector<ll> dist(n+1, INF);
    vector<int> p(n+1);
    p[1] = 1;
    dist[1] = 0;

    set<int> x;
    for(int i=0; i < n; i++){
        x.clear();

        for(Edge& e: edges){
            if(dist[e.a] > INF)
                if(dist[e.b] < dist[e.a] + e.w){
                    dist[e.b] = max(INF, dist[e.a] + e.w);
                    p[e.b] = e.a;
                    x.insert(e.b);
                }
        }
    }

    if(x.empty()) return dist[n];
    else {
        vector<int> cycle(n+1, false);

        while(!x.empty()){
            int y = *x.begin();
            x.erase(y);
            for(int i=0; i < n; i++)
                y = p[y];

            bool f = true;
            for(int curr = y; ; curr = p[curr]){
                if(x.find(curr) != x.end())
                    x.erase(curr);

                cycle[curr] = true;
                if(curr == 1 || curr == n) return -1;
                if(curr == y && !f) break;
                if(f) f = false;
            }
        }

        vector<bool> n_path(n+1, false);
        bool ans = false;
        for(int v=n, i = 0; i < n ; v = p[v], i++){
            n_path[v] = true;
            if(v == 1) {ans = true; break;}
        }

        if(!ans) return -1;

        for(Edge& e: edges){
            if(cycle[e.a] && n_path[e.b]) return -1;
        }

        return dist[n];
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i=0; i < m; i++){
        ll a, b, w;
        cin >> a >> b >> w;
        edges.push_back(Edge{a, b, w});
    }

    cout << bellman_ford(n) << endl;
}



