#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second 

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = LLONG_MAX;
const ll MAX = 2510;

struct Edge {
    int a, b;
    ll w;
};

vector<Edge> edges;
vector<int> path;

bool bellman_ford(int n){

    vector<ll> dist(MAX, 0);
    vector<int> par(MAX);
    for(int i=1; i <= n; i++) par[i] = i;

    int x;
    for(int i=0; i < n; i++){
        x = -1;

        for(Edge& e: edges){
            if(dist[e.a] < INF)
                if(dist[e.b] > dist[e.a] + e.w){
                    dist[e.b] = max(-INF, dist[e.a] + e.w);
                    x = e.b;
                    par[e.b] = e.a;
                }
        }
    }

    if(x == -1) {
        return false;
    } else {
        int y = x; 
        for(int i=0; i < n; i++)
            y = par[y];

        for(int curr = y; ; curr = par[curr]){
            path.push_back(curr);
            if(curr == y && path.size() > 1) 
                break;
        }   

        reverse(all(path));
    }

    return true;
}

int main(){

    int n, m; 
    int a, b; ll w;
    
    cin >> n >> m;
    for(int i=0; i < m; i++){
        cin >> a >> b >> w;
        edges.push_back(Edge{a, b, w});
    }

    if(bellman_ford(n)){
        cout << "YES" << endl;
        for(auto& i: path) cout << i << ' '; cout << endl;
        return 0;
    }
    else 
        cout << "NO" << endl;
}