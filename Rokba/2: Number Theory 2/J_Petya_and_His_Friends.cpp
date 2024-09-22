#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 1001;


int main(){

    int n; cin >> n;

    if(n == 2) cout << -1 << endl;
    else if(n >= 3) {
        cout << "6\n10\n15\n";
        for(int i=3; i < n; i++)
            cout << 6*i << endl;
    }
}

