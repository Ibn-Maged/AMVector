#include "NimBacktracking.h"
int Nim::get_NO_GOOD_MOVE(){
    return NO_GOOD_MOVE;
}

int Nim::get_MAX_MOVE(){
    return MAX_MOVE;
}

int Nim::get_N_COINS(){
    return N_COINS;
}

int Nim::get_HUMAN(){
    return HUMAN;
}

int Nim::get_COMPUTER(){
    return COMPUTER;
}

Nim::Nim(){
    NO_GOOD_MOVE = 0;
    MAX_MOVE = 3;
    N_COINS = 23;
    HUMAN = 1;
    COMPUTER = 0;
}

Nim::Nim(int N ,int M ,int N_C , int H , int C){
    NO_GOOD_MOVE = N;
    MAX_MOVE = M;
    N_COINS = N_C;
    HUMAN = H;
    COMPUTER = C;

}


int Nim::findGoodMove(int nCoins) {
	for (int n = 1; n <= MAX_MOVE; n++)
		if (isBadPosition(nCoins - n))
			return n;
	return NO_GOOD_MOVE;
}

bool Nim::isBadPosition(int nCoins) {
    if (nCoins == 1)
        return true;
    return
        findGoodMove(nCoins) == NO_GOOD_MOVE;
}

void Nim::Run(){
    int nCoins = N_COINS, n;
    int whoseTurn = HUMAN;
    
    cout << "Welcome to Nim. We start with " << nCoins << endl;
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";

    while (nCoins > 1) {

		  cout << "\nWe have " << nCoins << ".\n";
		  cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
          if (whoseTurn == HUMAN){
                 n = nCoins + 10;
                 while (n < 1 || n > 3 || n > nCoins) {
                    cout << "Pls pick 1 to 3 coins and <= remaining coins: ";
                    cin >> n;
                 }
          }
          else if(whoseTurn == COMPUTER){
              	n = findGoodMove(nCoins);
              	if (!n)
                    n = 1;
				cout << "Computer takes " << n << " coins.\n" ;
           }
           nCoins -= n;
           whoseTurn = (whoseTurn + 1) % 2;
    }
    cout << "\n\nWinner is : " << (whoseTurn ? "Computer \n" : "Human \n");

}

void NimVariant1::Run(){
    int nCoins = N_COINS, n;
    int H=0 , C=0;
    int whoseTurn = HUMAN;
    
    cout << "Welcome to Nim. We start with " << nCoins << endl;
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";

    while (nCoins >0) {

		  cout << "\nWe have " << nCoins << ".\n";
		  cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
          if (whoseTurn == HUMAN){
                 n = nCoins + 10;
                 while (n < 1 || n > 3 || n > nCoins) {
                    cout << "Pls pick 1 to 3 coins and <= remaining coins: ";
                    cin >> n;
                 }
                 H +=n;
          }
          else if(whoseTurn == COMPUTER){
                if (nCoins == 1) 
                {
                    n = 1;
                }
                else
                {
                    n = findGoodMove(nCoins,C);
                    if (!n)
                        n = 1;
                }
                C += n ;
				cout << "Computer takes " << n << " coins.\n" ;
           }
           nCoins -= n;
           whoseTurn = (whoseTurn + 1) % 2;
    }
    if (H%2==0)
    cout << "\n\nWinner is : " << ("Human \n");
    else if (C%2==0){
    cout << "\n\nWinner is : " << ("Computer \n");
    }

}

int NimVariant1::findGoodMove(int nCoins, int x) {
	for (int n = 1; n <= MAX_MOVE; n++)
		if (isBadPosition((nCoins - n) , x+n))
			return n; 
	return NO_GOOD_MOVE;
}

bool NimVariant1::isBadPosition(int nCoins , int x) {
    if ((nCoins == 1 or nCoins == 0) and x%2==0)
        return true;
    return
        findGoodMove(nCoins,x) == NO_GOOD_MOVE;
}





