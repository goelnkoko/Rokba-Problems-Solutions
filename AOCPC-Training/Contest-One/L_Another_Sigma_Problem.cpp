#include <bits/stdc++.h>
#define MAX 200001
#define MOD 998244353
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
            string s = to_string(tb[i]) + to_string(tb[j]);

            sum += stoll(s);
        }
    }

    cout << sum%MOD << endl;

}