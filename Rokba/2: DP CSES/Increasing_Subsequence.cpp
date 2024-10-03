#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int> 
#define ld long double
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e6;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

signed main(){

    int n; cin >> n;
    int tb[n];

    for(int i=0; i < n; i++){
        cin >> tb[i];
    }

    vector<int> lon;
    lon.push_back(tb[0]);

    for(int i=1; i < n; i++){
        auto it = lower_bound(all(lon), tb[i]);
        if(it == lon.end()){
            lon.push_back(tb[i]);
        }
        else {
            int pos = it - lon.begin();
            lon[pos] = tb[i];
        }
    }

    cout << lon.size() << endl;

}