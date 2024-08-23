#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define MAX 1e9
#define MOD 100000000
#define ll long long


using namespace std;

int main() {

    Nkumbo

    ll n, k, a;
    cin >> n >> k;

    ll sum = ((1+k)*k)/2;

    set<ll> b;

    for(int i=0; i < n; i++){
        cin >> a; 
        
        if(a <= k)
            b.insert(a);
    }

    for(ll c: b){
        sum -= c;
    }

    cout << sum << endl;

    return 0;
}