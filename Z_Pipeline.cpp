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

    ll n, k; 
    cin >> n >> k;

    ll l = 0, r = k-1;

    while(l <= r){
        ll mid = l + (r-l)/2;

        ll sum = ((1 + mid)*mid)/2;
        sum += 1;

        if(sum < n){
            l = mid +1;
        } else {
            r = mid -1;
        }
    }
    r++;
    cout << (r ? r : -1) << endl;

    return 0;
}