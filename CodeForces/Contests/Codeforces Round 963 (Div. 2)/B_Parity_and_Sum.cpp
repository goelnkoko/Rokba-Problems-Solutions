#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define vi vector<int>
#define endl '\n'

using namespace std;

int main() {

    Nkumbo

    ll t;
    cin >> t;

    while(t--){

        int n; 
        cin >> n;

        vector<ll> a(n);
        ll par = 0, imp = 0, mi = 0, mp = 0;

        map<ll, ll> llmp;

        for(int i=0; i < n; i++){
            cin >> a[i];

            if(a[i] % 2 == 0){
                par++;
                mp = max(mp, a[i]);
                llmp[a[i]]++;
            } else {
                imp++;
                mi = max(mi, a[i]);
            }
        }

        if(par == n || imp == n) {
            cout << 0 << endl;
            continue;
        }

        ll sum = mi; 
        bool ans = true;
        for(auto i: llmp){
            if(sum > i.first){
                sum += (i.first * i.second);
            } else {
                cout << par + 1 << endl;
                ans = false;
                break;
            }
        }

        if(ans)
            cout << par << endl;
    }

    return 0;
}