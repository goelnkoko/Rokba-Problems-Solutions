#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define f first 
#define s second
#define endl '\n'
#define vi vector<int>

using namespace std;

typedef long long ll;

const int MAX = 200010;
const int MOD = 1e9+7;
const int INF = INT_MAX;

int par[MAX], tam[MAX];

int find(int x){
    return par[x] < 0 ? x : par[x] = find(par[x]);
}

void merge(int x, int y){
    par[x] = min(par[x], par[y]);
    par[y] = x;
    tam[x] += tam[y];
}

int main(){

    for(int i=0; i < MAX; i++){
        tam[i] = 1;
        par[i] = -i;
    }

    int n, m, c = 0;
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a >> b;

        a = find(a);
        b = find(b);

        if(a == b) continue;

        merge(min(a, b), max(a, b));
    }   

    int a, b; a = b = 0;

    for(int i=1; i <= n; i++){
        if(par[i] < 0 && tam[i] > 1){
            if(a == 0) {
                a = i; 
                b = abs(par[i]);
            } else if(a < i && i < b) {
                merge(a, i);
                c++;
                b = abs(par[a]);
            }
        } 

        if(i == b) {
            int t = b - a + 1;
            c += t - tam[a];
            a = 0;

        }
    }

    cout << c << endl;
}

