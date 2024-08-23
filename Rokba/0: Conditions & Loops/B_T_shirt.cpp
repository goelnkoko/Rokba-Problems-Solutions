#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    double a, b, c, x;
    cin >> a >> b >> c >> x; 

    double r = 0;

    if(x <= a) 
        r = 1;
    else if(x > a && x <= b){
        r = c / (b - a);
        if(r > 1) r = 1;
    } else {
        r = 0;
    }

    cout << setprecision(12) << fixed << endl;
    cout << r << endl;
}