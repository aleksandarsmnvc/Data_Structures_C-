#include"TTreeTable.h"
int TTreeTable::IsFull()const{return 0;}
PTDatValue TTreeTable::FindRecord(TKey k)
{
    pCurrent=pRoot;
    while(pCurrent)
    {
        TKey curr_key=pCurrent->GetKey();
        St.push(pCurrent);
        CurrPos++;
        if(curr_key==k){ppRef=&pCurrent;return pCurrent;}
        else if(curr_key<k)pCurrent=pCurrent->pRight;
        else pCurrent=pCurrent->pLeft;
    }
    ppRef=nullptr;
    return nullptr;
}
void TTreeTable::InsRecord(TKey k,PTDatValue pVal)
{
    PTTreeNode new_node=new TTreeNode(k,pVal);
    if(!pRoot){pRoot=new_node;return;}
    if(!FindRecord(k))
    {
        PTTreeNode top=St.top();
        if(top->GetKey()>k)top->pLeft=new_node;
        else top->pRight=new_node;
    }
}
PTTreeNode TTreeTable::minNode(PTTreeNode start_root)
{
    while(start_root->pLeft->pLeft)
    {
        start_root=start_root->pLeft;
    }
    return start_root;
}
void TTreeTable::DelRecord(TKey k)
{
    if(FindRecord(k))
    {
        if(!pCurrent->pLeft&&!pCurrent->pRight)
        {
            St.pop();
            pCurrent=St.top();
            if(pCurrent->GetKey()>k)pCurrent->pLeft=nullptr;
            else pCurrent->pRight=nullptr;
            delete *ppRef;
        }
        else if(!(pCurrent->pLeft&&pCurrent->pRight))
        {
            if(pCurrent->pLeft)
            {
                pCurrent->Key=pCurrent->pLeft->Key;
                pCurrent->pValue=pCurrent->pLeft->pValue;
                delete pCurrent->pLeft;
                pCurrent->pLeft=nullptr;
            }
            else if(pCurrent->pRight)
            {
                pCurrent->Key=pCurrent->pRight->Key;
                pCurrent->pValue=pCurrent->pRight->pValue;
                delete pCurrent->pRight;
                pCurrent->pRight=nullptr;
            }
        }
        else
        {
            PTTreeNode zamena=minNode(pCurrent->pRight);
            pCurrent->Key=zamena->pLeft->Key;
            pCurrent->pValue=zamena->pLeft->pValue;
            delete zamena->pLeft;
            zamena->pLeft=nullptr;
        }
    }
}
TKey TTreeTable::GetKey()const{return pCurrent->GetKey();}
PTDatValue TTreeTable::GetValuePTR()const{return pCurrent->GetValuePTR();}
void TTreeTable::Reset(){pCurrent=pRoot;}
int TTreeTable::IsTabEnded()const{return pCurrent==nullptr;}
void TTreeTable::GoNext()
{
    char vibor;
    do
    {
        std::cin >> vibor;
    } while (vibor!='L'&&vibor!='R');
    if (vibor=='L'){pCurrent=pCurrent->pLeft;if(IsTabEnded())Reset();}
    else if (vibor=='R'){pCurrent=pCurrent->pRight;if(IsTabEnded())Reset();}
}
void TTreeTable::DeleteTreeTab(PTTreeNode node)
{
    if(node==nullptr)return;
    DeleteTreeTab(node->pLeft);
    DeleteTreeTab(node->pRight);
    delete node;
}
void TTreeTable::Print(){}
