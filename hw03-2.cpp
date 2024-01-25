#include <iostream>
using namespace std;
/***
Title: HW03-2.cpp
Abstract: This program is practice dor adding operations into a list.
Author: Kimberly Gaeta
Email: Kgaeta@csumb.edu
Date: 2/12/2023
Estimate: 3 hours
  ***/
const int CAPACITY = 16;
class List {
public:
	List();
	bool empty() const;
	void insert(int item, int pos);
	void erase(int pos);
	void display() const;
	int find(int value) const;
	int sum() const;

	/***********************
  ----------- HW 03 - 2 CODE -----------
  ***********************/
	// void append(int item);
	void append(int value);
  int getValue(int pos) const;
  bool hasDuplicate() const;
  bool isSorted() const;
  bool append (const List l);
  bool remove (int value);
 	int getSize() const {
		return mySize;
	};

private:
	int mySize;
	int myArray[CAPACITY];
};
int main() {
	List intList;
	cout << "Constructing intList\n";

	// testing empty
	if (intList.empty()) {
		cout << "Empty List: \n";
		intList.display();
		cout << endl;
	}
	// testing insert
	for (int i = 0; i < 9; i++) {
		cout << "Inserting " << i << " at position " << i / 2 << endl;
		intList.insert(i, i / 2);
		// testing display
		intList.display();
	}

	cout << "List empty? " << (intList.empty() ? "Yes" : "No") << endl;
	// testing for errors
	cout << "\nTry to insert at position -1" << endl;
	intList.insert(0, -1);
	cout << "\nTry to insert at position 10" << endl;
	intList.insert(0, 10);

	// testing sum
	intList.display();
	cout << "The sum is " << intList.sum() << endl;

	// test ing find (valid and invalid)
	cout << "Attempting to find the location of 7\n";
	cout << "\tThe location is: " << intList.find(7) << endl;
	cout << "Attempting to find the location of 9001\n";
	cout << "\tThe location is: " << intList.find(9001) << endl;
	/***********************
  ----------- HW 03 - 2 CODE -----------
  ***********************/
  
	List testingList;
	testingList.append(2);
	testingList.append(4);
	testingList.append(6);
	testingList.append(8);
  testingList.append(6);
	testingList.append(10);
  testingList.append(9);
  testingList.append(15);
	testingList.display();
  
  cout << "\n";
  // testing get value (valid and invalid)
  cout << "Attempting to find the value at location 5\n";
  cout << "\tThe value is: " << testingList.getValue(5) << endl;
  cout << "Attempting to find the value at location 604\n";
  cout << "\tThe value is: " << testingList.getValue(604) << endl;
  cout << "\n";
  // testing duplicate
  cout << "Are there duplicate values in the list?\n"
    << "\t" << boolalpha << testingList.hasDuplicate()
    << "\n";

  //testing sorting 
  cout << "Is the list sorted in ascending order?\n\t" 
    << boolalpha << testingList.isSorted() << "\n";
  
  // testing appending lists
  cout << "Adding in another list\n";
  testingList.append(intList);
  testingList.display();
  
  // testing remove 
  cout << "Removing the value 8 from the list!\n\t";
  testingList.remove(8);
  testingList.display();
  
  cout << "Removing the value 27 from the list!\n\t";
  testingList.remove(27);

  
	return 0;
}
// class constructor definition WORKS
List::List() {
	mySize = 0;
}
// empty definition WORKS
bool List::empty() const {
	return mySize == 0;
}
// display definition WORKS
void List::display() const {
	for (int i = 0; i < mySize; i++) {
		cout << myArray[i] << "  ";
	}
	cout << endl;
}
// insert definition WORKS
void List::insert(int item, int pos) {
	if (mySize == CAPACITY) {
		cerr << "*** No space for list element -- terminating "
				"execution ***\n";
		return;
	}
	if (pos < 0 || pos > mySize) {
		cerr << "*** Illegal location to insert -- " << pos
			 << ".  List unchanged. ***\n";
		return;
	}
	for (int i = mySize; i > pos; i--) {
		myArray[i] = myArray[i - 1];
	}
	myArray[pos] = item;
	mySize++;
}
// erase definition WORKS
void List::erase(int pos) {
	if (mySize == 0) {
		cerr << "*** List is empty ***\n";
		return;
	}
	if (pos < 0 || pos >= mySize) {
		cerr << "Illegal location to delete -- " << pos
			 << ".  List unchanged. ***\n";
		return;
	}
	for (int i = pos; i < mySize; i++) {
		myArray[i] = myArray[i + 1];
	}
	mySize--;
}
// find position defintion WORKS
int List::find(int value) const {
	for (int i = 0; i < mySize; i++) {
		if (myArray[i] == value) {
			return i;
		}
	}
	return -1;
}
// sum definition WORKS
int List::sum() const {
	int sum = 0;
	for (int i = 0; i < mySize; i++) {
		sum += myArray[i];
	}
	return sum;
}
/***********************
----------- HW 03 - 2 CODE -----------
***********************/
// append definition WORKS
void List::append(int value) {
	if (mySize != CAPACITY) {
		myArray[mySize] = value;
		mySize++;
	}else {
    cerr << "List is full!!";
  }
}
// get value definition WORKS
int List::getValue(int pos) const{
  int blank = -1;
  if (-1 > pos || pos > (mySize - 1)){
    return blank;
  }else {
   return myArray[pos];
  }
}
// has duplicate definition WORKS
bool List::hasDuplicate() const{
 for (int i = 0; i < mySize; i++){
   for (int k = mySize; k > i; k--){
     if (myArray[i] == myArray[k]){
       return true;
     }
   }
 }
  return false;
}
// sorting definition WORKS
bool List::isSorted() const{
  if (mySize == 0 || mySize == 1){
    return true;
  }
  for (int i = 0; i < mySize-1; i++){
    if (myArray[i] > myArray[i+1] ){
      return false;
    }
  }
  return true;
}
// appending list definition WORKS
bool List::append (const List l){
  int total = l.mySize + mySize;
  if (total > CAPACITY){
    cerr << "List Would Exceed Capacity!!\n";
    return false;
  } else {
    int check = 0;
    for (int i = mySize; i < total; i++){
      append(l.myArray[check]);
      check++;
    }
    return true;
  }
}
// remove definition
bool List::remove (int value){
  bool find = false;
  for (int i = 0; i < mySize; i++){
    if (value == myArray[i]){
      erase(i);
      find = true;
    }
  }
  if (find == true){
    return true;
  }else{
    cerr << "Value is not in the list!\n\n";
    return false;
  }
 
}
