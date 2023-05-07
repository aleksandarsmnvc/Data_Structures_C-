#ifndef T_ARRAY_HASH
#define T_ARRAY_HASH
#define TabMaxSize 25
#define TabHashStep 5
#include"TTabRecord.h"
#include"THashTable.h"
class TArrayHash : public THashTable {
 protected:
 PTTabRecord *pRecs; // память для записей таблицы
 int TabSize; // макс. возм. к-во записей
 int HashStep; // шаг вторичного перемешивания
 int FreePos; // первая свободная строка, обнаруженная при поиске
 int CurrPos; // строка памяти при завершении поиска
 PTTabRecord pMark;// маркер для индикации строк с удаленными записями
 PTTabRecord pEmpty;
 int GetNextPos(int pos){return (pos+HashStep)%TabSize;};// откр. перем.
 public:
 TArrayHash(int Size= TabMaxSize, int Step= TabHashStep); // конструктор
 ~TArrayHash();
 // информационные методы
 virtual int IsFull() const ; // заполнена?
 // доступ
 virtual TKey GetKey (void) const;
 virtual PTDatValue GetValuePTR (void) const;
 // основные методы
 virtual PTDatValue FindRecord (TKey k); // найти запись
 virtual void InsRecord (TKey k, PTDatValue pVal ); // вставить
 virtual void DelRecord (TKey k); // удалить запись
 // навигация
 virtual void Reset (void); // установить на первую запись
 virtual int IsTabEnded (void) const; // таблица завершена?
 virtual void GoNext (void) ; 
 virtual void Print(void);
};
#endif