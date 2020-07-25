#include <iostream>
#include <map>
using namespace std;
//110变为011
uint32_t reverseBits(uint32_t n)
{
    uint32_t ret = 0, power = 31;
    while (n != 0)
    { //n&1提取最低位
        ret += (n & 1) << power;
        n >>= 1;
        power -= 1;
    }
    return ret;
}

uint32_t reverseByte(uint32_t byte, map<uint32_t, uint32_t> cache)
{
    if (cache.find(byte) != cache.end())
        return cache[byte];
    uint32_t value=(byte*0x0202020202 & 0x010884422010) % 1023;
    cache.emplace(byte, value);
    return value;
}

uint32_t reverseBits_1(uint32_t n)
{
    uint32_t ret = 0, power = 24;
    map<uint32_t, uint32_t> cache;
    while (n != 0)
    {
        ret += reverseByte(n & 0xff, cache) << power;
        n >>= 8;
        power -= 8;
    }
    return ret;
}

uint32_t reverseBits_2(uint32_t n)
{
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}

int main()
{
}