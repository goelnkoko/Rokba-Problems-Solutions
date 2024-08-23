#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define MAX 1e9
#define MOD 100000000
#define ll long long


using namespace std;

int main() {

    Nkumbo

    ll w, a, b;

    cin >> w >> a >> b;

    ll fa = a+w, fb = b+w;

    if(w >= abs(b-a))
        cout << 0 << endl;
    else {

        ll d = 0;
        if(b > a)
            d = b-a-w;
        else 
            d = a-b-w;

        cout << d << endl;
    }

    return 0;
}