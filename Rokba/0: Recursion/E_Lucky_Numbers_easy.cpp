#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll MAX = 5e9;

inline bool is_super(ll l){
    int c = !l;
    while(l > 0){
        c += l%10 == 4 ? 1:-1;
        l /=10;
    }
    return !c;
}

inline ll lsl(ll n, ll l){
    if(is_super(l) && l >= n) return l;
    if(l >= MAX) return MAX;

    return min(lsl(n, l*10+4), lsl(n, l*10+7));
}

int main() {

    ll n;
    cin >> n;

    cout << lsl(n, 0) << endl;

    return 0;
}