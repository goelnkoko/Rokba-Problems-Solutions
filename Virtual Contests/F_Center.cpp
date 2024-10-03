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

const int MAX = 1e6;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

long double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


signed main(){
    Nkumbo

    int n; 
    cin >> n;

    vector<pii> a(n);
    pii lo = {0, 0};
    double d = 0;

    for(int i=0; i < n; i++){
        cin >> a[i].ff >> a[i].ss;
        
        long double c = dist(a[i].ff, a[i].ss, 0, 0);
        if(c > d){
            d = c;
            lo.first = a[i].ff; 
            lo.second = a[i].ss;
        }
    }

    pii sl = {0, 0};
    d = 0;
    for(int i=0; i < n; i++){
        long double c = dist(a[i].ff, a[i].ss, lo.first, lo.second);

        if(c > d){
            d = c;
            sl.first = a[i].ff;
            sl.second = a[i].ss;
        }       
    }

    long double dl = 0;

    for(int i=0; i < n; i++){
        long double x = abs(a[i].ff - a[i].ss) / sqrt(2);
        if(x > dl){
            dl = x;
        }
    }

    cout << setprecision(12) << fixed << endl;

    if(d/2 > dl){
        cout << d/2 << endl;
    }
    else {
        cout << dl << endl;
    }
}
