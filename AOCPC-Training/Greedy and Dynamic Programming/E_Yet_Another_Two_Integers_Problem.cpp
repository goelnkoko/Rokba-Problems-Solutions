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

    int a, b;
    cin >> a >> b;

    double dif = abs(a-b); 

    int ans = ceil(dif/10);

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