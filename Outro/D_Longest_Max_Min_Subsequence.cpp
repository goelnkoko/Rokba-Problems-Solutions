#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define endl '\n'
#define vi vector<int>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 1000 + 20;
const int MOD = 1000000007;

int main(){
    Nkumbo

    int t;
    cin >> t;

    while(t--){
        int n; cin >> n;
        vi a(n);
        map<int, int> mp;
        for(int i=0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;
        } 

        int tam = mp.size();
        vector<int> sol(tam, -1);
        int j = 0;
        for(int i=0; i < n; i++){
            if(j != 0) mp[sol[j-1]] = 0;
            if(mp[a[i]] == 0) continue;
            else mp[a[i]]--;

            if(sol[j] == -1) {sol[j] = a[i]; continue;}

            if(mp[a[i]] == 0){
                if(j%2 == 0 && a[i] >= sol[j]) sol[j] = a[i];
                else if(j%2 == 1 && a[i] <= sol[j]) sol[j] = a[i];
                else {j++; sol[j] = a[i]; mp[sol[j-1]] = 0;}
            }

            if(a[i] > sol[j] && j % 2 == 0) sol[j] = a[i];
            if(a[i] < sol[j] && j % 2 == 1) sol[j] = a[i];

            if(mp[a[i]] == 0) j++;
        }

        cout << tam << endl;
        for(auto i: sol) cout << i << ' '; cout << endl;
    }
}