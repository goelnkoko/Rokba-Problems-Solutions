#include <bits/stdc++.h>
#define MAX 200001
#define MOD 100000000
#define ll long long

using namespace std;


int main() {


    int n, k;
    cin >> n >> k;

    int tb[n];

    for(int i=0; i < n; i++){
        cin >> tb[i];
    }

    sort(tb, n+tb);

    int i = 0, j = n-1;

    while(k--){

        if((tb[j] - tb[i+1] > tb[j-1] - tb[i]) && i < j) {
            j--;
        } else {
            i++;
        }
    }

    cout << tb[j]-tb[i] << endl;
}