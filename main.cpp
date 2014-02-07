# include <iostream>
# include <iomanip>
# include <math.h>
# include <time.h>
# include <unistd.h>
# include "utilities.h"
# include "utilities.cpp"
# include "tests.h"
# include "tests.cpp"
# include "playMastermind.h"
# include "playMastermind.cpp"


using namespace std;

int main(){
	srand( time(0));
	int valg;
	cout << "\n" << "Velg funksjon:" << endl;
	cout << "  0)  Avslutt" << endl;
	cout << "  1)  Utilities" << endl;
	cout << "  2)  Test Part 2" << endl;
	cout << "  3)  Test Part 3" << endl;
	cout << "  4)  Test Part 4" << endl;
	cout << "  5)  Play mastermind" << endl;
	cout << "Angi valg (0 - 5): ";
	cin >> valg;
	cout << endl;
	if (valg == 0){
		return 0;
	}
	else if (valg == 1){
		int zz = randomWithLimits(10,1);
		cout << "Random Number = " << zz << endl;
		char z = randomCharWithLimits('A','F');
		cout << "Random Char = " << z << endl;
		usleep(600*1000);
		main();
	}
	else if (valg == 2){
		testPart2();
		int i=5,j=10;
		cout<<"Before swapping I = "<<i<<" J = "<<j<<endl;
		swapNumbers(&i,&j);
		cout<<"After swapping I = "<<i<<" J = "<<j<<endl;
		usleep(600*1000);
		main();
	}
	else if (valg == 3){
		testPart3();
		usleep(600*1000);
		main();
	}
	else if (valg == 4){
		testPart4();
		usleep(600*1000);
		main();
	}
	else if (valg == 5){
		playMastermind();
		usleep(600*1000);
		main();
	}
	else{
		cout << "Du har gjort et ulovlig valg. Prøv på nytt!" << endl;
		usleep(600*1000);
		main();
	}
}