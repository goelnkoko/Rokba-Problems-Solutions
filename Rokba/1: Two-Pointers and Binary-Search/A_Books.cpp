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

    int n, t;
    cin >> n >> t;

    vector<ll> a(n), ps(n, 0);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    ps[0] = a[0];
    for(int i=1; i < n; i++){
        ps[i] = ps[i-1] + a[i];
    }

    int l = 0, r = 0, M = 0;
    ll sum = 0; 

    while(r < n){
        if(l == 0 && ps[r] <= t){   
            M = max(M, r+1);
            r++;
        } else if(ps[r] - ps[l] <= t){
            M = max(M, r-l);
            r++;
        } else {
            l++;
            if(l > r){
                r++;
            }
        } 
    }

    cout << M << endl;

    return 0;
}