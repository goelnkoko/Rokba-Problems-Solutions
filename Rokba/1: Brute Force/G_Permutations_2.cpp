#include <bits/stdc++.h>
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define all(x) x.begin(), x.end()
using namespace std;

vector<string> res;

int main(){

    Nkumbo

    int n, k, ans = INT_MAX;
    cin >> n >> k;

    vector<string> a(n);
    string r, s;

    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    for(int i=0; i < k; i++){
        s.append(to_string(i));
    }

    do {
        int m = INT_MAX, M = 0;

        for(int i=0; i < n; i++){
            r = "";
            for(int j=0; j < k; j++){
                r += (a[i][s[j] - '0']);
            }
            int p = stoi(r);
            m = min(m, p);
            M = max(M, p);
        }

        ans = min(ans, M-m);
    } while(next_permutation(all(s)));

    cout << ans << endl;
}