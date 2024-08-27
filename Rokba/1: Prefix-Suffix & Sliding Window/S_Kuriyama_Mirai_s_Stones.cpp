#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<ll> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll MAX = 100010;
const ll MOD = 1e9+7;

int main() {

    int n; 
    cin >> n;

    ll ps[2][n];
    for(int i=0; i < n; i++) cin >> ps[0][i], ps[1][i] = ps[0][i];
    sort(ps[1], ps[1] + n);

    for(int i=1; i < n; i++){
        ps[0][i] += ps[0][i-1];
        ps[1][i] += ps[1][i-1];
    }

    int q, op, l, r;
    cin >> q;

    while(q--){
        cin >> op >> l >> r;
        op--, l--, r--;

        ll resp = l == 0 ? ps[op][r] : ps[op][r] - ps[op][l-1];
        cout << resp << endl;
    }
    

    return 0;
}