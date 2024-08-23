#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define MAX 1e9
#define MOD 1000000007
#define ll long long

using namespace std;

int main() {

    Nkumbo

    ll n, t, p; 
    cin >> n >> t >> p;

    int a[n];

    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    int d = 0; 
    
    int c = 0;
    for(int i=0; i < n; i++){
        if(a[i] >= t) c++;
    }

    while(c < p){
        c = 0;
        
        for(int i=0; i < n; i++){
            a[i]++;
            if(a[i] > t) c++;
        }

        if(c < p) {
            d++;
        } else { 
            break;
        }
    }

    cout << d << endl;


    return 0;
}
