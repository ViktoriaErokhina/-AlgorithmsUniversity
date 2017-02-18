#include <stdio.h>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	freopen("kth.in", "w", stdout);

	srand(time(NULL));
	int n = rand() % 100;
	cout << n << " " << (rand() % n) + 1 << endl;
	cout << rand() << " " << rand() << " " << rand() << " " << rand() 
		<< " " << rand() << endl;
	
	return 0;
}