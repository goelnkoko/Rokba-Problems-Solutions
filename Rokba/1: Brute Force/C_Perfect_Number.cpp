#include <bits/stdc++.h>
#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
#define endl '\n'
#define ll long long

using namespace std;

int digitsum(int x){

    int sum = 0, i = 1;

    while(x > 0){
        sum += x%10;
        x /= 10;
    }

    return sum;
}

int main(){

    Nkumbo

    int n; 
    cin >> n;
    
    int c = 0, i = 0; 
    while(c < n){
        i++;
        if(digitsum(i) == 10){
            c++;
        }
    }
    
    cout << i << endl;

}