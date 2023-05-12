//---------------------------------------------------------------------------
#ifndef UClassesH
#define UClassesH
//---------------------------------------------------------------------------
#endif

// Using Inheritance in C++
class Account{

public:
	Account(double b): balance(b){}

    void deposit(double amt){
    	balance += amt;
    }

    void withdraw(double amt){
    	balance -= amt;
    }

    double getBalance() const {
    	return balance;
    }

private:
	double balance;
};

class BankAccount: public Account{

public:
    // using Account::Account;
    BankAccount(double b): Account(b){}

    void addInterest(){
    	deposit( getBalance()*0.05 );
    }
};

// Using Polymorphism in C++
class Shape {
public:
	Shape() {}
  	//defining a virtual function called Draw for shape class
  	virtual String Draw() { return "Drawing a Shape"; }
};

class MyRectangle : public Shape {
public:
  	MyRectangle() {}
  	//Draw function defined for Rectangle class
  	virtual String Draw() { return "Drawing a Rectangle"; }
};

class Triangle : public Shape {
public:
  	Triangle() {}
  	//Draw function defined for Triangle class
  	virtual String Draw() { return "Drawing a Triangle"; }
};

class Circle : public Shape {
public:
  	Circle() {}
  	//Draw function defined for Circle class
  	virtual String Draw() { return "Drawing a Circle"; }
};

// Abstraction and Encapsulation
class abstraction
{
private:
    int a, b;

public:
    // public setter function
    void set(int x, int y)
    {
        a = x;
        b = y;
    }

    // public getter function
    String GetValuesToDisplay()
    {
        return  "a = " + String(a) + "\n" +
        		"b = " + String(b);
    }
};
