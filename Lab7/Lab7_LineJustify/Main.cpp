// Shawn Greathouse
// Line Justification
//10/17/19

#include <iostream>
#include <string>
#include <cstdlib>

using std::cin; using std::cout; using std::endl; using std::string;

void addSpace(string&);
void randSpace(string&);
const int size = 75;

int main() {
	string input;
	cout << "Enter a string to be justified: " << endl;
	getline(cin, input);
	while (input.size() < size)
		addSpace(input);
	system("pause");
}

void addSpace(string& s) {
	int pos = s.find_first_of(".,!?;");
	while (pos != string::npos && s.size() > 39 && pos != s.size() - 1) {
		s.insert(pos + 1, " ");
		pos = s.find_first_of(".,!?;", pos + 1);
	}
	if (s.size() < size && s.size() > 39)
		randSpace(s);
	cout << "Your line justified to 75 characters: \n" << s << endl << endl;
}

void randSpace(string& s) {
	srand(1);
	int pos = s.find(" ");
	while (s.size() < size && s.size() > 39) {
		int val = rand() % 2;
		bool space = val == 0 ? true : false;
		if (space == true) {
			s.insert(pos, " ");
			pos = s.find_first_of(" ", pos + 2);
		}
		if (pos == string::npos)
			pos = s.find(" ");
	}
}

