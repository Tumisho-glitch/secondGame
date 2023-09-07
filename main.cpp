#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

namespace globalSpace{
//Global function
int randomNum(int intMin, int intMax){
        int range = intMax - intMin + 1;
        int randomNumber = rand() % range + intMin;

        return randomNumber;
    }
}


struct GameWorld{
    int rows;
    int cols;
    int* GameArray;
    char GameElements[2] = {'*', '0'};

    GameWorld(int r){
        rows = r;

        //initialize every element on the array to the space
        initialize();
        //insert the player at a random place
        insertPlayer();
    }

    //puts empty spaces int the array
    void initialize(){
        GameArray = new int[rows];
        for(int r = 0; r < rows; r++){
            GameArray[r] = 0;
        }
    }

    void insertPlayer(){
        int PositionIndex = globalSpace::randomNum(0, rows - 1);
        //insert player in array which is 1
        GameArray[PositionIndex] = 1;
    }

    void movePlayer(int MOVE_POS){
        if(MOVE_POS == 0){
            //move left
            GameArray[getPlayer() - 1] = 1;
            GameArray[getPlayer()] = 0;
        }


        //
    }

    int getPlayer(){
        int playerPos;

        for(int r = 0; r < rows; r++){
            if(GameArray[r] == 1){
                playerPos = r;
            }
        }

        return playerPos;
    }

    //print game
    void printGame(){
        for(int counterRow = 0; counterRow < rows; counterRow++){
            //print every element in the array
            int GameElement = GameArray[counterRow];
            switch(GameElement){
            case 0:
                {
                    cout << GameElements[0] << " ";
                    break;
                }
            case 1:
                {
                    cout << GameElements[1] << " ";
                }
            }
        }
        cout << endl;
    }
};




int main()
{

    //seed random
    srand(time(0));

    //create game world
    GameWorld myGame = GameWorld(15);
    //player gets 20 moves
        int turnCounter = 20;


    //move player
    bool blnContinue = true;
    do{
            //this code clears the screen
            system("cls");

        myGame.printGame();
        //print turn number
        cout << "Turn : " << turnCounter << endl;


        int x;
        x = globalSpace::randomNum(1, 3);
        cout << "Guess a Number between 1 - 3 to move player" << endl;
        int guess = 0;
        cin >> guess;

        if(guess == x){
                //if player is at the end print game won message
                if(!(myGame.getPlayer() == 0) && turnCounter > 0){
                    myGame.movePlayer(0);
                }

        }

        turnCounter--;
        if(turnCounter == 0){
                        cout << "-----------------YOU LOSE---------------------" << endl;
                        blnContinue = false;
        }

        if(myGame.getPlayer() < 0){
            cout << "-----------------YOU WIN---------------------" << endl;
                    blnContinue = false;
        }


    }while(blnContinue);

    return 0;
}
