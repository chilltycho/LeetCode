//判断字符串是否表示数值
#include <iostream>
#include <cassert>
#include <unordered_map>
using namespace std;
/*状态：1.起始的空格 2.符号位 3.整数部分 4.左侧有整数的小数点 5.左侧无整数的小数点 
    6.小数部分 7.符号e 8.指数部分符号位 9.指数部分的整数部分 10.末尾空格
*/
enum State
{
    STATE_INITIAL,
    STATE_INT_SIGN,
    STATE_INTEGER,
    STATE_POINT,
    STATE_POINT_WITHOUT_INT,
    STATE_FRACTION,
    STATE_EXP,
    STATE_EXP_SIGN,
    STATE_EXP_NUMBER,
    STATE_END,
};
enum CharType
{
    CHAR_NUMEBR,
    CHAR_EXP,
    CHAR_POINT,
    CHAR_SIGN,
    CHAR_SPACE,
    CHAR_ILLEGAL,
};

CharType toCharType(char ch)
{
    if (ch >= '0' && ch <= '9')
        return CHAR_NUMEBR;
    else if (ch == 'e' || ch == 'E')
        return CHAR_EXP;
    else if (ch == '.')
        return CHAR_POINT;
    else if (ch == '+' || ch == '-')
        return CHAR_SIGN;
    else if (ch == ' ')
        return CHAR_SPACE;
    else
        return CHAR_ILLEGAL;
}
bool isNumber(string s)
{ //每个状态后面可以接什么字符到达什么状态？
    unordered_map<State, unordered_map<CharType, State>> transfer{
        {STATE_INITIAL,
         {
             {CHAR_SPACE, STATE_INITIAL},
             {CHAR_NUMEBR, STATE_INTEGER},
             {CHAR_POINT, STATE_POINT_WITHOUT_INT},
             {CHAR_SIGN, STATE_INT_SIGN},
         }},
        {STATE_INT_SIGN,
         {
             {CHAR_NUMEBR, STATE_INTEGER},
             {CHAR_POINT, STATE_POINT_WITHOUT_INT},
         }},
        {STATE_INTEGER,
         {
             {CHAR_NUMEBR, STATE_INTEGER},
             {CHAR_EXP, STATE_EXP},
             {CHAR_POINT, STATE_POINT},
             {CHAR_SPACE, STATE_END},
         }},
        {STATE_POINT,
         {
             {CHAR_NUMEBR, STATE_FRACTION},
             {CHAR_EXP, STATE_EXP},
             {CHAR_SPACE, STATE_END},
         }},
        {STATE_POINT_WITHOUT_INT,
         {
             {CHAR_NUMEBR, STATE_FRACTION},
         }},
        {STATE_FRACTION,
         {
             {CHAR_NUMEBR, STATE_FRACTION},
             {CHAR_EXP, STATE_EXP},
             {CHAR_SPACE, STATE_END},
         }},
        {STATE_EXP,
         {
             {CHAR_NUMEBR, STATE_EXP_NUMBER},
             {CHAR_SIGN, STATE_EXP_SIGN},
         }},
        {STATE_EXP_SIGN,
         {{CHAR_NUMEBR, STATE_EXP_NUMBER}}},
        {STATE_EXP_NUMBER,
         {
             {CHAR_NUMEBR, STATE_EXP_NUMBER},
             {CHAR_SPACE, STATE_END},
         }},
        {STATE_END,
         {
             {CHAR_SPACE, STATE_END},
         }},
    };
    int len = s.length();
    State st = STATE_INITIAL;//初始状态
    for (int i = 0; i < len; i++)
    {
        CharType typ = toCharType(s[i]);
        if (transfer[st].find(typ) == transfer[st].end())
            return false;
        else
            st = transfer[st][typ];
    }
    //可以以这些状态结尾
    return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION 
    || st == STATE_END || st == STATE_EXP_NUMBER;
}

int main()
{
    assert(isNumber("+100"));
    assert(isNumber("5e2"));
    assert(isNumber("-123"));
    assert(isNumber("3.1416"));
    assert(isNumber("-1E-16"));
    assert(isNumber("0123"));
    assert(!isNumber("12e"));
    assert(!isNumber("1a3.14"));
    assert(!isNumber("+-5"));
    assert(!isNumber("12e+5.4"));
}