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
    stack<int>s;
    vector<int>v;
    for (int i = 0; i <n; i++)
    {
       if(s.size()==0)
       v.push_back(-1);
       else if(s.size()>0&&s.top()>a[i])
       v.push_back(s.top());
       else if (s.size()>0&&s.top()<=a[i])
       {
           while(s.size()>0&&s.top()<=a[i])
           {
               s.pop();
           }
           if(s.size()==0)
            v.push_back(-1);
            else
            v.push_back(s.top());
       }
       s.push(a[i]);
       
     }
    //reverse(v.begin(),v.end());
    for (int i = 0; i <n; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
