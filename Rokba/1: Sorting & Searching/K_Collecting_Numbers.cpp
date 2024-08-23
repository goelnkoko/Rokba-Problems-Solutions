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

int main() {

    Nkumbo

    ll n;
    cin >> n;

    vector<pair<ll, ll>> a(n);

    for(int i=0; i < n; i++){
        cin >> a[i].f;
        a[i].s = i;
    }

    sort(all(a));

    int c = 1;
    for(int i=1; i < n; i++){
        if(a[i].s < a[i-1].s){
            c++;
        }
    }

    cout << c << endl;

    return 0;
}