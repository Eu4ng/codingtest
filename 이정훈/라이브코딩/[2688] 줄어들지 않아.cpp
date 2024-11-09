#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// count(n, v) 결과에 대한 캐싱 작업 필요

int cal(int n);
int count(int n, int v);

int main()
{
    // 입력 처리
    int t;
    cin >> t;

    vector<int> container;
    container.reserve(t);

    for(int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;

        container.push_back(n);
    }

    for(int e : container)
    {
        int count = cal(e);
        cout << count << endl;
    }

    return 0;
}

int cal(int n)
{
    int result = 0;

    for(int i = 0; i <= 9; ++i)
    {
        result += count(n, i);
    }

    return result;
}

int count(int n, int v)
{
    int result = 0;

    if(n == 2)
    {
       result = 10 - v;
    }
    else
    {
        for(int i = v; i <= 9; ++i)
        {
            result += count(n - 1, i);
        }
    }

    return result;
}