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
const int INF = 1e15;

signed main(){
    Nkumbo

    #ifndef ONLINE_JUDGE
    freopen("dis.in", "r", stdin);
    freopen("dis.out", "w", stdout);
    #endif

    string s; 
    char c;
    int q, op, pos, l, r;

    cin >> s; 

    vector<set<int>> conj(26);

    int n = s.size();
    for(int i=0; i < n; i++){
        conj[s[i]-'a'].insert(i);
    }

    cin >> q; 

    while(q--){
        cin >> op;

        if(op == 1) {
            cin >> pos >> c;
            pos--;
            conj[s[pos]-'a'].erase(pos);
            s[pos] = c;
            conj[s[pos]-'a'].insert(pos);
        } else {
            cin >> l >> r;
            l--; r--;
            int cont = 0;
            for(auto& cj: conj){
                auto it = cj.lower_bound(l);
                if(it != cj.end() && *it <= r) cont++;
            }
            cout << cont << endl;
        }
    }
}
