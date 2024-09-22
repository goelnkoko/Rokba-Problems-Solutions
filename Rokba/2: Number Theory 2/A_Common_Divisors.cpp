#include <bits/stdc++.h> 

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){

    ll n; 
    cin >> n; 

    ll tb[n];
    ll x = 0;
    for(auto& i: tb) {
        cin >> i;
        x = gcd(x, i);    
    }

    ll div = 0;

    for(ll i=1; i*i <= x; i++){
        if(x % i == 0){
            div++;
            if(x/i != i) div++;
        }
    }

    cout << div << endl;
}