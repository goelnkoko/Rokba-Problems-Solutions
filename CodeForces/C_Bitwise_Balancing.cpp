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
        ll b, c, d; 
        cin >> b >> c >> d;

        ll tg = d + c - b;

        ll a = b ^ tg;

        if (((a | b) - (a & c)) == d) {
            cout << a << endl;
        } else {
            cout << -1 << endl;
        }
    }

}