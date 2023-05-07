#include"TTreeNode.h"
PTTreeNode TTreeNode::GetLeft()const{return pLeft;}
PTTreeNode TTreeNode::GetRight()const{return pRight;}
TTreeNode* TTreeNode::GetCopy()
{
    PTTreeNode novi=new TTreeNode(Key,pValue,pLeft,pRight);
    return novi;
}