#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define vll vector<ll> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a/gcd(a, b)*b;
}

int main() {
	
	int n;
    cin >> n;

    vector<int> isPrime(n+1, 0);

    for(int i=2; i <= n; i++){
        if(!isPrime[i])
            for(int j=i+i; j <= n; j += i){
                isPrime[j]++;
            }
    }
    
    int c = 0;
    for(int i=0; i <= n; i++){
        if(isPrime[i] == 2) c++;
    }
    
    cout << c << endl;

	return 0;
}