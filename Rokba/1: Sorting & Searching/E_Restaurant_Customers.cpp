#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e9+10
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

    vector<ll> x, y;

    while(n--){
        int a, b;
        cin >> a >> b;

        x.push_back(a);
        y.push_back(b);
    }

    sort(all(x));
    sort(all(y));

    ll l = 0, r = 0;

    ll c = 0, m = 0;
    while(l < x.size() && r < y.size()){

        if(x[l] < y[r]){
            c++;
            m = max(m, c);
            l++;
        } else {
            c--;
            r++;
        }
    }

    cout << m << endl;

    return 0;
}