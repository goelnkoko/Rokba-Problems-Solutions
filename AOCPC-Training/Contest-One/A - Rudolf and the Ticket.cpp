#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    int n, m, k;

    while(t--) {

        cin >> n >> m >> k;

        int l[n], r[m];

        for(int i=0; i < n; i++){
            cin >> l[i];
        }

        for(int i=0; i < m; i++){
            cin >> r[i];
        }

        int c = 0;

        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++) {
                if(l[i] + r[j] <= k){
                    c++;
                }
            }
        }

        cout << c << endl;
    }
}