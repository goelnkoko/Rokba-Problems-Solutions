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

    int n, q; 
    cin >> n >> q;

    set<int> dist;
    multiset<int> tam;

    while(q--){
        int a; cin >> a;
        dist.insert(a);

        auto it = dist.lower_bound(a);
        if(dist.size() == 1){
            tam.insert(a);
            tam.insert(n-a);
        } else if(it == dist.begin() ){
            it++;
            tam.erase(tam.find(*it));
            tam.insert(a);
            tam.insert(abs(*it-a));
        } else if(a == *dist.rbegin()){
            it--;
            tam.erase(tam.find(abs(*it-n)));
            tam.insert(n-a);
            tam.insert(abs(*it-a));
        } else {
            auto itl = it, itr = it;
            itl--, itr++;
            tam.erase(tam.find(abs(*itl - *itr)));
            tam.insert(abs(*itr-*it));
            tam.insert(abs(*itl-*it));
        }

        cout << *tam.rbegin() << endl;
    }


}
