#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
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
 
const int MAX = 1e4+7;
const int MOD = 1e9+7;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

signed main(){

    #ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	#endif
    
    int n, m, k; cin >> n >> m >> k;
    
    vector<pair<pii, int>> op; 

    vi tb(n);
    for(int i=0; i < n; i++){
        cin >> tb[i];
    }

    for(int i=0; i < m; i++){
        int a, b, c; 
        cin >> a >> b >> c;
        op.push_back({{a-1, b-1}, c});
    }

    FenwickTree ft(m+1);

    while(k--){
        int a, b; cin >> a >> b;
        ft.add(a-1, 1);
        ft.add(b, -1);
    }

    FenwickTree ps(n+1);
    for(int i=0; i < m; i++){
        int t = ft.sum(i);
        int val = t * op[i].ss;
        ps.add(op[i].ff.ff, val);
        ps.add(op[i].ff.ss +1, -val);
    }

    for(int i=0; i < n; i++)
        cout << ps.sum(i) + tb[i] << ' ';
    cout << endl;
}