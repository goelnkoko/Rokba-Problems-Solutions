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

using namespace std;

int main() {

    Nkumbo

    ll t;
    cin >> t;

    while(t--){

        int n;
        string s; 
        cin >> n >> s;

        map<char, int> mp;
        for(int i=0; i < s.size(); i++){
            if(s[i] != '?')   
                mp[s[i]]++;
        }

        int c = 0;

        for(auto i: mp){
            c += min(i.second, n);
        }

        cout << c << endl;

    }

    return 0;
}