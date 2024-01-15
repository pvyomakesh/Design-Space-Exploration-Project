#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <algorithm>
#include <fstream>
#include <map>
#include <math.h>
#include <fcntl.h>

#include "431project.h"

unsigned int getdl1size(std::string configuration);

unsigned int getil1size(std::string configuration);

unsigned int getl2size(std::string configuration);

/*
 * Returns 1 if valid, else 0
 */
int validateConfiguration(std::string configuration){
  int configurationDimsAsInts[18];
  int returnValue=1; // assume true, set to zero otherwise
  if(isan18dimconfiguration(configuration)){ // necessary, but insufficient
    extractConfiguration(configuration, configurationDimsAsInts); // Configuration parameters now available in array
    // FIXME - YOUR CODE HERE
    unsigned int IL1cachesize = getil1size(configuration);
    unsigned int UL2cachesize = getl2size(configuration);
    unsigned int DL1cachesize = getdl1size(configuration);
    //UL2 blocksize
    if(16*(1<<configurationDimsAsInts[11]) < 16*(1<<configurationDimsAsInts[0]) || configurationDimsAsInts[11] > 3){returnValue=0;}
    //UL2 cachesize
    if(UL2cachesize < IL1cachesize + DL1cachesize){returnValue=0;} 
    //Maximum and minimum cahce size
    
    if(IL1cachesize < 8192 || DL1cachesize < 8192){
      returnValue=0;
    }
    if(IL1cachesize > 65536 || DL1cachesize > 65536){
      returnValue=0;
    }
    //IL1 latency
    if(configurationDimsAsInts[9] == 0){
      if(IL1cachesize == 8192 && configurationDimsAsInts[15] != 0){returnValue=0;}
      if(IL1cachesize == 16384 && configurationDimsAsInts[15] != 1){returnValue=0;}
      if(IL1cachesize == 32768 && configurationDimsAsInts[15] != 2){returnValue=0;}
      if(IL1cachesize == 65536 && configurationDimsAsInts[15] != 3){returnValue=0;}
    }
    if(configurationDimsAsInts[9] == 1){
      if(IL1cachesize == 8192 && configurationDimsAsInts[15] != 1){returnValue=0;}
      if(IL1cachesize == 16384 && configurationDimsAsInts[15] != 2){returnValue=0;}
      if(IL1cachesize == 32768 && configurationDimsAsInts[15] != 3){returnValue=0;}
      if(IL1cachesize == 65536 && configurationDimsAsInts[15] != 4){returnValue=0;}
    }
    if(configurationDimsAsInts[9] == 2){
      if(IL1cachesize == 8192 && configurationDimsAsInts[15] != 2){returnValue=0;}
      if(IL1cachesize == 16384 && configurationDimsAsInts[15] != 3){returnValue=0;}
      if(IL1cachesize == 32768 && configurationDimsAsInts[15] != 4){returnValue=0;}
      if(IL1cachesize == 65536 && configurationDimsAsInts[15] != 5){returnValue=0;}
    }
    //DL1 latency
    if(configurationDimsAsInts[7] == 0){
      if(DL1cachesize == 8192 && configurationDimsAsInts[14] != 0){returnValue=0;}
      if(DL1cachesize == 16384 && configurationDimsAsInts[14] != 1){returnValue=0;}
      if(DL1cachesize == 32768 && configurationDimsAsInts[14] != 2){returnValue=0;}
      if(DL1cachesize == 65536 && configurationDimsAsInts[14] != 3){returnValue=0;}
    }
    if(configurationDimsAsInts[7] == 1){
      if(DL1cachesize == 8192 && configurationDimsAsInts[14] != 1){returnValue=0;}
      if(DL1cachesize == 16384 && configurationDimsAsInts[14] != 2){returnValue=0;}
      if(DL1cachesize == 32768 && configurationDimsAsInts[14] != 3){returnValue=0;}
      if(DL1cachesize == 65536 && configurationDimsAsInts[14] != 4){returnValue=0;}
    }
    if(configurationDimsAsInts[7] == 2){
      if(DL1cachesize == 8192 && configurationDimsAsInts[14] != 2){returnValue=0;}
      if(DL1cachesize == 16384 && configurationDimsAsInts[14] != 3){returnValue=0;}
      if(DL1cachesize == 32768 && configurationDimsAsInts[14] != 4){returnValue=0;}
      if(DL1cachesize == 65536 && configurationDimsAsInts[14] != 5){returnValue=0;}
    }
    //Maximum ways
    if(configurationDimsAsInts[7] > 2 || configurationDimsAsInts[9] > 2){returnValue=0;}
    //UL2 size
    if(UL2cachesize < 131072 || UL2cachesize > 2097152){
      returnValue=0;
    }
    //UL2 latency
    if(configurationDimsAsInts[12] == 0){
      if(UL2cachesize == 131072 && configurationDimsAsInts[16] != 0){returnValue=0;}
      if(UL2cachesize == 262144 && configurationDimsAsInts[16] != 1){returnValue=0;}
      if(UL2cachesize == 524288 && configurationDimsAsInts[16] != 2){returnValue=0;}
      if(UL2cachesize == 1048576 && configurationDimsAsInts[16] != 3){returnValue=0;}
      if(UL2cachesize == 2097152 && configurationDimsAsInts[16] != 4){returnValue=0;}
    }
    if(configurationDimsAsInts[12] == 1){
      if(UL2cachesize == 131072 && configurationDimsAsInts[16] != 1){returnValue=0;}
      if(UL2cachesize == 262144 && configurationDimsAsInts[16] != 2){returnValue=0;}
      if(UL2cachesize == 524288 && configurationDimsAsInts[16] != 3){returnValue=0;}
      if(UL2cachesize == 1048576 && configurationDimsAsInts[16] != 4){returnValue=0;}
      if(UL2cachesize == 2097152 && configurationDimsAsInts[16] != 5){returnValue=0;}
    }
    if(configurationDimsAsInts[12] == 2){
      if(UL2cachesize == 131072 && configurationDimsAsInts[16] != 2){returnValue=0;}
      if(UL2cachesize == 262144 && configurationDimsAsInts[16] != 3){returnValue=0;}
      if(UL2cachesize == 524288 && configurationDimsAsInts[16] != 4){returnValue=0;}
      if(UL2cachesize == 1048576 && configurationDimsAsInts[16] != 5){returnValue=0;}
      if(UL2cachesize == 2097152 && configurationDimsAsInts[16] != 6){returnValue=0;}
    }
    if(configurationDimsAsInts[12] == 3){
      if(UL2cachesize == 131072 && configurationDimsAsInts[16] != 3){returnValue=0;}
      if(UL2cachesize == 262144 && configurationDimsAsInts[16] != 4){returnValue=0;}
      if(UL2cachesize == 524288 && configurationDimsAsInts[16] != 5){returnValue=0;}
      if(UL2cachesize == 1048576 && configurationDimsAsInts[16] != 6){returnValue=0;}
      if(UL2cachesize == 2097152 && configurationDimsAsInts[16] != 7){returnValue=0;}
    }
    if(configurationDimsAsInts[12] == 4){
      if(UL2cachesize == 131072 && configurationDimsAsInts[16] != 4){returnValue=0;}
      if(UL2cachesize == 262144 && configurationDimsAsInts[16] != 5){returnValue=0;}
      if(UL2cachesize == 524288 && configurationDimsAsInts[16] != 6){returnValue=0;}
      if(UL2cachesize == 1048576 && configurationDimsAsInts[16] != 7){returnValue=0;}
      if(UL2cachesize == 2097152 && configurationDimsAsInts[16] != 8){returnValue=0;}
    }
    if(configurationDimsAsInts[12] > 4){returnValue=0;}
    //Misc

  } else {
    returnValue=0;
  }
  return returnValue;
}




