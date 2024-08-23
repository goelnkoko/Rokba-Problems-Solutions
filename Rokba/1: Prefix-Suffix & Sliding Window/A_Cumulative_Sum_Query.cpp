#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define MAX 1e9
#define MOD 100000000
#define ll long long

using namespace std;

int main() {

    Nkumbo

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; 
    cin >> n;

    ll a[n];

    for(int i=0; i < n; i++)
        cin >> a[i];

    ll ps[n];
    ps[0] = a[0];

    for(int i=1; i < n; i++)
        ps[i] = ps[i-1] + a[i];

    int q; 
    cin >> q;

    while(q--){
        int x, y;
        cin >> x >> y;

        if(x != 0) 
            cout << ps[y] - ps[x-1] << endl;
        else 
            cout << ps[y] << endl;
    }

    return 0;
}