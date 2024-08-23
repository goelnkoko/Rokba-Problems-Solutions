#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, x;
    cin >> n >> x;

    int d = -1;

    for(int i=1; i <= n; i++){
        int v, p;
        cin >> v >> p;

        if(x == 0){
            if(p > 0){
                d = i;
                x = -1;
            }
        }
        else if(d == -1){
            x -= v*p/100;
            if(x < 0) d = i; 
        }
    }

    cout << d << endl;
}