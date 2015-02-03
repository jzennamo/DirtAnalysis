#define tree_cxx
#include "tree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

void tree::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L tree.C
//      Root > tree t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

  double bins[12] = {0.2,0.35,0.5,0.65,0.8,0.95,1.10,1.30,1.50,1.75,2.00,3.00};
  TH1D * MicroBooNE_Dirt                      = new TH1D("MicroBooNE_dirt","", 120,0,3);
  TH1D * MicroBooNE_Dirt_5cm_5cm_50cm         = new TH1D("MicroBooNE_dirt_5cm_5cm_50cm","", 120,0,3);      
  TH1D * MicroBooNE_Dirt_AnaBins_5cm_5cm_50cm = new TH1D("MicroBooNE_dirt_AnaBins_5cm_5cm_50cm","", 11, bins);

  TH1D * MicroBooNE_Dirt_30cm_5cm_50cm         = new TH1D("MicroBooNE_dirt_30cm_5cm_50cm","", 120,0,3);      
  TH1D * MicroBooNE_Dirt_AnaBins_30cm_5cm_50cm = new TH1D("MicroBooNE_dirt_AnaBins_30cm_5cm_50cm","", 11, bins);

  TH1D * MicroBooNE_Dirt_30cm_25cm_50cm         = new TH1D("MicroBooNE_dirt_30cm_25cm_50cm","", 120,0,3);      
  TH1D * MicroBooNE_Dirt_AnaBins_30cm_25cm_50cm = new TH1D("MicroBooNE_dirt_AnaBins_30cm_25cm_50cm","", 11, bins);

  TH1D * MicroBooNE_Dirt_30cm_20cm_50cm         = new TH1D("MicroBooNE_dirt_30cm_20cm_50cm","", 120,0,3);      
  TH1D * MicroBooNE_Dirt_AnaBins_30cm_20cm_50cm = new TH1D("MicroBooNE_dirt_AnaBins_30cm_20cm_50cm","", 11, bins);

  TH1D * MicroBooNE_Dirt_30cm_15cm_50cm         = new TH1D("MicroBooNE_dirt_30cm_15cm_50cm","", 120,0,3);      
  TH1D * MicroBooNE_Dirt_AnaBins_30cm_15cm_50cm = new TH1D("MicroBooNE_dirt_AnaBins_30cm_15cm_50cm","", 11, bins);

  TH1D * MicroBooNE_Dirt_30cm_10cm_50cm         = new TH1D("MicroBooNE_dirt_30cm_10cm_50cm","", 120,0,3);      
  TH1D * MicroBooNE_Dirt_AnaBins_30cm_10cm_50cm = new TH1D("MicroBooNE_dirt_AnaBins_30cm_10cm_50cm","", 11, bins);


  TH1D * ICARUS_Front_Dirt = new TH1D("ICARUS_Front_dirt","", 120,0,3);      
  TH1D * ICARUS_Sides_Dirt = new TH1D("ICARUS_Sides_dirt","", 120,0,3);      
  TH1D * ICARUS_Dirt = new TH1D("ICARUS_dirt","", 120,0,3);
  

  int From_Sliver_inFid = 0;
  int From_Sliver_inFid_1gam = 0;
  int From_Sliver_inFid_1gam_noLep = 0;

  double  TPC_Xmin = 0;
  double  TPC_Xmax = 256.35;
  double  TPC_Ymin = -116.5;
  double  TPC_Ymax = 116.5;
  double  TPC_Zmin = 0;
  double  TPC_Zmax = 1036.8;
  
  int numu = 0;

  double MicroBooNE_front = 0, MicroBooNE_side = 0; 
  
  double R2 = pow(470,2)/pow(600,2);

  double A_front = (3-.25-.25)*(3.16-.25-.25)/((2.56-.25-.25)*(2.33-.25-.25));
  double A_side = ((17.95-.3-.5)*(3.16-.25-.25)+(17.95-.3-.5)*(3-.25-.25))/((10.35-.3-.5)*(2.33-.25-.25)+(10.35-.3-.5)*(2.56-.25-.25));

  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;

    if(abs(nu_pdg) == 14 && nu_CC == 1 && nu_int_x > (TPC_Xmin/2)-50 && nu_int_x < (TPC_Xmin/2)+50 && nu_int_y > -50 && nu_int_y < 50 && nu_int_z > -20 && nu_int_z < 0 && nu_int_x != 0 && nu_int_y != 0 && nu_int_z != 0){
      
      numu++;

    }
    


    
    if(shower_pdg == 22 && shower_start_ina == 0  && shower_convert_inf_5cm_5cm_50cm && trk_enter == 0 && trk_start_ina == 0 && shower_multi_enter == 0 && shower_birth_ina == 0){

      MicroBooNE_Dirt_5cm_5cm_50cm->Fill(shower_E*0.001,(2.644*0.06));
      MicroBooNE_Dirt_AnaBins_5cm_5cm_50cm->Fill(shower_E*0.001,(2.644*0.06));

    }

    if(shower_pdg == 22 && shower_start_ina == 0  && shower_convert_inf_30cm_5cm_50cm && trk_enter == 0 && trk_start_ina == 0 && shower_multi_enter == 0 && shower_birth_ina == 0){

      MicroBooNE_Dirt_30cm_5cm_50cm->Fill(shower_E*0.001,(2.644*0.06));
      MicroBooNE_Dirt_AnaBins_30cm_5cm_50cm->Fill(shower_E*0.001,(2.644*0.06));

    }

  if(shower_pdg == 22 && shower_start_ina == 0  && shower_convert_inf_30cm_20cm_50cm && trk_enter == 0 && trk_start_ina == 0 && shower_multi_enter == 0 && shower_birth_ina == 0){

      MicroBooNE_Dirt_30cm_20cm_50cm->Fill(shower_E*0.001,(2.644*0.06));
      MicroBooNE_Dirt_AnaBins_30cm_20cm_50cm->Fill(shower_E*0.001,(2.644*0.06));

    }

  if(shower_pdg == 22 && shower_start_ina == 0  && shower_convert_inf_30cm_10cm_50cm && trk_enter == 0 && trk_start_ina == 0 && shower_multi_enter == 0 && shower_birth_ina == 0){

      MicroBooNE_Dirt_30cm_10cm_50cm->Fill(shower_E*0.001,(2.644*0.06));
      MicroBooNE_Dirt_AnaBins_30cm_10cm_50cm->Fill(shower_E*0.001,(2.644*0.06));

    }

  if(shower_pdg == 22 && shower_start_ina == 0  && shower_convert_inf_30cm_15cm_50cm && trk_enter == 0 && trk_start_ina == 0 && shower_multi_enter == 0 && shower_birth_ina == 0){

      MicroBooNE_Dirt_30cm_15cm_50cm->Fill(shower_E*0.001,(2.644*0.06));
      MicroBooNE_Dirt_AnaBins_30cm_15cm_50cm->Fill(shower_E*0.001,(2.644*0.06));

    }


    if(shower_pdg == 22 && shower_start_ina == 0  && shower_convert_inf_30cm_25cm_50cm && trk_enter == 0 && trk_start_ina == 0 && shower_multi_enter == 0 && shower_birth_ina == 0){

      MicroBooNE_Dirt_30cm_25cm_50cm->Fill(shower_E*0.001,(2.644*0.06));
      MicroBooNE_Dirt_AnaBins_30cm_25cm_50cm->Fill(shower_E*0.001,(2.644*0.06));



    }

   if(shower_pdg == 22 && shower_start_ina == 0  && shower_convert_inf_30cm_20cm_50cm && trk_enter == 0 && trk_start_ina == 0 && shower_multi_enter == 0 && shower_birth_ina == 0 && shower_convert_z < 50){
      
      if(shower_E*0.001 > .200){ MicroBooNE_front += 2.644*0.06;}
      
      ICARUS_Front_Dirt->Fill(shower_E*0.001,2*(2.644*0.06*R2*A_front));
   }
    
    if(shower_pdg == 22 && shower_start_ina == 0  && shower_convert_inf_30cm_20cm_50cm && trk_enter == 0 && trk_start_ina == 0 && shower_multi_enter == 0 && shower_birth_ina == 0 && shower_convert_z > 50){

      if(shower_E*0.001 > .200){ MicroBooNE_side += 2.644*0.06;}

      ICARUS_Sides_Dirt->Fill(shower_E*0.001,2*(2.644*0.06*R2*A_side));

    }


 if(shower_pdg == 22 && shower_start_ina == 0  && shower_convert_inf_30cm_20cm_50cm && trk_enter == 0 && trk_start_ina == 0 && shower_multi_enter == 0 && shower_birth_ina == 0){
   MicroBooNE_Dirt->Fill(shower_E*0.001,(2.644*0.06));}

