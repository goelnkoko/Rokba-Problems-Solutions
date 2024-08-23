#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define ll long long

using namespace std;

int main(){
    fast;

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<ll> a(n), ps(n+1, 0), pf(n+1);

        for(int i=0; i < n; i++){
            cin >> a[i];
        }

        ps[0] = pf[0] = a[0];
        for(int i=1; i < n; i++){
            ps[i] = ps[i-1] + a[i];
            pf[i] = max(pf[i-1], a[i]);
        }

        ll c = 0;
        if(a[0] == 0) c = 1;
        for(int i=1; i < n; i++){
            if(ps[i]-pf[i] == pf[i]){
                c++;
            }
        }
    
        cout << c << endl;
    }

  return 0;
}