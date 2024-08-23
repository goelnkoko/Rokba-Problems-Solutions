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

    vector<int> a(n), res(n, -1);

    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    map<int, int> back;

    for(int i=n-1; i >=0; i--){
        
        auto lb = back.upper_bound(a[i]);

        while(lb != back.end()){
            res[lb->second] = i;
            lb = back.erase(lb);
        }

        back[a[i]] = i;
    }

    for(int i=0; i < n; i++){
        cout << res[i]+1 << " ";
    }
    cout << endl;

    return 0;
}