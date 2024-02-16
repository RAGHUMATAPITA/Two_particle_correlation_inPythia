#include "input_variables.h"
#include "histogram_definition.h"

double massFromPID(int pid)
{
  double mass = -999.;
  if(TMath::Abs(pid) == 211) mass = 0.139570;
  else if(TMath::Abs(pid) == 321) mass = 0.493677;
  else if(TMath::Abs(pid) == 310) mass = 0.497614;
  else if(TMath::Abs(pid) == 2212) mass = 0.938272;
  else if(TMath::Abs(pid) == 3122) mass = 1.115683;
  else mass = -999.;
  return mass;
}

void signal_corr(std::vector<TVector3> sig_vec, std::vector<int> id_vec, double ptmin, double ptmax, double etamin, double etamax)
{
  for(int i1 = 0; i1 < (int)sig_vec.size(); i1++)
    {
      TVector3 vec1 = sig_vec[i1];
      double pt1 = vec1.Pt();
      double eta1 = vec1.Eta();
      double phi1 = vec1.Phi();
      int pid1 = id_vec[i1];

      //if(TMath::Abs(pid1) != pid) continue;
      
      if(TMath::Abs(pid1) == 211)
	{
	  if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax))
	    {
	      if(pid1 > 0)
                {
		  hsig_ntrk->AddBinContent(1,1);
		}
	      else if(pid1 < 0)
		{
		  hsig_ntrk->AddBinContent(1+10,1);
		}
	    }
	}
      else if (TMath::Abs(pid1) == 321)
	{
	  if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax))
            {
              if(pid1 > 0)
                {
                  hsig_ntrk->AddBinContent(2,1);
                }
              else if(pid1 < 0)
		{
                  hsig_ntrk->AddBinContent(2+10,1);
                }
            }
	}
      else if (TMath::Abs(pid1) == 310)
	{
	  if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax))
            {
              if(pid1 > 0)
                {
                  hsig_ntrk->AddBinContent(3,1);
                }
              else if(pid1 < 0)
		{
                  hsig_ntrk->AddBinContent(3+10,1);
		}
            }
        }
      else if (TMath::Abs(pid1) == 2212)
	{
	  if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax))
            {
              if(pid1 > 0)
                {
                  hsig_ntrk->AddBinContent(4,1);
                }
              else if(pid1 < 0)
		{
                  hsig_ntrk->AddBinContent(4+10,1);
                }
            }
        }
      else if (TMath::Abs(pid1) == 3122)
	{
	  if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax))
            {
              if(pid1 > 0)
                {
                  hsig_ntrk->AddBinContent(5,1);
                }
              else if(pid1 < 0)
		{
                  hsig_ntrk->AddBinContent(5+10,1);
                }
            }
        }
    
      for(int i2 = 0; i2 < (int)sig_vec.size(); i2++)
	{
	  if(i1 == i2) continue;
	  
	  TVector3 vec2 = sig_vec[i2];
	  double pt2 = vec2.Pt();
	  double eta2 = vec2.Eta();
	  double phi2 = vec2.Phi();
	  int pid2 = id_vec[i2];

	  //if(TMath::Abs(pid2) != pid) continue;
	  
	  //if(TMath::Abs(pid1) != TMath::Abs(pid2)) continue;
		  
	  double deta = eta1 - eta2;
	  double dphi = phi1 - phi2;
	  double dphi2 = phi2 - phi1;
	  
	  if(dphi > 1.5*TMath::Pi())
	    {
	      dphi = dphi - 2.0*TMath::Pi();
	    }
	  else if(dphi < -0.5*TMath::Pi())
	    {
	      dphi = dphi + 2.0*TMath::Pi();
	    }
	  
	  if(dphi2 > 1.5*TMath::Pi())
	    {
	      dphi2 = dphi2 - 2.0*TMath::Pi();
	    }
	  else if(dphi2 < -0.5*TMath::Pi())
	    {
	      dphi2 = dphi2 + 2.0*TMath::Pi();
	    }

	  //charged pion+-pion+, pion--pion-, pion+-pion-, pion--pion+
	  if(TMath::Abs(pid1) == 211 && TMath::Abs(pid2) == 211)
	    {
	      if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax) && (pt2 > ptmin && pt2 < ptmax) && (eta2 > etamin && eta2 < etamax))
		{
		  if(pid1 > 0 && pid2 > 0)
		    {
		      hsignal_pp_1->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_pp_1->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_pp_1->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_pp_1->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 > 0 && pid2 < 0)
		    {
		      hsignal_pm_1->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_pm_1->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_pm_1->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_pm_1->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 < 0 && pid2 > 0)
		    {
		      hsignal_mp_1->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_mp_1->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_mp_1->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_mp_1->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 < 0 && pid2 < 0)
		    {
		      hsignal_mm_1->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_mm_1->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_mm_1->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_mm_1->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		} 
	    }
	  
	  //charged kaon+-kaon+, kaon--kaon-, kaon+-kaon-, kaon--kaon+
	  if(TMath::Abs(pid1) == 321 && TMath::Abs(pid2) == 321)
	    {
	      if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax) && (pt2 > ptmin && pt2 < ptmax) && (eta2 > etamin && eta2 < etamax))
		{
		  if(pid1 > 0 && pid2 > 0)
		    {
		      hsignal_pp_2->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_pp_2->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_pp_2->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_pp_2->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 > 0 && pid2 < 0)
		    {
		      hsignal_pm_2->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_pm_2->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_pm_2->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_pm_2->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 < 0 && pid2 > 0)
		    {
		      hsignal_mp_2->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_mp_2->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_mp_2->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_mp_2->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 < 0 && pid2 < 0)
		    {
		      hsignal_mm_2->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_mm_2->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_mm_2->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_mm_2->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		}
	    }

	  //neutral kaon-kaon
	  if(TMath::Abs(pid1) == 310 && TMath::Abs(pid2) == 310)
	    {
	      if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax) && (pt2 > ptmin && pt2 < ptmax) && (eta2 > etamin && eta2 < etamax))
		{
		  if(pid1 > 0 && pid2 > 0)
		    {
		      hsignal_pp_3->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_pp_3->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_pp_3->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_pp_3->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 > 0 && pid2 < 0)
		    {
		      hsignal_pm_3->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_pm_3->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_pm_3->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_pm_3->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 < 0 && pid2 > 0)
		    {
		      hsignal_mp_3->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_mp_3->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_mp_3->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_mp_3->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 < 0 && pid2 < 0)
		    {
		      hsignal_mm_3->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_mm_3->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_mm_3->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_mm_3->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		}
	    }

	  //proton-proton, anitproton-antiproton, proton-antiproton, antiproton-proton
	  if(TMath::Abs(pid1) == 2212 && TMath::Abs(pid2) == 2212)
	    {
	      if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax) && (pt2 > ptmin && pt2 < ptmax) && (eta2 > etamin && eta2 < etamax))
		{
		  if(pid1 > 0 && pid2 > 0)
		    {
		      hsignal_pp_4->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_pp_4->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_pp_4->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_pp_4->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 > 0 && pid2 < 0)
		    {
		      hsignal_pm_4->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_pm_4->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_pm_4->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_pm_4->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 < 0 && pid2 > 0)
		    {
		      hsignal_mp_4->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_mp_4->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_mp_4->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_mp_4->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 < 0 && pid2 < 0)
		    {
		      hsignal_mm_4->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_mm_4->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_mm_4->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_mm_4->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		}
	    }

	  //lambda-lambda, antilambda-antilambda, lambda-antilambda, antilambda-lambda
	  if(TMath::Abs(pid1) == 3122 && TMath::Abs(pid2) == 3122)
	    {
	      if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax) && (pt2 > ptmin && pt2 < ptmax) && (eta2 > etamin && eta2 < etamax))
		{
		  if(pid1 > 0 && pid2 > 0)
		    {
		      hsignal_pp_5->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_pp_5->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_pp_5->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_pp_5->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 > 0 && pid2 < 0)
		    {
		      hsignal_pm_5->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_pm_5->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_pm_5->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_pm_5->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 < 0 && pid2 > 0)
		    {
		      hsignal_mp_5->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_mp_5->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_mp_5->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_mp_5->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 < 0 && pid2 < 0)
		    {
		      hsignal_mm_5->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_mm_5->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_mm_5->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_mm_5->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		}
	    }
	  //lambda-proton, antilambda-proton, lambda-antilproton, antilambda-antiproton
	  if((TMath::Abs(pid1) == 3122 && TMath::Abs(pid2) == 2212) || (TMath::Abs(pid1) == 2212 && TMath::Abs(pid2) == 3122))
	    {
	      if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax) && (pt2 > ptmin && pt2 < ptmax) && (eta2 > etamin && eta2 < etamax))
		{
		  if(pid1 > 0 && pid2 > 0)
		    {
		      hsignal_pp_6->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_pp_6->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_pp_6->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_pp_6->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 > 0 && pid2 < 0)
		    {
		      hsignal_pm_6->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_pm_6->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_pm_6->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_pm_6->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 < 0 && pid2 > 0)
		    {
		      hsignal_mp_6->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_mp_6->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_mp_6->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_mp_6->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		  if(pid1 < 0 && pid2 < 0)
		    {
		      hsignal_mm_6->Fill(fabs(deta), dphi, 1.0/4.0);
		      hsignal_mm_6->Fill(-fabs(deta), dphi, 1.0/4.0);
		      hsignal_mm_6->Fill(fabs(deta), dphi2, 1.0/4.0);
		      hsignal_mm_6->Fill(-fabs(deta), dphi2, 1.0/4.0);
		    }
		}
	    }
	} // second vector loop
    } // first vector loop
} // signal corr

