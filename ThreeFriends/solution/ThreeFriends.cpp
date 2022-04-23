#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <numeric>
#include <cstring>
#include <cmath>

using namespace std;

ifstream fin("13_sample.in");
ofstream fout("13_sample.ans");


int main()
{
    long long x;
    int k;
    long long arnold = 0, harmen = 0, andrea = 0;

    // reads number of games
    fin >> k;
    cout<<k<<endl;
    for (int i = 0; i < k; i++)
    {
        fin >> x;

        // we calculate how many picks of 21 were done
        long long picks = x / 21;

        // we calculate if there is a pick with less than 21 coins
        if (x % 21 != 0)
        {
            picks++;
        }

        picks %= 3;

        // we see who one the k-th game and we increase their winning counter
        switch (picks)
        {
        case 0:
            arnold++;
            break;
        case 1:
            harmen++;
            break;
        case 2:
            andrea++;
        }
    }

    // we print the name of the person with the most wins
    if (max(max(arnold, harmen), andrea) == arnold)
    {
        fout << "Arnold";

        if (arnold == harmen)
        {
            fout << endl
                 << "Harmen";
        }
        if (arnold == andrea)
        {
            fout << endl
                 << "Andrea";
        }

        return 0;
    }

    if (max(max(arnold, harmen), andrea) == harmen)
    {
        fout << "Harmen";

        if (harmen == arnold)
        {
            fout << endl
                 << "Arnold";
        }
        if (harmen == andrea)
        {
            fout << endl
                 << "Andrea";
        }
    }
    else
    {

        fout << "Andrea";

        if (andrea == arnold)
        {
            fout << endl
                 << "Arnold";
        }
        if (andrea == harmen)
        {
            fout << endl
                 << "Harmen";
        }
    }

    fin.close();
    fout.close();

    return 0;
}

/*

P.S

Don t forget that tc10 has two possible correct options.

*/