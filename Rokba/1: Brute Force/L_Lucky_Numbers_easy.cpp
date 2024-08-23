#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e6+10
#define ll long long
#define vll vector<ll> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

const int MOD = 1000000007;

int main() {
	
	ll n;
    cin >> n;

    ll x = log2(n);

    for(ll i =0; i < (1 << x); i++){
        ll y = i;

        while(y > 0)
    }
    
	return 0;
}