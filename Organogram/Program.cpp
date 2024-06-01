#include "OrganogramLinesProviderFromFile.h""

#include <fstream>
#include <vector>
#include <iostream>
#include <array>
#include <string>
#include <sstream>
int main(int argc, char* argv[])
{

        OrganogramLinesProviderFromFile linesProvider("companies_data.csv");
    auto res = linesProvider.GetOrganogramLines();


      for(const auto& row: res) { //
          std::cout<<"["<<" ";
        for(const auto& word: row) {
            std::cout<<word<<" --- ";
        }
        std::cout<<" ]"<<" ";
       std::cout<<"\n";

      }






	return 0;
}
