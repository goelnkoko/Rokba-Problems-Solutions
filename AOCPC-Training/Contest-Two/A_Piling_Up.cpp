#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define MAX 1e9
#define MOD 1000000007
#define ll long long

using namespace std;

int main() {

    Nkumbo

    ll n; 
    cin >> n;

    if (n < 100) {
        cout << 100 - n << endl;
    }
    else if (n < 200) {
        cout << 200 - n << endl;
    }
    else if (n < 300) {
        cout << 300 - n << endl;
    }

    return 0;
}
