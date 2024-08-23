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

    int t;
    cin >> t;

    while(t--){
        int l, n;
        cin >> l >> n;
        vector<int> a(n);
        for(auto& i: a) cin >> i;
        int mask = (1 << n)-1;
        bool ans = false;
        for(int s=mask; s ; s=(s-1)&mask){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(s & (1 << j)){
                    sum += a[j];
                }
            }

            if(sum == l) {ans = true; break;}
        }
        if(l == 0) ans = true;

        cout << (ans ? "YES":"NO") << endl;
    }

    return 0;
}


