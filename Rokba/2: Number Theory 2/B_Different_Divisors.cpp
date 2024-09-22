#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;

const int MAX = 22010;

vector<ll> dif(MAX, 0);

void init(){

    vector<bool> prime(MAX, true);

    for(int i=2; i*i < MAX; i++){
        if(prime[i])
            for(int j=i*i; j < MAX; j += i){
                prime[j] = false;
            }
    }

    vector<int> primos;
    for(int i=2; i < MAX; i++) 
        if(prime[i]) primos.push_back(i);
    
    for(int i=1; i < MAX; i++){
        ll x = *lower_bound(all(primos), i + 1);
        ll y = *lower_bound(all(primos), x + i);
        dif[i] = x * y;
    }    
}


int main(){

    int q;
    cin >> q;

    init();

    while(q--){
        int a;
        cin >> a;

        cout << dif[a] << endl;
    }



}