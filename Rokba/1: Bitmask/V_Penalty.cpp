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
        string s; cin >> s;
        ll n = s.size();

        ll q = 0, m = 10;
        for(auto& i: s) q += (i == '?' ? 1:0);

        for(ll i=0; i < (1LL << q); i++){
            string temp = s;
            ll j=0, k = 0;
            while(k < n){
                if(temp[k] == '?'){
                    temp[k] = (i & (1LL << j)) ? '1':'0';
                    j++;
                }
                k++;
            }

            ll a = 0, b = 0;
            for(ll v=0; v < n; v++){
                if(v % 2 == 0) a += temp[v] - '0';
                else b += temp[v] - '0';

                if((a > b && a - b > (n-v)/2) || (b > a && b - a > (n-v-1)/2)) {   
                    m = min(v+1, m);
                }
            }
        }

        cout << m << endl;
        
    }
    
    return 0;
}