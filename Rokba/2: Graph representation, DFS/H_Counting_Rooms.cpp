#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 1000 + 20;

int n, m;


int v[MAX][MAX] = {0};
pii moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isPossible(const vector<string>& a, int x, int y){
    if(!(x >= 0 && y >= 0 && x < n && y < m)) return false;
    if(a[x][y] == '#' || v[x][y] == 1) return false;
    return true;
}

void dfs(vector<string>& lab, int x, int y){
    v[x][y] = 1;

    for(const auto& i: moves){
        if(isPossible(lab, x + i.first, y + i.second)){
            dfs(lab, x + i.first, y + i.second);
        }
    }
}

int main(){

    Nkumbo

    cin >> n >> m;

    vector<string> lab(n);

    for(auto& i: lab) cin >> i;

    int c = 0;

    for(int i=0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(lab[i][j] == '.' && v[i][j] == 0){
                c++;
                dfs(lab, i, j);
            }
        }
    }

    cout << c << endl;
    
}