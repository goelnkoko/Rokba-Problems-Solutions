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
        int n; cin >> n;

        int cada = n/5;
        int rep = n%5;

        int a = 0;
        for(int i=0; i < 5;  i++){
            for(int j=0; j < cada; j++){
                cout << vw[a];
            }
            if(rep){
                cout << vw[a];
                rep--;
            }
            a++;
        }

        cout << endl;
    }
}

