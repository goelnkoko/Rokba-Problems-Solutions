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

int main() {
	
	int n;
    cin >> n;

    vector<int> a(n);
    vector<int> div(MAX, 0);
    int m = 0;
    for(int i=0; i < n; i++) {
        cin >> a[i];
        m = max(m, a[i]);    
    }
    sort(all(a));

    for(int i=0; i < n; i++){
        for(int j=a[i]; j <= m; j += a[i]){
            div[j]++;
        }   
    }

    int c = 0;
    for(int i=0; i < n; i++){
        if(div[a[i]] < 2) c++;
    }

    cout << c << endl;
    
	return 0;
}