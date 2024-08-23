#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 1000 + 20;

vector<int> p(MAX, -1);

inline int ask(int p, int q){
    cout << "? " << p + 1 << " " << q + 1 << endl;  
    int ans;
    cin >> ans;
    return ans - 1; 
}

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) p[i] = -1; 

        for(int i = 1; i < n; i++){  
            int pai = 0;  
            while(true){
                int ans = ask(i, pai);
                if(ans == i) break;
                pai = ans;
            }
            p[i] = pai;
        }
        
        cout << "! ";
        for(int i = 1; i < n; i++){
            cout << p[i] + 1 << ' ' << i + 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}