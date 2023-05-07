#include"TArrayTable.h"
TArrayTable::TArrayTable(int Size):TTable(),TabSize{Size},CurrPos{0} 
{
    pRecs=new PTTabRecord[TabSize];
}
int TArrayTable::IsFull()const
{
    return DataCount==TabSize;
}
int TArrayTable::GetTabSize()const{return TabSize;}
TKey TArrayTable::GetKey()const{return pRecs[CurrPos]->GetKey();}
PTDatValue TArrayTable::GetValuePTR (void) const{return pRecs[CurrPos]->GetValuePTR();}
TKey TArrayTable::GetKey(TDataPos mode) const
{
    switch (mode)
    {
    case FIRST_POS:
        return pRecs[0]->GetKey();
        break;
    case CURRENT_POS:
        return GetKey();
        break;
    case LAST_POS:
        return pRecs[TabSize]->GetKey();
        break;
    default:
        return "Wrong mode";
        break;
    }
}
PTDatValue TArrayTable::GetValuePTR(TDataPos mode) const
{
    switch (mode)
    {
    case FIRST_POS:
        return pRecs[0]->GetValuePTR();
        break;
    case CURRENT_POS:
        return GetValuePTR();
        break;
    case LAST_POS:
        return pRecs[TabSize]->GetValuePTR();
        break;
    default:
        return nullptr;
        break;
    }
}
void TArrayTable::SetCurrentPos(int pos){CurrPos=pos;}
int TArrayTable::GetCurrentPos()const{return CurrPos;}
void TArrayTable::Reset(){CurrPos=0;}
int TArrayTable::IsTabEnded()const{return CurrPos==TabSize;}
void TArrayTable::GoNext(){CurrPos++;if(IsTabEnded())CurrPos=0;}
