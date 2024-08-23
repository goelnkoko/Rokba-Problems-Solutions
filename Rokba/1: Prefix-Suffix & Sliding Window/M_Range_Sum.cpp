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

    ll n; 
    cin >> n;

    vector<ll> a(n);

    ll sum = 0, sum2 = 0;
    for(int i=0; i < n; i++) {
        cin >> a[i];
    }

    deque<ll> sf(n, 0);

    sf[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--){
        sf[i] = sf[i+1] + a[i];
    }

    int q; 
    cin >> q;

    while(q--){
        int charada;
        cin >> charada;

        if(charada == 1){
            ll l, r;
            cin >> l >> r;
            cout << sf[l-1] - sf[r] << endl;
        } else if(charada == 2){
            ll a; 
            cin >> a;
            sf.push_front(a+sf[0]);
        }
    }

    
    return 0;
}