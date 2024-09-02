#include <bits/stdc++.h>
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<ll> 
#define endl '\n'
using namespace std;
using ll = long long;

ll max_experience(int N, const vi& A) {
    vi dp(N + 1, 0);
    vi last_odd(N + 1, 0);
    vi last_even(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        // Option 1: Don't defeat this monster
        dp[i] = dp[i-1];
        
        // Option 2: Defeat as odd-numbered
        ll odd_exp = A[i-1] + dp[i-1];
        if (odd_exp > dp[i]) {
            dp[i] = odd_exp;
            last_odd[i] = i;
        } else {
            last_odd[i] = last_odd[i-1];
        }

        // Option 3: Defeat as even-numbered
        if (last_odd[i-1] > 0) {
            ll even_exp = 2 * A[i-1] + dp[last_odd[i-1] - 1];
            if (even_exp > dp[i]) {
                dp[i] = even_exp;
                last_even[i] = i;
            } else {
                last_even[i] = last_even[i-1];
            }
        } else {
            last_even[i] = last_even[i-1];
        }
    }

    return dp[N];
}

int main() {
    Nkumbo
    int N;
    cin >> N;
    vi A(N);
    for (auto& x : A) cin >> x;
    
    cout << max_experience(N, A) << endl;
    return 0;
}