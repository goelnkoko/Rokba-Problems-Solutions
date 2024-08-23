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

     int n; 
     cin >> n;

    vector<pair<int, int>> v;
    for(int i=0; i < n; i++){
        int a;
        cin >> a;
        
        v.push_back({a, i});
    }

    sort(all(v));

    cout << v[n-2].second + 1 << endl;

    return 0;
}