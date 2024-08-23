#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e9
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
        int n;
        cin >> n;

        map<int, int> a;
        for(int i=0; i < n; i++) {
            int aux;
            cin >> aux;
            a[aux]++;
        }
        int m = 0;
        for(auto i: a){
            m = max(i.s, m);
        }

        cout << n - m << endl;
    }

    return 0;
}


