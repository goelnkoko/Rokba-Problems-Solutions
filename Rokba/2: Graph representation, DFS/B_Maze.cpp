#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 501;

vector<pii> moves = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

char adj[MAX][MAX];
vector<vector<int>> v(MAX, vector<int>(MAX));

int n, m, k, dot = 0;

bool isPossible(int x, int y){
    if(x < n && y < m && x >= 0 && y >= 0 && adj[x][y] == '.' && v[x][y] == 0) return true;
    return false;
}

void dfs(int x, int y){

    v[x][y] = 1;

    if(!dot)
        adj[x][y]  = 'X';
    else 
        dot--;

    for(const auto& i: moves){
        int a = x + i.first, b = y + i.second;
        if(isPossible(a, b)){
            dfs(a, b);
        }
    }
}

int main(){

    Nkumbo

    cin >> n >> m >> k;

    int x, y;

    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++){
            cin >> adj[i][j];
            if(adj[i][j] == '.') {
                dot++;
                x = i;
                y = j;
            }
        }

    dot -= k;
    dfs(x, y);

    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cout << adj[i][j];
        }
        cout << endl;
    }
    
}