#include "Station.h"


//Part 1--------------------------------------------------------------
bool Station::find(int IDnum){
    if(IDlist.findValue(IDnum) == true){
        return true;
    }
    else{
        return false;
    }
}
/**
 * Let another car arrive at the station and become the current car.
 * Do not allow a new car to arrive if any of the following conditions apply:
 * 1.	There is already a current car
 * 2.	The new car's ID already exists in any structure
 * 3.	The new car's ID is negative
 *
 * @param car the ID of the car arriving at the station
 * @return true if the car successfully arrived; false otherwise
 */
bool Station::addToStation(int car){
    if (find(car)){
        cout << "Car is already in station" << endl;
        return false;
    }
    else if(turntable < 0 && car >=1 ){
        cout << "addToStation "<<car<<endl;
        turntable = car;
        return(true);
    }
    else{
        cout << "Car " << turntable << " is already in turntable \n";
        return false;
    }
}

/**
 * Returns the ID of the current car.
 * Return -1 if there is no current car.
 *
 * @return the ID of the current car; -1 if there is no current car
 */
int Station::showCurrentCar(){
    cout << "showCurrentCar "<< turntable <<endl;
}

/**
 * Removes the current car from the station.
 * Does nothing if there is no current car.
 *
 * @return true if the current car successfully left; false otherwise
 */
bool Station::removeFromStation(){
    cout << "removeFromStation "<<turntable<<endl;
    // remove from list
    IDlist.remove(turntable);
    turntable = -1;
    return(true);
}

//Part 2--------------------------------------------------------------
/**
 * Adds the current car to the stack.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the stack is already full.
 *
 * @return true if the car is successfully added to the stack; false otherwise
 */
bool Station::addToStack(){
    if (turntable > 0 && stacksize < 5){
        cout << "addToStack "<< turntable <<endl;
        thestack.push(turntable);
        IDlist.insertHead(turntable);
        turntable = -1;
        stacksize++;
        return true;
    }
}

/**
 * Removes the first car in the stack and makes it the current car.
 * Does nothing if there is already a current car or if the stack already empty.
 *
 * @return true if the car is successfully removed from the stack; false otherwise
 */
bool Station::removeFromStack(){
    if (turntable <= 0){
        cout << "removeFromStack "<< thestack.top() << endl;
        turntable = thestack.top();
        thestack.pop();
        stacksize--;
    }
}

/**
 * Returns the ID of the first car in the stack.
 *
 * @return the ID of the first car in the stack; -1 if the stack is empty
 */
int Station::showTopOfStack(){
    cout << "showTopOfStack ";
    return (thestack.top());
}
/**
 * Returns the number of cars in the stack.
 *
 * @return the number of cars in the stack
 */
int Station::showSizeOfStack(){
    cout << "showSizeOfStack ";
    return stacksize;
}

//Part 3--------------------------------------------------------------
/**
 * Adds the current car to the queue.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the queue is already full.
 *
 * @return true if the car is successfully added to the queue; false otherwise
 */
bool Station::addToQueue(){
    if (turntable > 0 && thequeue.size < 5){
        cout << "addToQueue " << turntable <<endl;
        thequeue.push(turntable);
        IDlist.insertHead(turntable);
        turntable = -1;
        thequeue.size++;
        return true;
    }
}

/**
 * Removes the first car in the queue and makes it the current car.
 * Does nothing if there is already a current car or if the queue already empty.
 *
 * @return true if the car is successfully removed from the queue; false otherwise
 */
bool Station::removeFromQueue(){
    if (turntable <= 0){
        cout << "removeFromQueue "<<endl;
        turntable = thequeue.front();
        thequeue.pop();
        thequeue.size--;
    }
}

/**
 * Returns the ID of the first car in the queue.
 *
 * @return the ID of the first car in the queue; -1 if the queue is empty
 */
int Station::showTopOfQueue(){
    cout << "showTopOfQueue ";
    return (thequeue.front());

}

/**
 * Returns the number of cars in the queue.
 *
 * @return the number of cars in the queue
 */
int Station::showSizeOfQueue(){
    cout << "showSizeOfQueue "<<endl;
    return thequeue.size;
}

//Part 4--------------------------------------------------------------
/**
 * Adds the current car to the deque on the left side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the deque is already full.
 *
 * @return true if the car is successfully added to the deque; false otherwise
 */
bool Station::addToDequeLeft(){
    if (turntable > 0 && thedeque.size < 5){
        cout << "addToDequeLeft "<< turntable << endl;
        thedeque.push_front(turntable);
        IDlist.insertHead(turntable);
        turntable = -1;
        thedeque.size++;
        return true;
    }
}

/**
 * Adds the current car to the deque on the right side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the deque is already full.
 *
 * @return true if the car is successfully added to the deque; false otherwise
 */
bool Station::addToDequeRight(){
    if (turntable > 0 && thedeque.size < 5){
        cout << "addToDequeRight "<< turntable << endl;
        thedeque.push_back(turntable);
        IDlist.insertHead(turntable);
        turntable = -1;
        thedeque.size++;
        return true;
    }
}

/**
 * Removes the leftmost car in the deque and makes it the current car.
 * Does nothing if there is already a current car or if the deque already empty.
 *
 * @return true if the car is successfully removed from the deque; false otherwise
 */
bool Station::removeFromDequeLeft(){
    if (turntable <= 0 ){
        cout << "removeFromDequeLeft "<<endl;
        turntable = thedeque.front();
        thedeque.pop_front();
        thedeque.size--;
    }
}

/**
 * Removes the rightmost car in the deque and makes it the current car.
 * Does nothing if there is already a current car or if the deque already empty.
 *
 * @return true if the car is successfully removed from the deque; false otherwise
 */
