//
//  main.cpp
//  tictactoe
//
//  Created by javier  on 28-10-21.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <vector>


using namespace std;

//function to print the board
void printBoard(char b[]) {
  cout<<endl<<" "<<b[0]<<" | "<<b[1]<<" | "<<b[2]<<endl;
  cout<<"-----------"<<endl;
  cout<<" "<<b[3]<<" | "<<b[4]<<" | "<<b[5]<<endl;
  cout<<"-----------"<<endl;
  cout<<" "<<b[6]<<" | "<<b[7]<<" | "<<b[8]<<endl;
}

//welcome message, also assigns a char for player and computer
void welcomeMessage(char& player, char& comp) {
  cout<<"Hello there, care to play tic-tac toe with me?. I´ll just choose randomly, so it´ll be much easier to beatme ;)"<<endl;
  cout<<"You get to choose: O or X"<<endl;
  cin>>player;
  //while(c!='X'&&c!='O'){
    //cout<<"come on, try again"<<endl;
    //cin>>c;
  //}
  cout<<"Thanks for choosing "<<player<<endl;
    if(player=='X') {
        comp='O';
    } else {
        comp='X';
    }
}

//gets the player move in the form of an int representing which position of the board
//the player wants tu put his mark
int makeMove() {
    int n{};
    cout<<"ok, your turn now!! choose the number where you want to put your mark:"<<endl;
    cout<<endl<<" "<<"1"<<" | "<<"2"<<" | "<<"3"<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<"4"<<" | "<<"5"<<" | "<<"6"<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<"7"<<" | "<<"8"<<" | "<<"9"<<endl;
    cin>>n;
    return n-1;
}

//this is to get the computer move, generating a random number and then  checking if the
//position is different tha ' '
int myTurn(char b[]) {
    srand((int)time(0));
    for(int i=0; i<500; i++) {
        int r = rand()%10;
        if(b[r]==' ') {
            cout<<endl<<"i chose randomly"<<endl;
            return r;
        }
    }
    int arrSize = sizeof(b)/sizeof(b[0]);
    for(int j=0; j<arrSize; j++) {
        if(b[j]==' ') {
            cout<<endl<<"i chose diffrently"<<endl;
            return j;
        }
    }
    cout<<endl<<"I chose the last one"<<endl;
    return 9;
}

//check if any sequence has won the game
bool checkIfWon(char b[], char c) {
    if(b[0]==c&&b[1]==c&&b[2]){
        cout<<endl<<"condition 1 triggered"<<endl;
        return true;
    } else if(b[3]==c&&b[4]==c&&b[5]==c){
        cout<<endl<<"condition 2 triggered"<<endl;
        return true;
    } else if(b[6]==c&&b[7]==c&&b[8]==c){
        cout<<endl<<"condition 3 triggered"<<endl;
        return true;
    } else if(b[0]==c&&b[3]==c&&b[6]==c){
        cout<<endl<<"condition 4 triggered"<<endl;
        return true;
    } else if(b[1]==c&&b[4]==c&&b[7]==c){
        cout<<endl<<"condition 5 triggered"<<endl;
        return true;
    } else if(b[2]==c&&b[5]==c&&b[8]==c){
        cout<<endl<<"condition 6 triggered"<<endl;
        return true;
    } else if(b[0]==c&&b[4]==c&&b[8]==c){
        cout<<endl<<"condition 7 triggered"<<endl;
        return true;
    } else if(b[2]==c&&b[4]==c&&b[6]==c){
        cout<<endl<<"condition 8 triggered"<<endl;
        return true;
    }
    else {
        return false;
    }
}

void goodByeMessage(){
    cout<<"bye madafaca";
}

void printMoveToBoard(int n, char b[], char pla) {
    b[n]=pla;
}


int main() {
    char board [9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char playerChar{};
    char compChar{};
    int n{};
    int c{};
    welcomeMessage(playerChar, compChar);
    cout<<endl<<"Player mark will be: "<<playerChar<<endl;
    cout<<"My mark will be: "<<compChar<<endl;
    int turns{1};
    //int games{0};
    while(turns <10) {
        if(turns%2==1){
            //player turn
            n=makeMove();
            printMoveToBoard(n, board, playerChar);
            if(checkIfWon(board, playerChar)&&turns>4) {
                cout<<"You won!, this is how you beat me:"<<endl;
                printBoard(board);
                break;
            }
            cout<<endl<<board<<endl;
        } else {
            //computer turn
            cout<<"Ok, my turn now!!I´ll beat ya! randomness is much superior to strategy"<<endl;
            c=myTurn(board);
            printMoveToBoard(c, board, compChar);
            if(checkIfWon(board, compChar)&&turns>4){
                cout<<"You Lose!, this is how I beat you:"<<endl;
                printBoard(board);
                break;
            }
            cout<<endl<<board<<endl;
        }
        printBoard(board);
        turns++;
    }
    if(checkIfWon(board, playerChar)==false&&checkIfWon(board, compChar)==false) {
        cout<<endl<<"Its a Tie"<<endl;
    }
    
  goodByeMessage();
  //printBoard(board);
  return 0;
}
