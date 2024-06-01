#pragma once

#include <string>
#include <vector>

//looks into the lorem ipsum text and provides few random words out of it.
class RandomWordsGenerator
{
	typedef std::string line_t;
	typedef std::vector<line_t> lines_t;
	typedef std::string word_t;
	typedef std::vector<word_t> words_t;

	//splits the single line of text into words
	words_t GetWordsForLine(const line_t& line);

public:

	//gets few random words from the lorem ipsum text
	 words_t GetFewRandomWords(const lines_t& lines);
	
	 //destructor
	virtual ~RandomWordsGenerator();
};

