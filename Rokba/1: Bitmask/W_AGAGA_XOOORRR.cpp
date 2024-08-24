#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = INT_MAX;

int main() {

    Nkumbo

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(auto& i: a) cin >> i;

        vi pfl(n+1, 0), pfr(n+1, 0);

        pfl[0] = a[0];
        for(int i=1; i < n; i++)
            pfl[i] = pfl[i-1] ^ a[i];

        bool ans = !pfl[n-1];
        for(int i=0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ans |= pfl[i] == (pfl[j]^pfl[i]) && pfl[i] == pfl[n-1]^pfl[j];
            }
        }

        cout << (ans ? "YES":"NO") << endl;
    }
    
    return 0;
}