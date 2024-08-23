#include <bits/stdc++.h>


using namespace std;

int main(){

    int a, b; 
    cin >> a >> b;

    double d = sqrt(a*a + b*b); 

    double x = a/d; 
    double y = b/d;

    cout << setprecision(12) << fixed << endl;
    cout << x << " " << y << endl;
}