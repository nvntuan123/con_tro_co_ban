#include <iostream>
#include <ctime>

using namespace std;

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
