#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = INT_MAX;

int main() {

    Nkumbo

    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for(auto& i: s) cin >> i;

    int total = 0;

    for(int i=0; i < (1 << h); i++){
        for(int j=0; j < (1 << w); j++){

            vector<string> temp(all(s));
            
            for(int u = 0; u < h; u++){
                for(int v = 0; v < w; v++){
                    if((j & (1 << v)) || (i & (1 << u))){
                        temp[u][v] = '*';
                    }
                }
            }

            int c = 0;
            for(int u=0; u < h; u++){
                for(int v = 0; v < w; v++){
                    if(temp[u][v] == '#') c++;
                }
            }
            if(c == k) total++;
        }
    }

    cout << total << endl;
    
    return 0;
}