#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mk make_pair 
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first 
#define ss second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 501;
const int MOD = 1e9+7;
const int INF = INT_MAX;

signed main(){

    Nkumbo
    
    int t; cin >> t;
    while(t--){

        int n; cin >> n;

        vi tb(n);
        
        for(auto& i: tb) cin >> i;
        
        sort(all(tb));

        int c = 0, gr = 0;
        for(int i=0; i < n; i++){
            if(c == 0){
                c = tb[i];
                gr++;
            }
            c--;
        }

        cout << gr << endl;
    }
}