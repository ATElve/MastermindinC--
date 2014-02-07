# include <iostream>
# include <iomanip>
# include <math.h>
# include "utilities.h"
using namespace std;

int randomWithLimits(int upper, int lower){
	int upper2 = upper;
	int rn = (rand()%upper2)+lower;
	return rn;
}

char randomCharWithLimits(char lower, char upper){
	char mid = upper - lower+1;
	char rn = (rand()%mid)+lower;
	return rn;
}

// 2a)
// v0 = 25;
	
