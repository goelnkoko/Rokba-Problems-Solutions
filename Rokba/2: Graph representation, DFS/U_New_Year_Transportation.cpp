#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 100 + 20;

int main(){

    Nkumbo

    int n, m;
    cin >> n >> m;
    m--;

    vector<int> a(n-1);
    for(auto& i: a) cin >> i;

    bool v = false;
    for(int i=0; i < n; i += a[i]){
        if(i == m) v = true;

        if(i == n-1) break;
    }

    cout << (v ? "YES":"NO") << endl;
}