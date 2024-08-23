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

    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    ll m = 0; 
    ll c = 1;
    for(int i=1; i < n; i++){
        if(a[i] > a[i-1]){
            c++;
        } else if(c > m) {
            m = c; 
            c = 1;
        } else {
            c = 1;
        }
    }

    cout << max(m, c) << endl;
}

int main() {


    int t=1; 
    // cin >> t; 

    while(t--) {
        solve();
    }

    return 0;
}