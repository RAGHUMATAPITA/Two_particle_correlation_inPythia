#include "call_libraries.h"

// event histo

TH1D* hntrk = new TH1D("hntrk", "", 500, 0, 500);

// track histo

// charged pion
TH1D* hpt_1 = new TH1D("hpt_1", "", 300, 0., 3.);
TH1D* heta_1 = new TH1D("heta_1", "", 96, -2.4, 2.4);
TH1D* hrap_1 = new TH1D("hrap_1", "", 100, -2.5, 2.5);
TH1D* hphi_1 = new TH1D("hphi_1", "", 64, -TMath::Pi(), TMath::Pi());
// charged  kaon
TH1D* hpt_2 = new TH1D("hpt_2", "", 300, 0., 3.);
TH1D* heta_2 = new TH1D("heta_2", "", 96, -2.4, 2.4);
TH1D* hrap_2 = new TH1D("hrap_2", "", 100, -2.5, 2.5);
TH1D* hphi_2 = new TH1D("hphi_2", "", 64, -TMath::Pi(), TMath::Pi());
// neutral  kaon
TH1D* hpt_3 = new TH1D("hpt_3", "", 300, 0., 3.);
TH1D* heta_3 = new TH1D("heta_3", "", 96, -2.4, 2.4);
TH1D* hrap_3 = new TH1D("hrap_3", "", 100, -2.5, 2.5);
TH1D* hphi_3 = new TH1D("hphi_3", "", 64, -TMath::Pi(), TMath::Pi());
// proton
TH1D* hpt_4 = new TH1D("hpt_4", "", 300, 0., 3.);
TH1D* heta_4 = new TH1D("heta_4", "", 96, -2.4, 2.4);
TH1D* hrap_4 = new TH1D("hrap_4", "", 100, -2.5, 2.5);
TH1D* hphi_4 = new TH1D("hphi_4", "", 64, -TMath::Pi(), TMath::Pi());
// lambda
TH1D* hpt_5 = new TH1D("hpt_5", "", 300, 0., 3.);
TH1D* heta_5 = new TH1D("heta_5", "", 96, -2.4, 2.4);
TH1D* hrap_5 = new TH1D("hrap_5", "", 100, -2.5, 2.5);
TH1D* hphi_5 = new TH1D("hphi_5", "", 64, -TMath::Pi(), TMath::Pi());

