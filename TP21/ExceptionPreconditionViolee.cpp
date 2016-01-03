//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education


/** @file ExceptionPreconditionViolee.cpp */

#include "ExceptionPreconditionViolee.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& message): logic_error("Precondition Violated Exception: " + message)
{
}  // end constructeur

// End du fichier d'implantation