bool Station::removeFromDequeRight(){
    if (turntable <= 0){
        cout << "removeFromDequeRight "<<endl;
        turntable = thedeque.back();
        thedeque.pop_back();
        thedeque.size--;
    }
}

/**
 * Returns the ID of the leftmost car in the deque.
 *
 * @return the ID of the leftmost car in the deque; -1 if the deque is empty
 */
int Station::showTopOfDequeLeft(){
    cout << "showTopOfDequeLeft ";
    return (thedeque.front());
}

/**
 * Returns the ID of the rightmost car in the deque.
 *
 * @return the ID of the rightmost car in the deque; -1 if the deque is empty
 */
int Station::showTopOfDequeRight(){
    cout <<"showTopOfDequeRight ";
    return (thedeque.back());
}

/**
 * Returns the number of cars in the deque.
 *
 * @return the number of cars in the deque
 */
int Station::showSizeOfDeque(){
    cout <<"showSizeOfDeque"<<endl;
    return thedeque.size;
}

		//Input-Restricted Deque----------------------------------------------
		/**
		 * Adds the current car to the IRDeque on the left side.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the IRDeque is already full.
		 *
		 * @return true if the car is successfully added to the IRDeque; false otherwise
		 */
bool Station::addToIRDequeLeft(){
    if (turntable > 0 && theIRdeque.size < 5){
        cout << "addToIRDequeLeft "<< turntable << endl;
        theIRdeque.push_front(turntable);
        IDlist.insertHead(turntable);
        turntable = -1;
        theIRdeque.size++;
        return true;
    }
}
		/**
		 * Removes the leftmost car in the IRDeque and makes it the current car.
		 * Does nothing if there is already a current car or if the IRDeque already empty.
		 *
		 * @return true if the car is successfully removed from the IRDeque; false otherwise
		 */
bool Station::removeFromIRDequeLeft(){
    if (turntable <= 0){
        cout << "removeFromIRDequeLeft "<<endl;
        turntable = theIRdeque.front();
        theIRdeque.pop_front();
        theIRdeque.size--;
    }
}
		/**
		 * Removes the rightmost car in the IRDeque and makes it the current car.
		 * Does nothing if there is already a current car or if the IRDeque already empty.
		 *
		 * @return true if the car is successfully removed from the IRDeque; false otherwise
		 */
bool Station::removeFromIRDequeRight(){
    if (turntable <= 0){
        cout << "removeFromIRDequeRight "<<endl;
        turntable = theIRdeque.back();
        theIRdeque.pop_back();
        theIRdeque.size--;
    }
}
		
		/**
		 * Returns the ID of the leftmost car in the IRDeque.
		 *
		 * @return the ID of the leftmost car in the IRDeque; -1 if the IRDeque is empty
		 */
int Station::showTopOfIRDequeLeft(){
	cout << "showTopOfIRDequeLeft ";
    return (theIRdeque.front());
}

		/**
		 * Returns the ID of the rightmost car in the IRDeque.
		 *
		 * @return the ID of the rightmost car in the IRDeque; -1 if the IRDeque is empty
		 */
int Station::showTopOfIRDequeRight() {
	cout <<"showTopOfIRDequeRight ";
    return (theIRdeque.back());
}

		/**
		 * Returns the number of cars in the IRDeque.
		 *
		 * @return the number of cars in the IRDeque
		 */
int Station::showSizeOfIRDeque(){
	cout <<"showSizeOfIRDeque"<<endl;
    return theIRdeque.size;  
}

		//Output-Restricted Deque---------------------------------------------
		/**
		 * Adds the current car to the ORDeque on the left side.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the ORDeque is already full.
		 *
		 * @return true if the car is successfully added to the ORDeque; false otherwise
		 */
bool Station::addToORDequeLeft(){
	if (turntable > 0 && theORdeque.size < 5){
        cout << "addToORDequeLeft "<< turntable << endl;
        theORdeque.push_front(turntable);
        IDlist.insertHead(turntable);
        turntable = -1;
        theORdeque.size++;
        return true;
}  
		}

		/**
		 * Adds the current car to the ORDeque on the right side.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the ORDeque is already full.
		 *
		 * @return true if the car is successfully added to the ORDeque; false otherwise
		 */
bool Station::addToORDequeRight(){
	if (turntable > 0 && theORdeque.size < 5){
        cout << "addToORDequeRight "<< turntable << endl;
        theORdeque.push_back(turntable);
        IDlist.insertHead(turntable);
        turntable = -1;
        theORdeque.size++;
        return true;
    }
}

		/**
		 * Removes the leftmost car in the ORDeque and makes it the current car.
		 * Does nothing if there is already a current car or if the ORDeque already empty.
		 *
		 * @return true if the car is successfully removed from the ORDeque; false otherwise
		 */
bool Station::removeFromORDequeLeft(){
    if (turntable <= 0){
        cout << "removeFromORDequeLeft "<<endl;
        turntable = theORdeque.front();
        theORdeque.pop_front();
        theORdeque.size--;
}   
		}

		/**
		 * Returns the ID of the leftmost car in the ORDeque.
		 *
		 * @return the ID of the leftmost car in the ORDeque; -1 if the ORDeque is empty
		 */
int Station::showTopOfORDequeLeft(){
	cout << "showTopOfORDequeLeft ";
    return (theORdeque.front());
}
		/**
		 * Returns the number of cars in the ORDeque.
		 *
		 * @return the number of cars in the ORDeque
		 */
int Station::showSizeOfORDeque(){
	cout <<"showSizeOfORDeque"<<endl;
    return theORdeque.size; 	
}

