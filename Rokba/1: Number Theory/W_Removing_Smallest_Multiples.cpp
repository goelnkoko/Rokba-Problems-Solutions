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
const int MAX = 1e6+1;

vector<vector<int>> dv(MAX);

inline void divs(){
    for(int i=1; i < MAX; i++){
        for(int j=i; j < MAX; j+=i){
            dv[j].push_back(i);
        }
    }
}

signed main(){

    int t; cin >> t;

    divs();

    while(t--){
        int n;
        string s;
        cin >> n >> s;

        ll cost = 0;

        for(int i=1; i <= n; i++){
            if(s[i-1] == '0'){
                for(auto j: dv[i]){
                    if(s[j-1] == '0'){
                        cost += j;
                        break;
                    }
                }
            } else {
                for(auto j: dv[i]){
                    s[j-1] = '1';
                }
            }
        }

        cout << cost << endl;
    }
}