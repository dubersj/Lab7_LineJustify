// Justifies lines of text under 75 characters
// 10/11/2019
// Steve J Duber IV

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::cin; using std::cout; using std::endl; using std::string;

void InsertPuncSpaces(string&, const int);
void InsertRandSpaces(string&, const int);
void EraseEnds(string&);
string getString();
int randomValue();

int main() {

	const int length = 75;

	string input = getString();

	InsertPuncSpaces(input, length);

	if (input.size() >= 40) {
		while (input.size() < length) {
			InsertRandSpaces(input, length);
			EraseEnds(input);
		}
	}

	cout << input.size() << endl;
	cout << input;
}

void InsertPuncSpaces(string &input, const int length) {
	if (input.size() < length) {
		int pos = input.find('!');
		while (pos != string::npos) {
			input.insert(pos + 1, 1, ' ');
			pos = input.find('!', pos + 1);
		}
		pos = input.find('?');
		while (pos != string::npos) {
			input.insert(pos + 1, 1, ' ');
			pos = input.find('?', pos + 1);
		}
		pos = input.find('.');
		while (pos != string::npos) {
			input.insert(pos + 1, 1, ' ');
			pos = input.find('.', pos + 1);
		}
		pos = input.find(',');
		while (pos != string::npos) {
			input.insert(pos + 1, 1, ' ');
			pos = input.find(',', pos + 1);
		}
	}
}

void InsertRandSpaces(string& input, const int length) {
	int end = 0, place = 0;
	while (input.size() < length) {
		if (end < length - 1) {
			if (randomValue() == 0) {
				end = input.find_first_of(' ', place);
				input.insert(end + 1, 1, ' ');
			}
			place = input.find_first_not_of(' ', end);
		}
		else place = 0;
	}
}

void EraseEnds(string& input) {
	if (input[0] == ' ') {
		input.erase(0, 1);
	}
	else if (input[74] == ' ') {
		input.erase(74, 1);
	}
}

string getString() {
	cout << "Please enter a string to be justified to 75 characters:" << endl;
	string input;
	getline(cin, input);
	return input;
}

int randomValue() {
	srand(time(NULL));
	int random = rand() % 2;
	return random;
}