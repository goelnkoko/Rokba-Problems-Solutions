#include <bits/stdc++.h>
#define MAX 200001

using namespace std;

int digitsum (int n) {

    int sum = 0;

    string s = to_string(n);

    for(int j=0; j < s.size(); j++){
        sum += s[j] - '0';
    }

    return sum;
}

int main() {

    int t, n; 
    cin >> t;

    int tb[MAX];

    tb[0] = 0;
    for(int i=1; i < MAX; i++){
        tb[i] = tb[i-1] + digitsum(i);
    }

    while(t--) {
        cin >> n;

        cout << tb[n] << endl;
    }
}