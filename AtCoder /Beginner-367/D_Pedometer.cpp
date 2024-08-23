#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 500
#define ll long long
#define vi vector<int> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

int main() {
    Nkumbo

    int n, m; 
    cin >> n >> m;

    vector<int> a(n);
    for(auto& i: a) cin >> i;

    vector<ll> ps(2*n+10, 0);
    for(int i = 0; i < 2*n; i++)
        ps[i+1] = (ps[i] + a[i % n]) % m;

    map<int, int> mp;
    ll c = 0;

    for(int i = 1; i <= 2*n; i++){
        mp[ps[i]]++;

        if(i >= n) mp[ps[i%n]]--;

        c += (mp[ps[i]] == 1 ? 0 : mp[ps[i]]-1);
    }

    cout << c << endl;

    return 0;
}