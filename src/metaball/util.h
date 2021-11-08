#include <vector>
#include <iostream>

class Util
{
public:
    // template<typename T>
    class Node
    {
    public:
        int data;
        int id;
        bool isSplit;
        bool first;
        bool last;
        Node *next,*prev;
        Node(void)
        {
            next = nullptr;
            prev = nullptr;
            isSplit = false;
            last = false;
        }
        ~Node(void)
        {
            next = nullptr;
            prev = nullptr;
            isSplit = false;
            last = false;
        }

        void InsertAtEnd(Node inserting)
        {
            
        }
    };

    
    // template<typename T>
    Node* MakeCircularList(std::vector<int> input,std::vector<int> split)
    {
        // // returns first(head) of the list

        Node *head = nullptr, *tail = nullptr;
        int idx = 0;
        for(auto i : input)
        {
            auto *newElem = new Node;
            newElem->data = i;
            newElem->id = idx;
            for(auto spl: split)
            {
                if(spl==newElem->data)
                {
                    newElem->isSplit=true;
                }
            }

            if(nullptr!=head)
            {
                tail->next=newElem;
                newElem->prev=tail;
                tail=newElem;
            }
            else
            {
                head=newElem;
                tail=newElem;
            }
            idx++;
            


        }
        tail->last = true;

        // // loop it
        // tail->next = head;

        return head;
    }
};

