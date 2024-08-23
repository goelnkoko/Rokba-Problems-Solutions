#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define llmp map<ll, ll> mp
#define vi vector<int>
#define endl '\n'
#define f first 
#define s second

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<ll> a(n);

    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    ll ans = 0;
    ll l = 0, r = n-1, sl = a[0], sr = a[n-1];

    while(l < r){
        if(sl == sr){
            ans = l + 1 + n - r;
        }

        if(sl <= sr){
            l++;
            sl += a[l];
        } else {
            r--;
            sr += a[r];
        }
    }

    cout << ans << endl;
}

int main() {

    Nkumbo

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}

