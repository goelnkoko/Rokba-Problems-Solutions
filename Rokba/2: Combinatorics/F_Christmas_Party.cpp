#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 1e6+10;

int fact[MAX];

inline ll binPow(ll a, ll b, ll m){

    a %= m;
    ll r = 1;

    while(b > 0){
        if(b & 1) r = (a * r) % m;

        b >>= 1;
        a = (a * a) % m;
    }

    return r;
}

signed main(){

    int n; cin >> n;

    vector<int> derragementOf(n+1);
    derragementOf[0] = 1; 
    derragementOf[1] = 0;

    for(int i=2; i <= n; i++){
        derragementOf[i] = (i * derragementOf[i-1] + (i%2 ? -1:1))%MOD;
    }

    cout << derragementOf[n] << endl;

}   