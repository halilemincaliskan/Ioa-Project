/*														    \
|		Name & Surname			: Halil Emin Çalışkan		|
|		School Number			: 1306180055				|
|		Date					: 22/12/2019				|
|		Development Environment : Visual Studio 2019		|
\														   */					


// I import important library in this area.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// I define edge class. It must have a name and childrens. I use vector for childrens.
class Edge
{
	public: 
		string edgeName;
		vector <Edge*> childrens;
};

// This function is for printing every word that can be create.
void printing(string &row, Edge& thisEdge, size_t funcMaxRowLength) {
	// This row is empty because first edge isn't children. In the if loop below for print childrens.
	row += thisEdge.edgeName;
	cout << row << endl;

	if (row.size() <= funcMaxRowLength-1) {
		for (size_t i = 0; i < thisEdge.childrens.size(); i++) {
			printing(row, *thisEdge.childrens[i], funcMaxRowLength);
		}
	}
	row = row.substr(0, row.size() - 1);
}

// This function is for learn how much letter in string.
int howMuchLetterInString(char thisString[], int sizeOfString) {
	int letterInString = 0;
	for (int i = 0; i < sizeOfString - 1; i++) {
		if (int(thisString[i]) >= 65 && int(thisString[i]) <= 90) {
			letterInString++;
		}
	}
	return letterInString;
}

// In this project I don't take any input when program is running so, I take string with argv.
int main(int argc, char* argv[])
{
	// This if loop checking argument count (argc).
	if ( argc == 2 ) { 
		string str = argv[1];
		char inputString[sizeof(str)];
		strcpy_s(inputString, str.c_str()); // I couldn't assign string to char so, I used strcpy_s for copy string to char.
		string emptyRow = "";
		int firstLetterInAscii = 65;
		int sumLetterInString = howMuchLetterInString(inputString, strlen(inputString));
		bool isItFirstTimeNumber = 1;
		bool isItFirstTimeLetter = 1;
		string maxRowLength = "";
		string parentName = "";
		string childrenName = "";

		Edge* edge = new Edge[sumLetterInString]; // I created edges as many letter in string.

		// I gived edgeName for every created edges.
		for (int i = 0; i < sumLetterInString; i++) {
			int thisAsciiCode = firstLetterInAscii + i;
			edge[i].edgeName = (char)thisAsciiCode;
		}

		for (size_t i = 0; i < strlen(inputString); i++) {
			// Checking for is it number.
			if (int(inputString[i]) >= 48 && int(inputString[i]) <= 57) {
				isItFirstTimeLetter = 1; // If the number has come, the next letter is displayed for the first time.
				// Checking for is it first time number.
				if (isItFirstTimeNumber == 1) {
					maxRowLength += inputString[i];
				}
				// If it is separated by 1, it continues without doing anything.
				else if (inputString[i] == 49) {
					continue;
				}
				// Giving error if it is not separated by 1..
				else {
					cout << "Please seperate between letters with 1." << endl;
				}
			}
			// Checking for is it letter.
			else if (int(inputString[i]) >= 65 && int(inputString[i]) <= 90) {
				isItFirstTimeNumber = 0; // This is only to check the number at the beginning of the string so once the letter display you do not need to do it again 1.
				// Checking for is it first time number. If it is first time, it is parent.
				if (isItFirstTimeLetter == 1) {
					parentName = inputString[i];
					isItFirstTimeLetter = 0; // After the first letter we make 0 to other letters make children.
				}
				// If it isn't first time it is children.
				else {
					childrenName = inputString[i];
					// If it is children we connect childrens with their parent.
					for (int k = 0; k < sumLetterInString; k++) {
						if (edge[k].edgeName == parentName) {
							for (int m = 0; m < sumLetterInString; m++) {
								if (edge[m].edgeName == childrenName) {
									edge[k].childrens.push_back(&edge[m]);
								}
							}
						}
					}

				}
			}
			// Give error if they input something other than a letter or number.
			else {
				cout << "Please check the your input. Turkish characters, symbols and lower case aren't accepted." << endl;
				break;
			}
		}
		// If still isItFirstTimeNumber == 0 , It means they didn't enter any letter.
		if (isItFirstTimeNumber == 0) {
			// If isItFirstTimeLetter == 0 , It means they didn't finish string with letter.
			if (isItFirstTimeLetter == 0) {
				int intMaxRowLength = stoi(maxRowLength);
				printing(emptyRow, edge[0], intMaxRowLength);
			}
			else {
				cout << "Your input must be finish with a letter !" << endl;
			}
		}
		else {
			cout << "You need to give a edge. (ex. 5ABCD)" << endl;
		}
	}
	else {
		cout << "You give " << argc << " argument(s) but you must give 2 arguments." << endl;
	}

	return 0;
}
