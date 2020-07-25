//计数问题 使用 unordered_map
#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    unordered_map<string,string> u=
    {
        {"RED","#FF0000"},
        {"GREEN","#00FF00"},
        {"BLACK","#0000FF"}
    };

    for(const auto &n:u)
     cout<<"Key: "<<n.first<<" Value: "<<n.second<<'\n';
    
    u["BLACK"]="#000000";
    u["WHITE"]="#FFFFFF";

    cout<<"RED: "<<u["RED"]<<endl;
    cout<<"BLACK: "<<u["BLACK"]<<endl;
}