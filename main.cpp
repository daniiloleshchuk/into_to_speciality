
#include <iostream>
#include "PuzzleZagFile.h"
#include <string>
using namespace std;
int main() {

    Puzzle A("Description1",256,50,10,1,2);
    A.numeric_field=45;
    A.string_field="str";

    Puzzle B("Description2",512,100,20,3,4);
    B.numeric_field=90;
    B.string_field="strstr";
    Puzzle C("Description3",1024,200,40,5,6);
    C.numeric_field=180;
    C.string_field="strstrstr";
    A.Cout();
    cout<<endl;

    B.Cout();
    cout<<endl;
    C.Cout();
    cout<<endl;
    return 0;
}


