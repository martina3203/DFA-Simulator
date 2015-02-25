#include "DFA.h"

DFA::DFA()
{
    //Constructor
}

DFA::~DFA()
{
    //clean up node list
    for (unsigned int i = 0; i < nodeList.size(); i++)
    {
        node * currentNode = nodeList.at(i);
        delete currentNode;
    }
}

//Executes the whole DFA
void DFA::execute()
{
    std::string fileName;
    bool fileOpened = false;
    //Ask user for filename
    while (fileOpened == false)
    {
        std::cout << "Please insert a file name" << std::endl;
        std::cin >> fileName;
        //If valid, opens, else return
        fileOpened = readFile(fileName);
        if (fileOpened == true)
        {
            std::cout << "File opened." << std::endl;
            fileOpened = true;
        }
        else
        {
            std::cout << "Invalid file name. Try again." << std::endl;
            fileOpened = false;
        }

    }
    //Ask user for string
    std::string testString = "";
    while (true)
    {
        std::cout << "Now, please input a string to test:" << std::endl;
        std::cin >> testString;

        if (testString == "quit")
        {
            //User wants to quit
            std::cout << "Exiting..." << std::endl;
            return;
        }
        else if (checkError(testString) == true)
        {
            findTraversal(testString);
        }
        else
        {
            std::cout << "String contains characters which are not available in the alphabet. Please try again." << std::endl;
        }
    }
    return;
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
        //First line is the final states, save for later
        std::string firstLine;
        std::getline(inputFile,firstLine);
        //The following lines are connections, parse until end of file
        while (!inputFile.eof())
        {
            int firstNumber = -1;
            int secondNumber = -1;
            char symbol = ' ';
            //Grab the values per line
            inputFile >> firstNumber;
            inputFile >> symbol;
            inputFile >> secondNumber;

            if ((firstNumber == -1) && (secondNumber == -1) && (symbol == ' '))
            {
                //This handles the case of an extra endline.
                //This means simply not to add it
            }
            else
            {
                //Print, Add it to the set
                std::cout << firstNumber << " " << symbol << " " << secondNumber << std::endl;
                addConnection(firstNumber,secondNumber,symbol);
            }
        }
        //Now we set the final states
        std::string parsingString = "";
        //We parse the string
        for (unsigned int i = 0; i < firstLine.size(); i++)
        {
            if ((firstLine.at(i) != ' ') && (i != firstLine.size() - 1))
            {
                parsingString = parsingString + firstLine.at(i);
            }
            else if (parsingString != "")
            {
                //Convert to Integer
                int Result;
                std::istringstream convert(parsingString);
                convert >> Result;
                parsingString = "";
                //Find corresponding integer
                for (unsigned int j = 0; j < nodeList.size(); j++)
                {
                    node * currentNode = nodeList.at(j);
                    if (currentNode -> returnStateName() == Result)
                    {
                        //Found node, make final
                        currentNode -> makeFinal();
                    }
                }
            }
        }
        return true;
    }
    else
    {
        //Invalid file
        return false;
    }
}

//Adds a connection between two nodes in the DFA
void DFA::addConnection(int firstNumber, int secondNumber, char symbol)
{
    bool nodeFound = false;
    node * firstNode = NULL;
    //Ensure that the first number is already in the list
    for (unsigned int i = 0; i < nodeList.size(); i++)
    {
        node * currentNode = nodeList.at(i);
        if (firstNumber == currentNode -> returnStateName())
        {
            //This node already exists
            nodeFound = true;
            firstNode = currentNode;
            break;
        }
    }
    //If the node doesn't exist yet
    if (nodeFound == false)
    {
        //Create a node if there isn't one already
        node * newNode = new node(firstNumber);
        firstNode = newNode;
        nodeList.push_back(firstNode);
    }

    //Ensure that the symbol is in the list
    bool symbolFound = false;
    for (unsigned int i = 0; i < validAlphabetList.size(); i++)
    {
        char currentSymbol = validAlphabetList.at(i);
        if (symbol == currentSymbol)
        {
            //This node already exists
            symbolFound = true;
            break;
        }
    }
    if (symbolFound == false)
    {
        //If not present, add to list
        validAlphabetList.push_back(symbol);
    }

    nodeFound = false;
    node * secondNode = NULL;
    //Ensure that the second number is already in the list
    for (unsigned int i = 0; i < nodeList.size(); i++)
    {
        node * currentNode = nodeList.at(i);
        if (secondNumber == currentNode -> returnStateName())
        {
            //This node already exists
            nodeFound = true;
            secondNode = currentNode;
            break;
        }
    }
    if (nodeFound == false)
    {
        //Create a node if there isn't one already
        node * newNode = new node(secondNumber);
        secondNode = newNode;
        nodeList.push_back(secondNode);
    }

    //Finally, add the connection to the first node
    firstNode -> addConnection(symbol,secondNode);
}

//Checks to see if the string is valid or not before testing it
bool DFA::checkError(std::string inputString)
{
    bool isValid = true;
    for (unsigned int i = 0; i < inputString.size(); i++)
    {
        for (unsigned int j = 0; j < validAlphabetList.size(); j++)
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
    return true;
}

//Executes traversal of the graph
bool DFA::findTraversal(std::string inputString)
{
    //Assuming we are starting from the integer 0
    //Parse string, moving from state to state
    //Record traversal, display to user
}
