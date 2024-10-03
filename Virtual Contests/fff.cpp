#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mk make_pair 
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long
#define ff first 
#define ss second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 501;
const int MOD = 1e9+7;
const int INF = INT_MAX;

bool isPossible(vi& tb, int total, int m, int k){
    int n = tb.size();

    int v = m * tb[n-1]; 
    int M = max(v, total);

    if(v < total){
        v = total + total%m;
    }

    if(v <= total + k){
        return true;
    } else {
        return false;
    }
}

signed main(){
    
    int a, b;
    cin >> a >> b;

    cout << (a/b) << endl;
}