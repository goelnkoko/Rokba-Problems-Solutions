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

    for(int i=0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> ps(n, 0);

    ps[0] = a[0];
    for(int i=1; i< n; i++){
        ps[i] = ps[i-1] + a[i];
    }

    ll x = ps[n-1] / 3;

    if(n < 3 || ps[n-1] % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    ll c = 0;
    ll total = 0;
    for(int i=0; i < n; i++){
        if(ps[i] == x * 2 && i < n-1){
            total += c;
        }
        if(ps[i] == x){
            c++;
        }
    }

    cout << total << endl;
    
    return 0;
}