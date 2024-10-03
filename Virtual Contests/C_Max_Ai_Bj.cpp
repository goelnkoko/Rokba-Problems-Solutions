#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mk make_pair 
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first 
#define ss second
#define int long long
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 501;
const int MOD = 1e9+7;
const int INF = INT_MAX;

signed main(){

    Nkumbo
    
    int n; cin >> n; 
    vector<int> a(n);
    vector<int> b(n);

    int A = INT_MIN;
    int B = INT_MIN;

    for(int i=0; i < n; i++){
        cin >> a[i];
        A = max(A, a[i]);
    }
    
    for(int i=0; i < n; i++){
        cin >> b[i];
        B = max(B, b[i]);
    }

    int res = A + B;
    cout << res << endl;
}