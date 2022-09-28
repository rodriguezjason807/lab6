//Name: Jason Rodriguez
//Lab6  Challenge 1
//Date: September 26 2022
#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;

const char fname[] =
"/home/fac/gordon/public_html/3350/dictionary.txt";

const int MAX = 1000;
string prefix[MAX];
int instances[MAX];
int counter = 0;

void lab_display () {
	cout << "3350 Lab-6 Challenge #1" << endl;
	cout << "Common word prefixes." << endl;

}

string convertToString(char* a) {
	string s = "";
	for (int i=0; i < 1; i++) {
		s = s + a[i] + a[i+1];
	}
	return s;
}
void insert ( string input ) {
	// check first, add if not present
	for (int i=0; i<counter; i++) {
		if ( input == prefix[i]) {
			instances[i]++;
			return;
		}
	}
	// check if prefix array is full
	if (counter < MAX) {
		prefix[counter] = input;
		instances[counter] = 1;
		counter++;
	} else
		cout << "Too many prefixes" << endl;
}
void findLargestPrefixes(int instances[], int n){
	sort(instances, instances + n, std::greater<>());
	int j = 0;
	cout<<"\nThe 10 most common word prefixes are: ";
	for(int i = 0; i < n; i++){ 
		if(instances[i] != instances[i+1]){ 
			cout<<prefix[i]<<" "; 
			j++;
		}
		if(j == 10){
			cout << endl << endl;
			cout << "2nd most common prefix: " << prefix[1] << endl;
			cout << "3nd most common prefix: " << prefix[2] << endl;
			break;
		}
	}
}
int main()
{
	lab_display();
	ifstream fin(fname);
	if (fin.fail()) {
		cout << "ERROR opening: " << fname << endl;
		exit(0);
	}
	cout << "File successfully opened." << endl;
    	
	//do a priming read.
	char line[100];
	//read through the file to find prefixes
	fin >> line;
	while (!fin.eof()) {
		if ( strlen(line) >= 2 ) {
			insert(convertToString(line));
		}	
		fin >> line;
	}
	fin.close();
	cout << "File close." << endl << endl;
	int n = sizeof(instances) / sizeof(instances[0]);
	findLargestPrefixes(instances, n);
	//Compare prefix via the number_of_uses array to get 2nd and 3rd most
	
	cout << endl;
	cout << "End of program" << endl;
	return 0;
}

