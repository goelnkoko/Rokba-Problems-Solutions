#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL);
#define endl '\n'
#define vi vector<int>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 400005;
const int MOD = 1e9+7;

int main() {

    Nkumbo

    ll n, m, q, r, c;
    cin >> n >> m >> q;

    ll total = n * m;

    set<int> row[n+1];
    set<int> col[m+1];
    vector<vi> tb(n+1, vi(m+1, true));

    for(int i=0; i <= n; i++)
        for(int j=0; j <= m; j++){
            row[i].insert(j);
            col[j].insert(i);
        }

    while (q--) {
        cin >> r >> c;

        if(tb[r][c]){
            tb[r][c] = false;
            row[r].erase(c);
            col[c].erase(r);
            total--;
        } else {
            auto itcr = row[r].lower_bound(c);
            auto itrd = col[c].lower_bound(r);

            int ru, rd, cl, cr;

            auto itcl = itcr; itcl--;
            auto itru = itrd; itru--;

            if(itcr != row[r].end()){
                cr = *itcr;

                tb[r][cr] = false;
                row[r].erase(cr);
                col[cr].erase(r);
                total--;
            }

            if(itcl != row[r].begin()){
                cl = *itcl;

                tb[r][cl] = false;
                row[r].erase(cl);
                col[cl].erase(r);
                total--;
            }

            if(itrd != col[c].end()){
                rd = *itrd;

                tb[rd][c] = false;
                row[rd].erase(c);
                col[c].erase(rd);
                total--;
            }

            if(itru != col[c].begin()){
                ru = *itru;

                tb[ru][c] = false;
                row[ru].erase(c);
                col[c].erase(ru);
                total--;
            }
        }
    }

    cout << total << endl;
    return 0;
}