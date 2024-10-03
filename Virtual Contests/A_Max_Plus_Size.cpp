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
        int n; cin >> n;
        int tb[n];
        int maxA = 0, maxB = 0, imp = 0, par = 0;
        for(int i=0; i < n; i++){
            int a; 
            cin >> a;

            if(i % 2){
                imp++;
                maxA = max(maxA, a);
            } else {
                par++;
                maxB = max(maxB, a);
            }
        }

        int res = max(maxA + imp, maxB + par);
        cout << res << endl;
    }
}