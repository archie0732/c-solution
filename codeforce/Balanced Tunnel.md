# Balanced Tunnel

```cpp
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
 
{
    int n;
    cin>>n;
    int ar[n+2];
    for(int i=0;i<n;i++)cin>>ar[i];
    vector<int>v;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        while(mp[v[v.size()-1]]!=0 && v.size()>0)
        {
            v.pop_back();
        }
        if(v[v.size()-1]!=ar[i])ans++;
        mp[ar[i]]=1;
    }
    cout<<ans<<endl;
 
}
```
