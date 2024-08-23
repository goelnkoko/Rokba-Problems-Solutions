#include <bits/stdc++.h>

using namespace std;

int main(){

    int a, b, x=0, y=0;

    for(int i=0; i < 3; i++){
        cin >> a >> b;
        x = x ^ a;
        y = y ^ b;
    }
    
    cout << x << " " << y << endl;
}