#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> a;

ll totalSum(ll sum, ll n, ll i){
    ll soma = sum;
    for(ll j=i; j < n; j++){
        soma += totalSum(sum | a[j], n, j+1);
    }
    return soma; 
}

int main() {

    ll n;
    cin >> n;

    a.resize(n);
    for(auto& i: a) cin >> i; 

    cout << totalSum(0, n, 0) << '\n';
    
    return 0;
}