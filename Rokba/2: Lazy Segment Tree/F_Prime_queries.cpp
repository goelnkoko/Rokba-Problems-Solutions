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
 
const int MAX = 1e7+7;
const int MOD = 1e9+7;
const int INF = -1e15;

vector<bool> primes(MAX, true);
vi tb, st, lazy;

void crivo(){
    primes[0] = false; 
    primes[1] = false; 

    for(int i = 2; i * i < MAX; i++){
        if(primes[i]){
            for(int j = i * i; j < MAX; j += i)
                primes[j] = false;
        }
    }
}
void build(int v, int tl, int tr){
    if(tl == tr){
        if(primes[tb[tl]] && tb[tl] <= 1e7)
            st[v] = 1;
        else 
            st[v] = 0;
        return;
    }

    int mid = (tl + tr)/2;
    build(2*v, tl, mid);
    build(2*v+1, mid+1, tr);

    st[v] = st[2*v] + st[2*v+1];
}

int query(int v, int tl, int tr, int l, int r){
    
    if(lazy[v] != 0){
        int dx = lazy[v];
        lazy[v] = 0;
        
        if(primes[dx] && dx <= 1e7)
            st[v] = 1 * (tr - tl + 1);
        else 
            st[v] = 0;

        if(tl != tr) 
            lazy[2*v] = dx, lazy[2*v+1] = dx;
    }

    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r) return st[v];

    int mid = (tl + tr) / 2;
    return query(2*v, tl, mid, l, r) + query(2*v+1, mid+1, tr, l, r);
}

void updateOne(int v, int tl, int tr, int pos, int val){

    if(lazy[v] != 0){
        int dx = lazy[v];
        
        lazy[v] = 0;
        
        if(primes[dx] && dx <= 1e7)
            st[v] = 1 * (tr - tl + 1);
        else 
            st[v] = 0;

        if(tl != tr)
            lazy[2*v] = dx, lazy[2*v+1] = dx;
    }

    if(tl == tr){
        tb[pos] += val;

        int x = tb[pos];
        bool temp = primes[tb[pos]];

        if(primes[tb[pos]] && tb[pos] <= 1e7)
            st[v] = 1;
        else 
            st[v] = 0;

        return;
    }

    int mid = (tl + tr)/2;
    if(pos <= mid) updateOne(2*v, tl, mid, pos, val);
    else updateOne(2*v+1, mid+1, tr, pos, val);

    st[v] = st[2*v] + st[2*v+1];
}

void updateAll(int v, int tl, int tr, int l, int r, int val){
    
    if(lazy[v] != 0){
        int dx = lazy[v];
        
        lazy[v] = 0;
        
        if(primes[dx] && dx <= 1e7)
            st[v] = 1 * (tr - tl + 1);
        else 
            st[v] = 0;

        if(tl != tr)
            lazy[2*v] = dx, lazy[2*v+1] = dx;
    }

    if(tl > r || tr < l) return;

    if(tl >= l && tr <= r){
        tb[tl] = tb[tr] = val;
        int dx = (tr - tl + 1) * val;
        
        if(primes[dx] && dx <= 1e7)
            st[v] = 1;
        else 
            st[v] = 0;

        if(tl != tr)
            lazy[2*v] = dx, lazy[2*v+1] = dx;
        return;
    }

    int mid = (tl + tr) / 2;
    updateAll(2*v, tl, mid, l, r, val);
    updateAll(2*v+1, mid+1, tr, l, r, val);
    st[v] = st[2*v] + st[2*v+1];
}

signed main(){

    Nkumbo

    #ifndef ONLINE_JUDGE
	freopen("ped.in","r",stdin);
	freopen("ped.out","w",stdout);
	#endif

    int n, q; 
    cin >> n >> q;

    tb.resize(n+1);
    st.assign(4*(n+1), 0);
    lazy.assign(4*(n+1), 0);

    crivo();

    for(int i=1; i <= n; i++)
        cin >> tb[i];
    
    build(1, 1, n);
    
    while(q--){
        char op; cin >> op;
        if(op == 'A'){
            int val, pos; cin >> val >> pos;
            updateOne(1, 1, n, pos, val);
        } else if(op == 'R'){
            int val, l, r; cin >> val >> l >> r;
            updateAll(1, 1, n, l, r, val);
        } else {
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}