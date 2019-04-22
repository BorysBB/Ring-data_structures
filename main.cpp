#include <iostream>
using namespace std;
class Iterator;
template<typename key, typename info>
class Ring{
struct node{
key id;
info value;
node *next;
node *prev;
};
node* first=NULL;
public:
        class Iterator{
        node* iterator;
        public:
        Iterator()
        {
        iterator = NULL;
        }
        Iterator(node *source)// copyconstructor
        {
            iterator = source;
        }
        const Iterator &operator = (const Iterator &copyIter)
        {
            iterator = copyIter.iterator;
            return *this;
        }
        bool operator == (const Iterator &compare)const
        {
            return iterator == compare.iterator;
        }
        Iterator operator ++ ()
        {
            if(iterator)
                iterator = iterator->next;
            return *this;
        }
        Iterator operator ++ (int)
        {
            Iterator copy_i(iterator);
            if(iterator != NULL)
                iterator = iterator->next;
            return copy_i;
        }
        Iterator operator -- ()
        {
            if(iterator)
                iterator = iterator->prev;
            return *this;
        }
        Iterator operator -- (int)
        {
            Iterator copy_i(iterator);
            if(iterator != NULL)
                iterator = iterator->prev;
            return copy_i;
        }
        key getKey()
        {
            return iterator->id;
        }
        info getInfo()
        {
            return iterator->value;
        }
        bool isnull()
        {
            if(iterator)
            {
                return false;
            }
            else
            {
            return true;
            }
        }
        void print_iterator()
        {
            cout<<"Key: "<<iterator->id<<endl;
            cout<<"Value: "<<iterator->value<<endl;
        }
        bool operator != (const Iterator &compare)const
        {
            return iterator != compare.iterator;
        }
        };

