#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 1e9
#define MOD 100000000
#define ll long long

using namespace std;

bool compareBySecond(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {

    Nkumbo

    int n;
    cin >> n;

    vector<pair<int, int>> mov;

    for(int i=0; i < n; i++){
        int a, b;
        cin >> a >> b;

        mov.push_back({a, b});
    }

    sort(mov.begin(), mov.end(), compareBySecond);

    int c = 0; 
    int f = 0;

    for(int i=0; i < mov.size(); i++) {
        if(mov[i].first >= f) {
            c++;
            f = mov[i].second;
        }
    }

    cout << c << endl;

    return 0;
}