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

ll cost (vector<ll>& a, ll x){
    ll c = 0;
    for(int i=0; i < a.size(); i++){
        c += abs(a[i]-x);
    }
    return c;
}

int main() {

    Nkumbo

    ll n;
    cin >> n;

    vector<ll> a(n);

    for(int i=0; i < n; i++){
        cin >> a[i];    
    }

    sort(all(a));

    ll c = 0, sum = 0; 
    for(int i=0; i < n; i++){
        if(sum + 1 >= a[i]){
            sum += a[i];
        } else {
            cout << sum + 1 << endl;
            return 0;
        }
    }

    cout << sum + 1 << endl;

    return 0;
}