    Ring();
    ~Ring();
    Ring(const Ring &source);
    void add_node_end(key ID, info val);
    void add_node_between(key after, key before, key ID, info VAL);
    void add_node_on_position(int position,key ID, info val);
    void push_front(key ID, info val);
    void push_back(key ID, info val);
    void remove_node_key(key ID);
    void remove_from_position(int position);
    void remove_ring();
    void pop_front();
    void pop_back();
    void print_ring();
    Ring& operator=(const Ring & source);
    Iterator begin()const
    {
        return Iterator(first);
    }
    Iterator end()const
    {
        return Iterator(first->prev);
    }
};
template<typename key, typename info>
Ring<key, info> produce(const Ring<key, info> &r1, int start1, int len1, bool dir1, const Ring<key,info>&r2, int start2, int len2, bool dir2, int repeat);
int main()
{
    Ring<int,int> R1;
    R1.add_node_end(1,1);
    R1.add_node_end(2,2);
    R1.add_node_end(3,3);
    R1.add_node_end(4,4);
    R1.add_node_end(5,5);
    R1.add_node_end(6,6);
    R1.remove_from_position(-6);
    R1.print_ring();
//Ring<int,int>::Iterator iterator1;
//iterator1=R1.begin();
//iterator1.print_iterator();
//iterator1++;
//iterator1--;
//iterator1.print_iterator();
//
//    Ring<int,int> R2;
//    R2.add_node_end(10,10);
//    R2.add_node_end(20,20);
//    R2.add_node_end(30,30);
//    R2.add_node_end(40,40);
//    R2.add_node_end(50,50);
//    R2.add_node_end(60,60);
//    R2.add_node_end(70,70);
//    cout<<"------------------"<<endl;
//    cout<<"produce function result"<<endl;
//    Ring<int,int> R3;
//    cout<<"R1"<<endl;
//    R1.print_ring();
//    cout<<"R2:"<<endl;
//    R2.print_ring();
////    cout<<"Improper usage"<<endl;
////    produce(R1,-100,3,true,R2,4,2,false,2);
//    cout<<"Proper usage"<<endl;
//    cout<<""<<endl;
//
//    R3 = produce(R1,10,2,false,R2,-10,2,true,1);
//    R3.print_ring();
//    cout<<"------------------"<<endl;
//    cout<<"Adding functions tests"<<endl;
//    cout<<" "<<endl;
//    cout<<"add_node_end test"<<endl;
//    Ring<float,float> R4;
//    R4.add_node_end(1.1,1.1);
//    R4.add_node_end(2.2,2.2);
//    R4.add_node_end(3.3,3.3);
//    R4.add_node_end(4.4,4.4);
//    R4.print_ring();
//    cout<<" "<<endl;
//    cout<<"add_node_between test"<<endl;
//    R4.add_node_between(1.1, 2.2, 5.5 ,6.6);
//    R4.print_ring();
//    cout<<"Improper usage"<<endl;
//    R4.add_node_between(1.1, 3.3, 5.5 ,6.6);
//    R4.add_node_between(10.5, 100.1, 6.6, 7.7);
//    cout<<" "<<endl;
//    cout<<"add_node_on_position test"<<endl;
//    R4.add_node_on_position(0,8.8, 9.9);
//    R4.print_ring();
//    cout<<endl;
//    R4.add_node_on_position(-1,8.8, 9.9);
//    R4.print_ring();
//    cout<<"Improper usage"<<endl;
//    R4.add_node_on_position(10, 9.9, 9.9);
//
//    cout<<" "<<endl;
//    cout<<"push_front and push_back test"<<endl;
//    Ring<int,int>R8;
//    R8.add_node_end(1,1);
//    R8.push_back(99,99);
//    R8.push_front(100,100);
//    R8.push_front(111,111);
//    R8.print_ring();
//    cout<<" "<<endl;
//    cout<<"pop_front and pop_back test"<<endl;
//    cout<<"Ring before"<<endl;
//    R8.print_ring();
//    cout<<"pop_front"<<endl;
//    R8.pop_front();
//    R8.print_ring();
//    cout<<"pop_back"<<endl;
//    R8.pop_back();
//    R8.print_ring();
//    cout<<"Removing from empty ring"<<endl;
//    R8.pop_back();
//    R8.pop_back();
//    R8.pop_back();
//    R8.pop_back();
//    R8.pop_front();
//    R8.print_ring();
//
//    cout<<"------------------"<<endl;
//    cout<<"Removing functions tests"<<endl;
//    cout<<"remove_from_position"<<endl;
//    R4.remove_from_position(0);
//    R4.print_ring();
//    cout<<endl;
//    R4.remove_from_position(-1);
//    R4.print_ring();
//    cout<<endl;
//    cout<<"improper usage"<<endl;
//    R4.remove_from_position(100);
//
//    cout<<"remove_ring"<<endl;
//    R4.remove_ring();
//    R4.print_ring();
//    cout<<"------------------"<<endl;
//    cout<<"Assigning operator test"<<endl;
//    Ring<int,int>R5;
//    R5.add_node_end(1,1);
//    R5.add_node_end(2,2);
//    R5.add_node_end(3,3);
//    R5.add_node_end(4,4);
//    R5.add_node_end(5,5);
//    Ring<int,int>R6;
//    R6.add_node_end(6,6);
//    R6.add_node_end(7,7);
//    R6.add_node_end(8,8);
//    R6.add_node_end(9,9);
//    R6.add_node_end(10,10);
//    cout<<"before: "<<endl;
//    R5.print_ring();
//    cout<<"after: "<<endl;
//    R5=R6;
//    R5.print_ring();
//
//    cout<<"------------------"<<endl;
//    cout<<"copy constructor test"<<endl;
//    Ring<int,int>R7(R5);
//    R7.print_ring();
    return 0;
}
template<typename key, typename info>
Ring<key, info> produce(const Ring<key, info> &r1, int start1, int len1, bool dir1, const Ring<key,info>&r2, int start2, int len2, bool dir2, int repeat)
{
    int abort=0;
    typename Ring<key, info>::Iterator iter1 = r1.begin();
    typename Ring<key, info>::Iterator iter2 = r2.begin();
    Ring<key, info> Result;
    typename Ring<key, info>::Iterator iter1_firstPrev = r1.begin();
    iter1_firstPrev--;
    typename Ring<key, info>::Iterator iter2_firstPrev = r2.begin();
    iter2_firstPrev--;
    typename Ring<key, info>::Iterator iter1_firstNext = r1.begin();
    iter1_firstNext++;
    typename Ring<key, info>::Iterator iter2_firstNext = r2.begin();
    iter2_firstNext++;
    int counter_one=0;
    int step1_counter=0;
    int counter_two=0;
    int step2_counter=0;
    int counter=0;
    if(len1<0 || len2<0)
    {
    cout<<"Length can not be smaller than 0"<<endl;
    abort++;
    }
    if(iter1==NULL && iter2==NULL)
    {
        cout<<"Rings are empty"<<endl;
    }
    else if(iter1!=NULL && iter2==NULL)
    {
        int limit1=0;
        int licznik1=0;
        counter_one=0;
        limit1=len1*repeat;
        iter1=r1.begin();
        if(start1>=0)
        {
            while(counter_one!=start1)
            {
                counter_one++;
                iter1++;
            }

        }
        else if(start1<0)
        {
            while(counter_one!=start1)
            {
                counter_one++;
                iter1--;
            }
        }
        if(dir1==true)
        {
            while(licznik1<limit1)
            {
                Result.add_node_end(iter1.getKey(), iter1.getInfo());
                iter1++;
                licznik1++;
            }
        }
        else
        {
            while(licznik1<limit1)
            {
                Result.add_node_end(iter1.getKey(), iter1.getInfo());
                iter1--;
                licznik1++;
            }
        }
    }
    else if(iter1==NULL && iter2!=NULL)
    {
        int limit2=0;
        int licznik2=0;
        limit2=len2*repeat;
        iter2=r2.begin();
        if(start2>=0)
        {
            while(counter_two!=start2)
            {
                counter_two++;
                iter2++;
            }
        }
        else if(start2<0)
        {
            while(counter_two!=start2)
            {
                counter_two++;
                iter2++;
            }
        }
        if(dir2==true)
        {
            while(licznik2<limit2)
            {
                Result.add_node_end(iter2.getKey(), iter2.getInfo());
                iter2++;
                licznik2++;
            }
        }
        else
        {
            while(licznik2<limit2)
            {
                Result.add_node_end(iter2.getKey(), iter2.getInfo());
                iter2--;
                licznik2++;
            }
        }
    }
    else
    {
    ///setting start position from 1 ring
    if(start1>=0)
    {
    while(counter_one != start1)
    {
        counter_one++;
        iter1++;
    }
    }
    else if(start1<0)
    {
        while( counter_one != start1)
    {
        counter_one--;
        iter1--;
    }
    }
       ///setting start position from 2 ring
    if(start2>=0)
    {
    while(counter_two != start2)
    {
        counter_two++;
        iter2++;
    }
    }
    else if(start2<0)
    {
        while(counter_two != start2)
    {
        counter_two--;
        iter2--;
    }
    }
    if(abort!=0)
    {
        cout<<"Wrong starting position"<<endl;
    }
    else
    {
    ///creating new ring
    while(counter<repeat)
    {
        if(dir1==true)   ///1 clockwise
        {
            step1_counter=0;
            while(step1_counter<len1)
            {
                Result.add_node_end(iter1.getKey(), iter1.getInfo());
                iter1++;
                step1_counter++;
            }
        }
        else       ///1 counter-clockwise
        {
            step1_counter=0;
            while(step1_counter<len1)
            {
                Result.add_node_end(iter1.getKey(), iter1.getInfo());
                iter1--;
                step1_counter++;
            }
        }
        if(dir2==true)   ///2 clockwise
        {
            step2_counter=0;
            while(step2_counter<len2)
            {
                Result.add_node_end(iter2.getKey(), iter2.getInfo());
                iter2++;
                step2_counter++;
            }
        }
        else        ///2 counter-clockwise
        {
            step2_counter=0;
            while(step2_counter<len2)
            {
                Result.add_node_end(iter2.getKey(), iter2.getInfo());
                iter2--;
                step2_counter++;
            }
        }
        counter++;
    }
    return Result;
    }
    }
}
template<typename key, typename info>
Ring<key, info>::Ring()
  {
      node* first=NULL;
      node* next=NULL;
      node* prev=NULL;
  }
