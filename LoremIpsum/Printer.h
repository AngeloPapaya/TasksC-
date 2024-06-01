#pragma once

#include <string>
#include <vector>

//prints the results to the console and waits for user decision
class Printer
{
public:
	//prints the result and waits for the user to decide what to do next
	static void PrintOnOutputandWaitForUserToDecideWhatIsNext(std::vector<std::string> lines, std::vector<std::string> wordsToSearch);
};

