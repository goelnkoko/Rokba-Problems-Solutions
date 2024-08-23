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

    int n;
    cin >> n;

    vi a(n);
    for(auto& i: a) cin >> i;

    for(int i=0; i < (1 << n); i++){
        int sum = 0;
        for(int j=0; j < n; j++){
            sum += (i & (1 << j) ? a[j] : -1*a[j]);
        }
        if(sum % 360 == 0){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}