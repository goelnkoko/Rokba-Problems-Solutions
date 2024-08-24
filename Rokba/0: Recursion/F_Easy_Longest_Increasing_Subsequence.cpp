#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = INT_MAX;
int n;

inline int lis(vector<int>& a, int i, int last, int c){

    if(i >= n)
        return c;

    int m = 0;

    if(last < a[i]){
        m = lis(a, i+1, a[i], c + 1);
    } else {
        m = max(m, lis(a, i+1, a[i], 1));
    }
        
    m = max(m, lis(a, i+1, last, c));

    return m;
}

int main() {

    cin >> n;

    vector<int> a(n);
    for(auto& i: a) cin >> i;

    cout << lis(a, 1, a[0], 1) << endl;

    return 0;
}