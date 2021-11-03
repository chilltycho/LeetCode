#include <bits/stdc++.h>
using namespace std;
class String
{
private:
    char *data;
    size_t length;
    
public:
    String(const char *str = nullptr)
    {
        if (!str)
        {
            length = 0;
            data = new char[1];
            *data = '\0';
        }
        else
        {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        }
    }

    String(const String &str)
    {
        length = str.size();
        data = new char[length + 1];
        strcpy(data, str.data);
    }

    ~String()
    {
        delete[] data;
        data = nullptr;
        length = 0;
    }

    friend String operator+(const String &lhs, const String &rhs)
    {
        String res;
        res.length = lhs.length + rhs.length;
        delete[] res.data;
        res.data = new char[res.length + 1];
        strcpy(res.data, lhs.data);
        strcat(res.data, rhs.data);
        return res;
    }

    String &operator=(const String &str)
    {
        if (this == &str)
            return *this;
        delete[] data;
        length = str.length;
        data = new char[length + 1];
        strcpy(data, str.data);
        return *this;
    }

    String &operator+=(const String &str)
    {
        length += str.length;
        char *newData = new char[length + 1];
        strcpy(newData, data);
        strcat(newData, str.data);
        delete[] data;
        data = newData;
        return *this;
    }

    bool operator==(const String &str) const
    {
        return strcmp(data, str.data) == 0;
    }
    
    char &operator[](size_t n) const
    {
        if (n >= length)
            throw out_of_range("operator [] out of range!");
        return data[n];
    }
    
    size_t size() const
    {
        return length;
    }
    
    const char *c_str() const
    {
        return data;
    }
    
    friend istream &operator>>(istream &is, String &str)
    {
        delete[] str.data;
        char tmp[1000];
        is >> tmp;
        str.length = strlen(tmp);
        str.data = new char[str.size() + 1];
        strcpy(str.data, tmp);
        return is;
    }
    
    friend ostream &operator<<(ostream &os, String &str)
    {
        os << str.data;
        return os;
    }
};

int main()
{
    String s{"fff"};
    cout << s << ": " << s.size() << endl;
    char a[] = "Hello", b[] = "World";
    String s1(a);
    String s2(b);
    String s3;
    s3 = s1 + s2;
    String s4;
    s4 += s1 = s2;
    //cin >> s2;
    cout << s1 << " + " << s2 << " = " << s3 << endl;
    cout << s4 << endl;
}