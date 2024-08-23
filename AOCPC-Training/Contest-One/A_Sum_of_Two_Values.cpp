#include <bits/stdc++.h>
#define MAX 1e9
#define MOD 100000000
#define ll long long

using namespace std;

int main() {

    ll n, x;
    cin >> n >> x;

    ll tb[n];

    for(ll i=0; i < n; i++){
        cin >> tb[i];
    }

    ll aux[n];
    for(ll i=0; i < n; i++){
        aux[i] = tb[i];
    }

    sort(tb, n+tb);

    ll l = 0, r = n-1;

    while(l < r) {

        if(tb[l] + tb[r] == x) {

            ll res1 = -1, res2 = -1;

            for(ll j=0; j < n; j++) {
                if(aux[j] == tb[l] && res1 == -1) res1 = j+1; 
                else if(aux[j] == tb[r] && res2 == -1) res2 = j+1;
            }

            cout << res1 << " " << res2 << endl;
            return 0;
        } else if (tb[l] + tb[r] < x){
            l++;
        } else { 
            r--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}