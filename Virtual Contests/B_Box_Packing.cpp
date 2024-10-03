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

    int n, k; cin >> n >> k;
    
    vector<int> tb[3];

    for(int j=0; j < 3; j++)
        for(int i=0; i < n; i++){
            int a; cin >> a; 
            tb[j].push_back(a);
        }

    int area = 0;

    for(int i=0; i < n; i++){
        int r = 1;
        for(int j=0; j < 3; j++){
            r *= (tb[j][i] - 2*k);
        }
        area += r;
    }

    cout << area << endl;
}