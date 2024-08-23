#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    int tb[n];

    int sum = 0;

    for(int i=0; i < n-1; i++){
        cin >> tb[i];
        sum += tb[i];
    }

    cout << -1 * sum  << endl;

    

}