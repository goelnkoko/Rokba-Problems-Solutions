#include <bits/stdc++.h>
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL);
#define f first
#define s second
#define ll long long

using namespace std;

int main(){

    Nkumbo

    int t, a, b;
    cin >> t;

    while(t--){

        cin >> a >> b;

        if(b >= a -1)
            cout << 1 << endl;
        else 
            cout << a << endl;
    }

}