/*
 * Given the current best known configuration, the current configuration, and the globally visible map of all previously investigated configurations, suggest a previously unexplored design point. You will only be allowed to investigate 1000 design points in a particular run, so choose wisely.
 */
std::string YourProposalFunction(std::string currentconfiguration, std::string bestEXECconfiguration, std::string bestEDPconfiguration, int optimizeforEXEC, int optimizeforEDP){
  std::string nextconfiguration=GLOB_baseline;

  std::stringstream ss;
  
  int configurationdim[18];
  extractConfiguration(nextconfiguration, configurationdim);
  if(optimizeforEXEC){
    for(int dim = 0; dim<17; ++dim){
      configurationdim[dim] = rand()%GLOB_dimensioncardinality[dim];
    }
    configurationdim[0] = (rand()%(GLOB_dimensioncardinality[0]-2)) + 2;
    configurationdim[1] = 1;
    configurationdim[2] = 1;
    configurationdim[3] = (rand()%(GLOB_dimensioncardinality[3]-2)) + 2;
    configurationdim[4] = (rand()%(GLOB_dimensioncardinality[4]-2)) + 2;
    configurationdim[5] = 1;
    configurationdim[6] = (rand()%(GLOB_dimensioncardinality[6]-1)) + 1;
    configurationdim[7] = (rand()%(GLOB_dimensioncardinality[7]-1)) + 1;
    configurationdim[8] = (rand()%(GLOB_dimensioncardinality[8]-1)) + 1;
    configurationdim[9] = (rand()%(GLOB_dimensioncardinality[9]-1)) + 1;
    configurationdim[10] = (rand()%(GLOB_dimensioncardinality[10] - 2)) + 2;
    configurationdim[11] = (rand()%(GLOB_dimensioncardinality[11]-2)) + 2;
    configurationdim[12] = (rand()%(GLOB_dimensioncardinality[11]-1)) + 1;
    configurationdim[17] = (rand()%(GLOB_dimensioncardinality[17]-2)) + 2;        
  }
  if(optimizeforEDP){
    for(int dim = 0; dim<17; ++dim){
      configurationdim[dim] = rand()%GLOB_dimensioncardinality[dim];
    }
    configurationdim[0] = rand()%(GLOB_dimensioncardinality[0]-2) + 1;
    configurationdim[2] = 1;
    configurationdim[3] = rand()%(GLOB_dimensioncardinality[3]-3) + 1;
    configurationdim[6] = rand()%(GLOB_dimensioncardinality[6]-1);
    configurationdim[7] = (rand()%(GLOB_dimensioncardinality[7]-1)) + 1;
    configurationdim[8] = rand()%(GLOB_dimensioncardinality[8]-1);
    configurationdim[9] = (rand()%(GLOB_dimensioncardinality[9]-1)) + 1;
    configurationdim[10] = 2 + rand()%(GLOB_dimensioncardinality[10] - 4);
    configurationdim[11] = (rand()%(GLOB_dimensioncardinality[11]-1)) + 1;
    configurationdim[12] = rand()%(GLOB_dimensioncardinality[12]-1) + 1;
    configurationdim[17] = (rand()%(GLOB_dimensioncardinality[17]-2)) + 2;
  }
  for(int i = 0; i < 18; ++i){
    ss << configurationdim[i];
    if(i < 17) ss << " ";
  }

  nextconfiguration=ss.str();
  ss.str("");    
  return nextconfiguration;
}

