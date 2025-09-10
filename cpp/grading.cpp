#include <iostream>

int coutscore(std::string thepoints){
    std::cout << thepoints << '\n';
    return 0;
}


int main(){
    int points, midterm, finalterm;
    std::cin >> points >> midterm >> finalterm;
    int sumpoints = points + midterm + finalterm;

    if(sumpoints >= 80){
        coutscore("A");
    }else if(sumpoints >= 75){
        coutscore("B+");
    }else if(sumpoints >= 70){
        coutscore("B");
    }else if(sumpoints >= 65){
        coutscore("C+");
    }else if(sumpoints >= 60){
        coutscore("C");
    }else if(sumpoints >= 55){
        coutscore("D+");
    }else if(sumpoints >= 50){
        coutscore("D");
    } else {
        coutscore("F");
    }

    return 0;
}