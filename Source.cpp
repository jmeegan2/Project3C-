//James Meegan CIS 221 
//12-10-2020
#include <iostream>
using namespace std;
//Constants
const int OK = 1;
const int NOT_FOUND = 2;
const int ERROR_MEMORY = -1;

// NODE SPECIFICATION
// Description: Each linked OOLNode structure contains the information
// for a single element in the list.
struct OOLNode
{
    int payload;
    OOLNode* next;
};
// OBJECT SPECIFICATION
// Description: Object interface specification for
// "Operator-overloaded Ordered Linked List" (OOLList).
class OOList
{
private:

    OOLNode* start;

public:
    // Description: Initializes the list with zero elements.
    OOList()
    {
        start = NULL;
    }
    // Description: Returns the number of elements currently in the list.
    int getListSize()
    {
        int count = 0;
        OOLNode* temp = start;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int getListSizeInBytes()
    {
        return (getListSize() * sizeof(OOLNode));
    }

    int getListElements(int* populateMeWithElements)
    {
        int count = 0;
        OOLNode* temp = start;
        while (temp != NULL)
        {
            populateMeWithElements[count] = temp->payload;
            count++;
            temp = temp->next;
        }
        return count;
    }

    int addElement(int addMe)
    {
        //Algorithm for inserting an element in list in increasing order.
        OOLNode* t = new OOLNode;
        t->next = NULL;
        t->payload = addMe;
        if (start == NULL)
        {
            start = t;
            return OK;
        }
        else if (start->payload > addMe)
        {
            t->next = start;
            start = t;
            return OK;
        }
        else
        {
            OOLNode* temp = start->next;
            OOLNode* prev = start;
            while (temp != NULL)
            {
                if (temp->payload > addMe)
                {
                    t->next = temp;
                    prev->next = t;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
                prev->next = t;
            return OK;
        }
        return ERROR_MEMORY;
    }

    int operator+(int addMe)
    {
        return addElement(addMe);
    }

    void deleteElementComp(int deleteMe) //deletes all the elements that are equal to deleteMe
    {
        while (deleteElement(deleteMe) != NOT_FOUND) //deletes a single instance of deleteMe repeatedly
        {
            if (start == NULL)
                break;
        }
    }

    int deleteElement(int deleteMe) //deletes a single instance of deleteMe
    {
        //Algorithm for deleting an element in a list in increasing order.
        if (start == NULL) //Checking if the list isn't already empty
            return NOT_FOUND;
        OOLNode* temp = start;
        if (start->payload == deleteMe)
        {
            start = start->next;
            delete temp;
            return OK;
        }
        OOLNode* prev = start;
        temp = temp->next;
        while (temp != NULL)
        {
            if (temp->payload == deleteMe)
            {
                OOLNode* t = temp;
                prev->next = temp->next;
                delete t;
                return OK;
            }
            prev = temp;
            temp = temp->next;
        }
        return NOT_FOUND;
    }

    void operator-(int deleteMe)
    {
        deleteElementComp(deleteMe);
    }

    void printOOL() //prints the list
    {
        if (start == NULL)
            return;
        OOLNode* temp = start;
        while (temp != NULL)
        {
            cout << temp->payload << " ";
            temp = temp->next;
        }
    }

};

int main()
{
    OOList obj;
   
    int NumberOfLoops = 100; // Assignment Instructions say to repeat steps 1-5 100 times in a loop therefor NumberOfLoops=100, CHANGE BACK TO 100 BEFORE TURNING IN
    int min = 100;  //The two values used to generate a random number between 100 and 100000 for the list size
    int max = 100000;
    while (NumberOfLoops) //It will take a long time since we iterating it 100 times.
   
    {
        cout << "Iteration number: " << NumberOfLoops << "\n\n";
        int r = min + (rand() % (int)(max - min + 1)); //Generating random number between 100 and 100000
        //int r=2;
        while (r)
        {
            int addMe = 1 + (rand() % (int)(100)); //Generating random number between 1 and 100
            obj.addElement(addMe);
            r--;
        }
        
        r = min + (rand() % (int)(max - min + 1)); //Second time in which the program will generate random number between 100 and 100000
        while (r)
        {
            int addMe = 1 + (rand() % (int)(100)); //Second time in which the program will genertae random number between 1 and 100
            obj + addMe;
            r--;
        }
       
        cout << "\nList size: " << obj.getListSize() << endl << endl; // Starting list size displayed here 
        cout << "The list after addition: \n";
        obj.printOOL(); //Numbers 1-100 displayed on screen
        cout << endl;
      
        //Deleting elements with payload 1 to 50
        for (int i = 1; i <= 50; i++)
            obj.deleteElementComp(i);
        cout << "\nList size: " << obj.getListSize() << endl << endl; //List size displayed here 
        cout << "The list after deleting <=50 elements \n";
        obj.printOOL(); //Numbers 51-100 displated here 
        cout << endl;
       
        //Deleting elements with payload 51 to 100
        for (int i = 51; i <= 100; i++)
            obj - i;//res=-obj(i);
        cout << "\nList size: " << obj.getListSize() << endl << endl; //List size displayed here
        cout << "The list after deleting >50 elements \n"; 
        obj.printOOL(); //Nothing will display here because of the deletion of the remaining elements
        cout << endl;
        NumberOfLoops--;
    }
    return 0;
}