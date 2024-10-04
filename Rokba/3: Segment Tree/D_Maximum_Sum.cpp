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
vector<pii> st;

void build(int v, int tl, int tr){
    if(tl == tr){
        st[v] = {tb[tl], tl};
        return;
    }

    int mid = (tl + tr)/2;
    build(2*v, tl, mid);
    build(2*v+1, mid+1, tr);

    st[v] = max(st[2*v], st[2*v+1]);
}

pii query(int v, int tl, int tr, int l, int r){
    if(tl > r || tr < l)
        return {INF, -1};
    
    if(tl >= l && tr <= r) return {st[v].ff, st[v].ss};

    int mid = (tl + tr)/2;
    return max(query(2*v, tl, mid, l, r), query(2*v+1, mid+1, tr, l, r));
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        tb[pos] = val;
        st[v] = {val, pos};
        return;
    }

    int mid = (tl + tr)/2;
    if(pos <= mid) update(2*v, tl, mid, pos, val);
    else update(2*v+1, mid+1, tr, pos, val);

    st[v] = max(st[2*v], st[2*v+1]);
}

signed main(){

    Nkumbo

    #ifndef ONLINE_JUDGE
	freopen("ped.in","r",stdin);
	freopen("ped.out","w",stdout);
	#endif

    
    int n, q; 
    cin >> n;
    tb.resize(n+1);
    st.resize(4*(n+1));

    for(int i=1; i <= n; i++) cin >> tb[i];

    build(1, 1, n);

    cin >> q;

    while(q--){
        char op; 
        cin >> op;
        if(op == 'U'){
            int pos, v; cin >> pos >> v;
            update(1, 1, n, pos, v);
        } else {
            int l, r; cin >> l >> r;
            auto [maior, pos] = query(1, 1, n, l, r);

            int left, right, x; left = right = 0;
            
            if(pos-1 >= l)
                tie(left, x) = query(1, 1, n, l, pos-1);
            
            if(pos+1 <= r)
                tie(right, x) = query(1, 1, n, pos+1, r);

            cout << maior + max(left, right) << endl;
        }
    }

}