#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e9
#define ll long long
#define vi vector<int> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

int main() {

    Nkumbo

    ll n, m;

    while(cin >> m >> n){

        vector<int> a(n), sol;
        int ssum = 0;
        for(int& i: a) cin >> i;

        for(int i=0; i < (1 << n); i++){
            int sum = 0;
            vector<int> res;
            for(int j=0; j < n; j++){
                if((i & (1 << j)) != 0){
                    sum += a[j];
                    res.push_back(a[j]);
                }
            }
            if(sum <= m && sum >= ssum) {
                ssum = sum;
                sol = res;
            }
        }
        
        for(auto i: sol) cout << i << ' ';
        cout << "sum:" << ssum << endl;
    }

    return 0;
}


