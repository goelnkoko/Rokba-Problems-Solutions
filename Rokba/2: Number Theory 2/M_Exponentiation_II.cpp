#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define vi vector<int>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 1e6+10;

ll binPow(ll a, ll b, ll m){
    ll r = 1;
    a %= m;

    while(b > 0){
        if(b % 2 == 1) r = (r*a)%m;

        b = b >> 1;
        a = (a*a)%m;
    }

    return r;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        ll a, b, c; 
        cin >> a >> b >> c;

        ll r = binPow(b, c, MOD-1);
        r = binPow(a, r, MOD);

        cout << r << endl;
    }
}

