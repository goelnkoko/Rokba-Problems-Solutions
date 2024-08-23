#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    bool tb[n+1];
    
    memset(tb, 0, (n+1) * sizeof(bool));

    for(int i=0; i < n; i++) {
        int a;
        cin >> a;

        tb[a] = true;
    }

    for(int i=1; i <= n; i++){
        if(!tb[i]){
            cout << i << endl;
            return 0;
        }
    }
}