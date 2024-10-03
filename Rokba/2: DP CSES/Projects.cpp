#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int> 
#define ld long double
#define int long long
#define ff first 
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e6;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

struct project {
    int s;
    int e;
    int v;
    bool operator<(const project &other) const {
        return e < other.e;
    }
};

signed main(){

    int n; cin >> n;

    vector<project> pro(n);

    for(int i=0; i < n; i++){
        cin >> pro[i].s >> pro[i].e >> pro[i].v;
    }

    sort(all(pro));
    set<pii> ends;
    ends.insert({0, 0});
    ll ans = 0;

    for(int i=0; i < n; i++){
        auto it = ends.lower_bound({pro[i].s, -1});
        it--;
        ans = max(ans, pro[i].v + it->second);
        ends.insert({pro[i].e, ans});
    }

    cout << ans;

}