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

using namespace std;

void solve() {

    int n, k, q; 
    cin >> n >> k >> q;

    int l, r;

    vll part (MAX, 0), ps(MAX, 0); 

    for(int i=0; i < n; i++){
        cin >> l >> r;
        
        part[l]++;
        part[r+1]--;
    }

    for(int i=1; i <= MAX; i++){
        part[i] += part[i-1];
    }


    for(int i=0; i < MAX; i++){
        if(part[i] >= k)
            ps[i]++;
    }

    for(int i=1; i < MAX; i++){
        ps[i] += ps[i-1];
    }

    for(int i=0; i < q; i++){
        cin >> l >> r;
        cout << ps[r]-ps[l-1] << endl;
    }
}

int main() {

    Nkumbo

    int t=1; 
    // cin >> t; 

    while(t--) {
        solve();
    }

    return 0;
}