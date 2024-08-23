#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define vll vector<ll> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

ll calc_last(ll x, ll y){
    ll mult = 1;
    for(ll i = x+1; i <= y; i++)
        mult *= i%10;

    return mult%10;
}

int main() {
	
	ll x, y;
    cin >> x >> y;

    ll d = y - x;

    if(d >= 10)
        cout << 0 << endl;
    else {
        ll last = calc_last(x, y);
        cout << last << endl;
    }

	return 0;
}






