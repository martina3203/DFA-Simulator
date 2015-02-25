#ifndef DFA_H
#define DFA_H

#include "node.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class DFA
{
    public:
        DFA();
        virtual ~DFA();
        bool readFile(std::string);
        void addConnection(int,int,char);
        bool checkError(std::string);
        bool findTraversal(std::string);
        void execute();
    protected:
    private:
        std::vector<node*> nodeList;
        std::vector<char> validAlphabetList;
};

#endif // DFA_H
