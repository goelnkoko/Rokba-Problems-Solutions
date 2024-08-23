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

    ll n, q;
    cin >> n >> q;

    vector<ll> a(n);

    for(ll i=0; i < n; i++)
        cin >> a[i];

    sort(all(a));

    vector<ll> ps(n);

    ps[0] = a[n-1];
    for(ll i=1; i < n; i++){
        ps[i] = ps[i-1] + a[n-i-1];
    }

    while(q--){
        ll a, b;
        cin >> a >> b;

        if(a != b)
            cout << ps[a-1] - ps[a-b-1] << endl;
        else 
            cout << ps[a-1] << endl;
    }

    return 0;
}