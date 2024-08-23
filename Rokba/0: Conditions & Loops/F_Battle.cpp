#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    float a,b,c,d;
    cin >> a >> b >> c >> d;

    int t = ceil(c/b);
    int ao = ceil(a/d);

    if(t <= ao){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}