#include <bits/stdc++.h> 

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define ff first 
#define ss second
#define vi vector<int> 
#define vvi vector<vector<int>>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAX = 1e7;
const int MOD = 1e9+7;
const int INF = 1e18;

signed main(){
	Nkumbo

    #ifndef ONLINE_JUDGE
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
    #endif

    vi subset = {1, 2, 3, 4, 5, 6, 7};

    do {
        for(const int& j: subset)
            cout << j << ' ';
        cout << endl;
    } while(next_permutation(all(subset)));

    int fact = 1;
    int n; cin >> n;
    for(int i=1; i <= n; i++){
        fact *= i;
    }
    cout << fact << endl;
}
