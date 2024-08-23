#include <bits/stdc++.h>
#define MAX 200001
#define MOD 100000000
#define ll long long

using namespace std;


int main() {


    int n;
    cin >> n;

    ll tb[n];

    ll sum = 0;

    for(ll i=0; i < n; i++)
        cin >> tb[i];

    for(ll i=0; i < n; i++){
        for(ll j=i+1; j < n; j++){
            sum = (sum + (tb[i]+tb[j])%MOD);
        }
    }

    cout << sum << endl;

}