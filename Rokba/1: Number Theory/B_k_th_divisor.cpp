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

ll fact(ll m) {
    ll sum = 1;
    for(int i=1; i <= m; i++){
        sum *= i;
    }
    return sum;
}

int main() {

    Nkumbo

    ll a, b;
    cin >> a >> b;
    vll ans;

    ans.push_back(1);
    if(a != 1) ans.push_back(a);

    for(ll i=2; i*i <= a; i++){
        if(a%i == 0){
            ans.push_back(i);

            if(a/i != i){
                ans.push_back(a/i);
            }
        }
    }

    if(ans.size() < b) cout << -1 << endl;
    else {
        sort(all(ans));
        cout << ans[b-1] << endl; }

    return 0;
}