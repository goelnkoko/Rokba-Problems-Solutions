#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 1e6+10;

vector<int> phi(MAX);

void sieve(){
    for(int i=0; i < MAX; i++){
        phi[i] = i;
    }
    for(int i=2; i < MAX; i++){
        if(phi[i] == i)
            for(int j=i; j < MAX; j+= i){
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
    }
}

int main(){

    ll t;
    cin >> t;

    sieve();

    while(t--){
        int n; cin >> n; 
        cout << phi[n] << endl;
    }
}

