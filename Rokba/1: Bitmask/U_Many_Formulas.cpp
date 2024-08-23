#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 500
#define ll long long
#define vi vector<int> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

int main() {

    Nkumbo

    string s;
    cin >> s;

    ll n = s.size();
    ll pos = n-1;

    ll soma = 0;

    for(ll i=0; i < (1LL << pos); i++){
        
        ll a = 0;
        string res;
        res += s[0];

        for(ll j = 0; j < n-1; j++){
            if((i & (1 << j)) != 0){
                a += stoi(res);
                res = "";
            }
            res += s[j+1];
        }

        a += stoll(res);
        soma += a;
    }

    cout << soma << endl;

    return 0;
}


