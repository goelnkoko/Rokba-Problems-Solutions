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

    vector<int> a(n);

    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    int m = 0; 

    for(int i=0; i < n; i+=2){
        m = max(m, a[i]);
    }

    cout << m << endl;

    
}

int main() {

    Nkumbo

    int t;
    cin >> t;
    
    while(t--){
        solve();
    }

}
