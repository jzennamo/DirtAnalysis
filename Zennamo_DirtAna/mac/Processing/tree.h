//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Dec 22 13:30:34 2014 by ROOT version 5.34/22
// from TTree tree/
// found on file: ../Dirt_TTree.root
//////////////////////////////////////////////////////////

#ifndef tree_h
#define tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class tree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        shower_E;
   UInt_t          shower_pdg;
   Int_t           shower_birth_ina;
   Int_t           shower_birth_end_ina;
   Int_t           shower_birth_pdg;
   Int_t           shower_mom_pdg;
   Int_t           shower_mom_start_ina;
   Int_t           shower_start_ina;
   Int_t           shower_start_in_sliver;
   Int_t           shower_extra_photons;
   Int_t           shower_vertex_Ntrk;
   Double_t        shower_vertex_E;
   Double_t        shower_vertex_L;
   Double_t        shower_start_x;
   Double_t        shower_start_y;
   Double_t        shower_start_z;
   Int_t           shower_convert_ina;
   Int_t           shower_convert_inf_5cm_5cm_50cm;
   Int_t           shower_convert_inf_30cm_5cm_50cm;
   Int_t           shower_convert_inf_30cm_25cm_50cm;
   Int_t           shower_convert_inf_30cm_20cm_50cm;
   Int_t           shower_convert_inf_30cm_10cm_50cm;
   Int_t           shower_convert_inf_30cm_15cm_50cm;
   Double_t        shower_convert_x;
   Double_t        shower_convert_y;
   Double_t        shower_convert_z;
   Int_t           shower_multi_enter;
   Double_t        shower_bdw;
   UInt_t          trk_start_ina;
   UInt_t          trk_pdg;
   UInt_t          trk_enter;
   UInt_t          trk_exit;
   Int_t           nu_pdg;
   Int_t           nu_inf;
   Int_t           nu_CC;
   Double_t        nu_int_x;
   Double_t        nu_int_y;
   Double_t        nu_int_z;
   Int_t           nu_neutron;
   Int_t           nu_neutron_ina;

   // List of branches
   TBranch        *b_shower_E;   //!
   TBranch        *b_shower_pdg;   //!
   TBranch        *b_shower_birth_ina;   //!
   TBranch        *b_shower_birth_end_ina;   //!
   TBranch        *b_shower_birth_pdg;   //!
   TBranch        *b_shower_mom_pdg;   //!
   TBranch        *b_shower_mom_start_ina;   //!
   TBranch        *b_shower_start_ina;   //!
   TBranch        *b_shower_start_in_sliver;   //!
   TBranch        *b_shower_extra_photons;   //!
   TBranch        *b_shower_vertex_Ntrk;   //!
   TBranch        *b_shower_vertex_E;   //!
   TBranch        *b_shower_vertex_L;   //!
   TBranch        *b_shower_start_x;   //!
   TBranch        *b_shower_start_y;   //!
   TBranch        *b_shower_start_z;   //!
   TBranch        *b_shower_convert_ina;   //!
   TBranch        *b_shower_convert_inf_5cm_5cm_50cm;   //!
   TBranch        *b_shower_convert_inf_30cm_5cm_50cm;   //!
   TBranch        *b_shower_convert_inf_30cm_25cm_50cm;   //!
   TBranch        *b_shower_convert_inf_30cm_20cm_50cm;   //!
   TBranch        *b_shower_convert_inf_30cm_10cm_50cm;   //!
   TBranch        *b_shower_convert_inf_30cm_15cm_50cm;   //!
   TBranch        *b_shower_convert_x;   //!
   TBranch        *b_shower_convert_y;   //!
   TBranch        *b_shower_convert_z;   //!
   TBranch        *b_shower_multi_enter;   //!
   TBranch        *b_shower_bdw;   //!
   TBranch        *b_trk_start_ina;   //!
   TBranch        *b_trk_pdg;   //!
   TBranch        *b_trk_enter;   //!
   TBranch        *b_trk_exit;   //!
   TBranch        *b_nu_pdg;   //!
   TBranch        *b_nu_inf;   //!
   TBranch        *b_nu_CC;   //!
   TBranch        *b_nu_int_x;   //!
   TBranch        *b_nu_int_y;   //!
   TBranch        *b_nu_int_z;   //!
   TBranch        *b_nu_neutron;   //!
   TBranch        *b_nu_neutron_ina;   //!

   tree(TTree *tree=0);
   virtual ~tree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef tree_cxx
tree::tree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../Dirt_TTree.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../Dirt_TTree.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

