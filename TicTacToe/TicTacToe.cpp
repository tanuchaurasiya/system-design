#include <iostream>
#include<vector>
using namespace std;

class CustomException: public std::runtime_error 
{
  public:

    CustomException(const std::string& message) : std::runtime_error(message) { 
    } 
};

class TicTacToe{
    public:
        vector<vector<int>> board; 
        int N;
        TicTacToe(int n){
            N=n;
            board.resize(n, vector<int>(n));
        }
        
        int move(int player, int row, int col){
            try{
                if(row<0 || col<0 ||row>=N ||col>=N) 
                    throw CustomException("Move Out Of Board Boundary\n");
                
                else if(board[row][col]!=0) 
                    throw CustomException("Square is already Occupied\n"); 
                    
                else if(player!=0 && player!=1) 
                    throw CustomException("Invalid Player\n"); 
                
                else{
                    player = player==0 ? -1 : +1;
                    board[row][col] = player;
                    // FOR ROW
                    bool win = true; 
                    for(int i=0;i<N;i++){
                        if(board[row][i]!=player){
                            win = false;
                            break;
                        }
                    } 
                    if(win) return player;  
                    
                    
                    // FOR COLUMN 
                    win = true;
                    for(int i=0;i<N;i++){
                        if(board[i][col]!=player){
                            win = false;
                            break;
                        }
                    } 
                    if(win) return player; 
                    
                    
                    // FOR DIAGONAL 
                    win = true;
                    if(row==col){
                        for(int i=0;i<N;i++){
                            if(board[i][i]!=player){
                                win = false;
                                break;
                            }
                        } 
                        if(win) return player;
                    }
                    
                    
                    
                    // FOR  REVERSE DIAGONAL 
                    win = true;
                    if(row==N-col-1){
                        for(int i=0;i<N;i++){
                            if(board[i][N-i-1]!=player){
                                win = false;
                                break;
                            }
                        } 
                        if(win) return player;
                    } 
                    
                }
            }
            catch(CustomException& s){   
                cout<<s.what()<<endl; 
                return 2;
            }  
             return 0;
        }
};
int main()
{
    cout<<"LETS PLAY TICTACTOE\n";
    TicTacToe t(3); 
    int row;
    int col;
    int i=0; 
    int player=0;
    while(i<9){
        cout<<"player "<<player<<" turn\n"; 
        cout<<"enter row and col "<<endl;
        cin>>row>>col; 
        int ret = t.move(player, row, col); 
        
        player = !player; 
        if (ret==2) {
            cout<<"you have entered wrong details game over\n"; 
            return 0;
        }
        
        else if(ret==1) {
            cout<<"player 0 wins\n"; 
            return 0;
        }
        
        else if(ret==-1){
            cout<<"player 1 wins\n";
            return 0;
        }
        
        else{
            if(i==8) {
                cout<<"match draw\n";
                return 0;
            } 
        } 
        i++;
        
    }
    return 0;
}



