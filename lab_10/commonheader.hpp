//
//  commonheader.hpp
//  lab_10
//
//  Created by Mike Mikulin on 24.11.2023.
//

#ifndef commonheader_hpp
#define commonheader_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void fillmat(double** mat, int ij);
void print(double** mat, int ij);
void inverting(double** mat, int ij);
void row_min(double **mat,int ij, int i, int ii, double kdel);
void column_make_zero(double** mat, int ij, int ii);
void replace(double** mat, int(ij), int i, int ii);
void mult(double** A, double* B, double* ans, int ij);

#endif /* commonheader_hpp */

