#include<iostream>
using namespace std;

int sol(int *s,int n)
{
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]>s[i-1])
            res+=s[i]-s[i-1];
    }
    return res;
}
int main()
{
    int s[]{7,1,5,3,6,4};
    int re=sol(s,6);
    cout<<re<<endl;
}