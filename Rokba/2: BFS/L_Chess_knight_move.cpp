#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()
#define f first 
#define s second

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 8;

int tb[MAX][MAX];

vector<pii> moves = {{-1, 2}, {1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, 1}, {2, -1}};

void init(){
    for(int i=0; i < MAX; i++)
        for(int j=0; j < MAX; j++)
            tb[i][j] = 0;
}

bool isPossible(int a, int b){
    if(a >= 0 && b >= 0 && a < MAX && b < MAX && tb[a][b] == 0) return true;
    return false;
}

int bfs(int x, int y, int d1, int d2){

    queue<pii> q;
    q.push({x, y});
    tb[x][y] = 1;

    while(!q.empty()){

        pii n = q.front();
        q.pop();

        for(auto& i: moves){
            int a = n.f + i.f, b = n.s + i.s;
            if(isPossible(a, b)){
                q.push({a, b});
                tb[a][b] = tb[n.f][n.s] + 1;
                if(a == d1 && b == d2) return tb[a][b] -1;
            }
        }
    }
}

int main(){

    Nkumbo

    int t;
    cin >> t;
    while(t--){
        char a, b;
        int x, y;
        cin >> a >> x >> b >> y;

        init();
        cout << bfs(a - 'a', x - 1, b - 'a', y - 1) << endl;
    }
}