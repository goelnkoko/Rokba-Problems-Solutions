#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e9+10
#define MOD 100000000
#define ll long long
#define llmp map<ll, ll> mp
#define vi vector<int>
#define endl '\n'

using namespace std;

int main() {

    Nkumbo

    ll n, x; 
    cin >> n >> x;

    vector<pair<int, int>> a;

    for(int i=0; i < n; i++){
        int b; 
        cin >> b;

        a.push_back({b, i});
    }

    sort(all(a));

    int l = 0, r = n-1;
    while(r - l > 0){
        ll soma = a[l].first + a[r].first;
        if(soma == x) {
            cout << a[l].second+1 << " " << a[r].second+1 << endl;
            return 0;
        } else if(soma > x){
            r--;
        } else {
            l++;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}