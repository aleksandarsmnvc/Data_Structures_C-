#include"TArrayHash.h"
TArrayHash::TArrayHash(int Size, int Step):HashStep{Step},TabSize{Size},FreePos{0},CurrPos{0},THashTable()
{
    pMark=new TTabRecord("Deleted",nullptr);
    pEmpty=new TTabRecord("Empty",nullptr);
    pRecs=new PTTabRecord[TabSize];
    for(int i=0;i<TabSize;i++)
    {
        pRecs[i]=pEmpty;
    }
}
TArrayHash::~TArrayHash()
{
    for(int i=0;i<TabSize;i++)
    {
        delete[] pRecs[i];
    }
    delete[] pRecs;
}
int TArrayHash:: IsFull ( ) const{return DataCount==TabSize;}
TKey TArrayHash::GetKey()const{return pRecs[CurrPos]->GetKey();}
PTDatValue TArrayHash::GetValuePTR()const{return pRecs[CurrPos]->GetValuePTR();}
PTDatValue TArrayHash::FindRecord(TKey k)
{
    int position=HashFunc(k);
    bool findFirst=false;
    CurrPos=position;
    if(pRecs[CurrPos]==pMark){FreePos=CurrPos;findFirst=true;}
    else if(pRecs[CurrPos]==pEmpty){FreePos=CurrPos;findFirst=true;return nullptr;}
    else if(GetKey()==k)return pRecs[CurrPos];
    else
    {
        CurrPos=GetNextPos(CurrPos);
        while(CurrPos!=position&&GetKey()!=k&&pRecs[CurrPos]!=pEmpty)
        {
            if(pRecs[CurrPos]==pEmpty||pRecs[CurrPos]==pMark){if(!findFirst){FreePos=CurrPos;findFirst=true;}}
            CurrPos=GetNextPos(CurrPos);
        }
    }
    if(CurrPos==position)return nullptr;
    else if(GetKey()==k)return pRecs[CurrPos];
    else{if(!findFirst)FreePos=CurrPos;return nullptr;}
}
void TArrayHash::InsRecord(TKey k,PTDatValue pVal)
{
    if(!IsFull())
    {
        PTDatValue find=FindRecord(k);
        if(find)std::cout<<"Already Inserted"<<std::endl;
        else
        {
            pRecs[FreePos]=new TTabRecord(k,pVal);
        }
        DataCount++;
    }
    else std::cout<<"Tablica Zapolnena!"<<std::endl;
}
void TArrayHash::DelRecord(TKey k)
{
    PTDatValue find=FindRecord(k);
    if(find)
    {
        PTTabRecord del=dynamic_cast<PTTabRecord>(find);
        delete del;
        del=pMark;
        DataCount--;
    }
}
void TArrayHash::Reset(void){CurrPos=0;}
int TArrayHash::IsTabEnded(void)const{return CurrPos==TabSize;}
void TArrayHash::GoNext(){CurrPos++;if(IsTabEnded())CurrPos=0;}
void TArrayHash::Print()
{
    for(int i=0;i<TabSize;i++)
    {
        if(pRecs[i]!=pEmpty)std::cout<<pRecs[i]->Key<<" "<<std::endl;
    }
}