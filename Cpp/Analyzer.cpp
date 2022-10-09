#include "StringData.h"
#include <iostream>
using namespace std;

// Linear search algorithm, a simple for loop that iterates over all elements of the given vector
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
/*
    Binary search algorithm, while the center, or c, value is not equal to the target,
    the left and right bounds of the search are adjusted
*/
int binary_search(vector<string> container, string element)
{
    // Left, right, and center values respectively
    int l = 0;
    int r = container.size();
    int c = -1;
    // While the left bound actually stays to the left of the right bounds, or less than...
    while (l <= r)
    {
        c = (l + r) / 2;                    // C, or center, is set to the average value between the left and right bounds
        if (container[c] == element)
        {
            return c;                       // If the center value is equal to the target, then return the center value
        }
        else if (element < container[c])    // If the element is less than the center, then the right bounds is adjusted to the old center
        {
            r = c - 1;
        }
        else                                // If otherwhise, then the left bounds is adjusted to the old center
        {
            l = c + 1;
        }
    }
    return -1;
}

int main()
{
    vector<string> data = getStringData();              // The sample dataset is exported from the header file
    /*
        The respective search is performed and the time taken is printed
    */
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