template<typename key, typename info>
Ring<key, info>::~Ring()
 {
     first=NULL;
     node* next=NULL;
 }
template<typename key, typename info>
Ring<key, info>::Ring(const Ring &source)
{
    node* s_curr = source.first;
    node* curr = first;
    if(source.first==NULL)
    {
        cout<<"Source ring is empty"<<endl;
    }
    else
    {
        remove_ring();
        do
        {
            add_node_end(s_curr->id, s_curr->value);
            s_curr=s_curr->next;
        }while(s_curr!=source.first);
    }
}
template<typename key, typename info>
    void Ring<key, info>::add_node_end(key ID, info val)
    {
        if(first==NULL)
        {
            node *n = new node;
            first=n;
            n->id = ID;
            n->value = val;
            n->next = first;
            n->prev = first;
            return;
        }
        else
        {
            node* curr = first;
            while(curr->next != first)
            {
                curr=curr->next;
            }
            node *n = new node;
            n->id = ID;
            n->value = val;
            curr->next=n;
            n->next=first;
            n->prev=curr;
            first->prev=n;
        }
    }
template<typename key, typename info>
void Ring<key, info>::add_node_between(key after, key before, key ID, info VAL)
{
    node* curr=first;
    node* temp=first->prev;
    int counter=0;
    if(first == NULL && first->next==first)
    {
        cout<<"No such place"<<endl;
    }
    else
    {
        while(curr!=first->prev)
        {
            if(temp->id==after && curr->id == before)
            {
                node* n= new node;
                n->id=ID;
                n->value=VAL;
                n->next=curr;
                curr->prev=n;
                n->prev=temp;
                temp->next=n;
                temp=temp->next;
                counter++;
            }
            else
            {
                temp=curr;
                curr=curr->next;
            }
        }
            if(counter==0)
            {
                cout<<"No such place"<<endl;
            }
    }
}
template<typename key, typename info>
void Ring<key, info>::add_node_on_position(int position,key ID, info val)
{
    int added=0;
    if(first==NULL && position!=0)
    {
        cout<<"No such position"<<endl;
    }
    else if(first == NULL && position == 0)
    {
        node* n = new node;
        n->id=ID;
        n->value=val;
        n->next=n;
        n->prev=n;
        first=n;
        added++;
    }
    else
    {
        if(position>=0)
        {
        int counter = 0;
        node* curr = first;
        while(curr != first->prev && counter<position)
        {
            curr=curr->next;
            counter++;
        }
        if(counter==position)
        {
            if(counter==0)
            {
            node *temp=curr->prev;
            node* n = new node;
            n->id=ID;
            n->value=val;
            n->next=curr;
            curr->prev=n;
            n->prev=temp;
            temp->next=n;
            first=n;
            added++;
            }
            else
            {
            node *temp=curr->prev;
            node* n = new node;
            n->id=ID;
            n->value=val;
            n->next=curr;
            curr->prev=n;
            n->prev=temp;
            temp->next=n;
            added++;
            }
        }
        }
        else
        {
        int counter = 0;
        node* curr = first;
        while(curr != first->next && counter!= position)
        {
            curr=curr->prev;
            counter--;
        }
            if(counter==position)
            {
            node *temp=curr->next;
            node* n = new node;
            n->id=ID;
            n->value=val;
            n->next=temp;
            temp->prev=n;
            n->prev=curr;
            curr->next=n;
            added++;
            }
        }
        if(added==0)
        {
            cout<<"No such position"<<endl;
        }
    }
}

