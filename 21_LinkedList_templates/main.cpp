#include <iostream>
using namespace std;

// A linked list node
template<typename T>

struct Data {
    T m_data;
    Data()
    {
        m_data = 0;
    }
};

template <typename T>
struct Node
{
   Node();
   Data<T> m_data;
   Node<T> *prev;
   Node<T> *next;
};

template <typename T>
Node<T>::Node()
{
   prev = nullptr;
   next = nullptr;
}

template<typename T>
class LinkedList {
  
  private:
    Node<T> *pHead;
    Node<T> Head;
  public:
    LinkedList();
    void insertLast(T data);    
    void print(void);
    void findDelete(T key);
    ~LinkedList();
};

template <typename T>
LinkedList<T>::LinkedList()
{
    this->pHead = &Head;
    pHead->m_data.m_data = 0;
    pHead->next = nullptr;
    pHead->prev = nullptr;
}

template <typename T>
void LinkedList<T>::insertLast(T datain)
{
    Node<T> *pTrav = this->pHead; 
    Node<T> *pTemp = new Node<T>;
    if(!pTemp)
    {
        //throw 1;
        return;
    }

    while(pTrav->next != NULL)
    {
        pTrav = pTrav->next;
    }

    pTrav->next = pTemp;
    pTemp->next = NULL;
    pTemp->prev = pTrav;
    pTemp->m_data.m_data = datain;
}

template <typename T>
void LinkedList<T>::print(void)
{
    if(this->pHead->next == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node<T> *pTemp = pHead->next;

    cout << "List is: ";
    while(pTemp != NULL)
    {
        cout << pTemp->m_data.m_data << ' ';
        pTemp = pTemp->next;
    }
    cout << endl;
}

template<typename T>
void LinkedList<T>::findDelete(T Key)
{
    Node<T> *pTrav = pHead->next;

    while(pTrav->next != NULL)
    {
        if(pTrav->m_data.m_data == Key)
        {
            pTrav->prev->next = pTrav->next;
            pTrav->next->prev = pTrav->prev;
            delete(pTrav);
            pTrav = NULL;
            break;
        }
        else
        {
            pTrav = pTrav->next;
        }
    }
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    cout<<"In default destructor.."<<endl;
}

int main() {
    LinkedList<int> LL;
    
    LL.insertLast(10);
    LL.insertLast(20);
    LL.insertLast(30);
    LL.insertLast(40);
    LL.insertLast(50);
    LL.print();
    LL.findDelete(30);
    LL.insertLast(60);
    LL.print();
}
