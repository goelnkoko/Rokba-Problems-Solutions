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

    int t, n;
    while(cin >> t >> n && t != 0){
        set<vector<int>> sol;
        vector<int> a(n);
        for(auto& i: a) cin >> i;
        sort(all(a), desc);
        
        for(int i=0; i < (1 << n); i++){
            int sum = 0;
            vector<int> aux;
            for(int j=0; j < n; j++){
                if(i & (1 << j)){
                    sum += a[j];
                    aux.push_back(a[j]);
                }
            }
            if(sum == t){
                sol.insert(aux);
            }
        }

        cout << "Sums of " << t << ":\n";
        if(sol.empty()) cout << "NONE" << endl;
        else 
        for(auto i = sol.rbegin(); i != sol.rend(); i++){
            bool f = true;
            for(auto j: *i){
                if(!f) cout << "+";
                cout << j;
                f = false; 
            }
            cout << endl;
        }
        
    }

    return 0;
}


