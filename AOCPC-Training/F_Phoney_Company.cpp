#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long
#define ff first
#define ss second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 2e5+10;
const int MOD = 1e9+7;
const int INF = -1e15;

vi adj[MAX];
vi _size;
vi tam;

int binPow(int a, int b){
    ll r = 1;
    a %= MOD;

    while(b > 0){
        if(b & 1) r = (a * r) % MOD;

        b >>= 1;
        a = (a * a) % MOD;
    }

    return r;
}

int dfs(int root){

    int total = 0;
    int t = 0; 

    for(int& i: adj[root]){
        t += dfs(i);
    }

    //Calculo das possiveis combinações
    total = (binPow(2, t) - 1 + MOD)%MOD;
    for(int& i: adj[root])
        total = (total - ((binPow(2, tam[i]) - 1 + MOD)%MOD) + MOD)%MOD;

    tam[root] = t;
    _size[root] = total;

    return tam[root] + 1;
}

void init(int n){
    for(int i=1; i <= n; i++)
        adj[i].clear();
}

signed main(){

    Nkumbo

    #ifndef ONLINE_JUDGE
	freopen("ped.in","r",stdin);
	freopen("ped.out","w",stdout);
	#endif

    int t; cin >> t;
    while(t--){
        int n; cin >> n; 

        init(n);
        _size.resize(n+1);
        tam.resize(n+1);

        int root = 0;
        for(int i=1; i <= n; i++){
            int a; cin >> a;

            if(a == 0)
                root = i;
            else 
                adj[a].push_back(i);
        }

        dfs(root);

        for(int i=1; i <= n; i++)
            cout << _size[i] << ' ';
        cout << endl;
    }
    

}