if(shower_pdg == 22 && shower_start_ina == 0  && shower_convert_inf_30cm_25cm_50cm && shower_birth_ina == 0 && shower_start_in_sliver){

  From_Sliver_inFid++;
  
  if(shower_multi_enter == 0){
    From_Sliver_inFid_1gam++;
    if(trk_enter == 0 && trk_start_ina == 0){
      From_Sliver_inFid_1gam_noLep++;
    }
  }
 }

      // if (Cut(ientry) < 0) continue;
  }

  std::cout << " Photons from the sliver which enter the Fid                : " << double(From_Sliver_inFid)*2.644  << std::endl;
  std::cout << " Photons from the sliver which enter the Fid, 1 gam         : " << double(From_Sliver_inFid_1gam)*2.644 << std::endl;
  std::cout << " Photons from the sliver which enter the Fid, 1 gam, no Lep : " << double(From_Sliver_inFid_1gam_noLep)*2.644 << std::endl;



  std::cout << "Number of dirt events in MicroBooNE in the front : " << MicroBooNE_front << std::endl;
  std::cout << "Number of dirt events in MicroBooNE in the side  : " << MicroBooNE_side << std::endl;


  std::cout << "Number of dirt events in ICARUS in the front : " << ICARUS_Front_Dirt->Integral(9,120) << std::endl;
  std::cout << "Number of dirt events in ICARUS in the side  : " << ICARUS_Sides_Dirt->Integral(9,120) << std::endl;

  ICARUS_Dirt->Add(ICARUS_Front_Dirt);
  ICARUS_Dirt->Add(ICARUS_Sides_Dirt);

  std::cout << "Test: Number of numu interactions in the sliver : " << numu*2.644 << std::endl;

  TFile *f = new TFile("MicroBooNE_dirt.root", "RECREATE");
  MicroBooNE_Dirt->Write();
  // MicroBooNE_Dirt_AnaBins->Write();
  
  MicroBooNE_Dirt_5cm_5cm_50cm->Write();
  MicroBooNE_Dirt_AnaBins_5cm_5cm_50cm->Write();

  MicroBooNE_Dirt_30cm_5cm_50cm->Write();
  MicroBooNE_Dirt_AnaBins_30cm_5cm_50cm->Write();

  MicroBooNE_Dirt_30cm_25cm_50cm->Write();
  MicroBooNE_Dirt_AnaBins_30cm_25cm_50cm->Write();

  MicroBooNE_Dirt_30cm_20cm_50cm->Write();
  MicroBooNE_Dirt_AnaBins_30cm_20cm_50cm->Write();

  MicroBooNE_Dirt_30cm_10cm_50cm->Write();
  MicroBooNE_Dirt_AnaBins_30cm_10cm_50cm->Write();

  MicroBooNE_Dirt_30cm_15cm_50cm->Write();
  MicroBooNE_Dirt_AnaBins_30cm_15cm_50cm->Write();

  f->Close();

  TFile *f1 = new TFile("ICARUS_dirt.root", "RECREATE");
  ICARUS_Dirt->Write();
  f1->Close();
}
