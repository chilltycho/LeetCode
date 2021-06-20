/*
给字符串path，表示绝对路径，转化为更简洁的规范路径。
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string simplifyPath(string path)
{
    stringstream is(path);         // 转换为输入流
    vector<string> strs;
    string res = "", temp = "";
    while (getline(is, temp, '/')) // getline从给定输入流获取数据
    {
        if (temp == "" || temp == ".")
            continue;
        else if (temp == ".." && !strs.empty())
            strs.pop_back();
        else if (temp != "..")
            strs.push_back(temp);
    }
    for (string str : strs)
        res += "/" + str;
    if (res.empty())
        return "/";
    return res;
}

int main()
{
    //cout << simplifyPath("/a/.b/../../c/") << endl;
    auto ms{"/home/jjjj"};
    stringstream is(ms);
    string tmp{};
    while (getline(is, tmp, '/'))
        cout << tmp;
}