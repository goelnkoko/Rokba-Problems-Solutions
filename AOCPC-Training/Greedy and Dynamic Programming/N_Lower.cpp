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

    int n;
    cin >> n;

    vi h(n);
    int c = 0, m = 0;
    for(int i=0; i < n; i++){
        cin >> h[i];
    }

    for(int i=1; i < n; i++){
        if(h[i] <= h[i-1]) {
            c++;
        } else if(c > m) {
            m = c;
            c = 0;
        } else {
            c = 0;
        }
    }

    cout << max(c, m) << endl;
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