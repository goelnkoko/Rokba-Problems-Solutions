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

    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;
        cout << (a ^ b) << endl;
    }

    return 0;
}