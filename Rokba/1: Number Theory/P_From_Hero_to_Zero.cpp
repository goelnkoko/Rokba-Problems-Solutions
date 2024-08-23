#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define ll long long
#define vll vector<ll> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

const int MOD = 1000000007;

int main() {
	
	int t;
    cin >> t;

    while(t--){

        ll n, k;
        cin >> n >> k;

        int c = 0;
        while(n > 0){
            if(n % k == 0){
                c++;
                n /= k;
            } else {
                c += (n%k);
                n -= (n%k);
            }
        }

        cout << c << endl;
    }
    
	return 0;
}