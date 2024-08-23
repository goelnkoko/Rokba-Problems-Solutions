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

ll fast_exp(ll a, ll b){

    if (b == 0)
        return 1;

    ll c = fast_exp(a, b/2);
    c *= c;

    if(b%2==1)
        c *= a;

    return c%5;
}

int main() {
	
	string s;
	cin >> s;

    string res = (s.size() > 1 ? s.substr(s.size()-2):s.substr(s.size()-1));
    ll n = stoi(res);

    ll sum = 0;

    for(ll i = 1; i <= 4; i++){
        sum += fast_exp(i, n);
    }

    sum %= 5;

    cout << sum << endl;

	return 0;
}






