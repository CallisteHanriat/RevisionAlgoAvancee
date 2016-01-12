//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education

#include "PrecondVioleeExcep.h"  

using namespace std;

PrecondVioleeExcep::PrecondVioleeExcep(const string& message) : logic_error("Précondition non respectée : " + message) {
} // end constructor

// End of implementation file.

