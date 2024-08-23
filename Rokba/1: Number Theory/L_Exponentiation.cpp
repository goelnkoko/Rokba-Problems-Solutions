#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1000010
#define MOD 1e9+7
#define ll long long
#define vll vector<ll> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

map<int, int> divs;

ll binPow(ll a, ll b, ll m){

    ll r = 1;
    a %= m;
    
    while(b > 0){
        if(b%2 == 1) r = (r*a)%m;

        b = b >> 1;
        a = (a*a)%m;
    }

    return r;
}

int main() {
	
    Nkumbo
	
    int t;
    cin >> t;

    while(t--){
        ll a, b;
        cin >> a >> b;

        cout << binPow(a, b, MOD) << endl;
    }
    
	return 0;
}