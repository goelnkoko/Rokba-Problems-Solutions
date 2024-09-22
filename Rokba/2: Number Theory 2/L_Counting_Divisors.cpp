#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define vi vector<int>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 1e6+10;


int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int c = 0;
        for(int j=1; j*j <= n; j++){
            if(n % j == 0){
                c++;
                if(n/j != j) c++;
            }
        }

        cout << c << endl;
    }
}

