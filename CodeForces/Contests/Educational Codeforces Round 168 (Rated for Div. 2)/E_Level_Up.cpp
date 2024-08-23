#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200005;

int n, q;
int monsters[MAX_N];
int fights_prefix[MAX_N];
int level_up[MAX_N];

void precompute() {
    fights_prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        fights_prefix[i] = fights_prefix[i-1] + (monsters[i] >= i/10 + 1);
    }
    
    for (int i = 1; i <= n; i++) {
        level_up[i] = i/10 + 1;
    }
}

string solve_query(int i, int x) {
    int fights = fights_prefix[i-1];
    int level = fights / x + 1;
    return (monsters[i] >= level) ? "YES" : "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> monsters[i];
    }

    precompute();

    while (q--) {
        int i, x;
        cin >> i >> x;
        cout << solve_query(i, x) << "\n";
    }

    return 0;
}