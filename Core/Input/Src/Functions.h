#pragma once
#include <functional>
using namespace std;

typedef std::function<void(double x, double y)> CursorPositionUpdate; /*Functions that take two doubles.*/
typedef std::function<void(void)> CommandFunc; /*Functions with no input.*/
typedef std::function<void(double d)> AxisPostionFunction; /*Functions that take one double.*/

//Author Hasan Al-Baghdadi

/***
* A base function class that stores a function and its ID
*/
class Function {
public:
    /***
     *This is a function class constructor that gives this function a unique ID.
     */
    Function(int &i) {
        m_id = i;
        i++;
    };
    /***
     *This is a function class default destructor.
     */
    ~Function() {};

    /***
     * Returns the Id of the function.
     */
    int GetID() { return m_id; };
protected:
    
    /***
     * The Id of a function, TODO: research why I did this.
     */
    int m_id;
};

/***
* A function class that stores a CursorPositionUpdate and its ID
*/
class DoubleFunction :public Function {
public:
    /***
     * Takes Id and a cursorPosition function to create the class
     */
    DoubleFunction(int &i, CursorPositionUpdate f): Function(i), m_function(f) {

    }
    /* 
     * Executes the function
     */
    void Run(double x, double y) { m_function(x,y); }

protected:
    CursorPositionUpdate m_function; /*the function.*/
};

class VoidFunction :public Function {
public:
    /***
     * Takes Id and a CommandFunc function to create the class
     */
    VoidFunction(int &i, CommandFunc f) : Function(i), m_function(f) {

    }
    /*
     * Executes the function
     */
    void Run() { m_function(); }

protected:
    CommandFunc m_function; /*the function.*/
};

class SingleFunction :public Function {
public:
    /***
     * Takes Id and an AxisPostionFunction function to create the class
     */
    SingleFunction(int &i, AxisPostionFunction f) : Function(i), m_function(f) {

    }
    /*
     * Executes the function
     */
    void Run(double x) { m_function(x); }

protected:
    AxisPostionFunction m_function; /*the function.*/
};