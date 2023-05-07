#include"TSortTable.h"
void TSortTable::SetSortMethod(TSortMethod sm){SortMethod=sm;}
TSortMethod TSortTable::GetSortMethod(void){return SortMethod;}
 TSortTable::TSortTable(const TScanTable& tab): TScanTable(tab.TabSize)
 {
     SortMethod=INSERT_SORT;
     DataCount=tab.DataCount;
     for(int i=0;i<DataCount;i++)
     {
         pRecs[i]=new TTabRecord(tab.pRecs[i]->GetKey(),tab.pRecs[i]->GetValuePTR());
     }
     SortData();
 }
 TSortTable& TSortTable::operator=(const TScanTable& tab)
 {
     for(int i=0;i<DataCount;i++)
     {
         delete[] pRecs[i];
     }
     delete[]pRecs;
     this->DataCount=tab.DataCount;
     this->CurrPos=0;
     this->TabSize=tab.TabSize;
     pRecs=new PTTabRecord[TabSize];
     for(int i=0;i<DataCount;i++)
     {
         *pRecs[i]=*tab.pRecs[i];
     }
     SortData();
     return *this;
 }
 void TSortTable::SortData(void)
 {
     switch (SortMethod)
     {
     case INSERT_SORT:
         InsertSort(pRecs,DataCount);
         break;
     case MERGE_SORT:
        MergeSort(pRecs,DataCount);
        break;
     case QUIQ_SORT:
        QuiqSort(pRecs,DataCount);
        break;
     default:
         break;
     }
 }
 void TSortTable::InsertSort(PTTabRecord *pMem, int DataCount)
 {
    int i, j;
    PTTabRecord key;
    for (i = 1; i < DataCount; i++)
    {
        key = pMem[i];
        j = i - 1;
        while (j >= 0 && pMem[j] > key)
        {
            pMem[j + 1] = pMem[j];
            j = j - 1;
        }
        pMem[j + 1] = key;
    }
 }
 void TSortTable::QuiqSort (PTTabRecord *pMem, int DataCount){QuiqSorter(pMem,0,DataCount-1);}
 void TSortTable::QuiqSorter(PTTabRecord *pMem,int l,int d)
 {
     if (l < d)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = QuiqSplit(pMem, l, d);
 
        // Separately sort elements before
        // partition and after partition
        QuiqSorter(pMem, l, pi - 1);
        QuiqSorter(pMem, pi + 1, d);
 }
 }
 static void swap(PTTabRecord* a,PTTabRecord* b)
 {
     PTTabRecord p=*a;
     *a=*b;
     *b=p;
 }
 int TSortTable::QuiqSplit(PTTabRecord *pData, int l,int d)
 {
    PTTabRecord pivot = pData[d]; 
    int i = (l - 1); 
    for (int j = l; j <= d - 1; j++)
    {
        
        if (pData[j] < pivot)
        {
            i++; 
            swap(&pData[i], &pData[j]);
        }
    }
    swap(&pData[i + 1], &pData[d]);
    return (i + 1);
 }
void TSortTable::MergeSort(PTTabRecord *pMem, int DataCount){MergeSorter(pMem,0,DataCount-1);}
void TSortTable::MergeSorter(PTTabRecord * &pData,int l,int d)
{
    if (l >= d)
        return; 
  
    auto mid = l + (d - l) / 2;
    MergeSorter(pData, l, mid);
    MergeSorter(pData, mid + 1, d);
    MergeData(pData, l, mid, d);
}
void TSortTable::MergeData(PTTabRecord *&pData,int l,int sr,int d)
{
    auto const subArrayOne = sr - l + 1;
    auto const subArrayTwo = d - sr;
  
    // Create temp arrays
    auto *leftArray = new PTTabRecord[subArrayOne],
         *rightArray = new PTTabRecord[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = pData[l + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = pData[sr + 1 + j];
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = l; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            pData[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            pData[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        pData[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        pData[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
PTDatValue TSortTable::FindRecord(TKey k)
{
    int l=0,d=DataCount-1;
    while(l<=d)
    {
        int mid=l+(d-l)/2;
        TKey provera=pRecs[mid]->GetKey();
        if(provera==k)return pRecs[mid];
        else if(provera<k)l=mid+1;
        else d=mid-1;
    }
    return nullptr;
}
void TSortTable::InsRecord(TKey k,PTDatValue pValue)
{
    PTTabRecord novi=new TTabRecord(k,pValue);
    if(novi!=nullptr)
    {
        if(!IsFull())pRecs[DataCount++]=novi;
        int i=DataCount-1;
        while(i>0&&pRecs[i]->Key<pRecs[i-1]->Key)
        {
            swap(&pRecs[i],&pRecs[i-1]);
            i--;
        }
    }
}
void TSortTable::DelRecord(TKey k)
{
    PTDatValue find=FindRecord(k);
    if(find)
    {
        PTTabRecord iter=dynamic_cast<PTTabRecord>(find);
        for(int i=(iter-pRecs[0])/sizeof(TTabRecord);i<DataCount-1;i++)
        {
            *pRecs[i]=*pRecs[i+1];
        }
        DataCount--;
    }
}
void TSortTable::Print()
{
    for(int i=0;i<DataCount;i++)
    {
        std::cout<<pRecs[i]->Key<<" ";
    }
    std::cout<<std::endl;
}



