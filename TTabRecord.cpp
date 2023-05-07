#include"TTabRecord.h"
TTabRecord::TTabRecord(TKey k, PTDatValue pVal): Key{k},pValue{pVal} {}
void TTabRecord::SetKey(TKey k){Key=k;}
TKey TTabRecord::GetKey(void){return Key;}
void TTabRecord::SetValuePtr(PTDatValue p){pValue=p;}
PTDatValue TTabRecord::GetValuePTR(void){return pValue;}
TTabRecord& TTabRecord::operator=(TTabRecord& tr)
{
    Key=tr.Key;
    pValue=tr.pValue;
    return *this;
}
int TTabRecord::operator==(const TTabRecord& tr)
{
    return Key==tr.Key;
}
int TTabRecord::operator<(const TTabRecord& tr)
{
    return Key<tr.Key;
}
int TTabRecord::operator>(const TTabRecord& tr)
{
    return Key>tr.Key;
}
TTabRecord* TTabRecord::GetCopy(void)
{       
    PTTabRecord copy=new TTabRecord;
    copy->Key=Key;
    copy->pValue=pValue;
    return copy;   
}
