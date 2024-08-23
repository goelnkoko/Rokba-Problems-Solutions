#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

map<ll, ll> mp; 

const int MAX = INT_MAX;

int main() {

    Nkumbo

    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vi a(n);
    for(auto& i: a) cin >> i;

    int c = 0;
    for(int i=1; i < (1 << n); i++){
        int sum = 0, m = MAX, M = 0;
        for(int j=0; j < n; j++){
            if(i & (1 << j)){
                sum += a[j];
                m = min(m, a[j]);
                M = max(M, a[j]);
            }
        }
        int d = M - m;
        if(sum >= l && sum <= r && d >= x && d != 0) c++;
    }

    cout << c << endl;
    return 0;
}