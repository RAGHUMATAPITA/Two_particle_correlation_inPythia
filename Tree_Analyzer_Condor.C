//#include "call_libraries.h"
#include "read_tree.h"
//#include "input_variables.h"
//#include "histogram_definition.h"
#include "function_defination.h" // call_libraries.h, input_variables.h and histogram_definition.h are called within function_defination.h

void Tree_Analyzer_Condor(TString input_file, int itxtoutFile, TString out_directory, TString name_of_roorFile)
{
  clock_t sec_start, sec_end;
  sec_start = clock();

  TDatime* date = new TDatime();

  print_start(); // start timing print

  fstream openInputFile;
  openInputFile.open(Form("%s",input_file.Data()), ios::in);
  if(!openInputFile.is_open())
    {
      cout << "List of input files not founded!" << endl;
      return;
    }
  
  std::vector<TString> file_name_vector;
  string file_chain;
  
  while(getline(openInputFile, file_chain))
    {
      file_name_vector.push_back(file_chain);
    }
  
  openInputFile.close();
  
  TChain *tree = new TChain("tr");
  
  for (std::vector<TString>::iterator listIterator = file_name_vector.begin(); listIterator != file_name_vector.end(); listIterator++)
    {
      TFile *testfile = TFile::Open(*listIterator);
      
      if(!testfile || testfile->IsZombie() || testfile->TestBit(TFile::kRecovered))
	{
	  cout << "File: " << *listIterator << " failed to open" << endl;
	  continue;
	}
      
      cout << "Adding file:--- " << *listIterator << "--- to the chains" << endl;
      
      tree->Add(*listIterator);
    }
  
  read_tree(tree);
  
  int nevents = tree->GetEntries(); // number of events
  
  cout<<endl;
  cout << "Total number of events in those files: "<< nevents << endl;
  cout<<endl;
      
  // resize the vector used for mixing                                                                                                         
  evtcount_vec.resize(0);
  trk_mix_vec.resize(0);
  pid_mix_vec.resize(0);
  
  int idx = 0; // counter of events
  
  for(int iev = 0; iev < nevents; iev++) //event loop start
    //for(int iev = 0; iev < 100; iev++) //event loop start
    {
      tree->GetEntry(iev);

      if(nTrack <= 0) continue;

      hntrk->Fill(nTrack);
      
      if(iev%10000 == 0) std::cout<<iev<<"  events running of total events "<< nevents <<std::endl;
      
      // resize all the vectors used to store jet quantity
      trk_vec.resize(0);
      pid_vec.resize(0);

      for (int itrk = 0; itrk < nTrack; itrk++) // track loop start
	{
	  int trk_pid = pid[itrk];
	  float trk_pt = pt[itrk];
	  float trk_eta = eta[itrk];
	  float trk_rap = rap[itrk];
	  float trk_phi = phi[itrk];
	  int trk_mom_pid = mom_pid[itrk];
	  
	  if(TMath::Abs(trk_pid) != 211 && TMath::Abs(trk_pid) != 321 && TMath::Abs(trk_pid) != 310 && TMath::Abs(trk_pid) != 2212 && TMath::Abs(trk_pid) != 3122) continue;
	  
	  // fill track histo
	  if(TMath::Abs(trk_pid) == 211)
	    {
	      if((trk_pt > pt_min && trk_pt < pt_max ) && (trk_eta > eta_min && trk_eta < eta_max ))
		{
		  hpt_1->Fill(trk_pt);
		  heta_1->Fill(trk_eta);
		  hrap_1->Fill(trk_rap);
		  hphi_1->Fill(trk_phi);
		}
	    }
	  else if(TMath::Abs(trk_pid) == 321)
	    {
	      if((trk_pt > pt_min && trk_pt < pt_max ) && (trk_eta > eta_min && trk_eta < eta_max ))
		{
		  hpt_2->Fill(trk_pt);
		  heta_2->Fill(trk_eta);
		  hrap_2->Fill(trk_rap);
		  hphi_2->Fill(trk_phi);
		}
	    }
	  else if(TMath::Abs(trk_pid) == 310)
	    {
	      if((trk_pt > pt_min && trk_pt < pt_max ) && (trk_eta > eta_min && trk_eta < eta_max ))
		{
		  hpt_3->Fill(trk_pt);
		  heta_3->Fill(trk_eta);
		  hrap_3->Fill(trk_rap);
		  hphi_3->Fill(trk_phi);
		}
	    }
	  else if(TMath::Abs(trk_pid) == 2212)
	    {
	      if((trk_pt > pt_min && trk_pt < pt_max ) && (trk_eta > eta_min && trk_eta < eta_max ))
		{
		  hpt_4->Fill(trk_pt);
		  heta_4->Fill(trk_eta);
		  hrap_4->Fill(trk_rap);
		  hphi_4->Fill(trk_phi);
		}
	    }
	  else if(TMath::Abs(trk_pid) == 3122)
	    {
	      if((trk_pt > pt_min && trk_pt < pt_max ) && (trk_eta > eta_min && trk_eta < eta_max ))
		{
		  hpt_5->Fill(trk_pt);
		  heta_5->Fill(trk_eta);
		  hrap_5->Fill(trk_rap);
		  hphi_5->Fill(trk_phi);
		}
	    }
	  
	  // stored the information in the vector
	  
	  TVector3 saved_trk;
	  saved_trk.SetPtEtaPhi(trk_pt, trk_eta, trk_phi);
	  trk_vec.push_back(saved_trk);
	  
	  pid_vec.push_back(trk_pid);
	  
	}// track loop end
      
      //calling function of signal correlation
      signal_corr(trk_vec, pid_vec, pt_min, pt_max, eta_min, eta_max);
      
      idx++;
      
      // fill the vector used for mixing
      evtcount_vec.push_back(idx);
      trk_mix_vec.push_back(trk_vec);
      pid_mix_vec.push_back(pid_vec);
      
      // clear all the vectors filled in event wise
      
      trk_vec.clear();
      pid_vec.clear();
      
    }// events loop end
  
  // function for the mixing events
  
  std::cout<<endl;
  std::cout<<"~~~~~~~~~~mixing loop start~~~~~~~~~~~~~~~~~~~~"<<std::endl;
  std::cout<<endl;
  
  //calling function of background correlation
  mixing_corr(evtcount_vec, trk_mix_vec, pid_mix_vec, pt_min, pt_max, eta_min, eta_max);
  
  std::cout<<endl;
  std::cout<<"~~~~~~~~~~mixing loop end~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
  std::cout<<endl;
  
  // clear the vector used for mixing                                                                                                

  evtcount_vec.clear();
  trk_mix_vec.clear();
  pid_mix_vec.clear();
  
  // delete the tree to clean memory
  delete tree;
  
  // output file name
  std::string outfilename = Form("%s/%s_Outfile_%d", out_directory.Data(), name_of_roorFile.Data(), itxtoutFile);
  std::replace(outfilename.begin(), outfilename.end(), '.', 'p'); // replace . to p
  std::replace(outfilename.begin(), outfilename.end(), '-', 'N'); // replace - to N for negative
  
  TFile* fout = new TFile(Form("%s.root", outfilename.c_str()), "recreate");
  
  fout->mkdir("Event_Hist");
  fout->cd("Event_Hist");
  write_event_hist();
  
  fout->mkdir("Track_Hist");
  fout->cd("Track_Hist");
  write_track_hist();
  
  fout->mkdir("Corr_Hist");
  fout->cd("Corr_Hist");
  write_corr_hist();
  
  std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~Finished, DONE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
  std::cout<<std::endl;
  
  sec_end = clock(); // stop time counting                                                                                       
  cout << "========================================" << endl;
  cout << "Total running time: " << (double)(sec_end - sec_start) / CLOCKS_PER_SEC << " [s]" << endl;
  cout << "========================================" << endl;
  
  print_stop(); // Print time, date and hour when it stops
}

int main(int argc, char **argv)
{
  using namespace std;

  TString inputfile;
  int itxtout;
  TString outfile;
  TString outfile_name;
  if(argc == 5)
    {
      std::cout<<std::endl;
      std::cout<<"You have given "<< argc <<" arguments including the program name;  Your program will run"<<std::endl;
      std::cout<<std::endl;
      inputfile = argv[1];
      itxtout = atoi(argv[2]);
      outfile = argv[3];
      outfile_name  = argv[4];

      Tree_Analyzer_Condor(inputfile, itxtout, outfile, outfile_name);
    }
  return 0;
}
