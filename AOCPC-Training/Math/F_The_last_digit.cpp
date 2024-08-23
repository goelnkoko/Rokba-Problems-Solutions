#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long


using namespace std;

int fast_exp(ll a, ll b){

    if (b == 0)
        return 1;

    ll c = fast_exp(a, b/2);
    c *= c;

    if(b%2==1)
        c *= a;

    return c%10;
}

int main() {

    Nkumbo

    int t; 
    cin >> t; 

    while(t--) {
        
        int a, b;
        cin >> a >> b;

        cout << fast_exp(a, b) << endl;

    }

    return 0;
}