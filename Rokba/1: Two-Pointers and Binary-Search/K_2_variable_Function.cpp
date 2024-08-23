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
#define f first 
#define s second

using namespace std;

ll calc_x(ll a, ll b){
    return (a*a + b*b)*(a+b);
}

int main() {

    Nkumbo

    ll n;
    cin >> n;

    ll a = 0, b = 1e6+5, ans = LLONG_MAX;
    while(a <= b){
        ll x = calc_x(a, b);

        if(x < n){
            a++;
        } else {
            b--;
            ans = min(ans, x);
        }
    }

    cout << ans << endl;

    return 0;
}

