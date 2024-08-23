#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define compareByFirstDesc [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; }
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

    ll n;
    cin >> n;

    vector<ll> a(n);

    for(int i=0; i < n; i++)
        cin >> a[i];

    multiset<ll> mst;

    for(int i=0; i < n; i++){
        auto it = mst.upper_bound(a[i]);

        if(it != mst.end()){
            mst.erase(it);
            mst.insert(a[i]);
        } else {
            mst.insert(a[i]);
        }
    }

    cout << mst.size() << endl;

    return 0;
}