#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

map<ll, ll> mp; 

const int MAX = 20000;

int main() {

    Nkumbo

    string a, b;
    cin >> a >> b;

    int pos, sec, q; pos = sec = q = 0;
    for(int i=0; i < a.size(); i++){
        pos += (a[i] == '+' ? 1 : -1);
        if(b[i] == '?') q++;
        else sec += (b[i] == '+' ? 1 : -1);
    }
    
    cout << setprecision(12) << fixed;

    int n = pos - sec; 
    double c = 0;
    for(int i=0; i < (1 << q); i++){
        int a = 0;
        for(int j = 0; j < q; j++){
            a += (i & (1 << j) ? 1 : -1);
        }
        if(a == n) c++;
    }
    cout << (c/(1 << q)) << endl;

    return 0;
}