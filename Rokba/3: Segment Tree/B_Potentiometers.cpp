#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 5e5+1;
const int MOD = 1e9+7;
const int INF = 1e15;

vi tb, st;

void build(int v, int tl, int tr){
    if(tl == tr){
        st[v] = tb[tl];
        return;
    } 

    int mid = (tl + tr)/2;
    build(2*v, tl, mid);
    build(2*v+1, mid+1, tr);

    st[v] = st[2*v] + st[2*v+1];
}

int sum(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    
    if(tl == l && tr == r) return st[v];

    int mid = (tl + tr)/2;
    return sum(2*v, tl, mid, l, min(r, mid)) + sum(2*v+1, mid+1, tr, max(l, mid+1), r);
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        st[v] = tb[pos] = val;
        return;
    }

    int mid = (tl + tr)/2;
    if(pos <= mid) update(2*v, tl, mid, pos, val);
    else update(2*v+1, mid+1, tr, pos, val);

    st[v] = st[2*v] + st[2*v+1];
}

signed main(){

    Nkumbo

    #ifndef ONLINE_JUDGE
	freopen("ped.in","r",stdin);
	freopen("ped.out","w",stdout);
	#endif

    int t = 1; 
    int n, q, l, r; 
    bool f = false;

    while(cin >> n && n != 0){
        if(f) cout << endl;
        cout << "Case " << t++ << ":" << endl;

        tb.resize(n+1);
        st.resize(4*(n+1));
        for(int i=1; i <= n; i++)
            cin >> tb[i];

        build(1, 1, n);
         
        string op;
        while(cin >> op && op != "END"){
            if(op == "M"){
                int l, r; 
                cin >> l >> r;
                cout << sum(1, 1, n, l, r) << endl;
            } else {
                int pos, x; cin >> pos >> x;
                update(1, 1, n, pos, x);
            }
        }
        f = true;
    }
}