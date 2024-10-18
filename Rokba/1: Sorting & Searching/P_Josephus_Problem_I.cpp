#include <bits/stdc++.h> 

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

const int MAX = 1e6+7;
const int MOD = 1e9+7;
const int INF = 1e12;

signed main(){
    Nkumbo

    #ifndef ONLINE_JUDGE
    freopen("dis.in", "r", stdin);
    freopen("dis.out", "w", stdout);
    #endif

    int n; cin >> n;

    set<int> child;
    for(int i=1; i <= n; i++) child.insert(i);

    bool rem = false;
    vi clr;
    while(!child.empty()){
        for(auto& i: child){
            if(rem){
                cout << i << ' ';
                clr.push_back(i);
            } 
            rem = !rem;
        }
        for(auto& i: clr){
            child.erase(i);
        }
        clr.clear();
    }
}
