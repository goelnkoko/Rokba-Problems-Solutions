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

int main() {

    Nkumbo

    int t;
    cin >> t;

    while(t--){
        string s, t;
        cin >> s >> t;

        int j = 0, i = 0;
        while(j < t.size() && i < s.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            } else if(s[i] == '?') {
                s[i] = t[j];
                i++;
                j++;
            } else {
                i++;
            }
        }

        while(i < s.size()){
            if(s[i] == '?')
                s[i] = 'a';
            i++;
        }

        if(j == t.size()){
            cout << "YES" << endl; 
            cout << s << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}