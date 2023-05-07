#ifndef T_TABLE
#define T_TABLE
#include"TTabRecord.h"
class TTable  {
 protected:
 int DataCount; // количество записей в таблице
 int Efficiency; // показатель эффективности выполнения операции
 public:
 TTable(){ DataCount=0; Efficiency=0;} // конструктор
 virtual ~TTable( ) {}; // деструктор
 // информационные методы
 int GetDataCount ( ) const {return DataCount;} // к-во записей
 int GetEfficiency ( ) const {return Efficiency;} // эффективность
 int IsEmpty ( ) const {return DataCount == 0;} //пуста?
 virtual int IsFull ( ) const =0; // заполнена?
 // доступ
 virtual TKey GetKey (void) const=0;
 virtual PTDatValue GetValuePTR (void) const =0;
 // основные методы
 virtual PTDatValue FindRecord (TKey k) =0; // найти запись
 virtual void InsRecord (TKey k, PTDatValue pVal ) =0; // вставить
 virtual void DelRecord (TKey k) =0; // удалить запись
 // навигация
 virtual void Reset (void) =0; // установить на первую запись
 virtual int IsTabEnded (void) const=0; // таблица завершена?
 virtual void GoNext (void) =0; // переход к следующей записи
 virtual void Print(void)=0;
 // (=1 после применения для последней записи таблицы)
};
#endif