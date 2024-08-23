#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    int n;
    cin >> n;

    ll s = 0;
    for(int i=0; i <=n; i++){
        if(!(i % 3 == 0 || i % 5 == 0)){
            s += i;
        }
    }

    cout << s << endl;
}