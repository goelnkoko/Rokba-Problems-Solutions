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

vector<pii> graph[MAX];
vi dist(MAX, INF);

void dikstra(){

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()){

        pii no = pq.top();
        pq.pop();

        if(no.f > dist[no.s]) continue;

        for(pii i: graph[no.s]){
            if(no.f + i.s < dist[i.f]){
                dist[i.f] = no.f + i.s;
                pq.push({dist[i.f], i.f});
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
        
        graph[a].push_back({b, w});
    }

    dikstra();

    for(int i=1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << endl;
}

