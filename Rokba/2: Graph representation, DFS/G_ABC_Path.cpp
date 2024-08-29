#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 53;

vector<pii> moves = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

char adj[MAX][MAX];
int v[MAX][MAX];

int n, m;

bool isPossible(int x, int y){
    if(x < n && y < m && x >= 0 && y >= 0 && v[x][y] == 0) return true;
    return false;
}

int dfs(int x, int y){

    v[x][y] = 1;

    int maior = 1; 

    for(const auto& i: moves){
        int a = x + i.first, b = y + i.second;
        if(isPossible(a, b)){
            if(adj[x][y] + 1 == adj[a][b]){
                maior = max(maior, 1 + dfs(a, b));
            }
        }
    }

    return maior;
}

int main(){

    Nkumbo

    int i = 1; 

    while(cin >> n >> m && n != 0 && m != 0){

        vector<pii> root;

        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                cin >> adj[i][j];

                if(adj[i][j] == 'A')
                    root.push_back({i, j});
            }
        }
        
        int maior = 0;
        for(const auto& i: root){

            for(int i=0; i < n; i++)
                for(int j=0; j < m; j++) v[i][j] = 0;

            maior = max(maior, dfs(i.first, i.second));
        }

        cout << "Case " << i++ << ": " <<  maior << endl;
    }
}