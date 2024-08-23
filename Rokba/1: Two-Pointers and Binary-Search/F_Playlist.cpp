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

int main() {

    Nkumbo

    int n; 
    cin >> n;

    vi op(n+1);
    llmp;

    for(int i=1; i <= n; i++){
        cin >> op[i];
    }

    ll l = 1, r = 1, c = 0, m = 0;
    while(r <= n){
        if(mp[op[r]] != 0){
            m = max(m, r-l);
            l = max(l, mp[op[r]]+1);
        }
        mp[op[r]] = r;
        r++;    
    }

    m = max(m, r-l);

    cout << m << endl;

    return 0;
}

