#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
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

    vi a(n);
    for(auto& i: a) cin >> i;
    map<int, int> mp;

    int l = 1, r = 1, m = 0; 
    while(r <= n){
        
        if(mp[a[r-1]] != 0)
            l = max(l, mp[a[r-1]] + 1);

        m = max(m, r - l + 1);
        mp[a[r-1]] = r;
        r++;
    }

    cout << m << endl;

    return 0;
}