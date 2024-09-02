#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main(){

    Nkumbo

    ll n; cin >> n;

    vector<ll> a(n);
    for(auto& i: a) cin >> i;

    ll r = a[1] - a[0];
    ll c = 2; 

    ll total = 0;

    for(int i=2; i < n; i++){
        if(a[i] - a[i-1] != r){
            total += ((c*(c+1))/2) - 1;
            c = 1;
            r = a[i] - a[i-1];
        }
        c++;
    }

    total += (c*(c+1)/2);

    if(n == 1) total = 1;

    cout << total << endl;
}