#ifndef T_LIST_HASH
#define T_LIST_HASH
#include"THashTable.h"
#include"TDatList.h"
using PTDatList=TDatList*;
#define TabMaxSize 25
class TListHash : public THashTable {
 protected:
 PTDatList *pList; // память для массива указателей на списки записей
 int TabSize; // размер массива указателей
 int CurrList; // список, в котором выполнялся поиск
 public:
 TListHash(int Size= TabMaxSize); // конструктор
 ~TListHash();
 // информационные методы
 virtual int IsFull ( ) const ; // заполнена?
 // доступ
 virtual TKey GetKey (void) const;
 virtual PTDatValue GetValuePTR (void) const;
 // основные методы
 virtual PTDatValue FindRecord (TKey k); // найти запись
 virtual void InsRecord (TKey k, PTDatValue pVal ); // вставить
 virtual void DelRecord (TKey k); // удалить запись
 // навигация
 virtual void Reset (void){CurrList=0;}// установить на первую запись
 virtual int IsTabEnded (void) const{return CurrList==TabSize;} // таблица завершена?
 virtual void GoNext (void) {CurrList++;if(IsTabEnded())Reset();} // переход к следующей записи
 virtual void Print(void);
 //(=1 после применения для последней записи таблицы)
};
#endif