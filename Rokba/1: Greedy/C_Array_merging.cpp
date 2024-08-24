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
        int n, m = 0; cin >> n;
        
        vector<int> a(n), b(n);
        map<int, int> ma, mb;

        for(auto& i: a) cin >> i;
        for(auto& i: b) cin >> i;

        int c = 1, d = 1;

        for(int i=1; i < n; i++){
            if(a[i] == a[i-1]) c++;
            else {
                ma[a[i-1]] = max(ma[a[i-1]], c);
                c = 1;
            }
            if(b[i] == b[i-1]) d++;
            else {
                mb[b[i-1]] = max(mb[b[i-1]], d);
                d = 1;
            }
        }

        ma[a[n-1]] = max(ma[a[n-1]], c);
        mb[b[n-1]] = max(mb[b[n-1]], d);
        
        for(auto& i: ma) mb[i.first] += i.second;
        for(auto& i: mb) m = max(m, i.second);

        cout << m << endl;
        
    }

    return 0;
}