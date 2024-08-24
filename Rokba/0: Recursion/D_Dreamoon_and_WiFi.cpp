#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = INT_MAX;

inline int prob(int a, int b, int q){
    if(q == 0) return a == b ? 1:0;

    return prob(a, b+1, q-1) + prob(a, b-1, q-1); 
}

int main() {

    string a, b;
    cin >> a >> b;

    int a_pos, b_pos, q, n = a.size();
    a_pos = b_pos = q = 0;

    for(int i=0; i < n; i++) {
        a_pos += a[i] == '+' ? 1:-1;
        if(b[i] == '?') q++;
        else b_pos += b[i] == '+' ? 1:-1;
    }

    double p = prob(a_pos, b_pos, q);
    
    cout << setprecision(12) << fixed << endl;
    cout << p/(1 << q) << endl;

    return 0;
}