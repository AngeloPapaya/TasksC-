#include "RandomWordsGenerator.h"

#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

//gets few random words from the lorem ipsum text
RandomWordsGenerator::words_t RandomWordsGenerator::GetFewRandomWords(const RandomWordsGenerator::lines_t& lines)
{
	words_t result;
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 3; ++i)
	{
		int lineIndex = rand() % lines.size();
		const line_t& line = lines.at(lineIndex);
		words_t words = GetWordsForLine(line);
		result.push_back(words.at(rand() % words.size()));
	}
	return result;
}

//splits the single line of text into words
RandomWordsGenerator::words_t RandomWordsGenerator::GetWordsForLine(const RandomWordsGenerator::line_t& line)
{
	words_t result;
	word_t word;
	istringstream stream(line);
	while (getline(stream, word, ' ') )
	{
		result.push_back(word);
	}
	return result;
}

//destructor
RandomWordsGenerator::~RandomWordsGenerator()
{
}
