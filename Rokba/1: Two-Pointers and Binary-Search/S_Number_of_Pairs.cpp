#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define llmp map<ll, ll> mp
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

        int n, x, y;
        cin >> n >> x >> y;

        vector<int> a(n);
        for(int i=0; i < n; i++){
            cin >> a[i];
        }
        sort(all(a));

        ll c = 0;
        for(int i=n-1; i >= 0; i--){
            if(x-a[i] <= 0){
                auto itr = upper_bound(a.begin(), a.begin()+i, y-a[i]);
                c += distance(a.begin(), itr);
            } else {
                auto itl = lower_bound(a.begin(), a.begin()+i, x-a[i]);
                auto itr = upper_bound(a.begin(), a.begin()+i, y-a[i]);

                if (itl != a.begin() + i) {
                    if (itl != itr) {
                        c += distance(itl, itr);
                    } else {
                        ll w = *itl + *itr;
                        if(w >= x && w <= y){
                            c++;
                        }
                    }
                }
            }
        }
        cout << c << endl;
    }

    return 0;
}

