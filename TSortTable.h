#ifndef T_SORT_TABLE
#define T_SORT_TABLE
#include"TScanTable.h"
enum TSortMethod {INSERT_SORT, MERGE_SORT, QUIQ_SORT};
class TSortTable: public TScanTable {
protected:
 TSortMethod SortMethod; // метод сортировки
 void SortData (void); // сортировка данных
 void InsertSort (PTTabRecord *pMem, int DataCount); // метод вставок
 void MergeSort (PTTabRecord *pMem, int DataCount); // метод слияния
 void MergeSorter (PTTabRecord * &pData,int l,int d);
 void MergeData (PTTabRecord *&pData,int l,int sr,int d);
 void QuiqSort (PTTabRecord *pMem, int DataCount);
 void QuiqSorter(PTTabRecord *pMem,int l,int d);
 int QuiqSplit (PTTabRecord *pData, int l,int d);
public:
 TSortTable(int Size=TabMaxSize): TScanTable(Size){SortMethod=INSERT_SORT;};// конструктор
 TSortTable(const TScanTable &tab); // из просматриваемой таблицы
 TSortTable & operator=(const TScanTable &tab); // присваивание
 TSortMethod GetSortMethod(void); // получить метод сортировки
 void SetSortMethod (TSortMethod sm);// установить метод сортировки
 // основные методы
 virtual PTDatValue FindRecord (TKey k) ; // найти запись
 virtual void InsRecord (TKey k, PTDatValue pVal ) ; // вставить
 virtual void DelRecord (TKey k) ; // удалить запись
 virtual void Print(void) ; //
};
#endif