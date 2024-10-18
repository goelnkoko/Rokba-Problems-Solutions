#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e6+10
#define ll long long
#define vll vector<ll> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

const int MOD = 1000000007;
vector<int> primes(MAX, 1);

void primos(int M){
primes[0] = primes[1] = 0;
for(int i=2; i*i <= M; i++){
    if(primes[i])
    for(int j = i*i; j <= M; j += i){
        primes[j] = 0;
    }
}

    for(int i=2; i <= M; i++)
        primes[i] += primes[i-1];
}

bool verify(int a, int b, int l, int k){
    for(int i = a; i <= b - l + 1; i++){
        if(primes[i+l-1] - primes[i-1] < k) return false;
    }
    return true;
}

int main() {
	
	ll a, b, k; 
    cin >> a >> b >> k;

    primos(b+10);

    int l = 1, r = b - a + 1;

    while(l <= r){
        int mid = l + (r-l)/2;

        bool v = verify(a, b, mid, k);

        if(v){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << (r >= (b - a + 1) ? -1:(r+1))  << endl;

    return 0;
}