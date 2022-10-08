#include "StringData.h"
#include <iostream>
using namespace std;

int linear_search(vector<string> container, string element)
{
    for (int i = 0; i < container.size(); i++)
    {
        if (container[i] == element)
        {
            return i;
        }
    }

    return -1;
}

int binary_search(vector<string> container, string element)
{
    int l = 0;
    int r = container.size();
    int c = -1;

    while (l <= r)
    {
        c = (l + r) / 2;
        if (container[c] == element)
        {
            return c;
        }
        else if (element < container[c])
        {
            r = c - 1;
        }
        else
        {
            l = c + 1;
        }
    }
    return -1;
}

int main()
{
    vector<string> data = getStringData();

    cout << "Linear Search: 'not_here'\n";
    long long begin_time = systemTimeNanoseconds();
    cout << linear_search(data, "not_here") << "\n";
    long long end_time = systemTimeNanoseconds();
    cout << "Time: " << end_time - begin_time << "\n";

    cout << "Binary Search: 'not_here'\n";
    begin_time = systemTimeNanoseconds();
    cout << binary_search(data, "not_here") << "\n";
    end_time = systemTimeNanoseconds();
    cout << "Time: " << end_time - begin_time << "\n";

    cout << "Linear Search: 'mzzzz'\n";
    begin_time = systemTimeNanoseconds();
    cout << linear_search(data, "mzzzz") << "\n";
    end_time = systemTimeNanoseconds();
    cout << "Time: " << end_time - begin_time << "\n";

    cout << "Binary Search: 'mzzzz'\n";
    begin_time = systemTimeNanoseconds();
    cout << binary_search(data, "mzzzz") << "\n";
    end_time = systemTimeNanoseconds();
    cout << "Time: " << end_time - begin_time << "\n";

    cout << "Linear Search: 'aaaaa'\n";
    begin_time = systemTimeNanoseconds();
    cout << linear_search(data, "aaaaa") << "\n";
    end_time = systemTimeNanoseconds();
    cout << "Time: " << end_time - begin_time << "\n";

    cout << "Binary Search: 'aaaaa'\n";
    begin_time = systemTimeNanoseconds();
    cout << binary_search(data, "aaaaa") << "\n";
    end_time = systemTimeNanoseconds();
    cout << "Time: " << end_time - begin_time << "\n";
}