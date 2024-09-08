#include <bits/stdc++.h> 

#define all(x) x.begin(), x.end()
#define endl '\n'
#define f first 
#define s second
#define vi vector<ll>
#define pii pair<ll, ll>

typedef long long ll;

const int MAX = 200010;
const int MOD = 1e9+7;

using namespace std;

int par[MAX];
int tam[MAX];
int sum[MAX];

int find(int x){
    return par[x] == x ? x : par[x] = find(par[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(tam[x] > tam[y]){
        par[y] = x;
        tam[x] += tam[y];
        sum[x] += sum[y];
    } else {
        par[x] = y;
        tam[y] += tam[x];
        sum[y] += sum[x];
    }
}

void almost_merge(int x, int y){
    int px = find(x);
    int py = find(y);

    if(px == py) return;

    tam[px]--;
    sum[px] -= x;
   
    par[x] = py;

    tam[py]++;
    sum[py] += x;
}

int main(){

    ll n, m;
    while(cin >> n >> m){

        for(int i=1, j = n + 1; i <= n; i++, j++) {
            tam[j] = 1;
            par[i] = par[j] = j;
            sum[j] = i;
        }

        for(int i=0; i < m; i++){
            int op, a, b;
            cin >> op;

            if(op == 1){
                cin >> a >> b;
                merge(a, b);
            } else if(op == 2){
                cin >> a >> b;
                almost_merge(a, b);
            } else {
                cin >> a;
                a = find(a);
                cout << tam[a] << ' ' << sum[a] << endl;
            }
        }
    }
}