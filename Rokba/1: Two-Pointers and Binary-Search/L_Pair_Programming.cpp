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
        ll k, n, m;
        cin >> k >> n >> m;

        vector<ll> a(n), b(m);
        for(int i=0; i < n; i++)
            cin >> a[i];

        for(int i=0; i < m; i++)
            cin >> b[i];

        int mc = 0, pc = 0;
        vector<ll> res;
        while(mc < n && pc < m){
            if(a[mc] <= b[pc]){
                res.push_back(a[mc]);
                mc++;
            } else {
                res.push_back(b[pc]);
                pc++;
            }
        }

        while(mc < n){
            res.push_back(a[mc]);
            mc++;
        }
        while(pc < m){
            res.push_back(b[pc]);
            pc++;
        }
        bool ans = true;
        for(int i=0; i < res.size(); i++){
            if(res[i] == 0){
                k++;
            } else if(res[i] > k){
                ans = false;
                break;
            }
        }

        if(ans){
            for(int i=0; i < res.size(); i++)
                cout << res[i] << " ";
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}

