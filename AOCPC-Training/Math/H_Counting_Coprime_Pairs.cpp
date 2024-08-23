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

    ll ans = 0;

    llmp;

    for(int i=0; i < n; i++){
        int a;
        cin >> a;
        mp[a]++;
    }

    vpll v;
    for(auto m: mp) 
        v.push_back(m);

    int m = v.size();
    for(int i=0; i < m; i++){
        if(v[i].first == 1) {
            cout << v[i].first << " " << n-i-1 << endl;
            ans += n-i-1; continue;
        }

        int c = 0;
        for(int j=v[i].first*2; j < m; j+= v[i].first){
            if(v[i].second != 0) c += v[i].second;
        }

        ans += (n-i-c-1);

        cout << v[i].first << " " << n-i-c-1 << endl;
    }

    cout << ans << endl;
}

int main() {

    Nkumbo

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t=1; 
    // cin >> t; 

    while(t--) {
        solve();
    }

    return 0;
}