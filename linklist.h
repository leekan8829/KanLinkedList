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
        void PrintList();           // �L�Xlist���Ҧ����
        void Push_front(int x);     // �blist���}�Y�s�Wnode
        void Push_back(int x);      // �blist�����ڷs�Wnode
        void Delete(int x);         // �R��list���� int x
        void Clear();               // ����list�R��
        void Reverse();             // �Nlist����: 7->3->14 => 14->3->7
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
    LinkNode *newNode = new LinkNode(x);          //�t�m�s���O����

    if(first == 0){
        first=newNode;
        return ;
    }
    newNode->next = first;                        //����first���bnewNode�᭱
    first = newNode;                              //�A��first���VnewNode�ҫ����O�����}
}

void Linklist::Push_back(int x){
    LinkNode *newNode = new LinkNode(x);

    if(first == 0){                                //��list�O�_��node,�Y�S���Onode��first
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
        previous = current;                         //�p�Gcurrent���Vnull �Ϊ̬O current->data ==x �N����while loop
        current =current->next;
    }

    if(current == 0){                               //list�S���n�R��node�Ϊ̬���
        cout<<"There is no "<<x<<" in list.\n";
    }
    else if (current == first){                     //�n�R����node��n�blist���}�Y
        first = current->next;                      //��first����U�@��node
        delete current;                             //�p�Glist�u���@��node ����first�N�|���VNULL
        current = 0;                                //����гQdelete��,�N����VNULL, �i�H�קK�����n��BUG
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
        current->next = previous;   //��current->next��V
        previous = current;         //previous ���ᮿ
        current =preceding;         //��current���ᮿ
        preceding = preceding->next;//��preceding���ᮿ
                                    //preceding��s��NULL�Y���Xwhile loop
    }

    current->next = previous;       //����curren���̫�@��node, �Ncurrent->next��V
    first = current;                //��sfirst��current
}


#endif // LINKLIST_H_INCLUDED
