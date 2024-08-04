#include<iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////
///////
//Code of Singly Linear LL
///////
///////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
struct nodeSL
{
    T data;
    struct nodeSL * next;
};

template <class T>
class SinglyLL          
{
    private:        
        struct nodeSL<T> * First;        
        int iCount;
        
    public:
    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);


};
template <class T>
SinglyLL<T> :: SinglyLL()
{
    cout<<"Inside Constructor"<<endl;
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T> ::Display()
{
    struct nodeSL<T> * temp = First;     //for every PNODE, write: struct node * as with generic aapan typedef nahi use karo shakat
    while(temp != NULL)         
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}

template <class T>
int SinglyLL<T> ::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T> ::InsertFirst(T No)
{

    struct nodeSL<T> * newn = NULL;

    //Creating new Node using "new" dynamically
    newn = new struct nodeSL<T>;
     //newn = new  node;     //Konta node ha kalayla pahije

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)   //OR  if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;              //Khupch important aahe he  karan aapn count function define karat naiye
}

template <class T>
void SinglyLL<T> ::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = NULL;

    //Creating new Node using "new" dynamically
    newn = new nodeSL<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)   //OR  if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;              //Khupch important aahe he  karan aapn count function define karat naiye

}

template <class T>
void SinglyLL<T> ::InsertAtPos(T No,int iPos)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = NULL;
    int i = 0;
    if((iPos < 1) || (iPos > iCount + 1))
    {   
        cout<<"Invalid Position"<<endl;
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        //Creating new Node using "new" dynamically
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        temp = First;
        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;           
    }

}

template <class T>
void SinglyLL<T> ::DeleteFirst()
{
    struct nodeSL<T> * temp = First;
    if(First == NULL)
    {
        cout<<"LL is Empty"<<endl;
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete(temp); 
    }
    iCount--;
}

template <class T>
void SinglyLL<T> ::DeleteLast()
{
    struct nodeSL<T> * temp = First;
    struct nodeSL<T> * temp2 = NULL;
    if(First == NULL)
    {
        cout<<"LL is Empty"<<endl;
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;

}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeSL<T> * temp1 = NULL;
    struct nodeSL<T> * temp2 = NULL;
    int i = 0;
    if((iPos < 1) || (iPos > iCount))
    {   
        cout<<"Invalid Position"<<endl;
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        iCount--;           
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////
//Code of Doubly Circular
///////
///////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC * next;
    struct nodeDC * prev;
};

template <class T>
class DoublyCL
{
    private:
    struct nodeDC<T> * First;
    struct nodeDC<T> * Last;
    int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last  = NULL;
    iCount = 0;
}

template <class T>
//Return Value - class cha naav - scope resolution (::) - Function cha naav
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::Display()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is Empty!"<<endl;
        return;
    }
    cout<<"<=>";
    do
    {
        cout<<"| "<<First->data<<" | <=> ";
        First = First->next;
    } while (Last->next != First); // OR while(First != Last->next); 
    cout<<endl;
    
}

