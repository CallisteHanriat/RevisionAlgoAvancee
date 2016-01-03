//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education

/** @file ExceptionPreconditionViolee.h */

#ifndef _EXCEPTION_PRECOND_VIOLEE
#define _EXCEPTION_PRECOND_VIOLEE

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
   PrecondViolatedExcep(const string& message = "");
}; // end ExceptionPreconditionViolee 

#endif
