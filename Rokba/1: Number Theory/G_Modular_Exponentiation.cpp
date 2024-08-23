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


int main() {
	
	ll n, m, b;
    cin >> n >> m;

    cout << (n >= 31 ? m : m % (1 << n)) << endl;
	
	return 0;
}