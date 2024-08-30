#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, b;
    cin >> n >> b;

    int c = 0;
    while(n > 0){
        n /= b;
        c++;
    }
    cout << c << endl;
}