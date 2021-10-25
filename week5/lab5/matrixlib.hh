#ifndef _MATRIXLIB_hh
#define _MATRIXLIB_hh

#include <iostream>
#include <string>

#include "param.hh"

bool matEqual(int A[][N], int B[][N]);

void matAdd(int A[][N], int B[][N], int C[][N]);

void matSub(int A[][N], int B[][N], int C[][N]);

void matMul(int A[][N], int B[][N], int C[][N]);

void transpose(int A[][N], int A_T[][N]);

std::string matrixToString(int A[][N]);

#endif