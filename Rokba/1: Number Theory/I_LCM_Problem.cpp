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

ll lcm(ll a, ll b){
    return a/gcd(a, b)*b;
}

int main() {
	
	int t;
    cin >> t ;

    while(t--){
        ll a, b;
        cin >> a >> b;

        if(lcm(a, a*2) > b) 
            cout << "-1 -1" << endl;
        else
            cout << a << " " << a*2 << endl;
    }
    
	return 0;
}