// Shawn Greathouse
// Line Justification
//10/17/19

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using std::cin; using std::cout; using std::endl; using std::string;
using std::ifstream; using std::ofstream;

void addSpace(string&);
void randSpace(string&);
const int size = 75;

ofstream fout("justified.txt");

int main() {
	string unjust;
	string fileName;

	cout << "Enter name of file to be justfied: ";
	getline(cin, fileName);

	ifstream fin(fileName);

	cout << "Contents of input file justified: \n";
while (getline(fin, unjust)) {
	if (unjust.size() < size && unjust.size() > 39)
		addSpace(unjust);
	fout << unjust << endl;
	cout << unjust << endl;
}

}

void addSpace(string& s) {
	int pos = s.find_first_of(".,!?;");
	while (pos != string::npos && s.size() > 39 && pos != s.size() - 1) {
		s.insert(pos + 1, " ");
		pos = s.find_first_of(".,!?;", pos + 1);
	}
	if (s.size() < size && s.size() > 39)
		randSpace(s);
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