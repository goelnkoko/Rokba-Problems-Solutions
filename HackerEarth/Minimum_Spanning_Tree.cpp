#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int> 

using namespace std;

typedef long long ll;

const int MAX = 100001;
const int MOD = 1e9+7;

struct edge {
    int a;
    int b;
    int w;
};

edge tree[MAX];
int par[MAX];

bool comp(const edge& a, const edge& b){
    return a.w < b.w;
}

int find(int x){
    if(par[x] == -1) return x;

    return par[x] = find(par[x]);
}

void merge(int x, int y){
    par[x] = y;
}

int main(){

    int n, m;
    cin >> n >> m;

    for(auto& i: par) i = -1;

    for(int i=0; i < m; i++){
        cin >> tree[i].a >> tree[i].b >> tree[i].w;
    }

    sort(tree, tree + m, comp);

    ll sum = 0;

    for(int i=0; i < m; i++){
        int x = find(tree[i].a);
        int y = find(tree[i].b);

        if(x == y) continue;

        sum += tree[i].w;
        merge(x, y);
    }

    cout << sum << endl;
}