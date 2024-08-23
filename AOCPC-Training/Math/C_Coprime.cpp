#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 200001
#define MOD 100000000
#define ll long long
#define llmp map<ll, ll> mp
#define vi vector<int>
#define vll vector<ll> 
#define vpll vector<pair<ll, ll>>

using namespace std;

void solve() {

    ll n; 
    cin >> n;

    vi a(n);

    ll ans = -1;

    llmp;

    for(int i=0; i < n; i++){
        cin >> a[i];

        if(mp[a[i]] < i)
            mp[a[i]] = i;
    }

    vpll v;
    for(auto m: mp) 
        v.push_back(m);

    for(int i=0; i < v.size(); i++){
        for(int j=i; j < v.size(); j++){
            if(__gcd(v[i].first, v[j].first) == 1){
                ans = max(ans, v[i].second + v[j].second + 2);
            }
        }
    }    

    cout << ans << endl;
}

int main() {

    Nkumbo

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; 
    cin >> t; 

    while(t--) {
        solve();
    }

    return 0;
}