#include <iostream>

using namespace std;

void setToNull(int*& iPtr)
{
    iPtr = nullptr;
}

void arrInput(int* iArr, int iLength)
{
    for (int i = 0; i < iLength; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> iArr[i]; 
    }
}

void arrOutput(const int* iArr, int iLength)
{
    for (int i = 0; i < iLength; i++)
    {
        cout << iArr[i] << " ";
    }
}

void arrChangeTheSize(int*& iArr, int iOldSize, int iNewSize)
{
    // Bước 1: Cấp phát mảng tạm và đỗ dữ liệu sang mảng tạm.
    int* iArrTemp = new int[iOldSize];
    for (int i = 0; i < iOldSize; i++)
    {
        iArrTemp[i] = iArr[i];
    }
    
    // Bước 2: Giải phóng mảng hiện tại và cấp phát với kích thước mới.
    delete[] iArr;
    iArr = new int[iNewSize];

    // Bước 3: Đỗ dữ liệu từ mảng tạm sang mảng hiện tại với kích thước mới.
    int iMinSize = iOldSize < iNewSize ? iOldSize : iNewSize;
    for (int i = 0; i < iMinSize; i++)
    {
        iArr[i] = iArrTemp[i];
    }

    // Bước 4: Giải phóng mảng tạm.
    delete[] iArrTemp;
}

void arrAddElement(int*& iArr, int& iLength, int iAddLocation, int iAddElement)
{
    /*
    a:      1 2 3 4 5
    index:  0 1 2 3 4
    vị trí thêm là 2
    phần tử thêm là 69
    
    1
    a:      1 2 3 4 5 0
    index:  0 1 2 3 4 5

    2
    a5 = a4
    a4 = a3
    a3 = a2
    a2 = 69

    3
    a:      1 2 69 3 4 5
    index:  0 1 2 3 4 5

    4
    length + 1
    */
    arrChangeTheSize(iArr, iLength, iLength + 1);
    for (int i = iLength - 1; i >= iAddLocation; --i)
    {
        iArr[i + 1] = iArr[i];
    }
    iArr[iAddLocation] = iAddElement;
    ++iLength;
}

void arrDeleteElement(int*& iArr, int& iLength, int iDeleteLocation)
{
    /*
    a:      1 2 3 4 5
    index:  0 1 2 3 4

    vị trí xoá: 2
    a2 = a3
    a3 = a4
    =>  a:   1 2 4 5 5
    index:   0 1 2 3 4
    */
    for (int i = iDeleteLocation + 1; i < iLength; ++i)
    {
        iArr[i - 1] = iArr[i];
    }
    arrChangeTheSize(iArr, iLength, iLength);
    iLength--;
}

int main()
{
    int iA = 5;
    cout << "Bien Thuong\n";
    cout << "1. Gia tri: " << iA << "\n";
    cout << "2. Dia chi: " << &iA << "\n";

    int* iPtr = &iA;
    cout << "\nCon Tro Cap 1\n";
    cout << "1. Gia tri: " << *iPtr << "\n";
    cout << "2. Dia chi that: " << &iPtr << "\n";
    cout << "3. Vung nho: " << iPtr << "\n";

    // int** iPtrLevel2 = &iA;
    int** iPtrLevel2;
    iPtrLevel2 = &iPtr;
    cout << "\nCon Tro Cap 2\n";
    cout << "Gia tri: " << **iPtrLevel2 << "\n";
    cout << "Dia chi that: " << &iPtrLevel2 << "\n";
    cout << "Vung nho 1: " << iPtrLevel2 << "\n";
    cout << "Vung nho 2: " << *iPtrLevel2 << "\n";
}
