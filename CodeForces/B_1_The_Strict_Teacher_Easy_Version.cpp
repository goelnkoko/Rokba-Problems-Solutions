#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 1001;

int main(){

    int t;
    cin >> t;

    char vw[5] = {'a', 'e', 'i', 'o', 'u'};

    while(t--){
        int n, m, q;
        cin >> n >> m >> q; 
        int pos[m];
        for(int i=0; i < m; i++){
            cin >> pos[i];
        }
        while(q--){
            int d;
            cin >> d;
            sort(pos, pos + m);
            if(d > pos[0] && d < pos[1]){
                int dist = pos[1] - pos[0] - 1;
                int res = dist/2 + dist%2; 
                cout << res << endl;
            } else if(d < pos[0] && d < pos[1]){
                cout << pos[0]-1 << endl;
            } else {
                cout << n - pos[1] << endl;
            }
        }
    }
}

