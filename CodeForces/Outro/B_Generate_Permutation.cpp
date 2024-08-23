#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'

using namespace std;

int main() {

    Nkumbo

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        
        if(n & 1){
            for(int i=0; i < n/2; i++){
                cout << n-i << ' ' << i+1 << ' ';
            }
            cout << (n+1)/2 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
