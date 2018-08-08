#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

typedef vector <string> Colors;
typedef vector <int> Output;

struct Line {
	int iter;
	Colors colors; 
	Output output;
};

void printHeader() {
	cout << string(80, '*') << endl;
	cout << string(17, '*') << "  MASTERMIND,  version 1.00  by Dario Marvin  " << string(17, '*') <<endl;
	cout << string(80, '*') << endl << endl;
}

void printColors(Colors c) {
	for (unsigned int i = 0; i < c.size(); i++) {
		if 				(c[i] == "red" || c[i] == "r") cout << "\033[1;31m\u25CF \033[0m";
		else if 	(c[i] == "green" || c[i] == "g") cout << "\033[1;32m\u25CF \033[0m";
		else if 	(c[i] == "black" || c[i] == "bla") cout << "\033[1;30m\u25CF \033[0m";
		else if 	(c[i] == "white" || c[i] == "w") cout << "\033[1;37m\u25CF \033[0m";
		else if 	(c[i] == "blue" || c[i] == "blu") cout << "\033[1;34m\u25CF \033[0m";
		else if 	(c[i] == "yellow" || c[i] == "y") cout << "\033[1;33m\u25CF \033[0m";
		else if 	(c[i] == "brown" || c[i] == "br") cout << "\033[22;33m\u25CF \033[0m";
		else if 	(c[i] == "magenta" || c[i] == "m") cout << "\033[1;35m\u25CF \033[0m";
	}
}

void printOutput(Output o) {
	for (unsigned int i = 0; i < o.size(); i++) {
		if (o[i] == 1) cout << "\u2B21 ";
		else if (o[i] == 2) cout << "\u2B22 ";
	}
}

void printLine(Line l) {
	cout << string(27, ' ') << l.iter; (l.iter < 10) ? cout << ":  " : cout << ": "; printColors(l.colors); cout << " | "; printOutput(l.output); cout << endl;
}

bool checkIfInColors(string a, Colors b) {
	for (unsigned int j(0); j<b.size(); j++) 
		if (a == b[j]) return true;
	return false;	
}

void destroyRepetitions(Colors& c) {
	c.erase(unique(c.begin(), c.end()), c.end());
}

Output checkColors(Colors guess, Colors solution) {
	Colors usedColors;
	Output output;
	for (unsigned int i = 0; i < guess.size(); i++) {
		if (!checkIfInColors(guess[i],usedColors) && guess[i]==solution[i]) {
			output.push_back(1);
			usedColors.push_back(guess[i]); 
			destroyRepetitions(usedColors);
		}
		for (unsigned int j = 0; j < solution.size(); j++) {
			if (!checkIfInColors(guess[i],usedColors) && guess[i]==solution[j] && i!=j) {
				output.push_back(2);
				usedColors.push_back(guess[i]); 
				destroyRepetitions(usedColors);
			}
		}
	}
	sort(output.begin(),output.end());
	return output;
}  

Colors getFiveRandomColors() {
	Colors colors;
	colors.push_back("red");colors.push_back("green");colors.push_back("blue");
	colors.push_back("yellow");colors.push_back("white");colors.push_back("black");
	colors.push_back("magenta");colors.push_back("brown");
	
	srand (time(NULL));
	random_shuffle(colors.begin(), colors.end());
	colors.pop_back();
	colors.pop_back();
	colors.pop_back();
	
	return colors;
}

Colors askFiveColors() {
	Colors colors;
	string s;
	cout << "Choose 5 colors between \033[1;31mred\033[0m, \033[1;32mgreen\033[0m, \033[1;34mblue\033[0m, \033[1;33myellow\033[0m, \033[1;37mwhite\033[0m,"
			 << " \033[1;30mblack\033[0m, \033[1;35mmagenta\033[0m, \033[22;33mbrown\033[0m  or type \"random\"."<< endl << endl;
	for (int i = 0; i < 5; i++)	{
		do {
			cin.clear();
			cout << i+1 << ": ";
			cin >> s;
		} while (s!="red" && s!="green" && s!="blue" && s!="yellow" && s!="white" && s!="black" && s!="magenta" && s!="brown" && s!="random" && s!="r");
		if (s == "random" || s == "r") return getFiveRandomColors();
		else colors.push_back(s);
	}
	return colors;	
}

int main() {
	printHeader();
	cout << "Rules:" << endl << endl << "1. You have to guess the combination of five non repeating colors between \033[1;31mred\033[0m,"
			 <<"     \033[1;32mgreen\033[0m, \033[1;34mblue\033[0m, \033[1;33myellow\033[0m, \033[1;37mwhite\033[0m, \033[1;30mblack\033[0m, \033[1;35mmagenta\033[0m and \033[22;33mbrown\033[0m." 
			 << endl << "2. The symbol \u2B21  means one color is in the combination at the right place, while   \u2B22  means a color is in the combination, but at the wrong place." 
			 << endl << "3. You have 12 attempts. If you've not guessed the right combination by then,      you will lose." << endl << endl;
	
	int i = 1;
	
	Colors solution = getFiveRandomColors();
	Colors guess = askFiveColors(); 

	vector <Line> lines;
	Line l;	
	l.iter = 1; 
	l.colors = guess; 
	l.output=checkColors(guess,solution); 
	lines.push_back(l);
	system("clear");	
	
	while (guess != solution && i <12) {
		system("clear");
		printHeader();
		for (unsigned int k = 0; k < lines.size(); k++)	printLine(lines[k]);
		cout << endl; 
		
		guess.clear();
		guess = askFiveColors();
		
		Line l;
		l.iter = ++i;
		l.colors = guess;
		l.output=checkColors(guess,solution); 
		lines.push_back(l);		
	}
	
	if (i<12) {
		system("clear");
		printHeader();
		for (unsigned int k = 0; k < lines.size(); k++) printLine(lines[k]);
		cout << endl << "Congratulations, you have found the solution "; printColors(solution); cout << " in only " << i << " attempts."; 
	}
		
	else {
		system("clear");
		printHeader();
		for (unsigned int k = 0; k < lines.size(); k++) printLine(lines[k]);
		cout << endl << "Sorry, you have lost. The solution was "; printColors(solution); cout<<".";
	}
	
	return 0;
}
