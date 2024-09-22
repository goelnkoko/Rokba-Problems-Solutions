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

    ll t;
    cin >> t;

    vector<char> vw = {'n', 'a', 'r', 'e', 'k'};

    while(t--){
        int n, m; 
        cin >> n >> m;

        vector<string> narek(n);
        for(int i=0; i < n; i++){
            cin >> narek[i];
        }        

        vector<bool> opt(n, true); 

        int a = 0;
        ll nar = 0, chat = 0, score = 0;

        for(int i=0; i < n; i++){
            nar = 0; chat = 0; a = 0;
            for(int j=0; j < m; j++){
                if(narek[i][j] == vw[a]){
                    nar++;
                    a++; a %= 5;
                } else if(find(all(vw), narek[i][j]) != vw.end()) {
                    chat++;
                }
            }

            if(nar >= chat){
                score += (nar - chat);
            } else {
                opt[i] = false;
            }
        }

        a = 0;
        nar = 0, chat = 0;

        for(int i=0; i < n; i++){
                for(int j=0; j < m; j++){
                    if(narek[i][j] == vw[a]){
                        nar++;
                        a++; a %= 5;
                    } else if(find(all(vw), narek[i][j]) != vw.end()) {
                        chat++;
                    }
                }
            }
        }

        nar -= nar%5;
        chat += nar%5;
        ll score2 = nar - chat;
        ll s = max(score, score2);
        if(s > 0) cout << s << endl;
        else cout << 0 << endl;
    }
}

