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
	
	int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i < n; i++) cin >> a[i];

    vector<int> r;
    int c = 0;
    r.push_back(a[0]);
    for(int i=1; i < n; i++){
        if(__gcd(a[i], a[i-1]) != 1){
            r.push_back(1);
            c++;
        }
        r.push_back(a[i]);
    }

    cout << c << endl;
    for(int i =0; i < r.size(); i++) cout << r[i] << " ";
    cout << endl;
    
	return 0;
}