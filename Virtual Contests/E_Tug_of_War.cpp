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

void organize(vi& aux, deque<int>& d, int n){
    for(int i=0; i < n; i++){
        if(n % 2){
            if(i % 2 == 0)
                d.push_back(aux[i]);
            else 
                d.push_front(aux[i]);
        }
        else {
            if(i % 2 == 0)
                d.push_front(aux[i]);
            else 
                d.push_back(aux[i]);
        }
    }
}

signed main(){

    Nkumbo
    
    int n; cin >> n; 
    vi tb1(n), tb2(n);
    for(auto& i: tb1) cin >> i;
    for(auto& i: tb2) cin >> i;

    vi aux1(all(tb1)), aux2(all(tb2));

    sort(all(aux1));
    sort(all(aux2));

    deque<int> d1, d2;

    organize(aux1, d1, n);
    organize(aux2, d2, n);

    int c1, c2; c1 = c2 = 0;

    int j = 0;
    for(auto& i: d1) {
        if(i == tb1[j]) c1++;
        j++;
    }
    j = 0;
    for(auto& i: d2) {
        if(i == tb2[j]) c2++;
        j++;
    }

    if(c1 > c2) {
        cout << "Team A" << endl;
    } else if(c2 > c1){
        cout << "Team B" << endl;
    } else {
        cout << "Tie" << endl;
    }
}