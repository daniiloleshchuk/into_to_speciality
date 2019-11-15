#include "PuzzleZagFile.h"
Puzzle::Puzzle(string puzzle_description,int number_of_puzzles,int width_of_box,int height_of_box,int protected1,int protected2){
    Puzzle_description=puzzle_description;
    Number_of_Puzzles=number_of_puzzles;
    Width_of_Box=width_of_box;
    Height_of_Box=height_of_box;
}
Puzzle::~Puzzle() {}
string Puzzle::getPuzzle_description(){
    return Puzzle_description;
}
int Puzzle::getNumber_of_Puzzles(){
    return Number_of_Puzzles;
}
int Puzzle::getWidth_of_Box(){
    return Width_of_Box;
}
int Puzzle::getHeight_of_Box(){
    return Height_of_Box;
}
int Puzzle::getProtected1(){
    return Protected1;
};
int Puzzle::getProtected2(){
    return Protected2;
};

