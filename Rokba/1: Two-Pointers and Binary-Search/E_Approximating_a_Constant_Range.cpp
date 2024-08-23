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

    int n; 
    cin >> n;

    vector<ll> op(n);

    for(int i=0; i < n; i++){
        cin >> op[i];
    }

    int l = 0, r = 0; 
    ll M = 0, m = op[0], v = op[0], c = 0;
    while(r < n){
        if(abs(v-op[r]) <= 1 && abs(m-op[r]) <= 1){
            v = min(op[r], v);
            m = max(op[r], m);
            c++;
            if(op[r] != op[l]){
                l = r;
            }
            r++;
        } else {
            M = max(M, c);
            c = 0;
            r = l;
            v = m = op[l];
        }
    }

    M = max(M, c);

    cout << M << endl;

    return 0;
}

