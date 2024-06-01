#include "LoremIpsumSearcher.h"

#include <sstream>
#include <unordered_set>

using namespace std;

//constructor
LoremIpsumSearcher::LoremIpsumSearcher()
{
}

//destructor
LoremIpsumSearcher::~LoremIpsumSearcher()
{
}

//searches the lorem ipsum lines for words. Returns the lines where there are words found.
vector<string>* LoremIpsumSearcher::Search(vector<string> lines, const vector<string>& words)
{
	unordered_set<string> set;
	for (vector<string>::const_iterator a = lines.cbegin(); a != lines.cend(); ++a)
	{
		auto wordsInLine = GetWordsForLine(const_cast<char*>((new string(a->c_str()))->c_str() ));
		for (vector<string>::const_iterator foo = wordsInLine.cbegin(); foo != wordsInLine.cend(); ++foo)
		{
			for (vector<string>::const_iterator local = words.cbegin(); local != words.cend(); ++local)
			{
				if (*foo == *local)
				{
					if (std::find(set.cbegin(), set.cend(), *a) == set.cend())
					{
						set.insert(*a);
					}
				}
			}
		}
	}
	return new vector<string>(set.begin(), set.end());
}

//splits the line of text into words
vector<string> LoremIpsumSearcher::GetWordsForLine(char* line)
{
	vector<string> result;
	string word;
	string stringLine(line);
	istringstream stream(stringLine);
	while (getline(stream, word, ' '))
	{
		result.push_back(word);
	}
	return result;
}