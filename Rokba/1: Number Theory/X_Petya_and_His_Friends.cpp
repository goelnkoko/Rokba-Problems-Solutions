#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 500
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

    if(n == 2) cout << -1 << endl;
    else {
        cout << 6 << '\n' << 10 << '\n' << 15 << endl;
        for(int i=1; i <= n-3; i++)
            cout << 30 * i << endl;
    }

    return 0;
}