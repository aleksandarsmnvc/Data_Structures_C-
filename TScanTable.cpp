#include"TScanTable.h"
PTDatValue TScanTable::FindRecord(TKey k)
{
   for(int i=0;i<DataCount;i++)
   {
       if(pRecs[i]->GetKey()==k)return pRecs[i];
   }
   return nullptr;
}
void TScanTable::InsRecord(TKey k,PTDatValue pVal)
{
    PTTabRecord novi=new TTabRecord(k,pVal);
    if(novi!=nullptr) 
    {
        if(!IsFull())pRecs[DataCount++]=novi;
        else std::cout<<"Table is Full!"<<std::endl;
    }
}
void TScanTable::DelRecord(TKey k)
{
    PTDatValue find=FindRecord(k);
    if(find)
    {
        *(dynamic_cast<PTTabRecord>(find))=*pRecs[DataCount-1];
        DataCount--;
    }
}
void TScanTable::Print(){}