template <class T>
void DoublyCL<T>::InsertFirst(T iNo)
{
    struct nodeDC<T> * newn = NULL;
    newn = new nodeDC<T>;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = iNo;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->next->prev = newn;
        First = newn;

    }
    Last->next = First;     //For maintaining the Circular nature of the linked list
    First->prev = Last;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T iNo)
{
    struct nodeDC<T> * newn = NULL;
    newn = new nodeDC<T>;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = iNo;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
       Last->next = newn;       //No traversal required due to circular linsked list and we know what is last
       newn->prev = Last;
       Last = newn;
    }
    Last->next = First;     //For maintaining the Circular nature of the linked list
    First->prev = Last;
    iCount++;
    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T iNo, int iPos)
{
    int i = 0;
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position!"<<endl;
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    if(iPos == iCount +1)
    {
        InsertLast(iNo);
    }
    else
    {
        newn = new nodeDC<T>;
        newn->next = NULL;
        newn->prev = NULL;
        newn->data = iNo;
        
        temp = First;
        for(i = 1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
    
    
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))       
    {
        cout<<"Unable to Delete as LL is empty"<<endl;
        return;
    }
    else if(First == Last)       //OR icount == 1 LL contains one single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else        //More than one node
    {
        First = First->next;
        delete Last->next;   //OR delete First->prev
        Last->next = First;
        First->prev = Last;
    }
    /*Last->next = First;
    First->prev = Last;*/       //Cannot be kept out of else as it will cause problems for when iCount ==1
    
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    struct nodeDC<T> * temp = NULL;
    if((First == NULL) && (Last == NULL))       
    {
        cout<<"Unable to Delete as LL is empty"<<endl;
        return;
    }
    else if(First == Last)       //OR icount == 1 LL contains one single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else        //More than one node
    {
      Last = Last->prev;
      delete First->prev;
      Last->next = First;
      First->prev = Last;
    }
   
    iCount--;
    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeDC<T> * temp = NULL;
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position!"<<endl;
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(i = 1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
    
    
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////
//Code of Doubly Linear
///////
///////////////////////////////////////////////////////////////////////////////////////////////////
//Add your code here//
template <class T>
struct nodeDL
{
    T data;
    struct nodeDL * next;
    struct nodeDL * prev;
};

template <class T>
class DoublyLL          
{
    public:
        struct nodeDL<T> * First;        
        int iCount;

    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};
template <class T>
DoublyLL<T> :: DoublyLL()
{
    cout<<"Inside Constructor of the doubly linear Linked list"<<endl;
    First = NULL;
    iCount = 0;
}
template <class T>
void DoublyLL<T> :: Display()
{
    struct nodeDL<T> * temp = First;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|=>";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}
template <class T>
void DoublyLL<T> :: InsertFirst(T No)
{
    struct nodeDL<T> * newn = NULL;
    newn = new nodeDL<T>;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = No;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}
template <class T>
void DoublyLL<T> :: InsertLast(T No)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = First;
    newn = new nodeDL<T>;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = No;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
        
    }
    iCount++;
}
template <class T>
void DoublyLL<T> :: InsertAtPos(T No, int iPos)
{
    int i = 0;
    if((iPos < 1) || (iPos  > iCount+1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeDL<T> * newn = NULL;
        struct nodeDL<T> * temp = First;
        newn = new nodeDL<T>;
        newn->next = NULL;
        newn->data = No;
        for (i=1 ; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}
template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"Unable to delete As teh linked list is empty!"<<endl;
        return;
    }
    if(First->next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->next->prev;
    }
    iCount--;

}
template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct nodeDL<T> * temp = First;
    if(First == NULL) 
    {
        cout<<"Unable to delete As teh linked list is empty!"<<endl;
        return;
    }
    if(First==NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
        iCount--;
}
template <class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    int i = 0;
    if((iPos < 1) || (iPos  > iCount))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeDL<T> * temp = First;
        struct nodeDL<T> * temp2 = NULL;
        for (i=1 ; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////
//Code of Singly Circular
///////
///////////////////////////////////////////////////////////////////////////////////////////////////
//Add your code here//

template <class T>
struct nodeSC
{
    T data;
    struct nodeSC * next;

};
template <class T>
class SinglyCL         
{
    public:
        struct nodeSC<T> * First;  
        struct nodeSC<T> * Last;      
        int iCount;

    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);


};
template <class T>
SinglyCL<T> :: SinglyCL()
{
    cout<<"Inside Constructor for Singly Circular Linked list"<<endl;
    First = NULL;
    Last = NULL;
    iCount = 0;
}
template <class T>
void SinglyCL<T>::Display()
{
    struct nodeSC<T> * temp = First;
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is empty!"<<endl;
        return;
    }
    do
    {
        cout<<"|"<<First->data<<"|<=>";
        First = First->next;
    }while(First!=Last->next);
    cout<<endl;
}
template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}
template <class T>
void SinglyCL<T> :: InsertFirst(T No)
{
    struct nodeSC<T> * newn = NULL;
    newn = new nodeSC<T>;
    newn->next = NULL;
    newn->data = No;

    if (First == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    iCount++;
}
template <class T>
void SinglyCL<T> :: InsertLast(T No)
{
    struct nodeSC<T> * newn = NULL;
    newn = new nodeSC<T>;
    newn->next = NULL;
    newn->data = No;

    if (First == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    iCount++;

}
template <class T>
void SinglyCL<T> :: InsertAtPos(T No, int iPos)
{
    int i = 0;
    if((iPos < 1) || (iPos  > iCount+1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeSC<T> * newn = NULL;
        struct nodeSC<T> * temp = First;
        newn = new nodeSC<T>;
        newn->next = NULL;
        newn->data = No;
        for (i=1 ; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}
template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Unable to delete As teh linked list is empty!"<<endl;
        return;
    }
    if(First==Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    iCount--;

}
template <class T>
void SinglyCL<T> :: DeleteLast()
{
    struct nodeSC<T> * temp = First;
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Unable to delete As teh linked list is empty!"<<endl;
        return;
    }
    if(First==Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        while(temp->next != Last)
        {
            temp = temp->next;
        }
        delete temp->next;
        Last = temp;

        Last->next = First;
    }
        iCount--;

}
template <class T>
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
    int i = 0;
    if((iPos < 1) || (iPos  > iCount))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeSC<T> * temp = First;
        struct nodeSC<T> * temp2 = NULL;
        for (i=1 ; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////
//Code of Stack
///////
///////////////////////////////////////////////////////////////////////////////////////////////////
//Add your code here//
template <class T>
struct nodest
{
    int data;
    struct nodest * next;
};

template <class T>
class Stack
{
    private:
        struct nodest<T> * First;
        int iCount;

    public:
        Stack();

        void Display();
        int Count();
        void Push(T iNo); //InsertFirst
        int Pop();      //DeleteFirst
};
template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
int Stack<T> :: Count()
{
    return iCount;
}
template <class T>
void Stack<T> :: Display()
{
    cout<<"Elements of the stack are: "<<endl;
    struct nodest<T> * temp = First;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl;

}
template <class T>
void Stack<T>::Push(T iNo)
{
    struct nodest<T> * newn = NULL;
    newn = new nodest<T>;
    newn->next= NULL;
    newn->data = iNo;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}
template <class T>
int Stack<T>::Pop()
{
    struct nodest<T> * temp = NULL;
    int iValue = 0;
    if(First == NULL)
    {
        cout<<"Unable to pop the element as the stack is empty!"<<endl;
        return -1;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;
        iCount--;

    }
    return iValue;
    
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////
//Code of Queue
///////
///////////////////////////////////////////////////////////////////////////////////////////////////
//Add your code here//

template <class T>
struct nodeq
{
    int data;
    struct nodeq * next;
};

template <class T>
class Queue
{
    private:
        struct nodeq<T> * First;
        int iCount;

    public:
        Queue();

        void Display();
        int Count();
        void EnQueue(T iNo); //InsertLast()
        int DeQueue();      //DeleteFirst()
};
template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}
template <class T>
int Queue<T>::Count()
{
    return iCount;
}
template <class T>
void Queue<T>::Display()
{
    cout<<"Elements of the queue are: "<<endl;
    struct nodeq<T> * temp = First;
    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<endl;

}
template <class T>
void Queue<T>::EnQueue(T iNo)
{
    struct nodeq<T> * newn = NULL;
    struct nodeq<T> * temp = NULL;
    newn = new nodeq<T>;
    newn->next= NULL;
    newn->data = iNo;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}
template <class T>
int Queue<T>::DeQueue()
{
    struct nodeq<T> * temp = NULL;
    int iValue = 0;
    if(First == NULL)
    {
        cout<<"Unable to remove the element as the queue is empty!"<<endl;
        return -1;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;
        iCount--;

    }
    return iValue;
    
}

///////////////////////////////////////////////////
//
///Start Of Main
///
/////////////////////////////////////////////////

int main()
{
//LL for integer
    cout<<"------------------------------Singly Linear Linked List -------------------------------------"<<endl;
    cout<<"---------------------Linked List of Integer-----------------------"<<endl;
    SinglyLL<int> *iobj = new SinglyLL<int>();
    int iRet2 = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet2 = iobj->Count();
    cout<<"Number of elements are: "<<iRet2<<endl;

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);
    
    iobj->Display();
    iRet2 = iobj->Count();
    cout<<"Number of elements are: "<<iRet2<<endl;

    iobj->DeleteFirst();
    iobj->Display();
    iRet2 = iobj->Count();
    cout<<"Number of elements are: "<<iRet2<<endl;

    iobj->DeleteLast();
    iobj->Display();
    iRet2 = iobj->Count();
    cout<<"Number of elements are: "<<iRet2<<endl;

    iobj->InsertAtPos(105,5);
    iobj->Display();
    iRet2 = iobj->Count();
    cout<<"Number of elements are: "<<iRet2<<endl;

    iobj->DeleteAtPos(5);
    iobj->Display();
    iRet2 = iobj->Count();
    cout<<"Number of elements are: "<<iRet2<<endl;

    //LL for characters

    cout<<"-----------------Linked List of Character------------------"<<endl;
    SinglyLL<char> *cobj = new SinglyLL<char>();
    int iRet = 0;

    cobj->InsertFirst('A');
    cobj->InsertFirst('B');
    cobj->InsertFirst('C');

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elements are: "<<iRet<<endl;

    cobj->InsertLast('D');
    cobj->InsertLast('E');
    cobj->InsertLast('F');
    
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elements are: "<<iRet<<endl;

    cobj->DeleteFirst();
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elements are: "<<iRet<<endl;

    iobj->DeleteLast();
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are: "<<iRet<<endl;

    cobj->InsertAtPos('V',5);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elements are: "<<iRet<<endl;

    cobj->DeleteAtPos(5);
    cobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are: "<<iRet<<endl;

    //LL for float
    cout<<"-----------------------Linked List of Float--------------------"<<endl;
    SinglyLL<float> *fobj = new SinglyLL<float>();
    int iRet3 = 0;

    fobj->InsertFirst(51.25f);
    fobj->InsertFirst(21.64f);
    fobj->InsertFirst(11.25f);

    fobj->Display();
    iRet3 = fobj->Count();
    cout<<"Number of elements are: "<<iRet3<<endl;

    fobj->InsertLast(101.2f);
    fobj->InsertLast(111.6f);
    fobj->InsertLast(121.58f);
    
    fobj->Display();
    iRet3 = fobj->Count();
    cout<<"Number of elements are: "<<iRet3<<endl;

    fobj->DeleteFirst();
    fobj->Display();
    iRet3 = fobj->Count();
    cout<<"Number of elements are: "<<iRet3<<endl;

    fobj->DeleteLast();
    fobj->Display();
    iRet3 = fobj->Count();
    cout<<"Number of elements are: "<<iRet3<<endl;

    fobj->InsertAtPos(105,5);
    fobj->Display();
    iRet3 = fobj->Count();
    cout<<"Number of elements are: "<<iRet3<<endl;

    fobj->DeleteAtPos(5);
    fobj->Display();
    iRet3 = fobj->Count();
    cout<<"Number of elements are: "<<iRet3<<endl;

    //LL for Double
    cout<<"-------------------Linked List of Double---------------------"<<endl;
    SinglyLL<double> *dobj = new SinglyLL<double>();
    int iRet4 = 0;

    dobj->InsertFirst(51.2565);
    dobj->InsertFirst(21.6413);
    dobj->InsertFirst(11.2546);

    dobj->Display();
    iRet4 = dobj->Count();
    cout<<"Number of elements are: "<<iRet4<<endl;

    dobj->InsertLast(101.254);
    dobj->InsertLast(111.6564);
    dobj->InsertLast(121.5854);
    
    dobj->Display();
    iRet4 = fobj->Count();
    cout<<"Number of elements are: "<<iRet4<<endl;

    dobj->DeleteFirst();
    dobj->Display();
    iRet4 = dobj->Count();
    cout<<"Number of elements are: "<<iRet4<<endl;

    dobj->DeleteLast();
    dobj->Display();
    iRet4 = dobj->Count();
    cout<<"Number of elements are: "<<iRet4<<endl;

    dobj->InsertAtPos(105,5);
    dobj->Display();
    iRet4 = dobj->Count();
    cout<<"Number of elements are: "<<iRet4<<endl;

    dobj->DeleteAtPos(5);
    dobj->Display();
    iRet4 = dobj->Count();
    cout<<"Number of elements are: "<<iRet4<<endl;

    cout<<"--------------------------------------Singly Circular Linked List -------------------------------------"<<endl;
    SinglyCL<int> *scobj = new SinglyCL<int>();
    int iReta = 0;

    scobj->InsertFirst(101);
    scobj->InsertFirst(51);
    scobj->InsertFirst(21);
    scobj->InsertFirst(11);
    scobj->Display();
    iReta = scobj->Count();
    cout<<"Number of elements after Insert First are: "<<iReta<<endl;

    scobj->InsertLast(111);
    scobj->InsertLast(121);
    scobj->InsertLast(151);
    scobj->Display();
    iReta = scobj->Count();
    cout<<"Number of elements after Insert Last are: "<<iReta<<endl;

    scobj->InsertAtPos(105,5);
    scobj->Display();
    iReta = scobj->Count();
    cout<<"Number of elements after Insert At position are: "<<iReta<<endl;

    scobj->DeleteFirst();
    scobj->Display();
    iReta = scobj->Count();
    cout<<"Number of elements after Delete First are: "<<iReta<<endl;

    scobj->DeleteLast();
    scobj->Display();
    iReta = scobj->Count();
    cout<<"Number of elements after Delete Last are: "<<iReta<<endl;

    scobj->DeleteAtPos(5);
    scobj->Display();
    iReta = scobj->Count();
    cout<<"Number of elements after Delete At position are: "<<iReta<<endl;


    cout<<"---------------------------------------Doubly Linear Linked List ---------------------------------------"<<endl;
    DoublyLL<int> *dlobj = new DoublyLL<int>();
    int iRetb = 0;

    dlobj->InsertFirst(101);
    dlobj->InsertFirst(51);
    dlobj->InsertFirst(21);
    dlobj->InsertFirst(11);
    dlobj->Display();
    iRetb = dlobj->Count();
    cout<<"Number of elements after Insert First are: "<<iRetb<<endl;

    dlobj->InsertLast(111);
    dlobj->InsertLast(121);
    dlobj->InsertLast(151);
    dlobj->Display();
    iRetb = dlobj->Count();
    cout<<"Number of elements after Insert Last are: "<<iRetb<<endl;

    dlobj->InsertAtPos(105,5);
    dlobj->Display();
    iRetb = dlobj->Count();
    cout<<"Number of elements after Insert At position are: "<<iRetb<<endl;

    dlobj->DeleteFirst();
    dlobj->Display();
    iRetb = dlobj->Count();
    cout<<"Number of elements after Delete First are: "<<iRetb<<endl;

    dlobj->DeleteLast();
    dlobj->Display();
    iRetb = dlobj->Count();
    cout<<"Number of elements after Delete Last are: "<<iRetb<<endl;

    dlobj->DeleteAtPos(5);
    dlobj->Display();
    iRetb = dlobj->Count();
    cout<<"Number of elements after Delete At position are: "<<iRetb<<endl;


    /////////////////////

    cout<<"------------Doubly Circular Linked List -------------------------------------"<<endl;
    DoublyCL<int> *idobj = new DoublyCL<int>();
    int iRet8 = 0;

    idobj->InsertFirst(51);
    idobj->InsertFirst(21);
    idobj->InsertFirst(11);
    idobj->Display();
    iRet8 = idobj->Count();
    cout<<"Number of nodes in Doubly Circular LinkedList: "<<iRet8<<endl;

    idobj->InsertLast(101);
    idobj->InsertLast(111);
    idobj->InsertLast(121);
    idobj->InsertLast(151);
    idobj->Display();
    iRet8 = idobj->Count();
    cout<<"Number of nodes in Doubly Circular LinkedList: "<<iRet8<<endl;

    idobj->DeleteFirst();
    idobj->Display();
    iRet8 = idobj->Count();
    cout<<"Number of nodes in Doubly Circular LinkedList: "<<iRet8<<endl;

    idobj->DeleteLast();
    idobj->Display();
    iRet8 = idobj->Count();
    cout<<"Number of nodes in Doubly Circular LinkedList: "<<iRet8<<endl;

    idobj->InsertAtPos(105,5);
    idobj->Display();
    iRet8 = idobj->Count();
    cout<<"Number of nodes in Doubly Circular LinkedList: "<<iRet8<<endl;

    idobj->DeleteAtPos(5);
    idobj->Display();
    iRet8 = idobj->Count();
    cout<<"Number of nodes in Doubly Circular LinkedList: "<<iRet<<endl;

    cout<<"------------------------------------Stack-------------------------------------------"<<endl;

    int iRetst = 0;
    Stack<int> *stobj = new Stack<int>();

    stobj->Push(10);
    stobj->Push(20);
    stobj->Push(30);
    stobj->Push(40);
    stobj->Display();
    iRetst = stobj->Count();
    cout<<"Number of elements in stack are: "<<iRetst<<endl;

    
    iRetst = stobj->Pop();
    cout<<"Popped element is : "<<iRetst<<endl;
    stobj->Display();
    iRetst = stobj->Count();
    cout<<"Number of elements in stack are: "<<iRetst<<endl;

    iRet = stobj->Pop();
    cout<<"Popped element is : "<<iRetst<<endl;
    stobj->Display();
    iRetst = stobj->Count();
    cout<<"Number of elements in stack are: "<<iRetst<<endl;

    stobj->Push(50);
    stobj->Display();
    iRetst = stobj-> Count();
    cout<<"Number of elements in stack are: "<<iRetst<<endl;



    cout<<"------------------------------------Queue-------------------------------------------"<<endl;

     int iRetq = 0;
    Queue<int> *qobj = new Queue<int>();

    qobj->EnQueue(10);
    qobj->EnQueue(20);
    qobj->EnQueue(30);
    qobj->EnQueue(40);
    qobj->Display();
    iRetq = qobj->Count();
    cout<<"Number of elements in queue are: "<<iRetq<<endl;

    
    iRetq = qobj->DeQueue();
    cout<<"Removed element is : "<<iRetq<<endl;
    qobj->Display();
    iRetq = qobj->Count();
    cout<<"Number of elements in queue are: "<<iRetq<<endl;

    iRetq = qobj->DeQueue();
    cout<<"Removed element is : "<<iRetq<<endl;
    qobj->Display();
    iRetq = qobj->Count();
    cout<<"Number of elements in queue are: "<<iRetq<<endl;

    qobj->EnQueue(50);
    qobj->Display();
    iRetq = qobj->Count();
    cout<<"Number of elements in queue are: "<<iRetq<<endl;



    return 0;
}