#pragma once

#include <vector>
#include <string>

//searches the text of lorem ipsum for rows containing words to search
class LoremIpsumSearcher
{
	//splits the line of text into words
	std::vector<std::string> GetWordsForLine(char* line);

public:

	//constructor
	LoremIpsumSearcher();
	
	//destructor
	~LoremIpsumSearcher();

	//searches the lorem ipsum lines for words. Returns the lines where there are words found.
	std::vector<std::string>* Search(std::vector<std::string> lines, const std::vector<std::string>& words);
};

