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
#define endl '\n'

using namespace std;

int main() {

    Nkumbo

    ll n, m; 
    cin >> n >> m;

    map<ll, int> mp;

    for(int i=0; i < n; i++){
        int a; 
        cin >> a;

        mp[a]++;
    }

    while(m--){
        int b; 
        cin >> b;

        auto it = mp.upper_bound(b);

        if(it == mp.begin()){
            cout << -1 << endl;
        } else {
            it--;
            cout << it->first << endl;
            it->second--;

            if(it->second == 0)
                mp.erase(it);
        }
    }
    return 0;
}