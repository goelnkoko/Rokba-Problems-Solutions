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

int n; 
vvi resp;
vi tb(5), used;
vector<char> subset = {'+', '-', '*'}, perm;
bool ans = false;

int calc(int a, int b, char op){
    if(op == '+') return a+b;
    else if(op == '-') return a-b;
    else if(op == '*') return a*b;
    else return 0;
}

void backt(){

    if(perm.size() == 4) {
        vector<char> temp(all(perm));
        int a = calc(tb[0], tb[1], perm[0]);
        int b = calc(a, tb[2], perm[1]);
        int c = calc(b, tb[3], perm[2]);
        int r = calc(c, tb[4], perm[3]);
        if(r == 23) ans = true;
        return;
    }

    for(int i=0; i < 3; i++){
        perm.push_back(subset[i]);
        backt();
        perm.pop_back();
    }
}

signed main(){
	Nkumbo

    #ifndef ONLINE_JUDGE
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
    #endif

    while(true){
        int c = 0;
        for(int i=0; i < 5; i++) {
            cin >> tb[i];
            if(tb[i] == 0) c++;
        }

        sort(all(tb));
        if(c == 5) break;

        ans = false;

        do {
            backt();
            if(ans) break;
        } while(next_permutation(all(tb)));

        if(ans) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }

}
