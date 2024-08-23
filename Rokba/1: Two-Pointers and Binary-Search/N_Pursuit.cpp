#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define endl '\n'
#define f first 
#define s second

using namespace std;

int main() {

    Nkumbo

    int t;
    cin >> t;

    while(t--){
        int n, m;

        cin >> n;
        vector<int> a(n), ps1(n+5, 0), b(n), ps2(n+5, 0);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        sort(all(a)); sort(all(b));

        ps1[0] = a[0]; ps2[0] = b[0];
        for(int i = 1; i < n; i++){
            ps1[i] = ps1[i-1] + a[i];
            ps2[i] = ps2[i-1] + b[i];
        }

        ll v = n / 4 , l = 0, r = 1e9, ans = 0;
        
        while(l <= r){
            ll mid = l + (r-l) / 2;

            ll val = (mid >= v) ? ps2[n-1] : ps2[n-1] - ps2[v-mid-1];
            ll p = ps1[n-1] + (mid * 100) - ((v > 0) ? ps1[v-1] : 0);

            if(p >= val) {r = mid - 1; ans = mid;}
            else l = mid + 1;
        }    

        cout << ans << endl; 
    }

    return 0;
}