#ifndef T_SCAN_TABLE
#define T_SCAN_TABLE
#include"TArrayTable.h"
class TScanTable: public TArrayTable {
 public:
 TScanTable(int Size=TabMaxSize): TArrayTable(Size){};//конструктор
 // основные методы
 virtual PTDatValue FindRecord (TKey k) override ;//найти запись
 virtual void InsRecord (TKey k, PTDatValue pVal ) ;//вставить
 virtual void DelRecord (TKey k) ;//удалить запись
 virtual void Print(void);
};
#endif