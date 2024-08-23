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

    ll n; 
    cin >> n;

    vector<pair<int, int>> a;

    for(int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;

        a.push_back({x, y});
    }

    sort(all(a), compareBySecond);

    int c = 0, x = 0;
    for(auto i: a){
        if(i.first >= x){
            c++;
            x = i.second;
        }
    }

    cout << c << endl;

    return 0;
}