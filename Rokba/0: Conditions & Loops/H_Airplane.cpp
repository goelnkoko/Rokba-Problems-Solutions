#include <bits/stdc++.h>

using namespace std;

int main(){

    int p, q, r;
    cin >> p >> q >> r;

    int m = max(p, max(q, r));

    int sum = p + q + r;

    cout << sum - m << endl;

}