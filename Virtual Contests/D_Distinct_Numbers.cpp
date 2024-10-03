#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mk make_pair 
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first 
#define ss second
#define int long long

using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 501;
const int MOD = 1e9+7;
const int INF = INT_MAX;

signed main(){

    Nkumbo

    int n; cin >> n; 

    map<int, int> aux;
    vector<int> d(n);
    for(int i=0; i < n; i++){
        cin >> d[i];
        aux[d[i]]++;
    }

    map<int, int> mp(all(aux));

    for(auto &i: aux){
        int x = i.ss - 1;
        while(x > 0){
            int temp = max(0LL, i.ff -1);
            if(aux[i.ff + 1] != 0){
                if(mp[i.ff + 1] - aux[i.ff + 1] > 0){
                    mp[temp]++;
                    mp[i.ff]--;
                } else {
                    mp[i.ff + 1]++;
                    mp[i.ff]--;
                }
            } else if(mp[temp] == 0LL){
                mp[temp]++;
                mp[i.ff]--;
            } else {
                mp[i.ff + 1]++;
                mp[i.ff]--;
            }
            x--;
        }
    }

    for(auto &i: mp){
        int x = i.ss - 1;

        if(aux[i.ff] > 0LL && x >= 1){
            int temp = max(0LL, i.ff -1);
            if(mp[temp] == 0LL){
                mp[temp]++;
                mp[i.ff]--;
            } else {
                mp[i.ff + 1]++;
                mp[i.ff]--;
            }
        }
    }

    cout << mp.size() << endl;
}