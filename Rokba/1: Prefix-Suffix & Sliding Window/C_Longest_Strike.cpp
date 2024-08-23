#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define MAX 1e9
#define MOD 100000000
#define ll long long
#define llmp map<ll, ll> mp

using namespace std;

int main() {

    Nkumbo

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t; 

    while(t--) {
        int n, k; 
        cin >> n >> k;

        vector<ll> a(n);
        llmp;

        for(int i=0; i < n; i++){ 
            cin >> a[i];
            mp[a[i]]++;
        }

        vector<int> v; 

        for(auto m: mp) {
            if(m.second >= k) {
                v.push_back(m.first);
            }
        }

        if(!v.empty()){

            int l=v[0], r=v[0], tl=v[0], tr=v[0], c = 0, m = 0;

            for(int i=1; i < v.size(); i++){

                if(v[i-1] + 1 == v[i]) {
                    c++;
                } else {
                    tr = v[i-1];
                    if(c > m) {
                        l = tl, r = tr;
                        m = c;
                    }
                    tl = v[i];
                    c = 0;
                }
            }

            if(c > m) {
                l = tl; 
                r = v[v.size()-1];
            }

            cout << l << " " << r << endl;
        } else {
            cout << -1 << endl;
        }
        
    }
    

    return 0;
}