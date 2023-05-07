#include"TTreeTable.h"
#include"TScanTable.h"
#include"TSortTable.h"
#include"TArrayHash.h"
#include"TListHash.h"
#include<string>
#include<sstream>
static void Proverka(TTable& tab,TKey k)
{
    if(tab.FindRecord(k))std::cout<<"Da"<<std::endl;
    else std::cout<<"Ne"<<std::endl;
}
static void Delete(TTable& tab,TKey k)
{
    tab.DelRecord(k);
}
static void Insert(TTable& tab,TKey k)
{
    tab.InsRecord(k,nullptr);
}
static void Print(TTable& tab)
{
    tab.Print();
}
static void Interface()
{
    std::cout<<"Del-Delete"<<std::endl;
    std::cout<<"Ins-Insert"<<std::endl;
    std::cout<<"Find-Find"<<std::endl;
    std::cout<<"Print"<<std::endl;
    std::cout<<"TreeTab-Tablica Derev,ScanTab-Obicnaya Tablica,SortTab-Sortirovanaya Tab,ArrayTab-Hesirovanaya Tab,ListTab-Hesirovanie s pomosju Spiskov"<<std::endl;
    std::cout<<"Komanda:[imya_opcii] [vid_tab] [key_znacenie]"<<std::endl;
    std::cout<<"Primer: Del TreeTab Petr"<<std::endl;
}
int main()
{
    TTreeTable TreeTab;
    TScanTable ScanTab;
    TSortTable SortTab;
    TArrayHash ArrayTab(3);
    TListHash ListTab;
    Interface();
    std::string input,option,table,key;
    while(true)
    {
    getline(std::cin,input);
    if(input=="Exit")break;
    std::stringstream command(input);
    command>>option>>table>>key;
    if(table=="TreeTab")
    {
        if(option=="Del")Delete(TreeTab,key);
        else if(option=="Find")Proverka(TreeTab,key);
        else if(option=="Ins")Insert(TreeTab,key);
        else if(option=="Print")Print(TreeTab);
        else std::cout << "Net takoy opcii!!!!" << std::endl;
    }
    else if(table=="ScanTab")
    {
        if(option=="Del")Delete(ScanTab,key);
        else if(option=="Find")Proverka(ScanTab,key);
        else if(option=="Ins")Insert(ScanTab,key);
        else if(option=="Print")Print(ScanTab);
        else std::cout << "Net takoy opcii!!!!" << std::endl;
    }
    else if(table=="SortTab")
    {
        if(option=="Del")Delete(SortTab,key);
        else if(option=="Find")Proverka(SortTab,key);
        else if(option=="Ins")Insert(SortTab,key);
        else if(option=="Print")Print(SortTab);
        else std::cout << "Net takoy opcii!!!!" << std::endl;
    }
    else if(table=="ListTab")
    {
        if(option=="Del")Delete(ListTab,key);
        else if(option=="Find")Proverka(ListTab,key);
        else if(option=="Ins")Insert(ListTab,key);
        else if(option=="Print")Print(ListTab);
        else std::cout << "Net takoy opcii!!!!" << std::endl;
    }
    else if(table=="ArrayTab")
    {
        if(option=="Del")Delete(ArrayTab,key);
        else if(option=="Find")Proverka(ArrayTab,key);
        else if(option=="Ins")Insert(ArrayTab,key);
        else if(option=="Print")Print(ArrayTab);
        else std::cout << "Net takoy opcii!!!!" << std::endl;
    }
    else std::cout << "Net takoy tablici!!!!" << std::endl;
    }
}