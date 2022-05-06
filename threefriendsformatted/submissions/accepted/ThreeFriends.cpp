#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <numeric>
#include <cstring>
#include <cmath>

using namespace std;

//ifstream fin("13_sample.in");
//ofstream fout("13_sample.ans");

int main()
{
	long long x;
	int k;
	long long arnold = 0, harmen = 0, andrea = 0;

	// reads number of games
	cin >> k;
	//cout << k << endl;
	for (int i = 0; i < k; i++)
	{
		cin >> x;

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
	if (max(max(arnold, harmen), andrea) == andrea)
	{
		cout << "Andrea";

	/*	if (arnold == harmen)
		{
			cout << endl
				<< "Harmen";
		}
		if (arnold == andrea)
		{
			cout << endl
				<< "Andrea";
		}
	*/

		return 0;
	}

	if (max(max(arnold, harmen), andrea) == arnold)
	{
		cout << "Arnold";
	
		/*
		if (harmen == arnold)
		{
			cout << endl
				<< "Arnold";
		}
		if (harmen == andrea)
		{
			cout << endl
				<< "Andrea";
		}
		*/
	}
	else
	{

		cout << "Harmen";

		/*
		if (andrea == arnold)
		{
			cout << endl
				<< "Arnold";
		}
		if (andrea == harmen)
		{
			cout << endl
				<< "Harmen";
		}
		*/
		
	}

	//fin.close();
	//fout.close();

	return 0;
}
