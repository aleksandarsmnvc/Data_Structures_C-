#include"TDatList.h"
TKey TDatList::HeadKey(){return head->value->GetKey();}
PTDatValue TDatList::HeadValuePtr(){return head->value->GetValuePTR();}
void TDatList::AddNode(TKey k,PTDatValue pVal)
{
    Node* new_node=new Node();
    if(new_node)
    {
        new_node->value=new TTabRecord(k,pVal);
        new_node->next=head;
        head=new_node;
    }
}
PTTabRecord TDatList::FindNode(TKey k)
{
    Node* temp=head;
    while(temp)
    {
        if(temp->value->GetKey()==k)return temp->value;
        temp=temp->next;
    }
    return nullptr;
}
void TDatList::DeleteNode(TKey k)
{
    PTTabRecord find=FindNode(k);
    if(find)
    {
        if(find==head->value)
        {
            delete head;
            head=nullptr;
        }
        else
        {
            Node* temp=head;
            while(temp->next->value!=find)temp=temp->next;
            Node* next_node=temp->next->next;
            delete temp->next;
            temp->next=next_node;
        }
    }
}
TDatList::TDatList():head{nullptr},count{0}{}
TDatList::~TDatList()
{
    Node* prev=head;
    Node* curr=head->next;
    while(curr!=nullptr)
    {
        delete prev;
        prev=curr;
        curr=curr->next;
    }
    delete prev;
}
void TDatList::Print()
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        std::cout<<temp->value->GetKey()<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}