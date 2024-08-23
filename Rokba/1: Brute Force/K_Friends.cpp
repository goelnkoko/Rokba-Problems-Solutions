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

int main() {

    Nkumbo

    int n; 
    cin >> n;

    vector<int> a[6];

    for(int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;

        a[x].push_back(y);
        a[y].push_back(x);
    }
    bool ans = false;

    for(int i=1; i <= 5; i++){
        if(a[i].size() >= 3){
            ans = true;
        }
        if(a[i].size() <= 1){
            ans = true;
        }
    }

    cout << (ans ? "WIN":"FAIL") << endl;

    return 0;
}

