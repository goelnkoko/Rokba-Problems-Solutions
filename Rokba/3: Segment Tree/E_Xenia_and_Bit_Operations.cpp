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

vi tb;
vi st;

void build(int v, int tl, int tr, bool ver){
    if(tl == tr){
        st[v] = tb[tl];
        return;
    }

    int mid = (tl + tr)/2;
    build(2*v, tl, mid, !ver);
    build(2*v+1, mid+1, tr, !ver);

    if(ver == 1)
        st[v] = (st[2*v] | st[2*v+1]);
    else 
        st[v] = (st[2*v] ^ st[2*v+1]);
}

int query(int v, int tl, int tr, int l, int r, bool ver){
    if(tl > r || tr < l)
        return 0;
    
    if(tl >= l && tr <= r) return st[v];

    int mid = (tl + tr)/2;
    
    if(ver == 1)
        return query(2*v, tl, mid, l, r, !ver) | query(2*v+1, mid+1, tr, l, r, !ver);
    else 
        return query(2*v, tl, mid, l, r, !ver) ^ query(2*v+1, mid+1, tr, l, r, !ver);
}

void update(int v, int tl, int tr, int pos, int val, bool ver){
    if(tl == tr){
        st[v] = tb[pos] = val;
        return;
    }

    int mid = (tl + tr)/2;
    if(pos <= mid) update(2*v, tl, mid, pos, val, !ver);
    else update(2*v+1, mid+1, tr, pos, val, !ver);

    if(ver == 1)
        st[v] = (st[2*v] | st[2*v+1]);
    else 
        st[v] = (st[2*v] ^ st[2*v+1]);
}

signed main(){

    Nkumbo

    #ifndef ONLINE_JUDGE
	freopen("ped.in","r",stdin);
	freopen("ped.out","w",stdout);
	#endif

    
    int n, q; 
    cin >> n >> q;

    bool ver = n%2;;

    n = (1 << n);
    tb.resize(n+1);
    st.resize(4*n + 1);

    for(int i=1; i <= n; i++)
        cin >> tb[i];
    
    build(1, 1, n, ver);
    
    while(q--){
        int pos, x; cin >> pos >> x;
        tb[pos] = x;
        update(1, 1, n, pos, x, ver);
        cout << query(1, 1, n, 1, n, ver) << endl;
    }
}