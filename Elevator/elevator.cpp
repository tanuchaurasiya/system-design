#include <iostream> 
#include<vector> ;
using namespace std;


class Elevator{
    private:
        enum Direction{"UP", "DOWN"}; 
        Direction direction; 
        vector<int> requests={}; 
        int min_floor;
        int max_floor;
        int current_floor=0;
        unsigned int passengers = 0;
        unsigned int capacity; 
        
        
        void set_request(); 
        int check_request(int flor); //since floor is a keyword
        int is_valid_request(int flor);
        void set_direction();
        
    public:
        Elevator(int min_floor, int max_floor, int capacity){ 
            this->min_floor = min_floor;
            thid->max_floor = max_floor;
            this->capacity = capacity;
        }
        
        ~Elevator(){}
        
        void startElevator();
};


int Elevator::check_request(int flor){
    // if direction is valid then 0 will be returned 
    if(passengers!=0 && direction==UP && current_floor>flor)  return 1;
    if(passengers!=0 && direction==DOWN && current_floor<flor) return 2; 
    if(flor>max_floor || flor<min_floor) return 3;
    if(passengers>capacity) return 4;
    return 0;
}

int Elevator::is_valid_request(int flor){
    int issue_number = check_request(flor);
    if(issue_number==1) cout<<"Elevator is going UP\n";
    if(issue_number==2) cout<<"Elevator is going DOWN\n"; 
    if(issue_number==3) cout<<"This floor dosen't exist\n"; 
    if(issue_number==4) cout<<"Capacity has crossed its limit\n";
}
int main()
{
    cout<<"Hello World";

    return 0;
}