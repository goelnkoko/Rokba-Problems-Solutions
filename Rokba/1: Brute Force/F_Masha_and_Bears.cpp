#include <bits/stdc++.h>
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
#define endl '\n'
#define ll long long

using namespace std;

int main(){

    Nkumbo

    int v1, v2, v3, v4; 
    cin >> v1 >> v2 >> v3 >> v4;

    if(2 * v3 < v4 || v4 >= v2 || v3 > 2*v4) cout << -1 << endl;
    else {
        cout << 2*v1 << "\n" << 2*v2 << "\n" << max(v3, v4) << endl;
    }
}