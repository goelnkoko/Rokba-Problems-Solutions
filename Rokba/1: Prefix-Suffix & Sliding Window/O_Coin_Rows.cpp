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

    ll t; 
    cin >> t;

    while(t--){

        ll n; 
        cin >> n;

        vector<ll> a(n), b(n), p1(n+1, 0), p2(n+1, 0);

        for(int i=0; i < n; i++)
            cin >> a[i];

        p1[n-1] = a[n-1];
        for(int i=n-2; i >= 0; i--)
            p1[i] = p1[i+1] + a[i];

        for(int i=0; i < n; i++)
            cin >> b[i];

        p2[0] = b[0];
        for(int i=1; i < n; i++)
            p2[i] = p2[i-1] + b[i];

        ll m = INT_MAX;

        for(int i=0; i < n; i++){
            if(i == 0){
                m = min(m, p1[1]);
            } else if(i == n-1){
                m = min(m, p2[i-1]);
            } else {
                ll x = max(p1[i+1], p2[i-1]);
                m = min(m, x);
            }
        }

        cout << m << endl;
    }
    
    return 0;
}