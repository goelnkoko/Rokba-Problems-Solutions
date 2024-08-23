#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 200010
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

    vector<int> ps(MAX, 0);

    for(int i=0; i < MAX; i++){
        int j = i, c = 0;
        while(j > 0){
            j /= 3;
            c++;
        }
        ps[i] = c;
    }

    for(int i=0; i < MAX; i++){
        ps[i] += ps[i-1];
    }

    while(t--){
        ll l, r;
        cin >> l >> r;

        int fir = ps[l] - ps[l-1];

        ll res = ps[r] - ps[l];

        res += fir*2;

        cout << res << endl;
    }

    return 0;
}