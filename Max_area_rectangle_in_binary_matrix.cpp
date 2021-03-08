#include <bits/stdc++.h>
using namespace std;
int MAH(vector<int>a,int n)
    {
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
     
    return ar[n-1];
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    vector<int>v;
     for(int j=0;j<m;j++)
     v.push_back(a[0][j]);
     int mx=MAH(v,m);
     for(int i=1;i<n;i++){
          for(int j=0;j<m;j++){
               if(a[i][j]==0)
               v[j]=0;
               else
               v[j]=v[j]+a[i][j];
          }
          mx=max(mx,MAH(v,m));
     }
     cout<<mx<<endl;
    return 0;
}
/*
Ex.
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
Output :
8;
Input :
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
Step 1: 
0 1 1 0  maximum area  = 2
Step 2:
row 1  1 2 2 1  area = 4, maximum area becomes 4
row 2  2 3 3 2  area = 8, maximum area becomes 8
row 3  3 4 0 0  area = 6, maximum area remains 8

*/