#include <iostream>
#include "linklist.h"
using std::cout;
using std::endl;

int main()
{
    Linklist mylist;
    mylist.PrintList();
    mylist.Push_front(1);
    mylist.Push_front(2);
    mylist.PrintList();
    mylist.Push_back(3);
    mylist.PrintList();
    mylist.Push_back(4);
    mylist.PrintList();
    mylist.Delete(3);
    mylist.PrintList();
    mylist.Reverse();
    mylist.PrintList();
    mylist.Clear();
    mylist.PrintList();
    return 0;
}
