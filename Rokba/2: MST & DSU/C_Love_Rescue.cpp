#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define f first 
#define s second
#define endl '\n'
#define vi vector<int>

using namespace std;

typedef long long ll;

const int MAX = 30;
const int MOD = 1e9+7;
const int INF = INT_MAX;

int par[MAX], tam[MAX];

int find(int x){
    return par[x] == x ? x : par[x] = find(par[x]);
}

void merge(int x, int y){

    if(tam[x] > tam[y]){
        par[y] == x;
        tam[y] += tam[x];
    }
    else {
        par[x] = y;
        tam[x] += tam[y];
    } 
}

int main(){

    for(int i=0; i < MAX; i++){
        tam[i] = 1;
        par[i] = i;
    }

    int n;
    string a, b;
    cin >> n >> a >> b;

    vector<pair<char, char>> res;

    for(int i=0; i < n; i++){
        int x = find(a[i] - 'a' + 1);
        int y = find(b[i] - 'a' + 1);   

        if(x == y) continue;

        res.push_back({a[i], b[i]});
        merge(x, y);
    }

    cout << res.size() << endl;
    for(auto i: res) cout << i.f << ' ' << i.s << endl;
}

