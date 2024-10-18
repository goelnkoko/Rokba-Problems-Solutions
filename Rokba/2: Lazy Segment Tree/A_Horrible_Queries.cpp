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
 
const int MAX = 5e5+1;
const int MOD = 1e9+7;
const int INF = -1e15;

vi st, lazy;

int query(int v, int tl, int tr, int l, int r){
    
    if(lazy[v] != 0){
        int dx = lazy[v];
        lazy[v] = 0;
        st[v] += dx * (tr - tl + 1);

        if(tl != tr) 
            lazy[2*v] += dx, lazy[2*v+1] += dx;
    }

    if(tl > r || tr < l) return 0;

    if(tl >= l && tr <= r) return st[v];

    int mid = (tl + tr) / 2;
    return query(2*v, tl, mid, l, r) + query(2*v+1, mid+1, tr, l, r);
}

void update(int v, int tl, int tr, int l, int r, int val){
    if(lazy[v] != 0){
        int dx = lazy[v];
        lazy[v] = 0;
        st[v] += dx * (tr - tl + 1);

        if(tl != tr)
            lazy[2*v] += dx, lazy[2*v+1] += dx;
    }

    if(tl > r || tr < l) return;

    if(tl >= l && tr <= r){
        int dx = (tr - tl + 1) * val;
        st[v] += dx;

        if(tl != tr)
            lazy[2*v] += val, lazy[2*v+1] += val;
        return;
    }

    int mid = (tl + tr) / 2;
    update(2*v, tl, mid, l, r, val);
    update(2*v+1, mid+1, tr, l, r, val);
    st[v] = st[2*v] + st[2*v+1];
}


signed main(){

    Nkumbo

    #ifndef ONLINE_JUDGE
	freopen("ped.in","r",stdin);
	freopen("ped.out","w",stdout);
	#endif

    int t; cin >> t;

    while(t--){
        int n, c; cin >> n >> c;

        st.assign(4*(n+1), 0);
        lazy.assign(4*(n+1), 0);

        while(c--){
            int op; cin >> op;
            if(op){
                int l, r; cin >> l >> r;
                cout << query(1, 1, n, l, r) << endl;
            } else {
                int l, r, v; cin >> l >> r >> v;
                update(1, 1, n, l, r, v);
            }
        }

        st.clear();
        lazy.clear();

    }
}