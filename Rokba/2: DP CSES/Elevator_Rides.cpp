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

    int n, x; cin >> n >> x;
    vi tb(n);
    for(int i=0; i < n; i++)
        cin >> tb[i];


    vector<pii> dp(1<<n, {1e9, 1e9});
    dp[0] = {1, 0};

    wfor(int mask = 0; mask < (1 << n); mask++){

        for(int j=0; j < (1 << n); j++){
            y = 0;
            for(int k=0; k < n; k++){
                if(j & (1 << k)){
                    y += tb[k];
                }
            }

            if(y <= x && y > w){
                w = y;
                curr = j;
            }
        }


        for(int j=n-1; j >= 0; j--){
            if(curr & (1 << j)){
                tb.erase(tb.begin()+j);
            }
        }

        c++;
    }

    cout << c << endl;
}