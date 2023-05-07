#include"TListHash.h"
int TListHash::IsFull()const{return 0;}
TListHash::TListHash(int Size):TabSize{Size},CurrList{0}
{
    pList=new PTDatList[Size];
    for(int i=0;i<Size;i++)
    {
        pList[i]=new TDatList();
    }
}
TKey TListHash::GetKey()const
{
    return pList[CurrList]->HeadKey();
}
PTDatValue TListHash::GetValuePTR()const
{
    return pList[CurrList]->HeadValuePtr();
}
PTDatValue TListHash::FindRecord (TKey k)
{
    int pos=HashFunc(k);
    CurrList=pos;
    return pList[pos]->FindNode(k);
}
void TListHash::InsRecord(TKey k,PTDatValue pVal)
{
    if(!FindRecord(k))
    {
        pList[CurrList]->AddNode(k,pVal);
    }
}
void TListHash::DelRecord(TKey k)
{
    if(FindRecord(k))
    {
        pList[CurrList]->DeleteNode(k);
    }
}
TListHash::~TListHash()
{
    for(int i=0;i<TabSize;i++)
    {
        delete[] pList[i];
    }
    delete[] pList;
}
void TListHash::Print()
{
    for(int i=0;i<TabSize;i++)
    {
        pList[i]->Print();
    }
}
