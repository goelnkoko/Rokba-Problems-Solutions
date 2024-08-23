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

    for(int i=0; i < n; i++)    
        cin >> a[i];

    vector<ll> l(n, 0), r(n, 0);

    l[0] = a[0];
    for(int i=1; i < n; i++){
        l[i] = __gcd(l[i-1], a[i]);
    }

    r[n-1] = a[n-1];
    for(int i=n-2; i >= 0; i--){
        r[i] = __gcd(r[i+1], a[i]);
    }

    ll m=0;
    for(int i=0; i < n; i++){
        if(i == 0)
            m = max(m, r[1]);
        else if(i == n-1)
            m = max(m, l[i-1]);
        else
            m = max(m, __gcd(l[i-1], r[i+1]));
    }

    cout << m << endl;

    return 0;
}