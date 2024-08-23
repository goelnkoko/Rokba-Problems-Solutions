#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    int sum = 0;

    for(int i=0; i < 4*n-1; i++){
        int a; 
        cin >> a;

        sum += a;
    }

    int sum2 = ((1 + n)*n)/2;

    sum2 *= 4;
    cout << sum2 - sum << endl;
}