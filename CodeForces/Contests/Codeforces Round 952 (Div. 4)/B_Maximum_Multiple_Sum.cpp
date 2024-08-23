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

        ll n;
        cin >> n;

        ll m = 0, x = 0; 

        for(int i=2; i <= n; i++){
            ll sum = 0;
            ll j = 1;
            while(i*j <= n){
                sum += i*j;
                if(sum > m){
                    m = sum;
                    x = i;
                }
                j++;
            }
        }

        cout << x << endl;
    }

  return 0;
}