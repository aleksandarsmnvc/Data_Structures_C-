#ifndef T_HASH_TABLE
#define T_HASH_TABLE
#include"TTable.h"
class THashTable : public TTable {
 protected:
 virtual unsigned long HashFunc(const TKey key){unsigned long res=1;
 for(int i=0;i<key.size();i++)
 {
     res+=key[i];
 }return res%25;}// hash-функция
 public:
 THashTable() : TTable() {} //конструктор
 virtual int IsFull ( ) const=0 ; // заполнена?
 // доступ
 virtual TKey GetKey (void) const=0;
 virtual PTDatValue GetValuePTR (void) const=0;
 // основные методы
 virtual PTDatValue FindRecord (TKey k)=0; // найти запись
 virtual void InsRecord (TKey k, PTDatValue pVal )=0; // вставить
 virtual void DelRecord (TKey k)=0; // удалить запись
 // навигация
 virtual void Reset (void)=0; // установить на первую запись
 virtual int IsTabEnded (void) const=0; // таблица завершена?
 virtual void GoNext (void)=0 ; 
};
#endif