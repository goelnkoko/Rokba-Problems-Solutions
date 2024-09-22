#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;

signed main(){

    int t, n; 
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>a(n);
        for(int i = 0; i <n; ++i){
            cin>>a[i];
        }
        sort(all(a));
        int m = a.size()/2 + a.size()%2 -1;
        if(m == 0){
            if(a[m] == a[m+1]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            int sm, eq, gr; sm = eq = gr = 0;
            for(int i=0; i < n; i++){
                if(a[i] > a[m]) gr++;
                else if(a[i] == a[m]) eq++;
                else sm++;
            }
            if(eq > 1 && (gr + eq -1) != sm) cout<<"YES"<<endl;
            else  cout<<"NO"<<endl;
        } 
         
    }
}