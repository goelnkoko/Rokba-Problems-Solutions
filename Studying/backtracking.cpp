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
vi subset;

void search(int k){
    if(k == n){
        resp.push_back(subset);
        return;
    } 

    search(k+1);
    subset.push_back(k+1);
    search(k+1);
    subset.pop_back();
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

    search(0);

    sort(all(resp), comp);

    for(auto i: resp){
        for(auto j: i){
            cout << j << ' ';
        }
        cout << endl;
    }
}
