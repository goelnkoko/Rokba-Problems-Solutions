#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mk make_pair 
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first 
#define ss second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 501;
const int MOD = 1e9+7;
const int INF = INT_MAX;

signed main(){

    Nkumbo

    string greatings = "Good morning sir, please proceed to slot number ";
    string goodbye = "Sorry sir, no available slots";
    
    int n, q; cin >> n >> q;
    set<int> st;
    unordered_map<string, int> mp;

    for(int i=1; i <= n; i++) 
        st.insert(i);

    while(q--){
        string a, s;
        cin >> a >> s;

        if(a == "E"){
            if(!st.empty()){
                mp[s] = *st.begin();
                st.erase(st.begin());
                cout << greatings << mp[s] << endl;
            } else {
                cout << goodbye << endl;
            }
        } else {
            st.insert(mp[s]);
            mp.erase(s);
        }
    }
}