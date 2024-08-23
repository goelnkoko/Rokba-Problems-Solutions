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

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
	
	ll a, b; 
    cin >> a >> b;

    vector<ll> divs;

    ll d = gcd(a, b);

    for(ll i = 1; i * i <= d; i++){
        if(d % i == 0) {
            divs.push_back(i);
            if(d/i != i) divs.push_back(d/i);
        }
    }
    sort(all(divs));

    int q;
    cin >> q;

     while(q--){
        cin >> a >> b;

        auto it = upper_bound(all(divs), b);
        it--;
        if(*it >= a) cout << *it << endl;
        else cout << -1 << endl;
    }


	return 0;
}