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

    vector<int> a(n), r(n);

    for(int i=0; i < n-1; i++){
        cin >> a[i];
    }

    r[0] = a[0];
    r[n-1] = a[n-2];

    for(int i=1; i < n-1; i++){
        r[i] = a[i-1] | a[i];
    }

    for(int i=0; i < n-1; i++){
        if((r[i] & r[i+1]) != a[i]){
            cout << -1 << endl;
            return;
        }
    }

    for(int i=0; i < n; i++)    
        cout << r[i] << " ";
    
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
