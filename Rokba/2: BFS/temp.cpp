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
const int INF = INT_MAX;

int n, m;

vector<pii> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char adj[MAX][MAX];
int v[MAX][MAX];
char path[MAX][MAX];

void init(){
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            v[i][j] = 0;
}

struct Direction {
    pii dir;
    char move;
};

Direction dir[] = {
    {{-1, 0}, 'U'}, 
    {{1, 0}, 'D'},  
    {{0, 1}, 'R'},  
    {{0, -1}, 'L'}  
};

bool isPossible(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && (adj[x][y] == '.' || adj[x][y] == 'A' || adj[x][y] == 'M') && v[x][y] == 0;
}

bool bfs(int x, int y){

    queue<pii> q;
    q.push({x, y});
    v[x][y] = 1;
    
    int M = INF;
    int l = INF-10;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();    

        if(M <= l) return true;

        for(auto i: dir){
            int a = x + i.f, b = y + i.s;
            if(!isPossible(a, b)) continue;

            v[a][b] = v[x][y] + 1;
            q.push({a, b});

            if(adj[a][b] == 'M') M = v[a][b];
            if(adj[a][b] == 'A') {
                l = v[a][b];
            }
        }
    }    
    return false;
}

int main(){

    Nkumbo

    int x, y;
    vector<pii> root;

    cin >> n >> m;

    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++){
            cin >> adj[i][j];
            if(adj[i][j] == '.' && (i==0 || i == n-1 || j == 0 || j == m-1))
                root.push_back({i, j});
            if(adj[i][j] == 'A')
                x = i, y = j;
        }
    
    string path;
    for(auto& i: root){
        init();
        bool r = bfs(i.f, i.s);
        if(r){
            cout << "YES" << endl;
            cout << v[x][y] << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
