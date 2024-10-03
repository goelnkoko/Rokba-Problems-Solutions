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
    
    cin >> n >> m;

    vi tb(n);
    for(int i=0; i < n; i++){
        cin >> tb[i];
        add(i, tb[i], tb[i]%m);
    }

    int q; cin >> q;

    while(q--){
        char a; cin >> a;
        if(a == '+'){
            int p, x; cin >> p >> x;
            add(p-1, -tb[p-1], tb[p-1]%m);
            tb[p-1] += x;
            add(p-1, tb[p-1], tb[p-1]%m);
            cout << tb[p-1] << endl;
        } else if(a == '-'){
            int p, x; cin >> p >> x;
            if(tb[p-1] - x >= 0){
                add(p-1, -tb[p-1], tb[p-1]%m);
                tb[p-1] -= x;
                add(p-1, tb[p-1], tb[p-1]%m);
            }
            cout << tb[p-1] << endl;
        } else {
            int l, r, mod; cin >> l >> r >> mod;
            int s = sum(l-1, r-1, mod);
            cout << s << endl;
        }
    }
}