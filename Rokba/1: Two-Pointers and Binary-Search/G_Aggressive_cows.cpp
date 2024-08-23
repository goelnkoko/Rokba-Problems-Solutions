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

ll teste(vector<ll>& a, ll x){
    
    ll c = 0, v = a[0];
    auto it = a.begin();

    while(it != a.end()){
        c++;
        it = lower_bound(all(a), v+x);
        v = *it;
    }

    return c;
}

void solve(){
    int n, c;
    cin >> n >> c;

    vector<ll> a(n);
    ll l = 0, r = 0, m = 0;

    for(int i=0; i < n; i++){
        cin >> a[i];
        r = max(a[i], r);
    }

    sort(all(a));
    ll ans = 0;

    while(l < r){
        ll mid = (l+r)/2;
        ll vacas = teste(a, mid);

        if(vacas >= c){
            l = mid+1;
            ans = mid;
        } else {
            r = mid;
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

