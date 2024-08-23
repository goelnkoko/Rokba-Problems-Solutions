#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 1e9
#define MOD 100000000
#define ll long long

using namespace std;

int main() {

    Nkumbo

    ll t[4];
    vector<vector<ll>> a(4);

    for (ll i = 0; i < 4; i++) {
        cin >> t[i];
        a[i].resize(t[i]);

        for (ll j = 0; j < t[i]; j++) {
            cin >> a[i][j];
        }
    }

    set<ll> sum;

    for(int j=0; j < t[0]; j++){
        for(int k=0; k < t[1]; k++){
            for(int l=0; l < t[2]; l++){
                sum.insert(a[0][j] + a[1][k] + a[2][l]);
            }
        }
    }

    for(int i=0; i < t[3]; i++){

        if(sum.find(a[3][i]) != sum.end()) cout << "Yes" << endl;
        else cout << "No" << endl;    
    }

    return 0;
}