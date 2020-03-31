#ifndef MYQUERY_H
#define MYQUERY_H
#include <QDebug>
template <class T>
class MyQuery
{
public:
    struct node
    {
        T x;
        node *next,*prev;
    };
    MyQuery()
    {
        head = NULL;
        tale = NULL;
        //head = new node();
        //tale = head;
    }
    void EnqueueFirst(T x)
    {
        count++;
        node *Q = new node();
        Q->x = x;
        Q->next = head;
        if (head!=NULL) head->prev = Q;
        else tale = Q;
        head = Q;
    }
    T DequeueFirst()
    {
        if (count == 0) throw (-1);
        T x = head->x;
        node *Q = head;
        head = head->next;
        delete Q;
        count--;
        if (count==0) tale=NULL;
        return x;
    }
    T PeekFirst ()
    {
        if (count == 0) throw (-1);
        return head->x;
    }
    void EraseAt(int p)
    {
        if (p<0 || p>count-1) throw (-1);
        if (p==0)
        {
            DequeueFirst();
            return;
        }
        if (p==count-1)
        {
            DequeueLast();
            return;
        }
        node *Q = head;
        for (int i = 0;i<p;i++)
            Q=Q->next;
        Q->next->prev=Q->prev;
        Q->prev->next=Q->next;
        delete Q;
        count--;
        if (count==0)
        {
            head = NULL;
            tale = NULL;
        }
    }
    int Count ()
    {
        return count;
    }
    void EnqueueLast(T x)
    {
        count++;
        node *Q = new node();
        Q->x = x;
        Q->prev = tale;
        if (tale!=NULL) tale->next = Q;
        else head = Q;
        tale = Q;
    }
    T DequeueLast()
    {
        if (count == 0) throw (-1);
        T x = tale->x;
        node *Q = tale;
        tale = tale->prev;
        delete Q;
        count--;
        if (count==0) head=NULL;
        return x;
    }
    T PeekLast()
    {
        if (count == 0) throw (-1);
        return tale->x;
    }
    void Clear()
    {
        while (count!=0) DequeueLast();
    }
    bool Empty()
    {
        if (count==0) return true;
        else return false;
    }
    void Insert(int p,int x)
    {
        node *Q = head;
        if (p<0 || p>count) throw (-1);
        if (p==0)
        {
            EnqueueFirst(x);
            return;
        }
        if (p==count)
        {
            EnqueueLast(x);
            return;
        }
        for (int i = 0;i<p;i++)
            Q=Q->next;
        node *P = new node;
        P->x = x;
        P->next = Q;
        P->prev = Q->prev;
        Q->prev->next = P;
        Q->prev = P;
        count++;
    }
    void Swap (int p1,int p2)
    {
        if (p1<0 || p1>count-1 || p2<0 || p2>count-1) throw (-1);
        if (p1==p2) return;
        node * Q1 = head;
        for (int i = 0;i<p1;i++)
            Q1 = Q1->next;
        node * Q2 = head;
        for (int i = 0;i<p2;i++)
            Q2 = Q2->next;
        int x = Q1->x;
        Q1->x = Q2->x;
        Q2->x = x;

        //swap (Q1->x,Q2->x);
        //swap (Q1->,Q2->x);
        //swap (Q1->x,Q2->x);
    }
    node *Last()
    {
        return tale;
    }
    node *First()
    {
        return head;
    }
private:
    node *head;
    node *tale;
    int count = 0;
};

#endif // MYQUERY_H
