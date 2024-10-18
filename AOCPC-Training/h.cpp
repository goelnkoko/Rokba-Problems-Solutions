#include <bits/stdc++.h>

#define Pin ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n' 
#define int long long
#define vi vector<int>

typedef long long ll;

using namespace std;

signed main(){

    Pin

    #ifndef ONLINE_JUDGE
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    #endif
    
    #ifdef ONLINE_JUDGE
    freopen("subset.in", "r", stdin);
    #endif


    int t;
    cin>>t;
    while(t--){
        int n; cin >> n;
        vi tb(n);
        for(auto& i: tb) cin >> i;

        sort(all(tb));
        
        vi px(n+1, 0);
        px[0] = tb[0];
        for(int i=1; i < n; i++)
            px[i] = px[i-1] + tb[i];

        int c = 0; 
        int res = 0;
        for(int i=n-1; i >= 0; i--){
            for(int j=0; j <= i; j++){
                if(j != 0)
                    res = max(px[i]-px[j-1] - (tb[i]-tb[j]), res);
                else 
                    res = max(px[i] - (tb[i]-tb[j]), res);
            }
            c++;
            if(c >= 1000) break;
        }

        cout << res << endl;
    }

    return 0;
}