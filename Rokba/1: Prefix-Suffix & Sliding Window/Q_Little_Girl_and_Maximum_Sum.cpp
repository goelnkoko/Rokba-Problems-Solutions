#include <bits/stdc++.h> 

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

const int MAX = 1e6+7;
const int MOD = 1e9+7;
const int INF = 1e12;

signed main(){
    Nkumbo

    #ifndef ONLINE_JUDGE
    freopen("dis.in", "r", stdin);
    freopen("dis.out", "w", stdout);
    #endif

    int n, q; cin >> n >> q;

    vi tb(n);
    for(int i=0; i < n; i++) cin >> tb[i];

    vi px(n+1);

    while(q--){
        int l, r; 
        cin >> l >> r;
        l--;
        px[l]++;
        px[r]--;
    }

    for(int i=1; i < n; i++){
        px[i] += px[i-1];
    }
    
    sort(all(tb), greater<int>());
    sort(all(px), greater<int>());

    int sum = 0;
    for(int i=0; i < n; i++){
        sum += (tb[i] * px[i]);
    }

    cout << sum << endl;
}
