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

    ll n;
    cin >> n;

    vector<ll> sol = {0};
    for(ll s=n; s ; s=(s-1)&n)
        sol.push_back(s);

    sort(all(sol));

    for(auto& i: sol)
        cout << i << endl;

    return 0;
}


