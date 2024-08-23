#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define llmp map<ll, ll> mp
#define vi vector<int>
#define endl '\n'

using namespace std;

int main() {

    Nkumbo

    ll t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        vector<ll> a(n);
        ll m = 0;

        for(int i=0; i < n; i++){
            cin >> a[i];
            m = max(m, a[i]);
        }

        vector<long double> d(n);
        vector<ll> res(n);
        ll M = 0;
        ll par = 0, imp = 0;
        for(int i=0; i < n; i++){
            d[i] = m - a[i];
            res[i] = floor(d[i]/k + 1);
            if(res[i] % 2 == 0) par++;
            else imp++;
        }

        for(int i=0; i < n; i++){
            if(res[i] == 1){
                M = max(M, a[i]);
            } else if(res[i] % 2 == 0){
                M = max(M, a[i] + (res[i] * k));
            } else {
                M = max(M, a[i] + (res[i]-1)*k);
            }
        }

        if(m > M)
            cout << -1 << endl;
        else 
            cout << M << endl;
    }

    return 0;
}