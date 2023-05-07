#ifndef T_TREE_NODE
#define T_TREE_NODE
#include"TTabRecord.h"
class TTreeNode;
using PTTreeNode=TTreeNode*;
class TTreeNode: public TTabRecord {
 protected:
 PTTreeNode pLeft, pRight; // указатели на поддеревья
 public:
 TTreeNode(TKey k="", PTDatValue pVal=NULL, PTTreeNode pL=NULL,
 PTTreeNode pR=NULL): TTabRecord(k,pVal), pLeft(pL), pRight(pR) {};
 PTTreeNode GetLeft(void) const; // указатель на левое поддерево
 PTTreeNode GetRight(void) const; // указатель на правое поддерево
 virtual TTreeNode* GetCopy(); // изготовить копию
 friend class TTreeTable;
 friend class TBalanceTree;
};
#endif
