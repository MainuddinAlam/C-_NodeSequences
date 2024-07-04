//node_sequence.cpp
//Irteja:Mainuddin Alam:A00446752:u11
//Submission 05
//Sequences of Linked Nodes

/*
 * My program is able to handle all the cases that is needed for
 * Submission 5. The compiled executable, node_sequence should be
 * able to handle all the necessary tests in the testing script,
 * my_tests.sh .
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

#include "utilities.h"
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;
using Scobey::TextItems;

//type definition for an int variable
typedef int DataType;
//structure for a Node to make a Doubly Linked List
struct Node
{
    DataType data;
    Node* forwardLink;
    Node* backwardLink;
};
//typedefinition for a Node variable
typedef Node* NodePointer;

/**
 * Function to build a sequences of linked nodes.
 *
 * @param head the node pointing to head Node
 * @param smallValue the small value passed by the user
 * @param largeValue the large value passed by the user
 * @string checkCh a variable that checks whether user passes "e" or "b"
 */
void BuildSequence
(
    NodePointer& head,   //inout
    int smallValue,      //in
    int largeValue,      //in
    string checkCh       //in
);

/**
 * Function to display the sequences of linked nodes.
 *
 * @param head the node pointing to head Node
 */
void DisplaySequence
(
    NodePointer& head   //in
);

/**
 * Function to search the built sequence.
 *
 * @param head the node pointing to head Node
 * @param checkSequence boolean variable to check whether value is present
 * @param userValue the value to be checked
 * @param position the position in the sequence the value is found
 */
void SearchSequence
(
    NodePointer& head,     //in
    bool& checkSequence,   //inout
    int userValue,         //in
    int& position          //inout
);

/**
 * Function to remove a node from a sequence of linked nodes.
 *
 * @param head the node pointing to head Node
 * @param smallValue the small value passed by the user
 * @param largeValue the large value passed by the user
 * @param removeValue the value to be removed from the sequence
 * @param position the position in the sequence the removed value is found
 * @string checkCh a variable that checks whether user passes "e" or "b"
 */
void RemoveNode
(
    NodePointer& head,   //inout
    int smallValue,      //inout
    int largeValue,      //inout
    int removeValue,     //in
    int position,        //in
    string checkCh       //in
);

/**
 * Function to insert a node in a sequence of linked nodes
 *
 * @param head the node pointing to head Node
 * @param insertValue the value of the Node to be inserted
 * @param previousValue the value of the previous Node
 * @param smallValue the small value passed by the user
 * @param largeValue the large value passed by the user
 * @param position the position in the sequence the previous value is found
 */
void InsertNode
(
    NodePointer& head,  //inout
    int insertValue,    //in
    int previousValue,  //in
    int smallValue,     //in
    int largeValue,     //in
    int position        //in
);

/**
 * Function to reclaim the heap storage.
 *
 * @param head the node pointing to head Node
 */
void ReclaimHeapStorage
(
    NodePointer& head   //inout
);

/**
 * The main function of Submission 5. The function will detect the number
 * of command-line parameters being passed and call the respective
 * conditional block to execute the necessary code.
 *
 * @param argc the number of command-lind arguments
 * @param argv array with the names of the command line arguments
 * @return int a number is returned when the program needs to be terminated
 */
