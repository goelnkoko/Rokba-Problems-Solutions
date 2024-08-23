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

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n, 0);

    for(int i=0; i < n; i++)
        cin >> a[i];

    vector<ll> ps(n, 0);

    ps[0] = a[0];
    for(int i=1; i < n; i++){
        ps[i] = ps[i-1] + a[i];
    }   

    ll m = ps[k-1];
    ll res = 0;
    for(int i=k; i < n; i++){

        ll v = ps[i] - ps[i-k];
        
        if(v < m){
            m = v;
            res = i-k+1;
        }
    }   

    cout << res+1 << endl;

    return 0;
}