#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED


using std::cout;
using std::endl;

class Linklist;

class LinkNode{
    private:
        LinkNode *next;
        int data;
    public:
        LinkNode():data(0),next(0){};
        LinkNode(int a):data(a),next(0){};

        friend class Linklist;
};

class Linklist{
    private:
        LinkNode *first;
    public:
        Linklist();
        void PrintList();           // 印出list的所有資料
        void Push_front(int x);     // 在list的開頭新增node
        void Push_back(int x);      // 在list的尾巴新增node
        void Delete(int x);         // 刪除list中的 int x
        void Clear();               // 把整串list刪除
        void Reverse();             // 將list反轉: 7->3->14 => 14->3->7
};
Linklist::Linklist(){
    first=0;
};

void Linklist::PrintList(){
    if (first == 0){
        cout<<"List is empty!\n";
        return ;
    }
    LinkNode *current = first;
    cout<<"List is = ";
    while( current != 0){
        cout << current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

void Linklist::Push_front(int x){
    LinkNode *newNode = new LinkNode(x);          //配置新的記憶體

    if(first == 0){
        first=newNode;
        return ;
    }
    newNode->next = first;                        //先把first接在newNode後面
    first = newNode;                              //再把first指向newNode所指的記憶體位址
}

void Linklist::Push_back(int x){
    LinkNode *newNode = new LinkNode(x);

    if(first == 0){                                //看list是否有node,若沒有令node為first
        first == newNode;
        return ;
    }

    LinkNode *current = first;
    while(current->next !=0){
        current = current->next;
    }
    current->next = newNode;

}

void Linklist::Delete(int x){
    LinkNode *current =first;
    LinkNode *previous = 0;

    while( current!=0 && current->data!=x){         //Traversal
        previous = current;                         //如果current指向null 或者是 current->data ==x 就結束while loop
        current =current->next;
    }

    if(current == 0){                               //list沒有要刪的node或者為空
        cout<<"There is no "<<x<<" in list.\n";
    }
    else if (current == first){                     //要刪除的node剛好在list的開頭
        first = current->next;                      //把first移到下一個node
        delete current;                             //如果list只有一個node 那麼first就會指向NULL
        current = 0;                                //當指標被delete後,將其指向NULL, 可以避免不必要的BUG
    }
    else{
        previous->next = current->next;
        delete current;
        current = 0;
    }
}


void Linklist::Clear(){
    while(first!=0){
        LinkNode *current = first;
        first = first->next;
        delete current;
        current=0;
    }
}

void Linklist::Reverse(){
    if(first==0 || first->next==0){
        //list is empty or has only has one node
        return;
    }
    LinkNode *previous = 0,
             *current = first,
             *preceding = first->next;

    while(preceding != 0){
        current->next = previous;   //把current->next轉向
        previous = current;         //previous 往後挪
        current =preceding;         //把current往後挪
        preceding = preceding->next;//把preceding往後挪
                                    //preceding更新成NULL即跳出while loop
    }

    current->next = previous;       //此時curren位於最後一個node, 將current->next轉向
    first = current;                //更新first為current
}


#endif // LINKLIST_H_INCLUDED
