#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n; 
        cin >> n;

        int tb[2*n];
        for(auto& i: tb) cin >> i;

        int lo = -1, le = -1;
        vector<pii> ans;
        for(int i=0; i < 2*n; i++){
            if(tb[i] & 1){
                if(lo == -1)
                    lo = i;
                else {
                    ans.push_back({lo+1, i+1});
                    lo = -1;
                }
            } else {
                if(le == -1)
                    le = i;
                else {
                    ans.push_back({le+1, i+1});
                    le = -1;
                }
            }
        }

        for(int i=0; i < n-1; i++)
            cout << ans[i].ff << ' ' << ans[i].ss << endl;
        
    }

}