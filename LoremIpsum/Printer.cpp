#include "Printer.h"

#include <iostream>
#include <iterator>

using namespace std;

//writes the vector to the output stream - each item is in a separate line
std::ostream &operator<<(std::ostream& stream, const std::vector<string>& lines)
{
	for (auto &item : lines)
	{
		stream << item << endl;
	}
	return stream;
}

//prints the result and waits for the user to decide what to do next
void Printer::PrintOnOutputandWaitForUserToDecideWhatIsNext(vector<string> lines, vector<string> wordsToSearch)
{
	system("cls");
	cout << "WORDS TO SEARCH:" << endl;
	copy(wordsToSearch.cbegin(), wordsToSearch.cend(), ostream_iterator<string>(cout, " "));
	cout << endl;
	cout << "RESULT:" << endl << lines;
	cout << endl << "Press ENTER to close otherwise program will continue" << endl;
}
