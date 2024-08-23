#include <bits/stdc++.h>
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
#define endl '\n'
#define ll long long

using namespace std;

bool is_trinagle(int i, int j, int x) {
    
    int M = max({i, j, x});
    int m = min({i, j, x});
    int o = i + j + x - M - m;

    if (M < (m + o)) return true;
    else return false;
}

int main(){

    Nkumbo

    int n; 
    cin >> n;

    int c = 0;
    for(int i=1; i <= n-2; i++){
        for(int j=i+1; j <= n-1; j++){
            int x = i ^ j;
            if(x <= n && x != 0 && x > j) {
                if(is_trinagle(i, j, x)) c++;
            }
        }
    }

    cout << c << endl;
}