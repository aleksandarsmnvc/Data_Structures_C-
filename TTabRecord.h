#ifndef T_TAB_RECORD
#define T_TAB_RECORD
#include<iostream>
#include"TDatValue.h"
class TTabRecord;
using TKey=std::string; // тип ключа записи
using PTDatValue=TDatValue*;
using PTTabRecord=TTabRecord*;
// Класс объектов-значений для записей таблицы
class TTabRecord : public TDatValue {
 protected: // поля
 TKey Key; // ключ записи
 PTDatValue pValue; // указатель на значение
 public: // методы
 TTabRecord (TKey k="", PTDatValue pVal = NULL);// конструктор
 void SetKey(TKey k);// установить значение ключа
 TKey GetKey(void); // получить значение ключа
 void SetValuePtr(PTDatValue p);// установить указатель на данные
 PTDatValue GetValuePTR (void); // получить указатель на данные
 TTabRecord* GetCopy ()override; // изготовить копию
 TTabRecord & operator = (TTabRecord &tr);// присваивание
 virtual int operator == (const TTabRecord &tr); // сравнение =
 virtual int operator < (const TTabRecord &tr); // сравнение «<»
 virtual int operator > (const TTabRecord &tr); // сравнение «>»
//дружественные классы для различных типов таблиц, см. далее
 friend class TArrayTable;
 friend class TScanTable;
 friend class TSortTable;
 friend class TTreeNode;
 friend class TTreeTable;
 friend class TArrayHash;
 friend class TListHash;
};
#endif
