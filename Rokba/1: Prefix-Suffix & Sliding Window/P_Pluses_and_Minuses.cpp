#include <bits/stdc++.h> 

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

const int MAX = 1e6+7;
const int MOD = 1e9+7;
const int INF = 1e12;

signed main(){
    Nkumbo

    #ifndef ONLINE_JUDGE
    freopen("dis.in", "r", stdin);
    freopen("dis.out", "w", stdout);
    #endif

    int n; cin >> n; 

    string s;
    for(int i=0; i < n; i++){
        cin >> s;

        int tam = s.size(); 

        vi px(tam);
        px[0] = s[0] == '+' ? 1:-1;

        for(int i=1; i < tam; i++)
            if(s[i] == '+') px[i] = px[i-1] + 1;
            else px[i] = px[i-1] - 1;
        
        int res = tam, pos = 0;
        for(int x = 0; x < tam; x++){
            if(pos + px[x] < 0) res += (x + 1), pos++;
        }

        cout << res << endl;
    }

}
