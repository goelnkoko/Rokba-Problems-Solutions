#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define ll long long
#define f first 
#define s second 
#define endl '\n'

using namespace std;

int main() {
    Nkumbo

    ll n, q;
    cin >> n >> q;

    vector<pair<ll, ll>> a(n);
    vector<int> br_p(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    vector<pair<ll, ll>> b(all(a));
    sort(all(a));

    int c = 1;
    for (int i = 1; i < n; i++) {
        if (a[i].second < a[i - 1].second) {
            c++;
            br_p[i] = 1;
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        swap(b[x], b[y]);

        a[b[x].s].f = b[x].f;
        a[b[y].s].f = b[y].f;

        sort(all(a));

        c = 1;
        fill(all(br_p), 0);
        for (int i = 1; i < n; i++) {
            if (a[i].second < a[i - 1].second) {
                c++;
                br_p[i] = 1;
            }
        }

        cout << c << endl;
    }

    return 0;
}
