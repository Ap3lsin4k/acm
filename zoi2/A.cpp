#include <bits/stdc++.h>

using namespace std;

int main()
{
  long t;
    cin>>t;
     for(int k=0;k<t;++k)
     {
         long n,dn;
         cin>>n;
         vector<long> tmp(n,0),count;
         vector<vector<long>> a(n,tmp),b(n,tmp);
         for(long i=0;i<n;++i)
           {
            for(long j=0;j<n;++j)
              {
                 cin>>a[i][j];
              }
           }

         for(long i=0;i<n;++i)
           {
            for(long j=0;j<n;++j)
              {
                 cin>>b[i][j];
              }
           }
        dn=n*2-1;
        for(long i=1;i<=int(dn/2)+1;++i)
        {
            count.push_back(i);
        }
        for(long i=int(dn/2);i>=1;--i)
        {
            count.push_back(i);
        }

        vector<set<long>> s;
          for(long i=0;i<n*2;++i)
            {
              set<long> tmp;
               for(long j=0;j<=i;j++)
               {
                    long f=i-j;
                    if(f<n && j<n )
                    {
                        tmp.insert(a[j][f]);
                        tmp.insert(b[j][f]);
                    }
               }
                s.push_back(tmp);
            }
          long c=0;
         for(long i=0;i<s.size()-1;++i)
         {
               c+=s[i].size()^count[i];
         }
         if(c>0)
         {
             cout<<"No"<<endl;
         }else
         {
             cout<<"Yes"<<endl;
         }
     }
}
