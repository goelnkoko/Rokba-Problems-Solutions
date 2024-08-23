#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define endl '\n'
#define f first 
#define s second

using namespace std;

ll kill(vector<ll>& a, ll x){
    
    ll sum = 0; 

    for(ll i=0; i < a.size(); i++){
        if(i != a.size()-1)
            sum += min(x, a[i+1] - a[i]);
        else 
            sum += x;
    }

    return sum;
}

int main() {

    Nkumbo

    int t;
    cin >> t;

    while(t--){
        ll n, h, ans = 0; 
        cin >> n >> h;

        vector<ll> a(n);

        for(ll i=0; i < n; i++)
            cin >> a[i];

        ll l = 0, r = 2e18;
        while(l <= r){
            ll mid = l + (r-l)/2;

            ll k = kill(a, mid);

            if(k >= h){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}