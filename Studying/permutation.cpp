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
vi tb, perm, used;

void search(){

    if(perm.size() == n){
        resp.push_back(perm);
        return;
    } 

    for(int i=0; i < n; i++){
        if(used[i]) continue;
        used[i] = 1;
        perm.push_back(i+1);
        search();
        used[i] = 0;
        perm.pop_back();
    }
}

bool comp(const vi& a, const vi& b){
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

signed main(){
	Nkumbo

    #ifndef ONLINE_JUDGE
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
    #endif

	cin >> n; 

    used.assign(n, 0);
    search();

    // sort(all(resp), comp);

    for(auto i: resp){
        for(auto j: i){
            cout << j << ' ';
        }
        cout << endl;
    }
}
