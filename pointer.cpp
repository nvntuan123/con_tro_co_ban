#include <iostream>
#include <ctime>

using namespace std;

void MatrixAllocationMemory(int**& iMatrix, int iRows, int iCols)
{
    iMatrix = new int*[iRows];
    for (size_t i = 0; i < iRows; i++)
    {
        iMatrix[i] = new int[iCols];
    }
}

void MatrixFree(int**& iMatrix, int iRows, int iCols)
{
    for (size_t i = 0; i < iRows; i++)
    {
        delete[] iMatrix[i];
    }
    delete[] iMatrix;
}

void MatrixDataCopy(int** iMatrixSource, int** iMatrixDest, int iRows, int iCols)
{
    for (size_t i = 0; i < iRows; i++)
    {
        for (size_t j = 0; j < iCols; j++)
        {
            iMatrixDest[i][j] = iMatrixSource[i][j];
        }
    }    
}

// bCheck = true ? Row : Col
void MatrixREADLOC(int**& iMatrix, int iRowOldSize, int iColOldSize, int iNewSize, bool bCheck)
{
    // B1: Tạo mảng tạm và đỗ dữ liệu từ mảng chính sang tạm.
    // Cấp phát mảng tạm.
    int** iMatrixTemp;
    MatrixAllocationMemory(iMatrixTemp, iRowOldSize, iColOldSize);

    // Đỗ dữ liệu từ mảng chính sang mảng tạm.
    MatrixDataCopy(iMatrix, iMatrixTemp, iRowOldSize, iColOldSize);

    // B2: Giải phóng mảng hiện tại và cấp phát với kích thước mới.
    MatrixFree(iMatrix, iRowOldSize, iColOldSize);
    MatrixAllocationMemory(iMatrix, iRowOldSize, iColOldSize);

    // B3: Đỗ dữ liệu từ mảng tạm sang mảng chính.
    MatrixDataCopy(
        iMatrixTemp,
        iMatrix,
        (bCheck ? (iRowOldSize < iNewSize ? iRowOldSize : iNewSize) : iRowOldSize),
        (bCheck ? iColOldSize : (iColOldSize < iNewSize ? iColOldSize : iNewSize))
        );

    // B4: Giải phóng mảng tạm.
    MatrixFree(iMatrixTemp, iRowOldSize, iColOldSize);
}

void MatrixRandomElement(int** iMatrix, int iRows, int iCols)
{
    srand(time(0)); // Reset time.
    for (size_t i = 0; i < iRows; i++)
    {
        for (size_t j = 0; j < iCols; j++)
        {
            iMatrix[i][j] = rand() % 100;
        }
    }
}

void MatrixOutput(int** iMatrix, int iRows, int iCols)
{
    for (size_t i = 0; i < iRows; i++)
    {
        for (size_t j = 0; j < iCols; j++)
        {
            cout << iMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int iRows = 3;
    int iCols = 4;
    int** iMatrix = new int*[iRows];
    for (size_t i = 0; i < iRows; i++)
    {
        iMatrix[i] = new int[iCols];
    }
    
    MatrixRandomElement(iMatrix, iRows, iCols);
    cout << "Ma tran sau khi random:\n";
    MatrixOutput(iMatrix, iRows, iCols);

    for (size_t i = 0; i < iRows; i++)
    {
        delete[] iMatrix[i];
    }
    delete[] iMatrix;
}
