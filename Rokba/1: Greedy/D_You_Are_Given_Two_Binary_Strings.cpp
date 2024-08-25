#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll MAX = 5e9;

int main() {

    int t;
    cin >> t;

    while(t--){
        string x, y;
        cin >> x >> y;

        int py = 0, px = 0;
        for(int i=y.size()-1; i >= 0; i--)
            if(y[i] == '1') {
                py = y.size() - i - 1;
                break;
            }

        for(int i=x.size()-py-1; i >= 0; i--)
            if(x[i] == '1'){
                px = x.size() - i - 1;
                break;
            }

        cout << (px - py) << endl;
    }

    return 0;
}