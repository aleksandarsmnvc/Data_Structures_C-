#ifndef T_TREE_TABLE
#define T_TREE_TABLE
#include"TTreeNode.h"
#include"TTable.h"
#include<stack>

class TTreeTable: public TTable {
 protected:
 PTTreeNode pRoot; // указатель на корень дерева
 PTTreeNode *ppRef;// адрес указателя на вершину-результата в FindRecord
 PTTreeNode pCurrent;// указатель на текущую вершину
 int CurrPos; // номер текущей вершины
 std::stack < PTTreeNode> St;// стек для итератора
 void DeleteTreeTab (PTTreeNode pNode); // удаление
 PTTreeNode minNode(PTTreeNode start_root);
 public:
 TTreeTable(): TTable(){CurrPos=0; pRoot=pCurrent=NULL; ppRef=NULL;}
 ~TTreeTable(){DeleteTreeTab (pRoot);} // деструктор
 // информационные методы
 virtual int IsFull ( ) const ; //заполнена?
 //основные методы
 virtual PTDatValue FindRecord (TKey k); // найти запись
 virtual void InsRecord(TKey k, PTDatValue pVal ); // вставить
 virtual void DelRecord(TKey k); // удалить запись
 // навигация
 virtual TKey GetKey (void) const;
 virtual PTDatValue GetValuePTR (void) const;
 virtual void Reset (void); // установить на первую запись
 virtual int IsTabEnded (void) const; // таблица завершена?
 virtual void GoNext (void) ;// переход к следующей записи
 virtual void Print(void);
 //(=1 после применения для последней записи таблицы)
};
#endif