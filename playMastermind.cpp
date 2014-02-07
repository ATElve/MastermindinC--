# include <iostream>
# include <iomanip>
# include <math.h>



void playMastermind(){
	cout << "MASTERMIND \n \n " << endl;
	const int SIZE = 4, LETTERS = 6;
	char code[SIZE+1], guess[SIZE+1], guesses[12*SIZE+1];
	code[SIZE] ='\0';
	guess[SIZE]='\0';
	randomizeCString(code,'A'+LETTERS-1, 'A', SIZE);
	int counter = 0;
	// char guesses[12*SIZE+1]={};
	guesses[12*SIZE] ='\0';
	int answers[24]={};
	char ssvar;
	cout << "Vil du få oppgitt koden? (Y/N) :";
	cin >> ssvar;
	if (ssvar == 'Y' || ssvar == 'y'){
		cout << code << endl;
	}
	while ( counter < 12){
		cout << "\n Forsøk : " << counter+1 << endl;
		// cout << code << endl;
		readInputToCString(guess,'A'+LETTERS-1,'A', SIZE);
		// cout << guess << endl;
		int svarte = checkCharactersAndPosition(code, guess, SIZE);
		// cout << "Svarte : "<< svarte << endl;
		int hvite = checkCharacters(code, guess, SIZE)-svarte;
		// cout << "Hvite : "<< hvite << endl;
		printMastermind(guesses,answers,guess, svarte, hvite, counter, SIZE);
		if (svarte == SIZE){
			cout << "HURRA DU VANT!" << endl;
			cout << "Koden var : " << code << endl;
			char svar;
			cout << "Vil du spille en gang til? (Y/N) :";
			cin >> svar;
			if (svar == 'Y' || svar == 'y'){
				playMastermind();
			}
			return;
		}
		counter++;
	}
	cout << "Du er ikke god nok " << endl;
	cout << "Koden var : " << code << endl;
	char svar;
	cout << "Vil du spille en gang til? (Y/N) :";
	cin >> svar;
	if (svar == 'Y'){
		playMastermind();
	}
	return;
}

int checkCharactersAndPosition(char code[], char guess[], int SIZE){
	int svarte = 0;
	for (int i = 0;i < SIZE; i++){
		if (code[i] == guess[i]){
			svarte++;
		}
	}
	return svarte;
}

int checkCharacters(char code[], char guess[], int SIZE){
	char guess2[SIZE+1];
	for (int i = 0;i < SIZE+1; i++){
		guess2[i] = guess[i];
	}
	int hvite = 0;
	for (int i = 0;i < SIZE; i++){
		for (int j = 0;j < SIZE; j++){
			if (code[i] == guess2[j]){
				hvite++;
				guess2[j]='a';
				j = SIZE;
			}
		}
	}
	return hvite;
}

void printMastermind(char guesses[], int answers[], char guess[], int svarte, int hvite, int counter, int SIZE){
	for (int i = 0;i < SIZE; i++){
		guesses[counter*SIZE+i] = guess[i];
	}
	answers[counter*2+0]=svarte;
	answers[counter*2+1]=hvite;
	cout << "\nSå langt har du spilt: " << endl;
	cout << "____________________________" << endl;
	for (int i = 0;i < counter+1; i++){
		if (i < 9){
			cout << " ";
		}
		cout << i+1 << ". | ";
		for (int j = 0; j <SIZE; j++){
			if (guesses[i*SIZE+j] == 'A'){
				cout << "\033[1;31mA \033[m" << "";
			}
			else if (guesses[i*SIZE+j] == 'B'){
				cout << "\033[1;33mB \033[m" << "";
			}
			else if (guesses[i*SIZE+j] == 'C'){
				cout << "\033[1;34mC \033[m" << "";
			}
			else if (guesses[i*SIZE+j] == 'D'){
				cout << "\033[1;35mD \033[m" << "";
			}
			else if (guesses[i*SIZE+j] == 'E'){
				cout << "\033[1;36mE \033[m" << "";
			}
			else if (guesses[i*SIZE+j] == 'F'){
				cout << "\033[1;32mF \033[m" << "";
			}
			else{
				cout << guesses[i*SIZE+j]<< " ";
			}
		}
		cout << " | H: " <<answers[i*2+1] << " S: " <<answers[i*2] << " |"  << endl;
	}
	cout << "----------------------------" << endl;
}