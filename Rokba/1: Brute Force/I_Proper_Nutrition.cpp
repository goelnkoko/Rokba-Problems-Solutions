#include <bits/stdc++.h>
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
#define endl '\n'
#define ll long long
#define all(x) x.begin(), x.end()
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }

using namespace std;

int main(){

    Nkumbo

    ll n, a, b;

    cin >> n >> a >> b;

    int x = 0, y = 0;
    bool ans = false;
    for(y=0; y*b <= n; y++){
        
        x = (n-y*b)/a;
        
        if(x * a == n-y*b){
            ans = true;
            break;
        }
    }

    if(ans) {
        cout << "YES\n" << x << " " << y << endl; 
    } else {
        cout << "NO" << endl;
    }
    
}