void mixing_corr(std::vector<int> evtcount_vect, std::vector<std::vector<TVector3>> trk_mix_vect, std::vector<std::vector<int>> pid_mix_vect, double ptmin, double ptmax, double etamin, double etamax)
{
  for(int ievt = 0; ievt < (int)evtcount_vect.size(); ievt++) // first event loop
    {
      int intrk = (int)trk_mix_vect[ievt].size();
      
      int mixstart = ievt - bkgFactor/2;
      int mixend   = ievt + bkgFactor/2 + 1;

      if(ievt%10000 == 0) std::cout<<ievt<<" th event running for mixing of total events "<<(int)evtcount_vect.size()<<" with multiplicity "<<intrk<<std::endl;

      if(ievt < bkgFactor)
	{
	  mixstart = 0;
	  mixend   = 2*bkgFactor + 1;
	}
      else if(ievt > (int)evtcount_vect.size() - bkgFactor - 1)
	{
	  mixstart = (int)evtcount_vect.size() - 2*bkgFactor - 1;
	  mixend   = (int)evtcount_vect.size();
	}
      
      if(mixend > (int)evtcount_vect.size())
	{
	  mixend = (int)evtcount_vect.size();
	}

      
      int nmix = 0;
      
      for(int jevt = mixstart; jevt < mixend; jevt++) // second event loop
	{
	  if(ievt == jevt) continue; // discard the same event

	  int jntrk = (int)trk_mix_vect[jevt].size();

	  nmix++;
	  
	  for(int i1 = 0; i1 < intrk; i1++) // 1st track loop
	    {
	      TVector3 vec1 = trk_mix_vect[ievt][i1];
	      double pt1 = vec1.Pt();
	      double eta1 = vec1.Eta();
	      double phi1 = vec1.Phi();
	      int pid1 = pid_mix_vect[ievt][i1];
	      
	      for(int i2 = 0; i2 < jntrk; i2++) // second track loop
		{
		  TVector3 vec2 = trk_mix_vect[jevt][i2];
		  double pt2 = vec2.Pt();
		  double eta2 = vec2.Eta();
		  double phi2 = vec2.Phi();
		  int pid2 = pid_mix_vect[jevt][i2];
		  
		  double deta = eta1 - eta2;
		  double dphi = phi1 - phi2;
		  double dphi2 = phi2 - phi1;
		  
		  if(dphi > 1.5*TMath::Pi())
		    {
		      dphi = dphi - 2.0*TMath::Pi();
		    }
		  else if(dphi < -0.5*TMath::Pi())
		    {
		      dphi = dphi + 2.0*TMath::Pi();
		    }
		  
		  if(dphi2 > 1.5*TMath::Pi())
		    {
		      dphi2 = dphi2 - 2.0*TMath::Pi();
		    }
		  else if(dphi2 < -0.5*TMath::Pi())
		    {
		      dphi2 = dphi2 + 2.0*TMath::Pi();
		    }
		  
		  //charged pion
		  if(TMath::Abs(pid1) == 211 && TMath::Abs(pid2) == 211)
		    {
		      if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax) && (pt2 > ptmin && pt2 < ptmax) && (eta2 > etamin && eta2 < etamax))
			{
			  if(pid1 > 0 && pid2 > 0)
			    {
			      hmixing_pp_1->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_pp_1->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_pp_1->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_pp_1->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 > 0 && pid2 < 0)
			    {
			      hmixing_pm_1->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_pm_1->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_pm_1->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_pm_1->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 < 0 && pid2 > 0)
			    {
			      hmixing_mp_1->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_mp_1->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_mp_1->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_mp_1->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 < 0 && pid2 < 0)
			    {
			      hmixing_mm_1->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_mm_1->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_mm_1->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_mm_1->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			} 
		    }
		  
		  //charged kaon
		  if(TMath::Abs(pid1) == 321 && TMath::Abs(pid2) == 321)
		    {
		      if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax) && (pt2 > ptmin && pt2 < ptmax) && (eta2 > etamin && eta2 < etamax))
			{
			  if(pid1 > 0 && pid2 > 0)
			    {
			      hmixing_pp_2->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_pp_2->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_pp_2->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_pp_2->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 > 0 && pid2 < 0)
			    {
			      hmixing_pm_2->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_pm_2->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_pm_2->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_pm_2->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 < 0 && pid2 > 0)
			    {
			      hmixing_mp_2->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_mp_2->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_mp_2->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_mp_2->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 < 0 && pid2 < 0)
			    {
			      hmixing_mm_2->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_mm_2->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_mm_2->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_mm_2->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			}
		    }
		  
		  //neutral kaon
		  if(TMath::Abs(pid1) == 310 && TMath::Abs(pid2) == 310)
		    {
		      if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax) && (pt2 > ptmin && pt2 < ptmax) && (eta2 > etamin && eta2 < etamax))
			{
			  if(pid1 > 0 && pid2 > 0)
			    {
			      hmixing_pp_3->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_pp_3->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_pp_3->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_pp_3->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 > 0 && pid2 < 0)
			    {
			      hmixing_pm_3->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_pm_3->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_pm_3->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_pm_3->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 < 0 && pid2 > 0)
			    {
			      hmixing_mp_3->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_mp_3->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_mp_3->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_mp_3->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 < 0 && pid2 < 0)
			    {
			      hmixing_mm_3->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_mm_3->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_mm_3->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_mm_3->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			}
		    }
		  
		  //proton
		  if(TMath::Abs(pid1) == 2212 && TMath::Abs(pid2) == 2212)
		    {
		      if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax) && (pt2 > ptmin && pt2 < ptmax) && (eta2 > etamin && eta2 < etamax))
			{
			  if(pid1 > 0 && pid2 > 0)
			    {
			      hmixing_pp_4->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_pp_4->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_pp_4->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_pp_4->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 > 0 && pid2 < 0)
			    {
			      hmixing_pm_4->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_pm_4->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_pm_4->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_pm_4->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 < 0 && pid2 > 0)
			    {
			      hmixing_mp_4->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_mp_4->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_mp_4->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_mp_4->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 < 0 && pid2 < 0)
			    {
			      hmixing_mm_4->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_mm_4->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_mm_4->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_mm_4->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			}
		    }
		  
		  //lambda
		  if(TMath::Abs(pid1) == 3122 && TMath::Abs(pid2) == 3122)
		    {
		      if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax) && (pt2 > ptmin && pt2 < ptmax) && (eta2 > etamin && eta2 < etamax))
			{
			  if(pid1 > 0 && pid2 > 0)
			    {
			      hmixing_pp_5->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_pp_5->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_pp_5->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_pp_5->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 > 0 && pid2 < 0)
			    {
			      hmixing_pm_5->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_pm_5->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_pm_5->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_pm_5->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 < 0 && pid2 > 0)
			    {
			      hmixing_mp_5->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_mp_5->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_mp_5->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_mp_5->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 < 0 && pid2 < 0)
			    {
			      hmixing_mm_5->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_mm_5->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_mm_5->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_mm_5->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			}
		    }
		  //lambda-proton
		  if((TMath::Abs(pid1) == 3122 && TMath::Abs(pid2) == 2212) ||(TMath::Abs(pid1) == 2212 && TMath::Abs(pid2) == 3122))
		    {
		      if((pt1 > ptmin && pt1 < ptmax) && (eta1 > etamin && eta1 < etamax) && (pt2 > ptmin && pt2 < ptmax) && (eta2 > etamin && eta2 < etamax))
			{
			  if(pid1 > 0 && pid2 > 0)
			    {
			      hmixing_pp_6->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_pp_6->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_pp_6->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_pp_6->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 > 0 && pid2 < 0)
			    {
			      hmixing_pm_6->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_pm_6->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_pm_6->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_pm_6->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 < 0 && pid2 > 0)
			    {
			      hmixing_mp_6->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_mp_6->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_mp_6->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_mp_6->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			  if(pid1 < 0 && pid2 < 0)
			    {
			      hmixing_mm_6->Fill(fabs(deta), dphi, 1.0/4.0);
			      hmixing_mm_6->Fill(-fabs(deta), dphi, 1.0/4.0);
			      hmixing_mm_6->Fill(fabs(deta), dphi2, 1.0/4.0);
			      hmixing_mm_6->Fill(-fabs(deta), dphi2, 1.0/4.0);
			    }
			}
		    }
		} // second vector loop
	    } // first vector loop
	} // 2nd event loop
      //if(ievt%10000 == 0) std::cout<<"number of Mixed events for "<<ievt<<" event is: "<<nmix<<std::endl;
    } // 1st event loop
} // mixing corr
      
void print_start()
{
  cout << endl;
  time_t init = time(0);
  char* init_time = ctime(&init); // convert now to string form                                        
  cout << "Starting at : " << init_time << endl;
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
  cout << endl;
}

void print_stop()
{
  time_t end = time(0);
  char* end_time = ctime(&end); // convert now to string form                                                   
  cout << endl;
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << endl;
  cout << "Stopping at : " << end_time << endl;
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << endl;
}