int main(int argc, char* argv[])
{
    //display the information when no command-line parameters are passed
    if (argc == 1)
    {
        //Display opening screen and program information
        DisplayOpeningScreen
        (
            "\t\tIrteja:Mainuddin Alam:A00446752:u11",
            "\n\t\tSubmission 05"
            "\n\t\tSequences of Linked Nodes"
        );
        TextItems textItem("node_sequence.txt");
        textItem.displayItem("ProgramDescription");
        return 0;
    }
    //check whether six command-line parameters have been passed
    else if (argc == 7)
    {
        //convert the C-strings to integers
        int smallVal = atoi(argv[1]);
        int largeVal = atoi(argv[2]);
        int removeVal = atoi(argv[4]);
        int insertVal = atoi(argv[5]);
        int previousVal = atoi(argv[6]);
        //initialize the head node to nullptr
        NodePointer head = nullptr;
        //build the sequence
        BuildSequence(head, smallVal, largeVal, argv[3]);
        //display the original sequence
        cout << "\nHere is the original sequence: \n";
        DisplaySequence(head);
        //check the sequence to see if the value to be removed is present
        int removePosition = 0;
        bool inSequenceForRemove = false;
        SearchSequence(head, inSequenceForRemove, removeVal, removePosition);
        //if the value is present, remove the node
        if (inSequenceForRemove == true)
        {
            RemoveNode(head, smallVal, largeVal, removeVal, removePosition,
                argv[3]);
        }
        //display the sequence again regardless whether the value
        //was removed or not
        cout << "\n\nHere is the same sequence with the value "
            << removeVal << "\nremoved, if the value "
            << removeVal << " was in the sequence."
            "\nOtherwise the sequence is displayed unchanged.\n";
        DisplaySequence(head);
        //check the sequence to see if the previous value is present
        int insertPosition = 0;
        bool inSequenceForInsert = false;
        SearchSequence(head, inSequenceForInsert, previousVal,
            insertPosition);
        //if the previous value is present, insert the new node
        if (inSequenceForInsert == true)
        {
            InsertNode(head, insertVal, previousVal, smallVal,
                largeVal, insertPosition);
        }
        //display the sequence again regardless whether the previous value
        //is present or not
        cout << "\n\nAnd finally, here is the revised sequence with the"
            "\nvalue " << insertVal << " added after "
            << previousVal << " if " << previousVal << " was in the "
            "sequence.\nOtherwise the sequence is displayed unchanged.\n";
        DisplaySequence(head);
        cout << "\n";
        //Pause before continuing
        Pause();
        //Reclaim the heap storage
        ReclaimHeapStorage(head);
    }
}

void BuildSequence
(
    NodePointer& head,   //inout
    int smallValue,      //in
    int largeValue,      //in
    string checkCh       //in
)
{
    //initialize the head node
    head = new Node;
    //check which character user has pressed
    if (checkCh == "b")
    {
        //initialize the current node, set it's data to smallValue,
        //and point it's forwardLink to nullptr
        NodePointer current = new Node;
        current->data = smallValue;
        current->forwardLink = nullptr;
        //loop through and add the values to the beginning
        for (int i = smallValue + 1; i <= largeValue; i++)
        {
            //for each iteration set the previous->data to i,
            //point the current's backwardLink to the previous node,
            //point the previous's forwardLink to the current node,
            //and finally point current node to previous node
            NodePointer previous = new Node;
            previous->data = i;
            current->backwardLink = previous;
            previous->forwardLink = current;
            current = previous;
        }
        //set current's backwardLink to nullptr and point head to the
        //current node
        current->backwardLink = nullptr;
        head = current;
    }
    else if (checkCh == "e")
    {
        //initialize the current node to head node, set it's data to
        //smallValue and point it's backwardLink to nullptr
        NodePointer current = head;
        current->data = smallValue;
        current->backwardLink = nullptr;
        //loop through and add values to the end
        for (int i = smallValue + 1; i <= largeValue; i++)
        {
            //for each iteration set next->data to i,
            //point the current's forwardLink to the next node,
            //point the next's backwardLink to current,
            //and finally point the current node to next node
            NodePointer next = new Node;
            next->data = i;
            current->forwardLink = next;
            next->backwardLink = current;
            current = next;
        }
        //set current's forwardLink to nullptr
        current->forwardLink = nullptr;
    }
    else
    {
        //Just exit the program for strings other than "b" or "e"
        exit(0);
    }
}

