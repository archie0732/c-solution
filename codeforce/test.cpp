#include<iostream>
#define ll long long 

using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        ll x,y,k;
        cin>>x>>y>>k;
        ll ans = (x+k-1)/k;
        if((x+y)%k!=0){
            ans++;
        }
        cout<<ans<<endl;
    }
}