#include <iostream>
#include <cmath>
using namespace std;
class Polinom {
protected:
    int n = 1;
    int m,x;
    void setRes() {
        for (n = 1; n <= m; n++) {
            res += (pow(-1, n + 1)) * (pow(x, n) / n);
        }
    }
public:
    double res;
    Polinom(int _m,int _x){
        m=_m;
        x=_x;
        this->setRes();

    }
    double getRes(){
        return res;
    }
    //
    Polinom& operator=(const Polinom& result) {
        //проверка на самоприсваивание
        if (this == &result) {
            return *this;
        }
        res= result.res;
        return *this;
    }

};
bool operator == (Polinom A, Polinom B)
{
    return A.res == B.res;
}
bool operator < (Polinom A, Polinom B)
{
    return  A.res < B.res;
}
bool operator > (Polinom A, Polinom B)
{
    return  A.res > B.res;
}
double operator - (Polinom A,Polinom B){
    return  A.res-B.res;
}
double operator *= (Polinom A,Polinom B){
    return A.res*=B.res;
}
ostream& operator<<(ostream &stream, Polinom& n){
    cout<<n.res<<endl;
    stream << n.res;
    return stream;
}
istream& operator>>(istream &stream,Polinom& n){
    cout << "Enter res" << endl;
    stream >> n.res;
    return stream;
}
int main() {
    Polinom A(4,2);
    Polinom B(3,2);
    cout<<"A   "<<A.getRes()<<endl;
    cout<<"B   "<<B.getRes()<<endl;
    bool b = (A==B);
    double c;
    if (b==1){
        cout<<"Поліном A = Поліном B"<<endl;
    }
    else cout<<"Поліном А != Поліном B"<<endl;
    b= (A<B);
    if (b==1){
        cout<<"Поліном A < Поліном B"<<endl;
    } else cout<<"Поліном А !< Поліном B"<<endl;
    b= (A>B);
    if (b==1){
        cout<<"Поліном A > Поліном B"<<endl;
    } else cout<<"Поліном А !> Поліном B"<<endl;
    c= (A-B);
    cout<<"A-B === "<<c<<endl;
    c=(A*=B);
    cout<<"A*=B === "<<c<<endl;
    cin>>A;
    cin>>B;
    cout<<"A is "<<A<<endl;
    cout<<"B is "<<B<<endl;
    A=B;
    cout<<"A is "<<A<<endl;


    /*
                    A=B
                    A==B
                    A<B
                    A>B
                    A-B
                    A*=B
                    vyvod<<A vyvod<<B
                    vvid>>A vvid>>B
*/
    return 0;
}

