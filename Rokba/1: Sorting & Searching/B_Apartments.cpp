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

    ll n, m, k; 
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);

    for(int i=0; i < n; i++)
        cin >> a[i];
    
    for(int j=0; j < m; j++)
        cin >> b[j];

    sort(all(a));
    sort(all(b));

    int u = 0, d = 0, c = 0;

    while(u < n && d < m){

        if(abs(a[u] - b[d]) <= k){
            c++; 
            u++;
            d++;
        } else if(a[u] > b[d]){
            d++;
        } else {
            u++;
        }
    }

    cout << c << endl;
    
    return 0;
}