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

    int n; 
    cin >> n;

    if(n%2 == 0 && n > 2) cout << 2 << endl;
    else if(isPrime(n)) cout << 1 << endl;
    else if(isPrime(n-2)) cout << 2 << endl;
    else cout << 3 << endl;
}