#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e9
#define ll long long
#define vi vector<int> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

int main() {

    Nkumbo

    ll a, b;
    cin >> a >> b;

    ll c = 0;
    for(ll i=log2(a); i <= (ll)log2(b)+1; i++){
        ll m = (1LL << i) - 1;

        for(ll j = 0; j < i; j++){
            ll v = m ^ (1LL << j);
            if(v >= a && v <= b && (v & (v+1))) c++;
        }
    }

    cout << c << endl;

    return 0;
}


