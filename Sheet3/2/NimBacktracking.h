#include <iostream>

using namespace std;

class Nim {
    protected:

        int NO_GOOD_MOVE ;
        int MAX_MOVE ;
        int N_COINS ;
        int HUMAN ;
        int COMPUTER;

   public:
        virtual bool isBadPosition(int nCoins);
        virtual int findGoodMove(int nCoins);
        Nim();
        Nim(int N ,int M ,int N_C , int H , int C);
        int get_NO_GOOD_MOVE();
        int get_MAX_MOVE();
        int get_N_COINS();
        int get_HUMAN();
        int get_COMPUTER();
        virtual void Run();

    
};


class NimVariant1 : public Nim {

    public:
    void Run();
    bool isBadPosition(int nCoins , int x);
    int findGoodMove(int nCoins, int x);
    
};

class NimVariant2 : public Nim {


    public:
    void Run();
    bool isBadPosition( int R1 , int R2 , int R3);
    int findGoodMove( int R1 , int R2 , int R3);
    int findGoodRow(int n , int R1 , int R2 , int R3);
    int findGoodMoveInLastRow(int nCoins);
    bool isBadPositionInLastRow(int nCoins);



    
};