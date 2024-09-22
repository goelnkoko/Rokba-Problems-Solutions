#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define vi vector<int>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 1e6+10;


int main(){

    int n; cin >> n;
    int m_gcd = 0;
    vi tb(n);
    for(auto& i: tb) {cin >> i;}

    vi mp(MAX, 0);

    for(int i=0; i < n; i++){
        int x = tb[i];
        for(int j=1; j*j <= x; j++){
            if(x % j == 0){
                mp[j]++;
                if(x/j != j) mp[x/j]++;
            }
        }
    }

    for(int i=0; i < MAX; i++){
        if(mp[i] >= 2) m_gcd = max(m_gcd, i);
    }

    cout << m_gcd << endl;
}

