#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1e14
#define MOD 100000000
#define ll long long
#define llmp map<ll, ll> mp
#define vi vector<int>
#define endl '\n'
#define f first 
#define s second

using namespace std;

void solve(){


}

int main() {

    Nkumbo
    
    int n;
    string s;
    cin >> n >> s;

    set<char> st(all(s));
    map<char, int> mp;

    int l = 0, res = n, c = 0;
    
    for(int i=0; i < n; i++){
        if(mp[s[i]] == 0){
            c++;
        }
        mp[s[i]]++;

        while(c == st.size()){
            res = min(res, i-l+1);
            mp[s[l]]--;
            if(mp[s[l]] == 0){
                c--;
            }
            l++;
        }
    }

    cout << res << endl;

    return 0;
}