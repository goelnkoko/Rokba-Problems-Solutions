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

    ll n;
    cin >> n;

    vector<int> a(n);
    for(auto& i: a) cin >> i;

    for(auto& i: a){
        int m = INT_MAX;
        if(i != 0)
            for(int j=0; j <= 15; j++){
                int d = (i+j) & (-1*(i+j));
                d = log2(d);
                m = min(m, (15-d) + j);
            }
        else 
            m = 0;
        cout << m << " ";
    }
    cout << endl;

    return 0;
}


