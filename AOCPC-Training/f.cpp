#include <bits/stdc++.h>

#define Pin ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n' 
#define int long long
#define vi vector<int> 

using namespace std;

signed main(){

    Pin

    #ifndef ONLINE_JUDGE
    freopen("racing.in", "r", stdin);
    freopen("racing.out", "w", stdout);
    #endif
    
    #ifdef ONLINE_JUDGE
    freopen("racing.in", "r", stdin);
    #endif


    int t;
    cin>>t;

    while(t--){
        int n, q; cin >> n >> q;
        vi tb(n+1), pos(n+1);

        for(int i=1; i <= n; i++){
            int a; cin >> a; 
            tb[a] = i;
            pos[i] = a;
        }

        while(q--){
            int a; cin >> a;

            int temp = pos[tb[a]-1];
            swap(pos[tb[a]], pos[tb[a]-1]); 
            swap(tb[a], tb[temp]);
        }

        for(int i=1; i <= n; i++)
            cout << pos[i] << ' ';
        cout << endl;
    }
    return 0;
}