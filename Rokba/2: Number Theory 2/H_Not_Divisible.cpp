#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 1e6+1;

int main(){

    int n; cin >> n;

    vector<int> tb(n); 
    vector<int> dv(MAX, 0);

    int M = 0;
    for(int& i: tb) {
        cin >> i;
        dv[i]++; M = max(M, i);
    }

    set<int> a(all(tb));

    for(const int& i: a)
        for(int j=i+i; j <= M; j += i)
            dv[j]++;

    int c = 0;
    for(int i=0; i < n; i++){
        if(dv[tb[i]] == 1) c++;
    }

    cout << c << endl;
}

