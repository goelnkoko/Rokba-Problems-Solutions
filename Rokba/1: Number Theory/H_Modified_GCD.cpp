#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 2e5+10;

inline int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

inline int lcm(int a, int b){
    return a*b/gcd(a, b);
}

signed main(){

    int a, b;
    cin >> a >> b;

    int g = gcd(a, b);

    vector<int> dv;

    for(int i=1; i*i <= g; i++)
        if(g % i == 0){
            dv.push_back(i);
            if(g/i != i)
                dv.push_back(g/i);
        }

    sort(all(dv));

    int n; 
    cin >> n;

    while(n--){
        int l, r;
        cin >> l >> r;

        auto it = upper_bound(all(dv), r);
        if(it != dv.begin()) it--;

        if(*it < l) cout << -1 << endl;
        else cout << *it << endl;
    }
}