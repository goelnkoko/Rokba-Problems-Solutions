#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int> 
#define ld long double
#define int long long
#define ff first 
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e6;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;


signed main(){

    Nkumbo

    int t; cin >> t;

    while(t--){
        int n, k; 
        cin >> n >> k;

        vi res;
        int p = k;

        res.push_back(1);
        if(p != 1){
            while(p <= n){
                res.push_back(p);
                p *= k;
            }
        }

        int c = 0;
        int i = res.size() - 1;
        while(n > 0){
            if(n - res[i] >= 0){
                int r = (n / res[i]);
                n -= r * res[i];
                c += r;
            } else {
                i--;
            }
        }

        cout << c << endl;
    }

}