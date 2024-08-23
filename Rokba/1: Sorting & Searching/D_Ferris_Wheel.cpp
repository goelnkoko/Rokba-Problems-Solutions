#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 200001
#define MOD 100000000
#define ll long long
#define llmp map<ll, ll> mp
#define vi vector<int>
#define endl '\n'

using namespace std;

int main() {

    Nkumbo

    ll n, m; 
    cin >> n >> m;

    vector<ll> a(n);

    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    sort(all(a));

    int c = 0;

    int l = 0, r = n-1;
    while(l < r) {
        if(a[l] + a[r] <= m){
            l++;
            r--;
            c++;
        } else {
            r--;
            c++;
        }
    }

    if(l == r) c++;
    
    cout << c << endl;

    return 0;
}