#include <iostream>

#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    _chatBot = nullptr;

    ////
    //// EOF STUDENT CODE
}

GraphNode::GraphNode(const GraphNode& source)
:_childEdges(source._childEdges),
 _parentEdges(source._parentEdges),
 _chatBot(source._chatBot),
 _id(source._id),
 _answers(source._answers)
{
    std::cout<<"GraphNode copy constructor\n";
}

GraphNode& GraphNode::operator=(const GraphNode& source)
{
    std::cout<<"GraphNode copy assignment operator\n";
    if(this == &source)
        return *this;

    _childEdges.clear();
    _parentEdges.clear();
    _answers.clear();

    _childEdges = source._childEdges;
    _parentEdges = source._parentEdges;
    _chatBot = source._chatBot;
    _id = source._id;
    _answers = source._answers;
}

GraphNode::GraphNode(GraphNode&& source)
:_childEdges(std::move(source._childEdges)),
 _parentEdges(std::move(source._parentEdges)),
 _chatBot(source._chatBot),
 _id(source._id),
 _answers(std::move(source._answers))
{
    std::cout<<"GraphNode move constructor\n";
    source._chatBot = nullptr;
    source._id = 0;
}

GraphNode& GraphNode::operator=(GraphNode&& source)
{
    std::cout<<"GraphNode move assignment operator\n";
    if(this == &source)
        return *this;
    
    _childEdges.clear();
    _parentEdges.clear();
    _answers.clear();

    _childEdges = std::move(source._childEdges);
    _parentEdges = std::move(source._parentEdges);
    _chatBot = source._chatBot;
    _id = source._id;
    _answers = std::move(source._answers);

    source._chatBot = nullptr;
    source._id = 0;

    return *this;
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _childEdges.push_back(edge);
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index];

    ////
    //// EOF STUDENT CODE
}