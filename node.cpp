#include "node.h"

node::node()
{
    //basic constructor
    Final = false;
    stateNumber = 0;
}

node::node(int name)
{
    //Sets the name of the node, which is an integer value
    stateNumber = name;
    Final = false;
}

node::~node()
{
    //Destructor
}

void node::addConnection(char symbol, node * targetState)
{
    //Adds a new nodeConnection to this node
    connectionList.push_back(targetState);
    symbolList.push_back(symbol);
}

node * node::findConnection(char symbol)
{
    for (unsigned int i = 0; i < connectionList.size(); i++)
    {
        node * currentState = connectionList.at(i);
        //And this is connection by the same symbol
        if (symbolList.at(i) == symbol)
        {
            return currentState;
        }
    }
    //Returns NULL if the connection does not exist
    return NULL;
}

int node::returnStateName()
{
    return stateNumber;
}

bool node::isFinal()
{
    return Final;
}

void node::makeFinal()
{
    Final = true;
}
