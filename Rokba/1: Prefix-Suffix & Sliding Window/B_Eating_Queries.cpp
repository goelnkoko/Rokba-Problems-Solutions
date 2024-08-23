#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e9
#define MOD 1000000007
#define ll long long

using namespace std;

int main() {

    Nkumbo

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t; 

    while(t--) {
        int n, q; 
        cin >> n >> q;

        vector<ll> a(n);

        for(int i=0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end(), desc);

        vector<ll> ps(n);
        ps[0] = a[0];

        for(int i=1; i < n; i++)
            ps[i] = ps[i-1] + a[i];

        while(q--){
            int x;
            cin >> x;

            auto it = lower_bound(ps.begin(), ps.end(), x);

            if(it != ps.end()){
                cout << distance(ps.begin(), it)+1 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    

    return 0;
}