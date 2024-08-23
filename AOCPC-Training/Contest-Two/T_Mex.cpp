#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define MAX 1e9
#define MOD 100000000
#define ll long long


using namespace std;

int main() {

    Nkumbo

    int n;
    cin >> n;

    set<int> a;

    for(int i=0; i < n; i++){
        int x; 
        cin >> x;
        a.insert(x);
    }

    int i = 0;
    while(a.find(i) != a.end()){
        i++;
    }

    cout << i << endl;

    return 0;
}