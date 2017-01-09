#include <cstdlib> //EXIT_FAILURE
#include <iostream>
#include <stdexcept> //std::logic_error



float calculate(const char operation, const float left, const float right){
	
	//switch
	switch(operation){
		//read input from left to right in order to do the calculation
		// add
		case '+':
			return left + right;
		//substract
		case '-':
			return left - right;
		//divide
		case '/':
			return left / right;
		//multiply
		case '*':
			return left * right;
		//if user enters not defined above operator. Thro an error.
		default: throw std::logic_error("unsupported operator");
	}//end switch
	
}// end calculate

using namespace std; //using standard library (no need to write std:: before everything in c++ standard library
//main method
int main(){
	cout << "Enter two numbers: " << endl;
	//declare the type of integer (float - with decimal point) for 2 numbers
	float left, right;
	//prompt for number 1(left) then number 2(right)
	cin >> left >> right;
	
	cout << "\nEnter your operation (+, -, /, *): " << endl;
	//declare type of integer which will be entered
	char operation;
	//prompt user for chosen operator
	cin >> operation;
	
	// delete right away if dividing by zero
	if(operation == '/' && right == 0){
		//cerr - ostream's error stream (char)
		cerr << "Cannot divide by 0";
		//terminate
		return EXIT_FAILURE;
	}// end if
	
	//declare the variable result
	float result;
	
	// attemt the calculation (will throw error if failed)
	try {
		//try tocalculate the result
		result = calculate(operation, left, right);
	}//end try
	
	// if it failst - catch an exception, display it then delete (terminate)it;
	catch(logic_error const& e){
		//ostreams error streaam (to catch errors)
		cerr << "Error: " << e.what();
		//terminate
		return EXIT_FAILURE;
	}// end catch logic error
	
	//display the result of user's calculation
	cout << "\nResult = " << result << endl;

	system("pause"); // pause calculator .exe file from closing after showing the result

}//end main
