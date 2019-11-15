
#pragma once
#include <string>
#include <iostream>

using namespace std;
class Puzzle {
    private:
        string Puzzle_description;
        int Number_of_Puzzles;
        int Width_of_Box;
        int Height_of_Box;
    protected:
        int Protected1;
        int Protected2;
    public:
        int numeric_field;
        string string_field;
    Puzzle(string puzzle_description,int number_of_puzzles,int width_of_box,int height_of_box,int protected1,int protected2);
    ~Puzzle();
    string getPuzzle_description();
    int getNumber_of_Puzzles();
    int getWidth_of_Box();
    int getHeight_of_Box();
    int getProtected1();
    int getProtected2();
    void Cout(){
        cout<<"Puzzle description is:"<<getPuzzle_description() <<endl;
        cout<<"Number of puzzle is:"<<getNumber_of_Puzzles() <<endl;
        cout<<"Width of box is:"<<getWidth_of_Box() <<endl;
        cout<<"Height of box is:"<<getHeight_of_Box() <<endl;
        cout<<"Protected 1 is:"<<getProtected1()<<endl;
        cout<<"Protected 2 is:"<<getProtected2()<<endl;
        cout<<"Numeric field is:"<<numeric_field <<endl;
        cout<<"String Field is:"<<string_field <<endl;
    }

};

