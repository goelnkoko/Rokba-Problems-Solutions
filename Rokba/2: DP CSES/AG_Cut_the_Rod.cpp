#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e6+7;
const int MOD = 1e9+7;

signed main(){

    int t;
    cin >> t;

    while(t--){
        int n; cin >> n; 
        n-=2;
        cout << (2 << n) << endl;
    }
}
