#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mk make_pair 
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long
#define ff first 
#define ss second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 501;
const int MOD = 1e9+7;
const int INF = INT_MAX;

signed main(){
    
    int t; cin >> t;

    while(t--){
        int n, q;
        cin >> n >> q;

        int tb[n];
        for(int i=0; i < n; i++){
            cin >> tb[i];
        }

        vector<int> ps(n+1, 0);
        ps[0] = n-1;

        for(int i=1; i < n; i++){
            ps[i] = ps[i-1] - (i-1);
            ps[i] += (n-i-1);
        }

        map<int, int> mp;
        for(int i=0; i < n; i++){
            if(i != n-1){
                mp[ps[i]]++;
                mp[ps[i]-i] += tb[i+1] - tb[i] - 1;
            } else { 
                mp[ps[i]] += 1;
            }
        }

        while(q--){
            int k; cin >> k;
            cout << mp[k] << ' ';
        }
        cout << endl;
    }
}