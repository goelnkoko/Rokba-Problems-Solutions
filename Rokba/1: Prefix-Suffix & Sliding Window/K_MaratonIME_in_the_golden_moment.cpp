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
        sum += a[i];
        sum2 += a[i]*a[i];
    }

    ll x = (sum*sum - sum2)/2;

    cout << x << endl;
    
    return 0;
}