template<typename key, typename info>
void Ring<key, info>::push_front(key ID, info val)
{
    add_node_on_position(0, ID, val);
}
template<typename key, typename info>
void Ring<key, info>:: push_back(key ID, info val)
{
    if(first==NULL || first->next==first)
    {
        add_node_end(ID,val);
    }
    else
    {
    add_node_on_position(-1, ID, val);
    }
}

template<typename key, typename info>
void Ring<key, info>::remove_node_key(key ID)
{
    node *curr = first;
    node *temp = first;
    node *help = first;
    node *temporary = NULL;
    if(first==NULL)
    {
        cout<<"Ring is empty"<<endl;
    }
    else if(first->next==first)
    {
        if(first->id==ID)
        {
            first=NULL;
            delete first;
        }
    }
    else
    {
        temporary=first->prev;
        while(curr!=temporary && first->next!=temporary)
        {
            if(curr->id==ID && curr!=first)
            {
            node* delPtr=curr;
            curr=curr->next;
            curr->prev=help;
            help->next=curr;
            delete delPtr;
            }
            else if(curr->id==ID && curr==first)
            {
            node *delPtr = first;
            first=first->next;
            curr=curr->next;
            curr->prev=temporary;
            temporary->next=curr;
            delete delPtr;
            }
            else
            {
            help=curr;
            curr=curr->next;
            }
        }
        if(curr==temporary && curr->id == ID)
        {
            if(temporary->next==temporary)
            {
                first=NULL;
                delete first;
                delete temporary;
            }
        }
    }
}
template<typename key, typename info>
void Ring<key, info>::remove_from_position(int position)
{
    int counter=0;
    node *current=first;
    node *temp=first;
    if(first==NULL)
    {
        cout<<"Ring is empty"<<endl;
    }
    if(position>0)
    {
        while(counter<position)
        {
            current=current->next;
            counter++;
        }
        if(current==first)
        {
            pop_front();
        }
        else
        {
            node *delPtr = current;
            current=current->next;
            temp=delPtr->prev;
            temp->next=current;
            current->prev=temp;
            delete delPtr;
        }
    }
    else if(position==0 && first->next!=first)
    {
        node* delPtr=first;
        node *current=first->prev;
        first=first->next;
        current->next=first;
        first->prev=current;
        delete delPtr;
    }
    else if(position==0 && first->next==first)
    {
        node *delPtr=first;
        first=NULL;
        delete delPtr;
    }
    else if(position<0)
    {
        while(counter>position)
        {
            current=current->prev;
            counter--;
        }
        if(current==first)
        {
            pop_front();
        }
        else
        {
            node *delPtr = current;
            current=current->next;
            temp=delPtr->prev;
            temp->next=current;
            current->prev=temp;
            delete delPtr;
        }
    }
}
template<typename key, typename info>
void Ring<key, info>::remove_ring()
{
    if(first==NULL)
    {
        cout<<"Ring is empty"<<endl;
    }
    else if(first->next==first)
    {
        first=NULL;
        delete first;
    }
    else
    {
        node *temp=first ->prev;
        node *curr=NULL;
        while(first->next!=temp)
        {
            node *delPtr=first;
            first=first->next;
            delete delPtr;
        }
        first=NULL;
        delete first;
        delete temp;
    }
}
template<typename key, typename info>
void Ring<key, info>::pop_back()
{
    if(first==NULL)
    {
        cout<<"Ring empty"<<endl;
    }
    else if(first->next==first)
    {
        remove_ring();
    }
    else
    {
    remove_from_position(-1);
    }
}
template<typename key, typename info>
void Ring<key, info>::pop_front()
{
    if(first==NULL)
    {
        cout<<"Ring empty"<<endl;
    }
    else
    {
    remove_from_position(0);
    }
}
template<typename key, typename info>
void Ring<key, info>::print_ring()
{
    if(first==NULL)
    {
        cout<<"Ring is empty"<<endl;
        return;
    }
    else if(first->next==first)
    {
            cout<<"Key: "<<first->id<<endl;
            cout<<"Value: "<<first->value<<endl;
    }
    else
    {
        node*curr=first;
        do
        {
            cout<<"Key: "<<curr->id<<endl;
            cout<<"Value: "<<curr->value<<endl;
            cout<<" "<<endl;
            curr = curr->next;
        }while(curr!= first);
    }
}

template<typename key, typename info>
Ring<key, info> & Ring<key,info>:: operator=(const Ring<key,info> & source)
{
    node* s_curr = source.first;
    node* curr = first;
    if(source.first==NULL)
    {
        cout<<"Source ring is empty"<<endl;
    }
    else
    {
        remove_ring();
        do
        {
            add_node_end(s_curr->id, s_curr->value);
            s_curr=s_curr->next;
        }while(s_curr!=source.first);
    }
}
