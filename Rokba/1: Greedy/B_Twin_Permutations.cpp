#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll MAX = 5e9;

int main() {

    ll t;
    cin >> t;

    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(auto& i: a) cin >> i;

        for(int i=0; i < n; i++)
            cout << (n - a[i] + 1) << ' ';
        cout << endl;
    }

    return 0;
}