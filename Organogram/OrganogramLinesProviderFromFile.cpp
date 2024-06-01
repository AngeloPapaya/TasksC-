#include "OrganogramLinesProviderFromFile.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <array>
#include <string>
#include <sstream>


std::vector<std::vector<std::string>> OrganogramLinesProviderFromFile::GetOrganogramLines()
    {
        std::ifstream file(_fileName);
        std::string line;
        std::vector <std::vector<std::string>> results; //big vector which contains all rows

            if (!file.is_open())
                {
                    std::cerr << "Nie uda³o siê otworzyæ pliku.\n";
                    return results;
                }

        while (std::getline(file,line))
        {
            std::vector <std::string> wordVector;//separate vector for each row, each time creating new vector for row
            std::string word;
            std::istringstream iss(line); // Ta linia kodu tworzy obiekt strumienia wejœciowego std::istringstream o nazwie iss, który

                                                //jest uzywany do przetwarzania danych tekstowych z line,
                while (std::getline(iss,word,',')) //tutaj dzielimy lancuch znakow uzywaja separatora przecinku i zapisujemy dane w 'word'
                {
                    if (!word.empty())
                        wordVector.push_back(word);//adding word to wordVector for each row
                    //std::cout << word << "\n";
                }
            results.push_back(wordVector);//adding new row to big vector

        }

     return results;
     file.close();
    }
