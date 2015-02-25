#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>

class node
{
    public:
        node();
        node(int);
        virtual ~node();
        int returnStateName();
        void makeFinal();
        bool isFinal();
        void addConnection(char,node*);
        node * findConnection(char);
    protected:
    private:
        int stateNumber;
        bool Final;
        std::vector<node*> connectionList;
        std::vector<char> symbolList;
};

#endif // NODE_H
