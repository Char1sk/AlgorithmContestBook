#include <iostream>
// #include <stack>

// class Node
// {
// public:
//     int value;
//     Node *next;
//     Node(int v = 0, Node *n = nullptr) : value(v), next(n) {}
// };

// class List
// {
// public:
//     Node *head;
//     List() : head(new Node()) { head->next = head; }
//     ~List()
//     {
//         while (!isEmpty())
//         {
//             popFront();
//         }
//         delete head;
//     }
//     bool isEmpty()
//     {
//         return head->next == head;
//     }
//     void pushFront(int v)
//     {
//         head->next = new Node(v, head->next);
//     }
//     void popFront()
//     {
//         if (!isEmpty())
//         {
//             Node *temp = head->next;
//             head->next = temp->next;
//             delete temp;
//         }
//     }
//     void erase(int v)
//     {
//         for (Node *beg = head; beg->next != head; beg = beg->next)
//         {
//             if (beg->next->value == v)
//             {
//                 Node *temp = beg->next;
//                 beg->next = temp->next;
//                 delete temp;
//             }
//         }
//     }
// };

int main()
{
    int total, k1, k2;
    while ( (std::cin >> total >> k1 >> k2) && total && k1 && k2 )
    {
        // List lst;
        // for (int i = total; i >= 1; --i)
        // {
        //     lst.pushFront(i);
        // }
        bool isOut[20] {0};
        int outCount = 0;
        int index1 = -1, index2 = total;
        while (outCount != total)
        {
            for (int i = 0; i < k1; ++i)
            {
                do
                {
                    ++index1;
                    if (index1 == total)
                    {
                        index1 = 0;
                    }
                } while (isOut[index1]);
            }
            for (int i = 0; i < k2; ++i)
            {
                do
                {
                    --index2;
                    if (index2 == -1)
                    {
                        index2 = total-1;
                    }
                } while (isOut[index2]);
            }
            isOut[index1] = true;
            isOut[index2] = true;
            if (outCount)
            {
                std::cout << ',' ;
            }
            if (index1 != index2)
            {
                outCount += 2;
                printf("%3.d%3.d", index1+1, index2+1);
            }
            else
            {
                outCount += 1;
                printf("%3.d", index1+1);
            }
            
        }
        std::cout << std::endl;
    }
    return 0;
}