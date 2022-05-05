#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <numeric>
#include <cstring>
#include <cmath>

using namespace std;

//ifstream fin("./data/19_sample.in");
//ofstream fout("./data/19_sample.ans");

string solveIt(long long first, long long second, long long third, long long s0, long long s1, long long s2, long long s3)
{
    long long extra = 0;

    if (first + second < third)
    {
        extra = extra + (third - (first + second));
    }
    else
    {
        if (second + third < first)
        {
            extra = extra + (first - (third + second));
        }
        else
        {
            if (third + first < second)
            {
                extra = extra + (second - (first + third));
            }
        }
    }

    if (extra == 0 && (first + second + third) % 2 == 1)
    {
        extra++;
    }

    if (extra + s0 <= s2 + s3)
    {
        return "yes\n";
    }
    else
    {
        return "no\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    // reading the difficulties
    long long dif1, dif2, dif3;

    cin >> dif1 >> dif2 >> dif3;

    long long students;

    long long s0 = 0, s1 = 0, s2 = 0, s3 = 0;

    long long val1, val2, val3;

    long long first = 0, second = 0, third = 0;

    cin >> students;

    for (long long i = 0; i < students; i++)
    {

        int count = 0;

        // reading the knwoledge level and counting how many problems they can solve    
        cin >> val1 >> val2 >> val3;

        if (val1 >= dif1)
        {
            count++;
        }

        if (val2 >= dif2)
        {
            count++;
        }

        if (val3 >= dif3)
        {
            count++;
        }


        // counting the number of people that can solve 0,1,2,3 problems
        switch (count)
        {
        case 0:
            s0++;
            break;
        case 1:
            // for these people, we count which problem exactly they can solve
            s1++;
            if (val1 >= dif1)
            {
                first++;
            }

            if (val2 >= dif2)
            {
                second++;
            }

            if (val3 >= dif3)
            {
                third++;
            }
            break;
        case 2:
            s2++;
            break;
        case 3:
            s3++;
            break;
        }
    }

    if (s1 + s0 <= s2 + s3)
    {
        cout << "yes\n";
    }
    else
    {
        // solving the problem + the edge cases
        cout << solveIt(first, second, third, s0, s1, s2, s3);
    }


    return 0;
}
