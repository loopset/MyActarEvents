#ifndef MEVENT_H
#define MEVENT_H

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <TObject.h>
#include <TString.h>
#include <TH2F.h>
#include <TGraph.h>
#include <TF1.h>


#include "MCoboAsad.h"
#include "MEventReduced.h"
#include "Parameters.h"
#include "DataParameters.h"

//#include <reduction/TrapezoidAnalyser.h>

using namespace std;
//using namespace reduction;


class MEvent
{
public:
    int run_number;
	unsigned long int EN;
	unsigned long int TS;
	std::vector<MCoboAsad> CoboAsad;
	
	bool hasConfigFile;
	float CalibCoefs[NB_COBO][NB_ASAD][NB_AGET][NB_CHANNEL][2];
	bool hasCalBaseline;
	float BaselineCal[NB_COBO][NB_ASAD][NB_AGET][NB_CHANNEL][NB_SAMPLES];
    bool hasSpecificTreatment;
    char* SpecificTreatmentFile;
    int SpecificTreatment[NB_COBO][NB_ASAD][NB_AGET][NB_CHANNEL];
  
	unsigned long stat_good_frame;
	unsigned long stat_recovered_frame;
	unsigned long stat_bad_frame;
	
	MEvent();
	~MEvent();
	void GetAndFillCalibCoeffs();
	void InitVXIParameters(char*,std::vector<TString>,std::vector<int>, int offset = 0);
	int TreatBaseline(bool,bool);
   
	
	MEventReduced ReducedEvent;
	unsigned long labelVXI[16384];
  
  
	
	protected:
	DataParameters parametersVXI;
// 	short labelVXI[16384];
	
	TF1* ffitSig;
	TGraph* Gsig;
	float Charge[NB_SAMPLES];

};

//double SignalFitFunction(double*, double*);


#endif
