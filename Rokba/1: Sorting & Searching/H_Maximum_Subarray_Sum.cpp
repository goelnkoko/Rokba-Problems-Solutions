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

    ll n, sum, m;
    cin >> n;
    
    for(int i=0; i < n; i++){
        ll a; 
        cin >> a;

        if(i == 0) {
            sum = a;
            m = sum;
            continue;
        }

        sum = max(a, sum + a);
        m = max(m, sum);
    }

    cout << m << endl;

    return 0;
}