void NimVariant2::Run(){
    int nCoins = N_COINS, n;
    int whoseTurn = HUMAN;
    int Row1 = N_COINS/3;
    int Row2= N_COINS/3;
    int Row3 = (N_COINS -(Row2 + Row1));
    int N_Row=0;
    int Selected_Row=1;
    
    cout << "Welcome to Nim. We start with 3 Rows : " <<endl;
    cout << "Row1 = " << Row1 <<endl;
    cout << "Row2 = " << Row2 <<endl;
    cout << "Row3 = " << Row3 <<endl;


    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";

    while (Row1 > 1 || Row2 > 1 || Row3>1) {

		    cout << "\nWe have " <<":\n";
            cout << "Row1 = " << Row1 <<endl;
            cout << "Row2 = " << Row2 <<endl;
            cout << "Row3 = " << Row3 <<endl;
		  cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
          if (whoseTurn == HUMAN){
                 while (N_Row < 1 || N_Row > 3 || Selected_Row ==0){
                    cout << "pls Enter number of Full Row "<<endl;;
                    cin >> N_Row;
                    if(N_Row==1)
                    Selected_Row = Row1;
                    else if (N_Row==2)
                    Selected_Row = Row2;
                    else if (N_Row==3)
                    Selected_Row= Row3;
                 }
                    n = Selected_Row + 10;
                    while (n < 1 || n > 3 || n >Selected_Row ) {
                        cout << "Pls pick 1 to 3 coins and <= remaining coins: ";
                        cin >> n;
                    }
                    if(N_Row==1)
                    Row1 = Row1 - n;
                    else if (N_Row==2)
                    Row2 = Row2 -n;
                    else if (N_Row==3)
                    Row3 = Row3 - n;


          }
          else if(whoseTurn == COMPUTER){
                int divide;
                divide = findGoodMove( Row1 , Row2 , Row3);
                if(divide==0){
                    N_Row = 1;
                    n=1;
                }
                else{
                    N_Row = divide/10;
                    n= divide%10;
                }
              	
				cout << "Computer takes " << n << " coins. From Row"<< N_Row<<endl; 
                if(N_Row==1)
                    Row1 = Row1 - n;
                    else if (N_Row==2)
                    Row2 = Row2 -n;
                    else if (N_Row==3)
                    Row3 = Row3 - n;
           }
            N_Row=0;
            Selected_Row=1;        
           whoseTurn = (whoseTurn + 1) % 2;
    }
    cout << "\n\nWinner is : " << (whoseTurn ? "Computer \n" : "Human \n");

}


int NimVariant2::findGoodMove( int R1 , int R2 , int R3) {
    for(int j=1 ; j<4 ; j++ ){
	for (int i = 1; i <= MAX_MOVE; i++){
        if (j==1 and (R1-i)>=0){
            if (isBadPosition((R1 - i) , R2 , R3))
                return ((j*10)+i);
            }
        else if (j==2 and (R2-i) >=0){
             if (isBadPosition(R1  , (R2-i) , R3))
                return ((j*10)+i);
            }
        else if (j==3 and (R3-i)>=0){
             if (isBadPosition(R1 , R2 , (R3-i)))
                return ((j*10)+i);
        }

    }
    }
	return NO_GOOD_MOVE;
}

bool NimVariant2::isBadPosition( int R1 , int R2 , int R3) {
    if ((R1 == 0 and R2 ==0 and R3==1) or (R1 == 1 and R2 ==0 and R3==0) or (R1 == 0 and R2 ==1 and R3==0))
        return true;
    return
        findGoodMove(   R1 ,  R2 ,  R3) == NO_GOOD_MOVE;
}

/*int NimVariant2::findGoodRow(int& n , int R1 , int R2 , int R3){
    for (int i = 1; i <=3; i++){

        if (i==1 and R1>0){
            if(R2==0 and R3==0){
                n= findGoodMoveInLastRow(R1);
            }
            else{
            n= findGoodMove(R1);
            }
            if(n)
            return i;
        }
        else if (i==2 and R2>0){
            if(R1==0 and R3==0){
                n= findGoodMoveInLastRow(R2);
            }
            else{
            n= findGoodMove(R2);
            }
            if(n)
            return i;
        }
          else if (i==3 and R3>0){
            if(R2==0 and R1==0){
                n= findGoodMoveInLastRow(R3);
            }
            else{
            n= findGoodMove(R3);
            }           
            if(n)
            return i;
        }
    }

    n=1;
	if(R1>0){
        return 1;
    }
    if(R2>0){
        return 2;
    }
    if(R3>0){
        return 3;
    }


    return 1;
}



int NimVariant2::findGoodMoveInLastRow(int nCoins) {
	for (int n = 1; n <= MAX_MOVE; n++)
		if (isBadPositionInLastRow(nCoins - n))
			return n;
	return NO_GOOD_MOVE;
}

bool NimVariant2::isBadPositionInLastRow(int nCoins) {
    if (nCoins == 1)
        return true;
    return
        findGoodMoveInLastRow(nCoins) == NO_GOOD_MOVE;
}
*/