void DisplaySequence
(
    NodePointer& head   //in
)
{
    //if head is nullptr, display that the sequence is empty
    if (head == nullptr)
    {
        cout << "\nThe sequence is currently empty.";
    }
    //else display the sequence
    else
    {
        //point current to head node
        NodePointer current = head;
        //loop through while current is not nullptr
        while (current != nullptr)
        {
            //display the current's data and point current to current's
            //forwardLink
            cout << current->data << " ";
            current = current->forwardLink;
        }
    }
}

void SearchSequence
(
    NodePointer& head,      //in
    bool& checkSequence,    //inout
    int userValue,          //in
    int& position           //inout
)
{
    //point current node to head node
    NodePointer current = head;
    //loop through while current is not nullptr and checkSequence is false
    while (current != nullptr && checkSequence == false)
    {
        //set checkSequence to true if userValue is equal current's data
        if (userValue == current->data)
        {
            checkSequence = true;
        }
        //increment the position and point current to current's forwardLink
        position++;
        current = current->forwardLink;
    }
}


void RemoveNode
(
    NodePointer& head,   //inout
    int smallValue,      //in
    int largeValue,      //in
    int removeValue,     //in
    int position,        //in
    string checkCh       //in
)
{
    //find the difference between largeValue and smallValue
    int difference = largeValue - smallValue + 1;
    //point current to head
    NodePointer current = head;
    //check difference is equal to position
    if (difference != position)
    {
        //loop while current is not equal nullptr
        while (current != nullptr)
        {
            //do this if the node to be removed is not the head node
            //or last node
            if (removeValue == current->data && head == current)
            {
                //point next to current's forwardLink,
                //point next's forwardLink to nullptr, and finally
                //point to head to next before returning
                NodePointer next = current->forwardLink;
                next->backwardLink = nullptr;
                head = next;
                return;
            }
            //do this if the node to be removed is the head node
            if (removeValue == current->data && head != current)
            {
                //point previous to current's backwardLink,
                //point next to current's forwardLink,
                //point previous's forwardLink to next,
                //and fnally point next's backwardLink to previous
                NodePointer previous = current->backwardLink;
                NodePointer next = current->forwardLink;
                previous->forwardLink = next;
                next->backwardLink = previous;
            }
            //point current to current's forwardLink
            current = current->forwardLink;
        }
    }
    else
    {
        //else remove the last node by making the sequence again
        //without the last node
        if (checkCh == "b")
        {
            //increment smallValue
            smallValue += 1;
        }
        else
        {
            //decrement the largeValue
            largeValue -= 1;
        }
        //build the sequence again without including the last node
        BuildSequence(head, smallValue, largeValue, checkCh);
    }
}


void InsertNode
(
    NodePointer& head,   //inout
    int insertValue,     //in
    int previousValue,   //in
    int smallValue,      //in
    int largeValue,      //in
    int position         //in
)
{
    //find the difference between largeValue and smallValue
    int difference = largeValue - smallValue + 1;
    //point current to head and initialize the insertNode
    NodePointer current = head;
    NodePointer insertNode = new Node;
    //loop through while current is not equal nullptr
    while (current != nullptr)
    {
        //insert new node if previousValue is equal current's data
        if (previousValue == current->data)
        {
            //set insertNode's data to insertValue,
            //point next to current's forwardLink,
            //point current's forwardLink to insertNode,
            //point insertNode's backwardLink to current,
            //and finally point insertNode's forwardLink to next
            insertNode->data = insertValue;
            NodePointer next = current->forwardLink;
            current->forwardLink = insertNode;
            insertNode->backwardLink = current;
            insertNode->forwardLink = next;

        }
        //point current to current's forwardLink
        current = current->forwardLink;
    }
    //if the position is the last node, point current's forwardLink to
    //nulptr
    if (difference == position)
    {
        current->forwardLink = nullptr;
    }
}


void ReclaimHeapStorage
(
    NodePointer& head   //inout
)
{
    //loop through until head is not equal to nullptr
    while (head != nullptr)
    {
        //for each iteration point current to head,
        //point head to head's forwardLink,
        //and finally delete the current node
        NodePointer current = head;
        head = head->forwardLink;
        delete current;
    }
}
