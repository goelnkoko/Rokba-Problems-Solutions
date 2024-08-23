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

    map<ll, vector<int>> mp;

    for(int i=0; i < n; i++){
        int b; 
        cin >> b;
        mp[b].push_back(i+1);
    }

    int q;
    cin >> q;



    while(q--){
        int l, r, x, d = 0;
        cin >> l >> r >> x;
        
        auto itl = lower_bound(all(mp[x]), l);
        auto itr = upper_bound(all(mp[x]), r);
        
        if(itl != mp[x].end() && *itl <= r){
            d = distance(itl, itr);
            if(itr != mp[x].end() && *itr == r) d++;
        }
        
        cout << d << endl;
    }

    return 0;
}

