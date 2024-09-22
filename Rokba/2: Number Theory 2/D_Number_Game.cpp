#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool isPrime(int n){
    for(int i=2; i*i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        bool r = (n == 1);

        if(n > 2 && n % 2 == 0){
            if((n & (n-1)) == 0) r = true;
            else if(n % 4 != 0 && isPrime(n/2)) r = true;
        }

        cout << (r ? "FastestFinger":"Ashishgup") << endl;
    }

}