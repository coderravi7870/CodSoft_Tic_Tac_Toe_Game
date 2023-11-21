#include<iostream>

using namespace std;

char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int colum;
char token = 'x';
bool tie = false;
string n1 = "";
string n2 = "";

void functionOne(){
    cout<<"   |    |   \n";
    cout<<" "<<space[0][0]<<" | "<<space[0][1]<<"  | "<<space[0][2]<<"   \n";
    cout<<"___|____|___\n";
    cout<<"   |    |   \n";
    cout<<" "<<space[1][0]<<" | "<<space[1][1]<<"  | "<<space[1][2]<<"   \n";
    cout<<"___|____|___\n";
    cout<<"   |    |   \n";
    cout<<" "<<space[2][0]<<" | "<<space[2][1]<<"  | "<<space[2][2]<<"   \n";
    cout<<"   |    |   \n";
}

void functionTwo(){
    int digit;
    
    if(token == 'x'){
        cout<<n1<< " Please Enter : ";
        cin>>digit;
    }
    if(token == 'o'){
        cout<<n2<<" Please Enter : ";
        cin>>digit;
    }

    if(digit == 1){
        row = 0;
        colum = 0;
    }
    else if(digit == 2){
        row = 0;
        colum = 1;
    }
    else if(digit == 3){
        row = 0;
        colum = 2;
    }
    else if(digit == 4){
        row = 1;
        colum = 0;
    }
    else if(digit ==5){
        row = 1;
        colum = 1;
    }
    else if(digit == 6){
        row = 1;
        colum = 2;
    }
    else if(digit == 7){
        row = 2;
        colum = 0;
    }
    else if(digit == 8){
        row = 2;
        colum = 1;
    }
    else if(digit == 9){
        row = 2;
        colum = 2;
    }
    else{
        cout<<"Invalid !!!"<<endl;
    }

    if(token =='x' && space[row][colum] != 'x' && space[row][colum] != 'o'){
        space[row][colum]= 'x';
        token = 'o';
    }
    else if(token =='o' && space[row][colum] != 'x' && space[row][colum] != 'o'){
        space[row][colum]= 'o';
        token = 'x';
    }
    else {
        cout<<"There is no empty space ! "<<endl;
        functionTwo();
    }
    functionOne();
}

bool functionThree(){
    for(int i=0;i<3;i++){
        if((space[i][0]==space[i][1] && space[i][1]==space[i][2]) || (space[0][i]==space[1][i] && space[1][i]==space[2][i])) return false;
    }
    if((space[0][0]==space[1][1] && space[1][1]==space[2][2]) || (space[0][2]==space[1][1] && space[1][1]==space[2][0])) return false;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j] != 'x' && space[i][j] != 'o') {
                
                return true;
            }    
        }
    }

    tie = true;
    
    return false;
}

int main(){
    cout<<"Enter the name of the First Player : ";
    getline(cin,n1);
    cout<<"Enter the name of the Second Player : ";
    getline(cin,n2);

    cout<<n1 <<" is player1 so he/she will play first \n";
    cout<<n2 <<" is player2 so he/she will play Second \n";
    
    while(functionThree()){
        functionOne();
        functionTwo();
        functionThree();
    }
    
    if(token == 'x' && tie == false){
        cout<<n2 <<" Wins"<<endl;
    }
    else if(token == 'o' && tie == false){
        cout<<n1 <<" Wins"<<endl;
    }
    else{
        cout<<"Game is draw ! "<<endl;
    }
}