// signal histo
TH1D* hsig_ntrk = new TH1D("hsig_ntrk", "", 20, 0., 20.);
//charged pion
TH2D* hsignal_pp_1 = new TH2D("hsignal_pp_1", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_mm_1 = new TH2D("hsignal_mm_1", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_pm_1 = new TH2D("hsignal_pm_1", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_mp_1 = new TH2D("hsignal_mp_1", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
//charged kaon
TH2D* hsignal_pp_2 = new TH2D("hsignal_pp_2", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_mm_2 = new TH2D("hsignal_mm_2", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_pm_2 = new TH2D("hsignal_pm_2", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_mp_2 = new TH2D("hsignal_mp_2", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
//neutral kaon
TH2D* hsignal_pp_3 = new TH2D("hsignal_pp_3", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_mm_3 = new TH2D("hsignal_mm_3", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_pm_3 = new TH2D("hsignal_pm_3", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_mp_3 = new TH2D("hsignal_mp_3", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
//proton
TH2D* hsignal_pp_4 = new TH2D("hsignal_pp_4", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_mm_4 = new TH2D("hsignal_mm_4", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_pm_4 = new TH2D("hsignal_pm_4", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_mp_4 = new TH2D("hsignal_mp_4", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
//lambda
TH2D* hsignal_pp_5 = new TH2D("hsignal_pp_5", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_mm_5 = new TH2D("hsignal_mm_5", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_pm_5 = new TH2D("hsignal_pm_5", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_mp_5 = new TH2D("hsignal_mp_5", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
//lambda-proton
TH2D* hsignal_pp_6 = new TH2D("hsignal_pp_6", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_mm_6 = new TH2D("hsignal_mm_6", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_pm_6 = new TH2D("hsignal_pm_6", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_mp_6 = new TH2D("hsignal_mp_6", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

// mixing histo
//charged pion
TH2D* hmixing_pp_1 = new TH2D("hmixing_pp_1", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_mm_1 = new TH2D("hmixing_mm_1", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_pm_1 = new TH2D("hmixing_pm_1", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_mp_1 = new TH2D("hmixing_mp_1", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
//charged kaon
TH2D* hmixing_pp_2 = new TH2D("hmixing_pp_2", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_mm_2 = new TH2D("hmixing_mm_2", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_pm_2 = new TH2D("hmixing_pm_2", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_mp_2 = new TH2D("hmixing_mp_2", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
//neutral kaon
TH2D* hmixing_pp_3 = new TH2D("hmixing_pp_3", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_mm_3 = new TH2D("hmixing_mm_3", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_pm_3 = new TH2D("hmixing_pm_3", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_mp_3 = new TH2D("hmixing_mp_3", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
//proton
TH2D* hmixing_pp_4 = new TH2D("hmixing_pp_4", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_mm_4 = new TH2D("hmixing_mm_4", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_pm_4 = new TH2D("hmixing_pm_4", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_mp_4 = new TH2D("hmixing_mp_4", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
//lambda
TH2D* hmixing_pp_5 = new TH2D("hmixing_pp_5", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_mm_5 = new TH2D("hmixing_mm_5", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_pm_5 = new TH2D("hmixing_pm_5", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_mp_5 = new TH2D("hmixing_mp_5", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
//lambda-proton
TH2D* hmixing_pp_6 = new TH2D("hmixing_pp_6", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_mm_6 = new TH2D("hmixing_mm_6", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_pm_6 = new TH2D("hmixing_pm_6", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_mp_6 = new TH2D("hmixing_mp_6", "", 31, -4.8, 4.8, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

void sumw2()
{
  // event histo
  hntrk->Sumw2();

  // track histo 
  hpt_1->Sumw2();
  heta_1->Sumw2();
  hrap_1->Sumw2();
  hphi_1->Sumw2();

  hpt_2->Sumw2();
  heta_2->Sumw2();
  hrap_2->Sumw2();
  hphi_2->Sumw2();

  hpt_3->Sumw2();
  heta_3->Sumw2();
  hrap_3->Sumw2();
  hphi_3->Sumw2();

  hpt_4->Sumw2();
  heta_4->Sumw2();
  hrap_4->Sumw2();
  hphi_4->Sumw2();

  hpt_5->Sumw2();
  heta_5->Sumw2();
  hrap_5->Sumw2();
  hphi_5->Sumw2();
  
  // signal histo
  hsig_ntrk->Sumw2();
  hsignal_pp_1->Sumw2();
  hsignal_mm_1->Sumw2();
  hsignal_pm_1->Sumw2();
  hsignal_mp_1->Sumw2();

  hsignal_pp_2->Sumw2();
  hsignal_mm_2->Sumw2();
  hsignal_pm_2->Sumw2();
  hsignal_mp_2->Sumw2();

  hsignal_pp_3->Sumw2();
  hsignal_mm_3->Sumw2();
  hsignal_pm_3->Sumw2();
  hsignal_mp_3->Sumw2();
  
  hsignal_pp_4->Sumw2();
  hsignal_mm_4->Sumw2();
  hsignal_pm_4->Sumw2();
  hsignal_mp_4->Sumw2();
  
  hsignal_pp_5->Sumw2();
  hsignal_mm_5->Sumw2();
  hsignal_pm_5->Sumw2();
  hsignal_mp_5->Sumw2();

  hsignal_pp_6->Sumw2();
  hsignal_mm_6->Sumw2();
  hsignal_pm_6->Sumw2();
  hsignal_mp_6->Sumw2();
  
  // mixing histo
  hmixing_pp_1->Sumw2();
  hmixing_mm_1->Sumw2();
  hmixing_pm_1->Sumw2();
  hmixing_mm_1->Sumw2();

  hmixing_pp_2->Sumw2();
  hmixing_mm_2->Sumw2();
  hmixing_pm_2->Sumw2();
  hmixing_mp_2->Sumw2();

  hmixing_pp_3->Sumw2();
  hmixing_mm_3->Sumw2();
  hmixing_pm_3->Sumw2();
  hmixing_mp_3->Sumw2();
  
  hmixing_pp_4->Sumw2();
  hmixing_mm_4->Sumw2();
  hmixing_pm_4->Sumw2();
  hmixing_mp_4->Sumw2();
  
  hmixing_pp_5->Sumw2();
  hmixing_mm_5->Sumw2();
  hmixing_pm_5->Sumw2();
  hmixing_mp_5->Sumw2();

  hmixing_pp_6->Sumw2();
  hmixing_mm_6->Sumw2();
  hmixing_pm_6->Sumw2();
  hmixing_mp_6->Sumw2();
}

void write_event_hist()
{
  hntrk->Write();
}

void write_track_hist()
{
  hpt_1->Write();
  heta_1->Write();
  hrap_1->Write();
  hphi_1->Write();

  hpt_2->Write();
  heta_2->Write();
  hrap_2->Write();
  hphi_2->Write();

  hpt_3->Write();
  heta_3->Write();
  hrap_3->Write();
  hphi_3->Write();

  hpt_4->Write();
  heta_4->Write();
  hrap_4->Write();
  hphi_4->Write();

  hpt_5->Write();
  heta_5->Write();
  hrap_5->Write();
  hphi_5->Write();
}

void write_corr_hist()
{
  hsig_ntrk->Write();

  // signal histo
  hsignal_pp_1->Write();
  hsignal_mm_1->Write();
  hsignal_pm_1->Write();
  hsignal_mp_1->Write();

  hsignal_pp_2->Write();
  hsignal_mm_2->Write();
  hsignal_pm_2->Write();
  hsignal_mp_2->Write();

  hsignal_pp_3->Write();
  hsignal_mm_3->Write();
  hsignal_pm_3->Write();
  hsignal_mp_3->Write();
  
  hsignal_pp_4->Write();
  hsignal_mm_4->Write();
  hsignal_pm_4->Write();
  hsignal_mp_4->Write();
  
  hsignal_pp_5->Write();
  hsignal_mm_5->Write();
  hsignal_pm_5->Write();
  hsignal_mp_5->Write();

  hsignal_pp_6->Write();
  hsignal_mm_6->Write();
  hsignal_pm_6->Write();
  hsignal_mp_6->Write();

  // mixing histo
  hmixing_pp_1->Write();
  hmixing_mm_1->Write();
  hmixing_pm_1->Write();
  hmixing_mp_1->Write();

  hmixing_pp_2->Write();
  hmixing_mm_2->Write();
  hmixing_pm_2->Write();
  hmixing_mp_2->Write();

  hmixing_pp_3->Write();
  hmixing_mm_3->Write();
  hmixing_pm_3->Write();
  hmixing_mp_3->Write();
  
  hmixing_pp_4->Write();
  hmixing_mm_4->Write();
  hmixing_pm_4->Write();
  hmixing_mp_4->Write();
  
  hmixing_pp_5->Write();
  hmixing_mm_5->Write();
  hmixing_pm_5->Write();
  hmixing_mp_5->Write();

  hmixing_pp_6->Write();
  hmixing_mm_6->Write();
  hmixing_pm_6->Write();
  hmixing_mp_6->Write();
}
