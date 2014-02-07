# include <iostream>
# include <iomanip>
# include <math.h>
# include "tests.h"

using namespace std;

void testPart2(){
	int *result = new(int);
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimes(v0, increment, iterations, result);
	cout << "v0: " << v0
	                << " increment: " << increment
	                << " iterations: " << iterations
	                << " result: " << *result << endl;
	

}

void incrementByValueNumTimes(int startValue, int increment, int numTimes, int *result){
	for (int i = 0; i < numTimes; i++){
		startValue += increment;
	}
	*result = startValue;
}

void swapNumbers(int *a, int *b){
	int *temp,i;
	temp = &i;
	*temp = *a;
	*a=*b;
	*b=*temp;
}

void testPart3(){
	int percentages[20] = {};
	printArray(percentages,20);
	randomizeArray(percentages,20);
	swapNumbers(&percentages[0],&percentages[1]);
	printArray(percentages,20);
	sortArray(percentages,20);
	printArray(percentages,20);
	int mid = medianOfArray(percentages,20);
	cout << "Median = " << mid << endl;
	return;
}

void printArray(int tabell[],int lengde){
	int i = 0;
	while (i < lengde){
		if (tabell[i] < 10){
			cout << "  ";
		}
		else if (tabell[i] >= 100){
			cout << "";
		}
		else{
			cout << " ";
		}
		cout << tabell[i] <<" ";	
		i++;	
	}
	cout << endl;
	return;
}

void randomizeArray(int tabell[], int lengde){
	for (int i = 0;i < lengde; i++){
		tabell[i] = randomWithLimits(100, 0);
	}
	printArray(tabell,20);
	return;
}

void sortArray(int tabell[], int lengde){
	int i = 0;
	while(i < lengde){
		for (int j = i+1;j < lengde; j++){
			if (tabell[j] < tabell[i]){
				swapNumbers(&tabell[j],&tabell[i]);
			}
		}
		i++;
	} 
}

int medianOfArray(int tabell[], int lengde){
	sortArray(tabell,lengde);
	int med;
	if (lengde%2==0){
		med = (tabell[lengde/2]+tabell[lengde/2+1])/2;
	}
	else{
		med = tabell[lengde/2];
	}
	return med;
}

void testPart4(){
	char svar;
	cout << "Vil du legge til karakterer selv? (Y/N) :";
	cin >> svar;
	char grades[41] = {};
	if (svar == 'Y' || svar == 'y'){
		cout << "Les inn gyldige karakterer, når ferdig med innlesning tast S. " << endl;
		readInputToCString(grades,'F','A', 40);
	}
	else if (svar == 'N'|| svar == 'n'){
		randomizeCString(grades,'F','A',40);
	}
	else{
		cout << "Les Teksten!!! " << endl;
		testPart4();
	}
		
	int antall = (sizeof(grades)/sizeof(*grades));
	
	int gradeCount[6] = {};
	for (int i = 0;i < 6; i++){
		gradeCount[i] += countOccurencesOfCharacter(grades, 65+i, antall);
	}
	cout << "  A   B   C   D   E   F" << endl;
	printArray(gradeCount,6);
	int value[] = {1,2,3,4,5,6};
	int summen = 0;
	double sumverdi = 0;
	for (int i = 0;i < 6; i++){
		summen += gradeCount[i];
		sumverdi += value[i]*gradeCount[i];
	}
	double snittverdi = sumverdi/summen;
	// cout << summen<< endl;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);	
	cout <<"Snittkarakteren din er : " << snittverdi << endl;
	return;
}

void randomizeCString(char tabell[],char upper, char lower, int antall){
	for (int i = 0;i < antall; i++){
		tabell[i] = randomCharWithLimits(lower,upper);
	}
	tabell[antall]='\0';
	return;
}

void readInputToCString(char tabel[], char upper, char lower, int antall){
	char kar[5]={};
	for (int i = 0;i < antall; i++){
		cout << "Skriv et symbol mellom " << lower << " og " << upper<< " :";
		cin >> kar;
		tabel[i] = kar[0];
		if (kar[0] == 'S'){
			return;
		}
		if (kar[1] != 0){
			cout << "Din dust! LES TEKSTEN!" << endl;
			i--;
		}
		if (kar[0] > upper || kar[0] < lower){
			cout << "Din dust! LES TEKSTEN!" << endl;
			i--;
		}
			
	}
}

int countOccurencesOfCharacter(char tabell[], char sym, int antall){
	int counter = 0;
	for (int i = 0;i < antall; i++){
		if (tabell[i] == sym){
			counter ++;
		}
	}
	return counter;
}