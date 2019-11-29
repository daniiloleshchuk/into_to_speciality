/*
#include <iostream>
using namespace std;
#define SIZE 5

class Array {
private:
    int PrivateArr[SIZE];
public:
    friend void setMatrix(Array Matrix[]);
    friend void coutMatrix(Array Matrix[]);
    friend void FiAij(Array *Matr);
    friend void SortArray(Array  arr[], int n);
    int operator [] (int i){
         return PrivateArr[i];
     }
};

void SortArray(Array  arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int BlockSizeIterator = 1; BlockSizeIterator < n; BlockSizeIterator *= 2)
        {
            for (int BlockIterator = 0; BlockIterator < n - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
            {
                int LeftBlockIterator = 0;
                int RightBlockIterator = 0;
                int LeftBorder = BlockIterator;
                int MidBorder = BlockIterator + BlockSizeIterator;
                int RightBorder = BlockIterator + 2 * BlockSizeIterator;
                RightBorder = (RightBorder < n) ? RightBorder : n;
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
        for (int i = 0; i <SIZE ; i++) {
            for (int j = 0; j <SIZE ; j++) {
                cout << "Enter array element №" << j + 1 << endl;
                cin>>Matrix[i].PrivateArr[j];
            }
        }
}
void coutMatrix(Array Matrix[]){
    for (int row = 0; row <SIZE ; row++) {
        for (int column = 0; column <SIZE ; column++) {
            cout<<Matrix[row].PrivateArr[column]<<"     ";
        }
        cout<<"\n\n\n";
    }
}
void FiAij(Array *Matr){
    int n = 0;
    float res=1;
    for (int k = 0,r=1; k < SIZE-1 ; k++,r++) {
        n = 0;
        float s = 0;
        cout<<"Середнє арифметичне чисел  ";
        for (int l = 0; l < SIZE - k - 1 ; l++) {
            s+=Matr[l][k];
            cout<<Matr[l][k]<<"  ";
            n++;
        }
        if (n != 0) {
            s /= n;
            cout<<" === "<<s<<endl;
        }
        res*=s;
    }
    cout<<"F(FiAij)= "<<res<<endl;
}

int main(){
    Array Matrix[SIZE];
    cout<<"\t\t\t\tInPut matrix"<<endl;
    setMatrix(Matrix);
    cout<<"\t\t\t\tOutPut not-sorted matrix"<<endl;
    coutMatrix(Matrix);
    cout<<"\n\n\n";

    cout<<"\t\t\t\tOutPut sorted matrix"<<endl;
    SortArray(Matrix,SIZE);

    coutMatrix(Matrix);
    cout<<"\t\t\t\tOutPut Fi(Aij)"<<endl;
    FiAij(Matrix);
    return 0;
}
*/




#include <iostream>
#include "math.h"
#define n 5
using namespace std;
/*
    1 16 21 11 6
    2 17 22 12 7
    3 18 23 13 8
    4 19 24 14 9
    5 20 25 15 10
 */

class Vector {
private:
    int arr[5];
public:
    friend void EnterTheMatrix(Vector matrix[]) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>matrix[j].arr[i];

            }
        }

    }

    void mergeSort(int begin, int end) {
        if (begin < end) {
            int middle = (begin + end) / 2;
            mergeSort(begin, middle);
            mergeSort(middle + 1, end);
            merge(begin, middle, end);
        }
    }
    friend void ShowTheMatrix(Vector matrix[])
    {
        for(int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; ++j) {
                cout << matrix[j].arr[i]<< " ";
            }
            cout << endl;
        }
        cout<<endl;
    }
    void merge(int start, int mid, int end) {
        int t[5];
        int i = start, j = mid + 1, k = 0;

        while (i <= mid && j <= end) {
            if (this->arr[i] <= this->arr[j]) {
                t[k] = this->arr[i];
                k++;
                i++;
            } else {
                t[k] = this->arr[j];
                k++;
                j++;
            }
        }

        while (i <= mid) {
            t[k] = this->arr[i];
            k++;
            i++;
        }

        while (j <= end) {
            t[k] = this->arr[j];
            k++;
            j++;
        }
        for (i = start; i <= end;i++) {
            this->arr[i] = t[i - start];
        }
    }
    double Calculation(Vector matrix[])
    {
        int sum[4] = {0, 0, 0, 0};
        int suma = 0;
        double result= 0;
        double res=0;
        double dob = 1;
        int schetchik=0;
        for(int j = 0; j<n-1;j++){
            for (int i = j+1; i < n;i++) {
                sum[j] += matrix[j].arr[i];
                suma += matrix[j].arr[i];

                schetchik++;
            }
            result += sum[j];
            res += suma;
            cout <<"Середнє арифметичне: "<< sum[j]/schetchik << endl;
        }
        cout << endl;
        dob *= res;
        cout<<"Добуток:"<< dob <<endl;
    }
};


int main()
{
    Vector Matrix[n];
    cout << "Enter the matrix:" << endl;
    EnterTheMatrix(Matrix);
    for (int i = 0; i < n; ++i) {
        Matrix[i].mergeSort(0, n-1);
    }
    cout<<"Sorted matrix:"<< endl;
    ShowTheMatrix(Matrix);
    Matrix->Calculation(Matrix);

    return 0;
}