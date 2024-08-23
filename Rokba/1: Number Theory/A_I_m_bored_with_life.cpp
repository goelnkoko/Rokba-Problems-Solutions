#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define endl '\n'
#define f first 
#define s second

using namespace std;

ll fact(ll m) {
    ll sum = 1;
    for(int i=1; i <= m; i++){
        sum *= i;
    }
    return sum;
}

int main() {

    Nkumbo

    ll a, b;
    cin >> a >> b;

    ll m = min(a, b);

    cout << fact(m) << endl;
    return 0;
}