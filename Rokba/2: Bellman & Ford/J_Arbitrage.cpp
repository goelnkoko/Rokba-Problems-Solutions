#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl '\n'
#define vi vector<ll>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;

struct Edge {
    int a, b;
    double w;
};

const ld INF = 2e9;

vector<Edge> edges;

//Solution with floyed_warshall
bool floyed_warshall(int n){

    vector<vector<ld>> dist(n+1, vector<ld>(n+1, 0));

    for(Edge& e: edges)
        dist[e.a][e.b] = e.w;

    for(int k=1; k <= n; k++)
        for(int i=1; i <= n; i++)
            for(int j=1; j <= n; j++)
                dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);

    for(int i=0; i <= n; i++)
        if(dist[i][i] > 1.0)
            return true;
    return false;
}

//Solution with Bellman_Ford
bool bellman_ford(int n){
    
    for(int k = 1; k <= n; k++){

        vector<ld> dist(n+1, 0);
        dist[k] = 1.0;

        for(int i=0; i < n; i++){
            for(Edge& e: edges){
                if(dist[e.a] != 0)
                    dist[e.b] = max(dist[e.b], dist[e.a] * e.w);
            }
        }

        if(dist[k] > 1.0) return true;
    }

    return false;
}

int main(){

    Nkumbo

    int n, m; string c, s, t; ld f;
    int cont = 1;

    while(cin >> n && n != 0){

        edges.clear();
        
        int curr = 0;
        map<string, int> mp;

        for(int i=0; i < n; i++){
            cin >> c;
            mp[c] = ++curr;
        }

        cin >> m;

        for(int i=0; i < m; i++){
            cin >> s >> f >> t;
            edges.push_back(Edge{mp[s], mp[t], f});
        }

        // bool ans = floyed_warshall(n, dist);
        bool ans = bellman_ford(n);

        cout << "Case " << cont++ << ": " << (ans ? "Yes":"No") << endl;
    }
}