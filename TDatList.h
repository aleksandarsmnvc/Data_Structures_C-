#ifndef T_DAT_LIST
#define T_DAT_LIST
#include"TTabRecord.h"
struct Node
{
    PTTabRecord value;
    Node* next;
};
class TDatList
{
private:
    Node* head;
    int count;
public:
    TDatList();
    ~TDatList();
    void AddNode(TKey,PTDatValue);
    void DeleteNode(TKey k);
    PTTabRecord FindNode(TKey k);
    TKey HeadKey();
    PTDatValue HeadValuePtr();
    void Print();
};
#endif