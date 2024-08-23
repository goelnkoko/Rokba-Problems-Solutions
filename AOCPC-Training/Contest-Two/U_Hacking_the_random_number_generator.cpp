#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define MAX 1e9
#define MOD 100000000
#define ll long long


using namespace std;

int main() {

    Nkumbo

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int c = 0;

    for(int i=0; i < n; i++){
        if(binary_search(a.begin(), a.end(), a[i]+k)) {
            c++;
        }
    }

    cout << c << endl;

    return 0;
}