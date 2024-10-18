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

    int q; cin >> q;

    while(q--){
        int n, k; cin >> n >> k;

        vi pos(k);
        vi ar(n);
        
        for(int i=0; i < k; i++) 
            cin >> pos[i];
        
        for(int i=0; i < k; i++){
            int a; cin >> a;
            ar[pos[i]-1] = a;
        }

        vi px(n, INF);

        int atual = INF;
        for(int i=0; i < n; i++){
            if(ar[i] != 0){
                atual = min(atual, ar[i]);
            }
            px[i] = min(px[i], atual++);
        }

        atual = INF;
        for(int i=n-1; i >= 0; i--){
            if(ar[i] != 0){
                atual = min(atual, ar[i]);
            }
            px[i] = min(px[i], atual++);
        }

        for(auto& i: px) cout << i << ' ';
        cout << endl;
    }
}
