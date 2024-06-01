#include "LoremIpsumLinesProviderFromFile.h"
#include "RandomWordsGenerator.h"
#include "LoremIpsumSearcher.h"
#include "Printer.h"

using namespace std;

int main()
{
	//load lines of lorem ipsum text
	LoremIpsumLinesProviderFromFile linesProvider("lorem_ipsum.txt");
	vector<string> lines = linesProvider.GetLoremIpsumLines();

	vector<string> result;
	while (true)
	{
		//get few random words
		RandomWordsGenerator *pRandomWordsGenerator = new RandomWordsGenerator();
		vector<string> randomWords = pRandomWordsGenerator->GetFewRandomWords(lines);

		//search these words in the lorem ipsum text
		LoremIpsumSearcher *pLoremIpsumSearcher = new LoremIpsumSearcher();
		auto data = (*pLoremIpsumSearcher).Search(lines, randomWords);

		//display result of the search, break the loop if the user decides so
		result.insert(result.end(), data->begin(), data->end() );
		Printer::PrintOnOutputandWaitForUserToDecideWhatIsNext(result, randomWords);
	}
	return 0;
}

