#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define MAX 1e9
#define MOD 1000000007
#define ll long long

using namespace std;

void solve() {

    int n; 
    cin >> n;

    vector<ll> a(n);

    int p = 0, ip = 0;
    for(int i=0; i < n; i++){
        cin >> a[i];

        
        if(a[i]%2 == 0) {
            p++;
        } else {
            ip++;
        }
    }

    if(p > 0 && ip > 0) {
        cout << -1 << endl;
        return;
    }

    ll c = 30;
    if(p > 0) c++;

    cout << c << endl;

    for(int i=29; i >= 0; i--){
        cout << (1 << i) << " ";
    }

    if(p > 0){
        cout << 1;
    }

    cout << endl;
}

int main() {

    Nkumbo

    int t;
    cin >> t;
    
    while(t--){
        solve();
    }

}
