/* MyList header */
#ifndef MYLIST_H
#define MYLIST_H

namespace Neeraj
{


class ForwardList
{
     public:
        ForwardList() : _head(NULL){ }        ~ForwardList();
        void pushFront(int newItem_);  // insert  item front 
        void popFront();              // delete item from front 
        void remove(int item_);      // remove item from forward list
        const int& front()const          // return const reference of item from front
        {
                return  empty() ?  throw "Empty List" : _head->_data;
        }; 
        void eraseAfter(int index_);   //erase element from forward list
        void insertAfter(int index_,int newItem_);   // insert element into forward list
        void display()const;              // print item 
        bool empty()const            //check for forward list empty
        {
            return _head == NULL  ? true : false;
        };
            
     private:   
        class Node
        {
            public:
            int    _data;
            Node * _next;
            Node(int item_) : _data(item_){ }
            Node *display()            //print item
            {
                std::cout << _data << std::endl;
                return _next;
            };
        };
        Node * _head;

};

}

#endif
