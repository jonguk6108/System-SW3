//CHANGE COPYRIGHT HEADER WHEN YOU WRITE CODE (SUTDENT NAME, VERSION DATE MUST BE CHANGED)

/* ******************************************************************************************************************
 * Copyright (c) 2021 2017312848, Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : ppm.cc
 * - File Type : c++ source code
 * - File Version(Last Update Date) : 1.1 (Sep. 26, 2021.)
 * - Date : Sep. 9, 2021.
 * - Description : Version 1.0 is provided skeleton code for SSE2034-41(SKKU, 2021) class HW4.
 *                 This file has definition of ppm_process. In version 1.0 process_ppm() is not implemented.
 *                 After version 1.0, process_ppm() must be implemented.
 * ****************************************************************************************************************/

//DO NOT MODIFY PROVIDED PARTS! IF THESE PARTS ARE MODIFIED, YOU WILL GET LOW GRADE!
//WITHOUT MARKED PART! DO NOT MODIFY ANY CODE!

//Do Not Include Any Other Header Without Below
#include "ppm.h"
#include <fstream>
#include <cmath>
#include <iostream>
using namespace std;

/***********************************************************************************************************
 * TIPS & REFERENCES for HW4
 *
 * (1) pbm, pgm, ppm file format description : refer to HW4 PDF file
 *
 * (2) RGB to GRAY Scale formula : 0.299 * R + 0.587 * G + 0.114 * B (Round To UINT8(unsigned char) value)
 *     Ex 1) R : 120, G : 60, B : 35 -> Gray : 75.09 -> 75
 *     Ex 2) If Gray Value is 60.9 -> 61
 *
 * (3) W/B Bitmap Value : if gray > max_val/2 -> 0, else 1
 *     Ex) R : 120, G : 60, B :35 -> Gray : 75 -> W/B 1
 *
 * (4) Color Inversion formula : max_val - R, max_val - G, max_val - B
 *     Ex) R : 120, G : 60, B : 35 -> R : 135, G : 195, B : 220
 *
 * (5) All output files must be loaded in ppm image viewer.
 *     Viewer Site URL : https://www.kylepaulsen.com/stuff/NetpbmViewer/
 *
 * ********************************************************************************************************/

PROCESS_RESULT process_ppm(char *in_file_name, char *out_pbm_name, char *out_pgm_name, char *out_ppm_name) {

    //WRITE YOUR CODE Between /*****************************/ lines.
    /**************************************************************************************************/

    ifstream inStream;
    ofstream outStream1;
    ofstream outStream2;
    ofstream outStream3;

    inStream.open( in_file_name );
    if(inStream.fail( ))
        return INPUT_ERROR;

    char pv1 = 'J', pv2 = 'U';
    inStream >> pv1 >> pv2;
    if(pv1 != 'P' || pv2 != '3')
        return INPUT_ERROR;

    int size[2] = {0,};
    double maxsize = 0;
    inStream >> size[0] >> size[1] >> maxsize;

    
    outStream1.open( out_pbm_name );
    outStream2.open( out_pgm_name );
    outStream3.open( out_ppm_name );

    if(outStream1.fail( ))
        return OUTPUT_ERROR;
    if(outStream2.fail( ))
        return OUTPUT_ERROR;
    if(outStream3.fail( ))
        return OUTPUT_ERROR;

    outStream1 << "P1" << endl;
    outStream2 << "P2" << endl;
    outStream3 << "P3" << endl;

    outStream1 << size[0] << ' ' << size[1] << endl;
    outStream2 << size[0] << ' ' << size[1] << endl;
    outStream3 << size[0] << ' ' << size[1] << endl;
    
    outStream2 << maxsize << endl;
    outStream3 << maxsize << endl;

    int cv[3], gray;
    int tc = -1999;
    int i, j, k;
    char pbmv;
    for(k = 0; k < size[1] ; k++) {
        for(j = 0; j < size[0]; j++) {
            for(i = 0; i < 3; i++)
                cv[i] = maxsize+1;
            for(i = 0; i < 3; i++)
                inStream >> cv[i];

            for(i = 0; i < 3; i++)
                if(cv[i] > maxsize) 
                    return INPUT_ERROR;

            gray = round(cv[0]*0.299 + cv[1]*0.587 + cv[2]*0.114);
            pbmv = '0';
            if(gray < maxsize/2) pbmv = '1';

            for(i=0; i < 3; i++) cv[i] = maxsize - cv[i];

            if(j != size[0]-1) {
                outStream1 << pbmv << ' ';
                outStream2 << gray << ' ';
                outStream3 << cv[0] << ' ' << cv[1] << ' ' << cv [2] << ' ';
            }
            else if(j == size[0]-1 && k == size[1] -1) {
                outStream1 << pbmv;
                outStream2 << gray;
                outStream3 << cv[0] << ' ' << cv[1] << ' ' << cv [2];
            }
            else {
                outStream1 << pbmv << endl;
                outStream2 << gray << endl;
                outStream3 << cv[0] << ' ' << cv[1] << ' ' << cv [2] << endl;
            }
        }
    }
    
    inStream >> tc;
    if(tc != -1999) return INPUT_ERROR;

    inStream.close( );
    outStream1.close( );
    outStream2.close( );
    outStream3.close( );

    return SUCCESS;
    /**************************************************************************************************/
}


