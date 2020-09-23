#include <iostream>
using namespace std;
void viorotate(int *a, int n, int r)
{
    r = r % n;
    for (int i = 0; i < r; i++)
    {
        int temp = a[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            a[j] = a[j - 1];
        }
        a[0] = temp;
    }
}

void rotate_1(int *a, int n, int r)
{
    //r = r % n;
    int count = 0;//每个元素移动一次，等于数组长度时，换位完成
    for (int start = 0; count < n; start++)
    {
        int current = start;
        int prev = a[start];
        do
        {
            int next = (current + r) % n;

            int temp = a[next];
            a[next] = prev;
            prev = temp;
            
            current = next;
            count++;
        } while (start != current);
        cout<<"fff"<<endl;
        for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
        cout<<"fff"<<endl;
    }
}


void reverse(int *a, int i, int j)
{
    int mid = (i + j) / 2;
    for (int k = 0; i <= mid; i++, k++)
    {
        int temp = a[i];
        a[i] = a[j - k];
        a[j - k] = temp;
    }
}
void rotate_2(int *a, int n, int r)
{
    r = r % n;
    reverse(a, 0, n - r - 1);
    reverse(a, n - r, n - 1);
    reverse(a, 0, n - 1);
}

int main()
{
    int a[]{1, 2, 3, 4,5,6};
    rotate_1(a, 6, 2);
    for (int c : a)
        cout << c << ' ';
    cout << endl;
}