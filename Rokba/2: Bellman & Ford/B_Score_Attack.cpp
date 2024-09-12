#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define endl '\n'

using namespace std;

typedef long long ll;

const ll INF = LLONG_MIN;

struct Edge{
    int a, b;
    ll w;
};

vector<Edge> edges;

ll bellman_ford(int n){

    vector<ll> d(n+1, INF);
    vector<int> par(n+1);

    d[1] = 0;
    par[1] = 1;

    set<int> x;
    for(int i=0; i < n; i++){
        x.clear();
        for(Edge& e: edges)
            if(d[e.a] > INF)
                if(d[e.b] < d[e.a] + e.w){
                    d[e.b] = max(d[e.b], d[e.a] + e.w);
                    x.insert(e.b);
                    par[e.b] = e.a;
                }
    }

    if(x.empty())
        return d[n];
    else {
        vector<bool> cycle(n+1, false);
        while(!x.empty()){
            int y = *x.begin();
            x.erase(y);

            for(int i=0; i < n; i++)
                y = par[y];
            
            for(int curr = y, c = 1; ; curr = par[curr], c++){
                if(x.find(curr) != x.end()) x.erase(curr);
                cycle[curr] = true;
                if(curr == 1 || curr == n) return -1;
                if(curr == y && c > 1) break;
            }
        }

        vector<bool> path(n+1, false);
        for(int p = n, i=0; i < n; p = par[p], i++){
            path[p] = true;
            if(p == 1) break;
        }

        for(Edge& e: edges)
            if(cycle[e.a] && path[e.b]) return -1;
    }
    return d[n];
}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i=0; i < m; i++){
        int a, b; ll w;
        cin >> a >> b >> w;
        edges.push_back(Edge{a, b, w});
    }

    ll ans = bellman_ford(n);

    if(ans == -1) cout << "inf" << endl;
    else cout << ans << endl;

}