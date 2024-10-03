#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long
 
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
    
    int n, m; cin >> n >> m;
    vi tb(n);
    FenwickTree ft(n);

    for(int i=0; i < n; i++)
        cin >> tb[i];

    vector<pii> op;

    for(int i=0; i < m; i++){
        int a, b; cin >> a >> b;
        op.push_back({a, b});
        ft.add(a-1, 1);
        ft.add(b, -1);
    }

    multimap<int, int> mp;
    for(int i=0; i < n; i++){
        mp.insert({ft.sum(i), i});
    }

    sort(all(tb), greater<int>());
    vector<int> fin(n);
    int j = 0;
    for(auto it = mp.rbegin(); it != mp.rend(); ++it, j++){
        fin[it->second] = tb[j]; 
    }   

    vector<int> ps(n+1);
    ps[1] = fin[0];
    for(int i=2; i <= n; i++)
        ps[i] = fin[i-1] + ps[i-1];
    
    int sum = 0;
    for(auto& [l, r]: op){
        sum += (ps[r] - ps[l-1]);
    }   
    cout << sum << endl;

}