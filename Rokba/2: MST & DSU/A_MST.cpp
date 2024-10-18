#include <bits/stdc++.h> 

#define endl '\n'
#define vi vector<int> 
#define f first 
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100001;
const int MOD = 1e9+7;

int par[MAX], tam[MAX];
pair<pii, int> tree[MAX];

bool comp(const pair<pii, int>& a, const pair<pii, int>& b){
    return a.s < b.s;
}

int find(int x){
    if(par[x] < 0) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y){

    if(tam[x] < tam[y]){
        par[x] = y;
        tam[x] += tam[y];
    }   
    else { 
        par[y] = x;
        tam[y] += tam[x];
    }
}

int main(){

    int n, m; 
    cin >> n >> m;

    memset(par, -1, sizeof(par));
    memset(tam, 0, sizeof(tam));

    for(int i=0; i < m; i++){
        cin >> tree[i].f.f >> tree[i].f.s >> tree[i].s;
    }

    sort(tree, tree + m, comp);

    ll sum = 0;

    for(int i=0; i < m; i++){
        int x = find(tree[i].f.f);
        int y = find(tree[i].f.s);

        if(x == y) continue;

        sum += tree[i].s;
        merge(x, y);
    }

    cout << sum << endl;
}