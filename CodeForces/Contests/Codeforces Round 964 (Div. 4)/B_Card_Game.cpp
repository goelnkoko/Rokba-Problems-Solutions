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
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        int x = 0;

        if(a1 > b1 && a2 > b2){
            x++;
        }
        if(a1 > b1 && a2 == b2){
            x++;
        }
        if(a1 == b1 && a2 > b2){
            x++;
        }

        if(a1 > b2 && a2 > b1){
            x++;
        }
        if(a1 > b2 && a2 == b1){
            x++;
        }
        if(a1 == b2 && a2 > b1){
            x++;
        }


        if(a2 > b1 && a1 > b2){
            x++;
        }
        if(a2 > b1 && a1 == b2){
            x++;
        }
        if(a2 == b1 && a1 > b2){
            x++;
        }


        if(a2 > b2 && a1 > b1){
            x++;
        }
        if(a2 > b2 && a1 == b1){
            x++;
        }
        if(a2 == b2 && a1 > b1){
            x++;
        }

        cout << x << endl;
    }

    return 0;
}