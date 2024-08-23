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

using namespace std;

int main() {

    Nkumbo

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> pf(MAX, 0);

    int m = 0;

    for(int i=0; i < n; i++){
        int a, b;
        cin >> a >> b;

        pf[a]++;
        pf[b+1]--;   

    }

    for(int i=1; i < MAX; i++){
        pf[i] += pf[i-1];
    }

    vector<int> p(MAX, 0);

    for(int i=1; i < MAX; i++){
        if(pf[i] >= k)
            p[i]++;
    }

    for(int i=1; i < MAX; i++){
        p[i] += p[i-1];
    }

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << p[b] - p[a-1] << endl;
    }

    return 0;
}