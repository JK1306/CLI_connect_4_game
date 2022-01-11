#include <iostream>
#define row 6 
#define column 7

using namespace std;

bool checkPlayerWon(char **arr, char checkColor){
    int colorCount;
    int addCount;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(arr[i][j] == checkColor){
                addCount = 1;
                // check horizontal
                for(int columnI = j+1; addCount<=4 && columnI<column ; columnI++, addCount++){
                    if(arr[i][columnI] != checkColor){ break; }
                }
                if (addCount == 4){
                    return true;
                }

                addCount = 1;
                // check vertical
                for(int rowI = i+1; addCount<=4 && rowI<row ; rowI++, addCount++){
                    if(arr[rowI][j] != checkColor){ break; }
                }
                if (addCount == 4){
                    return true;
                }

                addCount = 1;
                // check diagonal
                for(int rowI = i+1, columnI = j+1; addCount<=4 && rowI<row && columnI<column ; rowI++, columnI++, addCount++){
                    if(arr[rowI][columnI] != checkColor){ break; }
                }
                if (addCount == 4){
                    return true;
                }
             }
            // cout<<"Row : "<<i<<" Column : "<<j<<" : "<<((arr[i][j])? arr[i][j] : 'F')<<endl;
        }
    }
    return false;
}

bool insertPlayer(char **charArr, int columnIndx, char player){
    for(int i=row-1; i>=0; i--){
        if(!charArr[i][columnIndx]){
            charArr[i][columnIndx] = player;
            return true;
        }
    }
    return false;
}

int main(){
    char **playBoard;
    playBoard = new char*[row];
    for(int i=0; i<row; i++){
        playBoard[i] = new char[column];
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            playBoard[i][j] = '\0';
        }
    }
    int arrSize = row*column;
    int insertionCount =0;
    int inputColumn;
    char player;

    while(true){
        if(insertionCount >= arrSize){ 
            cout<<"Match Draw.. :(\n";
            break;
        }
        for(int i=0; i<column; i++){
            cout<<'\t'<<i+1;
        }
        cout<<'\n';
        for(int i=0; i<row; i++){
            cout<<i+1<<'\t';
            for(int j=0; j<column; j++){
                cout<<playBoard[i][j]<<'\t';
            }
            cout<<'\n';
        }
        player = (insertionCount%2==0)?'R':'Y';
        cout<<"Player - "<<player<<endl;
        cout<<"Enter Column : ";
        cin>>inputColumn;
        if (inputColumn > column){
            cout<<"\t\n !! Enter Valid Column !! \n\n";
            continue;
        }
        if(insertPlayer(playBoard, inputColumn-1, player)){
            insertionCount++;
            if(checkPlayerWon(playBoard, player)){
                if(player == 'R'){
                    cout<<"Hurray...... Player - 1 Red WON... :)\n";
                }else{
                    cout<<"Yeah..... Player - 2 Yellow WON... :>\n";
                }
                break;
            }
        }
        else{
            cout<<"\t\n** Column is Full Try different Column **\n\n";
        }
    }
}