#include "DFA.h"

DFA::DFA()
{
    //Constructor
}

DFA::~DFA()
{
    //Destructor
}

//Executes the whole DFA
void DFA::execute()
{
    //Ask user for filename
    //If valid, opens, else return
    //Ask user for string
    //If string is "quit", exit, else check to see if it's valid
}

//Reads in a file and adds components of file to the DFA
bool DFA::readFile(std::string fileName)
{
    std::ifstream inputFile;
    //Open file
    inputFile.open(fileName.c_str());
    if (inputFile.is_open())
    {
        //Carry out read in

        return true;
    }
    else
    {
        return false;
    }
}

//Adds a connection between two nodes in the DFA
void DFA::addConnection(int startNode, int endNode, char symbol)
{
    return;
}

//Checks to see if the string is valid or not before testing it
bool DFA::checkError(std::string inputString)
{
    bool isValid = true;
    for (unsigned int i = 0; i < inputString.size(); i++)
    {
        for (unsigned int j = 0; j < validAlphabetList.size(); i++)
        {
            //If this letter of the input string exists in the valid alphabet
            if (inputString.at(i) == validAlphabetList.at(j))
            {
                isValid = true;
                break;
            }
            else
            {
                isValid = false;
            }
        }
        //If after we check for letters and isValid is false,
        //the string contains an invalid character
        if (isValid == false)
        {
            //This is not valid
            return isValid;
        }
    }
}

bool DFA::findTraversal(std::string inputString)
{

}
