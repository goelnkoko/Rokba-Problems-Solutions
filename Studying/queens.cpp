#include <bits/stdc++.h> 

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define ff first 
#define ss second
#define vi vector<int> 
#define vvi vector<vector<int>>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAX = 1e7;
const int MOD = 1e9+7;
const int INF = 1e18;

int n, m, cont = 0; 

vi col, diag1, diag2;

void search(int y){
    if(y == n){
        cont++;
        return;
    }

    for(int x = 0; x < m; x++){
        if(col[x] || diag1[x+y] || diag2[n-1+x-y]) continue;

        col[x] = diag1[x+y] = diag2[n-1+x-y] = true;
        search(y+1);
        col[x] = diag1[x+y] = diag2[n-1+x-y] = false;
    }
}

signed main(){
	Nkumbo

    #ifndef ONLINE_JUDGE
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
    #endif

    cin >> n >> m;
    col.assign(m, false);
    diag1.assign(n+m, false);
    diag2.assign(n+m, false);

    search(0);

    cout << cont << endl;
}
