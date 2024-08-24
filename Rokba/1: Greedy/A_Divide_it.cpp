#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll MAX = 5e9;

int main() {

    ll t;
    cin >> t;

    while(t--){
        ll n, c = 0; cin >> n;

        while(n > 1){
            if(n % 2 == 0) n /= 2;
            else if(n%3 == 0) n = 2*n/3;
            else if(n%5 == 0) n = 4*n/5;
            else {
                c = -1; 
                break;
            }
            c++;
        }

        cout << c << endl;
    }

    return 0;
}