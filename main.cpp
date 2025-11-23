#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

class Elevator {
private:
    int current_floor;
    int destination_floor;
    int elevator_state;

public:
    Elevator(int start_floor, int dest_floor)
        : current_floor(start_floor), destination_floor(dest_floor) {}

    void move() {
        auto start = chrono::high_resolution_clock::now();

        if (current_floor > destination_floor) {
            while (current_floor != destination_floor) {
                this_thread::sleep_for(chrono::milliseconds(500));
                current_floor--;
                cout << "Elevator at floor " << current_floor << endl;
            }
        } else {
            while (current_floor != destination_floor) {
                this_thread::sleep_for(chrono::milliseconds(500));
                current_floor++;
                cout << "Elevator at floor " << current_floor << endl;
            }
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Elevator finished in " << duration.count
		
		() << " ms" << endl;
    }

    int getCurrentFloor() const {
        return current_floor;
    }
};

class ElevatorController {
private:
    vector<Elevator> elevators;

public:
    void addElevator(const Elevator& e) {
        elevators.push_back(e);
    }

    void runAll() {
        vector<thread> threads;
        for (auto& e : elevators) {
            threads.push_back(thread(&Elevator::move, &e));
        }

        for (auto& t : threads) {
            t.join();
        }
    }
};

int main() {
    ElevatorController controller;
	
	bool start=true;
	while(start == true){
		bool direction;
		cin>>direction;
		if(direction==false){
			
		}
		else{
			
		}
		controller.addElevator(Elevator(1, 5));
	    controller.addElevator(Elevator(2, 6));
	    controller.addElevator(Elevator(7, 3));
	
	    controller.runAll();	
	}
    return 0;
}
