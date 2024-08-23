#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 500
#define ll long long
#define vi vector<int> 
#define endl '\n'
#define f first 
#define s second

using namespace std;


int main() {

    Nkumbo

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), v(n, 1), res, ps(n+1, 0);
        for(auto& i: a) cin >> i;

        sort(all(a));
        res.push_back(a[n-1]);
        ps[0] = a[n-1];
        v[n-1] = 0;
        int pos = log2(a[n-1]) + 1;
        int m = (1 << pos) - 1;

        int i = 0;
        while(ps[i] < m && i < n-1){
            int d = m ^ ps[i];
            pos = log2(d) + 1;
            d = (1 << pos) - 1;
            auto it = upper_bound(all(a), d);

            while(it == a.end() && d < m){
                pos++;
                d = (1 << pos) - 1;
                it = upper_bound(all(a), d);
            }
            
            int dis = distance(a.begin(), it) - 1;

            res.push_back(a[dis]);
            v[dis] = 0;

            i++;
            ps[i] = ps[i-1] | a[dis];
        }

        for(int i=0; i < n; i++){
            if(v[i]) res.push_back(a[i]);
        }

        for(auto i: res) cout << i << ' ';
        cout << endl;
    }

    return 0;
}