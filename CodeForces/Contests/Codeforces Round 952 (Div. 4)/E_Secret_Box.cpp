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

        ll a, b, c, k;
        cin >> a >> b >> c >> k;

        ll x[3];

        x[0] = cbrt(k);
        x[1] = sqrt(k/x[0]);
        x[2] = k/x[0]/x[1];

        if(x[0] * x[1] * x[2] != k){
            cout << 0 << endl;
            continue;
        }

        ll sum = 0, m = 0;
        for(int i=0; i < 3; i++){
            for(int j=0; j < 3; j++){
                for(int k=0; k < 3; k++){
                    if(i != j && i != k && j != k){
                        sum = (a-x[i]+1)*(b-x[j]+1)*(c-x[k]+1);
                        m = max(m, sum);
                    }
                }
            }
        }
        
        cout << m << endl;
    }

  return 0;
}