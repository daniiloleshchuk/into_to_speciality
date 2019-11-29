
#include <iostream>
using namespace std;
#define SIZEOFARRAY 5

class Array {
private:
    int PrivateArr[SIZEOFARRAY];
public:
    friend void setMatrix(Array Matrix[]);
    friend void coutMatrix(Array Matrix[]);
    friend void FiAij(Array *Matr);
    friend void MergeRowsColDesc(Array  arr[], int n);
    int operator [] (int i){
         return PrivateArr[i];
     }
};
//this sort is taken from wiki and changed some variables according to mine code
void MergeRowsColDesc(Array  arr[], int ARRAYSIZE)
{
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        for (int BlockSizeIterator = 1; BlockSizeIterator < ARRAYSIZE; BlockSizeIterator *= 2)
        {
            for (int BlockIterator = 0; BlockIterator < ARRAYSIZE - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
            {
                int LeftBlockIterator = 0;
                int RightBlockIterator = 0;
                int LeftBorder = BlockIterator;
                int MidBorder = BlockIterator + BlockSizeIterator;
                int RightBorder = BlockIterator + 2 * BlockSizeIterator;
                RightBorder = (RightBorder < ARRAYSIZE) ? RightBorder : ARRAYSIZE;
                int* SortedBlock = new int[RightBorder - LeftBorder];

                while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
                {
                    if (arr[i].PrivateArr[LeftBorder + LeftBlockIterator] > arr[i].PrivateArr[MidBorder + RightBlockIterator])
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[i].PrivateArr[LeftBorder + LeftBlockIterator];
                        LeftBlockIterator++;
                    }
                    else
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[i].PrivateArr[MidBorder + RightBlockIterator];
                        RightBlockIterator++;
                    }
                }
                while (LeftBorder + LeftBlockIterator < MidBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[i].PrivateArr[LeftBorder + LeftBlockIterator];
                    LeftBlockIterator++;
                }
                while (MidBorder + RightBlockIterator < RightBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[i].PrivateArr[MidBorder + RightBlockIterator];
                    RightBlockIterator++;
                }

                for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
                {
                    arr[i].PrivateArr[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
                }
                delete SortedBlock;

            }

        }
    }
}
void setMatrix(Array Matrix[]) {
        for (int i = 0; i <SIZEOFARRAY ; i++) {
            for (int j = 0; j <SIZEOFARRAY ; j++) {
                cout << "Enter array element №" << j + 1 << endl;
                cin>>Matrix[i].PrivateArr[j];
            }
        }
}
void coutMatrix(Array Matrix[]){
    for (int row = 0; row <SIZEOFARRAY ; row++) {
        for (int column = 0; column <SIZEOFARRAY ; column++) {
            cout<<Matrix[row].PrivateArr[column]<<"     ";
        }
        cout<<"\n\n\n";
    }
}
void FiAij(Array *Matr){
    int numberForDividing = 0;
    float result=1;
    for (int k = 0,r=1; k < SIZEOFARRAY-1 ; k++,r++) {
        numberForDividing = 0;
        float sumOfElementsInColumnsAboveAuxiliaryDiag = 0;
        cout<<"Середнє арифметичне чисел  ";
        for (int l = 0; l < SIZEOFARRAY - k - 1 ; l++) {
            sumOfElementsInColumnsAboveAuxiliaryDiag+=Matr[l][k];
            cout<<Matr[l][k]<<"  ";
            numberForDividing++;
        }
        if (numberForDividing != 0) {
            sumOfElementsInColumnsAboveAuxiliaryDiag /= numberForDividing;
            cout<<" === "<<sumOfElementsInColumnsAboveAuxiliaryDiag<<endl;
        }
        result*=sumOfElementsInColumnsAboveAuxiliaryDiag;
    }
    cout<<"F(FiAij)= "<<result<<endl;
}

int main(){
    Array Matrix[SIZEOFARRAY];
    cout<<"\t\t\t\tInPut matrix"<<endl;
    setMatrix(Matrix);
    cout<<"\t\t\t\tOutPut not-sorted matrix"<<endl;
    coutMatrix(Matrix);
    cout<<"\n\n\n";

    cout<<"\t\t\t\tOutPut sorted matrix"<<endl;
    MergeRowsColDesc(Matrix,SIZEOFARRAY);

    coutMatrix(Matrix);
    cout<<"\t\t\t\tOutPut Fi(Aij)"<<endl;
    FiAij(Matrix);
    return 0;
}


