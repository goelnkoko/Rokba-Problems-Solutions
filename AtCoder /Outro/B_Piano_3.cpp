#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main(){

    Nkumbo

    bool fl = true, fr = true;
    int t; 
    cin >> t;

    int fat = 0;
    int al, ar;

    while(t--){
        int k;
        char h;
        cin >> k >> h;

        if(h == 'L'){
            if(fl){
                al = k;
                fl = !fl;
            } else {
                fat += abs(k - al);
                al = k;
            }
        }
        if(h == 'R'){
            if(fr){
                ar = k;
                fr = !fr;
            } else {
                fat += abs(k - ar);
                ar = k;
            }
        }
    }

    cout << fat << endl;
}