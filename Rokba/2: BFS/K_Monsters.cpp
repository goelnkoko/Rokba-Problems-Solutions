#include <bits/stdc++.h> 

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define f first
#define s second

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 1001;

vector<pii> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char adj[MAX][MAX];
int n, m;

bool isPossible(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m && adj[x][y] == '.') return true;
    return false;
}

void bfs(vector<vector<int>>& v){
    
    deque<pii> q;
    q.push_front({0, 0});
    v[0][0] = 0;

    while(!q.empty()){
        pii no = q.front();
        q.pop_front();

        for(auto& i: moves){
            ll a = no.f + i.f, b = no.s + i.s;
            if(isPossible(a, b)){
                ll k = adj[a][b] == adj[no.f][no.s] ? 0:1;
                if(v[no.f][no.s] + k < v[a][b]){
                    v[a][b] = v[no.f][no.s] + k;
                    
                    if(k) q.push_back({a, b});
                    else q.push_front({a, b});
                }
            }
        }
    }
}

int main(){

    Nkumbo

    cin >> n >> m;

    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> adj[i][j];

    for(int i=0; i < n; i++){
        for
    }

}