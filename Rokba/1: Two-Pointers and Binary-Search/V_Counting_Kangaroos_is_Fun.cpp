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

    vi kang(n);
    for(auto& i: kang) cin >> i;

    sort(all(kang));

    int l = 0, r = n/2 + n%2;
    while(r != n){
        if(kang[l]*2 <= kang[r]){
            l++, r++;
        } else {
            r++;
        }
    }

    cout << n - l << endl;

    return 0;
}