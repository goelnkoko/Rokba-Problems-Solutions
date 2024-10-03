#include <bits/stdc++.h>
 
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long
#define ff first
#define ss second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 1e4+7;
const int MOD = 1e9+7;

signed main(){

    #ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	#endif

    int l, r; cin >> l >> r; 

    int n = ceil(log2(r));

    int pos = n;
    while(pos >= 0){
        if(((l >> pos) & 1) == 0 && ((r >> pos) & 1) == 1)
            break;
        pos--;
    }

     for(int i=pos-1; i >= 0; i--){
        if(((l >> i) & 1) == 0){
            l += (1LL << i);
        }

        if(((r >> i) & 1) == 1){
            r -= (1LL << i);
        }
    }

    int x = l ^ r;
    cout << x << endl;
    

}