tree::~tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t tree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void tree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("shower_E", &shower_E, &b_shower_E);
   fChain->SetBranchAddress("shower_pdg", &shower_pdg, &b_shower_pdg);
   fChain->SetBranchAddress("shower_birth_ina", &shower_birth_ina, &b_shower_birth_ina);
   fChain->SetBranchAddress("shower_birth_end_ina", &shower_birth_end_ina, &b_shower_birth_end_ina);
   fChain->SetBranchAddress("shower_birth_pdg", &shower_birth_pdg, &b_shower_birth_pdg);
   fChain->SetBranchAddress("shower_mom_pdg", &shower_mom_pdg, &b_shower_mom_pdg);
   fChain->SetBranchAddress("shower_mom_start_ina", &shower_mom_start_ina, &b_shower_mom_start_ina);
   fChain->SetBranchAddress("shower_start_ina", &shower_start_ina, &b_shower_start_ina);
   fChain->SetBranchAddress("shower_start_in_sliver", &shower_start_in_sliver, &b_shower_start_in_sliver);
   fChain->SetBranchAddress("shower_extra_photons", &shower_extra_photons, &b_shower_extra_photons);
   fChain->SetBranchAddress("shower_vertex_Ntrk", &shower_vertex_Ntrk, &b_shower_vertex_Ntrk);
   fChain->SetBranchAddress("shower_vertex_E", &shower_vertex_E, &b_shower_vertex_E);
   fChain->SetBranchAddress("shower_vertex_L", &shower_vertex_L, &b_shower_vertex_L);
   fChain->SetBranchAddress("shower_start_x", &shower_start_x, &b_shower_start_x);
   fChain->SetBranchAddress("shower_start_y", &shower_start_y, &b_shower_start_y);
   fChain->SetBranchAddress("shower_start_z", &shower_start_z, &b_shower_start_z);
   fChain->SetBranchAddress("shower_convert_ina", &shower_convert_ina, &b_shower_convert_ina);
   fChain->SetBranchAddress("shower_convert_inf_5cm_5cm_50cm", &shower_convert_inf_5cm_5cm_50cm, &b_shower_convert_inf_5cm_5cm_50cm);
   fChain->SetBranchAddress("shower_convert_inf_30cm_5cm_50cm", &shower_convert_inf_30cm_5cm_50cm, &b_shower_convert_inf_30cm_5cm_50cm);
   fChain->SetBranchAddress("shower_convert_inf_30cm_25cm_50cm", &shower_convert_inf_30cm_25cm_50cm, &b_shower_convert_inf_30cm_25cm_50cm);
   fChain->SetBranchAddress("shower_convert_inf_30cm_20cm_50cm", &shower_convert_inf_30cm_20cm_50cm, &b_shower_convert_inf_30cm_20cm_50cm);
   fChain->SetBranchAddress("shower_convert_inf_30cm_10cm_50cm", &shower_convert_inf_30cm_10cm_50cm, &b_shower_convert_inf_30cm_10cm_50cm);
   fChain->SetBranchAddress("shower_convert_inf_30cm_15cm_50cm", &shower_convert_inf_30cm_15cm_50cm, &b_shower_convert_inf_30cm_15cm_50cm);
   fChain->SetBranchAddress("shower_convert_x", &shower_convert_x, &b_shower_convert_x);
   fChain->SetBranchAddress("shower_convert_y", &shower_convert_y, &b_shower_convert_y);
   fChain->SetBranchAddress("shower_convert_z", &shower_convert_z, &b_shower_convert_z);
   fChain->SetBranchAddress("shower_multi_enter", &shower_multi_enter, &b_shower_multi_enter);
   fChain->SetBranchAddress("shower_bdw", &shower_bdw, &b_shower_bdw);
   fChain->SetBranchAddress("trk_start_ina", &trk_start_ina, &b_trk_start_ina);
   fChain->SetBranchAddress("trk_pdg", &trk_pdg, &b_trk_pdg);
   fChain->SetBranchAddress("trk_enter", &trk_enter, &b_trk_enter);
   fChain->SetBranchAddress("trk_exit", &trk_exit, &b_trk_exit);
   fChain->SetBranchAddress("nu_pdg", &nu_pdg, &b_nu_pdg);
   fChain->SetBranchAddress("nu_inf", &nu_inf, &b_nu_inf);
   fChain->SetBranchAddress("nu_CC", &nu_CC, &b_nu_CC);
   fChain->SetBranchAddress("nu_int_x", &nu_int_x, &b_nu_int_x);
   fChain->SetBranchAddress("nu_int_y", &nu_int_y, &b_nu_int_y);
   fChain->SetBranchAddress("nu_int_z", &nu_int_z, &b_nu_int_z);
   fChain->SetBranchAddress("nu_neutron", &nu_neutron, &b_nu_neutron);
   fChain->SetBranchAddress("nu_neutron_ina", &nu_neutron_ina, &b_nu_neutron_ina);
   Notify();
}

Bool_t tree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void tree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t tree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef tree_cxx
