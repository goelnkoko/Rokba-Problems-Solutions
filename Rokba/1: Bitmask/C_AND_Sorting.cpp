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
        vector<int> a(n);
        for(auto& i: a) cin >> i;

        int sum = (1 << 32) - 1;
        for(int i=0; i < n; i++){
            if(i != a[i]) 
                sum &= a[i];
        }

        cout << sum << endl;
    }

    return 0;
}


