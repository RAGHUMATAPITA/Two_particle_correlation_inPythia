#include "call_libraries.h"  // call libraries from ROOT and C++

// events quantities 
int nTrack;

// Track quantities
const int nmax = 99999;
int pid[nmax];
float pt[nmax];
float eta[nmax];
float rap[nmax];
float phi[nmax];
int mom_pid[nmax];

void read_tree(TChain *tree)
{
  tree->SetBranchStatus("*", 0); // disable all branches - this is important while reading big files
  
  // enable branches of interest -> see definition of each variables above

  // event quantities

  tree->SetBranchStatus("nTrack", 1);
  tree->SetBranchAddress("nTrack", &nTrack);
  
  // track quantities
  
  tree->SetBranchStatus("pid", 1);
  tree->SetBranchAddress("pid", &pid);
  
  tree->SetBranchStatus("pt", 1); 
  tree->SetBranchAddress("pt", &pt);

  tree->SetBranchStatus("eta", 1); 
  tree->SetBranchAddress("eta", &eta);

  tree->SetBranchStatus("rap", 1); 
  tree->SetBranchAddress("rap", &rap);

  tree->SetBranchStatus("phi", 1); 
  tree->SetBranchAddress("phi", &phi);

  tree->SetBranchStatus("motherID", 1); 
  tree->SetBranchAddress("motherID", &mom_pid);
}
