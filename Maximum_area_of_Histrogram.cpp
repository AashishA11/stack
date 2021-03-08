#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    stack<pair<int,int>>s;
    stack<pair<int,int>>s1;
    vector<int>vl;
    vector<int>vr;
    int pi=-1;
    for (int i = 0; i<n; i++)
    {
       if(s.size()==0)
       vl.push_back(pi);
       else if((s.size()>0)&&s.top().first<a[i])
       vl.push_back(s.top().second);
       else if (s.size()>0&&s.top().first>=a[i])
       {
           while(s.size()>0&&s.top().first>=a[i])
           {
               s.pop();
           }
           if(s.size()==0)
            vl.push_back(pi);
            else
            vl.push_back(s.top().second);
       }
       s.push({a[i],i});
     }
    //reverse(v.begin(),v.end());
    /*for (int i = 0; i <n; i++)
    {
        cout<<vl[i]<<" ";
    }*/
    int pl=n;
    for (int i = n-1; i>=0; i--)
    {
       if(s1.size()==0)
       vr.push_back(pl);
       else if((s1.size()>0)&&s1.top().first<a[i])
       vr.push_back(s1.top().second);
       else if (s1.size()>0&&s1.top().first>=a[i])
       {
           while(s1.size()>0&&s1.top().first>=a[i])
           {
               s1.pop();
           }
           if(s1.size()==0)
            vr.push_back(pl);
            else
            vr.push_back(s1.top().second);
       }
       s1.push({a[i],i});
     }
    reverse(vr.begin(),vr.end());
    int w[n];
    int ar[n];
    for (int i = 0; i <n; i++)
    {
        w[i]=vr[i]-vl[i]-1;
    }
    for (int i = 0; i <n; i++)
    {
        ar[i]=a[i]*w[i];
    }
    sort(ar,ar+n);
    cout<<ar[n-1]<<endl;
    return 0;
}
