#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define ll long long

using namespace std;

int main(){
    fast;

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<string> s(n);
        ll h = 0, M = 0;
        for(int i=0; i < n; i++){
            cin >> s[i];

            int c = 0; 
            for(int j=0; j < m; j++){
                if(s[i][j] == '#'){
                    c++;
                }
            }

            if(c > M){
                M = c;
                h = i;
            }
        }

        ll k = M / 2 + 1, c = 0;

        for(int i=0; i < m; i++){
            if(s[h][i] == '#'){
                c++;
            }
            if(c == k){
                k = i;
                break;
            }
        }

        cout << (h+1) << " " << (k+1) << endl;
    }

  return 0;
}