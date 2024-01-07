#include <iostream> 
#include<vector> 
#include<string>
#include<sstream> 
#include<algorithm>
using namespace std;


class Elevator{
    private:
        enum Direction{UP, DOWN}; 
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
        void set_direction(int flor);
        
    public:
        Elevator(int min_floor, int max_floor, int capacity){ 
            this->min_floor = min_floor;
            this->max_floor = max_floor;
            this->capacity = capacity;
        }
        
        ~Elevator(){}
        
        void start_elevator();
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
    return issue_number;
}

void Elevator::set_direction(int flor){
    if(current_floor>flor) {
        direction = DOWN;
    }
    
    else if(current_floor<flor) {
        direction = UP;
    }
}

void Elevator::set_request(){
    string dest_floors_str; //stores all floors request
 	string dest_floor_str; //stores single floor in string
 	int dest_floor; // stores single floor as integer 
 	
 	int num_of_reqs = capacity - passengers;
 	cout << "\n" << num_of_reqs << " passengers can enter in the elevator right now\n";
	
	cout << "\nEnter \"GO\" if no one enters from the floor \nOr to exit from program if elevator is idle\n";

 	cout << "\nEnter destination floor number.\n"; 
 	
 	getline(std::cin, dest_floors_str); 
 	stringstream s(dest_floors_str);
 	
 	while(s >> dest_floor_str){
 	    if (dest_floor_str == "GO" || dest_floor_str == "Go" || dest_floor_str == "go" || dest_floor_str == "gO"){
 			return;
 		}
 		
 		dest_floor = stoi(dest_floor_str); 
//  		cout<<"dest_floor "<<dest_floor<<endl;
 		if(passengers<capacity){
 		    int is_valid = is_valid_request(dest_floor); 
 		    if(is_valid==0) {
 		        if(passengers==0) 
 		            set_direction(dest_floor);
 		        requests.push_back(dest_floor);
 				passengers++;
 		    }
 		}
 		else if (passengers == capacity){
 			cout << "Elevator full!! Cannot accept more requests\n";
 			return;
 		}
 		
 	}
}

void Elevator:: start_elevator(){
    std::cout << "\nFLOOR : " << current_floor << "\tNumber of Occupants : " << passengers <<"\n";
 	//Entering requests for first time
 	set_request();
 	cout<<"req size="<<requests.size()<<endl;
 	sort(requests.begin(), requests.end());
 	int next_floor;
 	while(!requests.empty()){
 	    if(direction==UP){
 	        next_floor = requests[0];
 	    }
 	    if(direction==DOWN)
 	        next_floor = requests[requests.size()-1];
 	    
 	    auto next_floor_req = find(requests.begin(), requests.end(), next_floor);
 	    while(next_floor_req!=requests.end()){
 	        requests.erase(next_floor_req);
 	        passengers--;
 	        next_floor_req = find(requests.begin(), requests.end(), next_floor);
 	    }
 	    
 	    current_floor = next_floor;
 	    string dir;
 		if (direction == UP)
 		{
 			dir = "UP";
 		}
 		else
 		{		
 			dir = "DOWN";
 		}

 		//Entering requests for current floor
 		std::cout << "\n=======================================================\n"
    		"FLOOR : " << current_floor 
    		<< "\tNumber of Occupants : " << passengers 
    		<< "\n\nDIRECTION : " << dir 
    		<< "\tTotal Capacity : " << capacity
    		<< "\n\nMinimum floor number is " << min_floor
    		<< "\tMaximum floor number is " << max_floor
    		<< "\n\n=======================================================\n";

 		if (current_floor == max_floor)
 		{
 			direction = DOWN;
 		}
		else if (current_floor == min_floor) 		
		{
 			direction = UP;
 		}

 		set_request();
 		std::sort(requests.begin(), requests.end());	
 	}

}
int main()
{
	std::string capacity_str, min_floor_num_str, max_floor_num_str;
	int min_floor_num, max_floor_num;
	std::size_t capacity;

	std::cout << "Enter minimum floor number, maximum floor number in the building\n";
	std::cin >> min_floor_num_str;
	std::cin >> max_floor_num_str;

	min_floor_num = std::stoi(min_floor_num_str);
	max_floor_num = std::stoi(max_floor_num_str);

	std::cout << "Enter capacity for the elevator\n";
	std::cin >> capacity_str;
	std::cin.ignore();
	std::stringstream capacity_stream(capacity_str);
	capacity_stream >> capacity;

	Elevator elevator(min_floor_num, max_floor_num, capacity);
	elevator.start_elevator();	
}