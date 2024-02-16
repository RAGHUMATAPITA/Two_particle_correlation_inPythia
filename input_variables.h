#include "call_libraries.h"

// track cut
float pt_min = 0.3;
float pt_max = 4.0;

float eta_min = -2.4;
float eta_max = 2.4;

//number of event to mix
int bkgFactor = 10;

// track vector for signal
std::vector<TVector3> trk_vec;
std::vector<int> pid_vec;

// vector for mixing
std::vector<int> evtcount_vec;
std::vector<std::vector<TVector3>> trk_mix_vec;
std::vector<std::vector<int>> pid_mix_vec;
