#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> a(n);

    for(auto& i: a) cin >> i;

    int l = 0;

    int pizza[360];
    memset(pizza, 0, sizeof(pizza));

    for(int i=0; i < n; i++){
        l = (l + a[i])%360;
        pizza[l] = 1;
    }

    int c = 1, m = 1;
    pizza[0] = 1;
    for(int i=0; i < 360; i++){
        if(pizza[i] == 1){
            m = max(c, m);
            c = 0;
        }
        c++;
    }

    cout << max(m, c) << endl;
}