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
 
const int MAX = 5e5+1;
const int MOD = 1e9+7;
const int INF = 1e15;

vi tb(1e5+10), st(MAX);

void build(int v, int tl, int tr){
    if(tl == tr){
        st[v] = tb[tl];
        return;
    }

    int mid = (tl + tr)/2;
    build(2*v, tl, mid);
    build(2*v+1, mid+1, tr);

    st[v] = min(st[2*v], st[2*v+1]);
}

int query(int v, int tl, int tr, int l, int r){
    if(tl > r || tr < l)
        return INF;
    
    if(tl >= l && tr <= r) return st[v];

    int mid = (tl + tr)/2;
    return min(query(2*v, tl, mid, l, r), query(2*v+1, mid+1, tr, l, r));

}

signed main(){
    
    int n, q, l, r; 
    cin >> n;
    for(int i=1; i <= n; i++) cin >> tb[i];

    build(1, 1, n);

    cin >> q;

    while(q--){
        cin >> l >> r;
        cout << query(1, 1, n, l+1, r+1) << endl;
    }

}