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

    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& i: a) cin >> i;

    int m = 0;

    for(int i=1; i < (1 << n); i++){
        int last = -1, c = 0;
        for(int j=0; j < n; j++){
            if((i & (1 << j)) && a[j] > last){
                c++;
                last = a[j];
            }
        }
        m = max(c, m);
    }

    cout << m << endl;

    return 0;
}


