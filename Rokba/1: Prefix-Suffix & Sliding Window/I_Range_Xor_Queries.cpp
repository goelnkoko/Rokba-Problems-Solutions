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

    vector<ll> ps(n+5, 0);

    ps[0] = a[0];
    for(int i=1; i <= n; i++){
        ps[i] = ps[i-1] ^ a[i];
    }

    while(q--){
        int a, b;
        cin >> a >> b;

        if(a == 1)
            cout << ps[b-1] << endl;
        else 
            cout << (ps[b-1] ^ ps[a-2]) << endl;
    }

    return 0;
}