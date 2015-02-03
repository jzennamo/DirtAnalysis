#ifndef DIRTANALYSIS_CXX
#define DIRTANALYSIS_CXX

#include "DirtAnalysis.h"

namespace larlite {

  bool DirtAnalysis::initialize() {

    

    //DETECTOR GEOMETERY 
    TPC_Xmin = 0;
    TPC_Xmax = 256.35;
    TPC_Ymin = -116.5;
    TPC_Ymax = 116.5; 
    TPC_Zmin = 0; 
    TPC_Zmax = 1036.8;
    
    top_front_right.SetXYZ(TPC_Ymax,TPC_Zmin,TPC_Xmax);
    top_back_right.SetXYZ(TPC_Ymax,TPC_Zmax,TPC_Xmax);
    top_back_left.SetXYZ(TPC_Ymax,TPC_Zmax,TPC_Xmin);

    bottom_front_right.SetXYZ(TPC_Ymin,TPC_Zmin,TPC_Xmax);
    bottom_back_left.SetXYZ(TPC_Ymin,TPC_Zmax,TPC_Xmin);
    bottom_back_right.SetXYZ(TPC_Ymin,TPC_Zmax,TPC_Xmax);
    bottom_front_left.SetXYZ(TPC_Ymin,TPC_Zmin,TPC_Xmin);

    //FIDUCIAL VOLUME CUTS
    fid = 25; fidz_min = 5; fidz_max = 100;

    ShowerStartPos.Clear();
    ShowerStartDir.Clear();

    TrackStartPos.Clear();
    TrackStartDir.Clear();

    
    //
    // This function is called in the beggining of event loop
    // Do all variable initialization you wish to do here.
    // If you have a histogram to fill in the event loop, for example,
    // here is a good place to create one on the heap (i.e. "new TH1D"). 
    //
    tree = new TTree("tree","");

    tree->Branch("shower_E",&shower_E,"shower_E/D");
    tree->Branch("shower_pdg",&shower_pdg,"shower_pdg/i");

    tree->Branch("shower_birth_ina",&shower_birth_ina,"shower_birth_ina/I");
    tree->Branch("shower_birth_end_ina",&shower_birth_end_ina,"shower_birth_end_ina/I");
    tree->Branch("shower_birth_pdg",&shower_birth_pdg,"shower_birth_pdg/I");
    tree->Branch("shower_mom_pdg",&shower_mom_pdg,"shower_mom_pdg/I");
    tree->Branch("shower_mom_start_ina",&shower_mom_start_ina,"shower_mom_start_ina/I");

    tree->Branch("shower_start_ina",&shower_start_ina,"shower_start_ina/I");    
    tree->Branch("shower_start_in_sliver",&shower_start_in_sliver,"shower_start_in_sliver/I");    


    tree->Branch("shower_extra_photons",&shower_extra_photons,"shower_extra_photons/I");

    tree->Branch("shower_vertex_Ntrk",&shower_vertex_Ntrk,"shower_vertex_Ntrk/I");
    tree->Branch("shower_vertex_E",&shower_vertex_E,"shower_vertex_E/D");
    tree->Branch("shower_vertex_L",&shower_vertex_L,"shower_vertex_L/D");

    tree->Branch("shower_start_x",&shower_start_x,"shower_start_x/D");
    tree->Branch("shower_start_y",&shower_start_y,"shower_start_y/D");
    tree->Branch("shower_start_z",&shower_start_z,"shower_start_z/D");

    tree->Branch("shower_convert_ina",&shower_convert_ina,"shower_convert_ina/I");    
    tree->Branch("shower_convert_inf_5cm_5cm_50cm",&shower_convert_inf_5cm_5cm_50cm,"shower_convert_inf_5cm_5cm_50cm/I");    
    tree->Branch("shower_convert_inf_30cm_5cm_50cm",&shower_convert_inf_30cm_5cm_50cm,"shower_convert_inf_30cm_5cm_50cm/I");    
    tree->Branch("shower_convert_inf_30cm_25cm_50cm",&shower_convert_inf_30cm_25cm_50cm,"shower_convert_inf_30cm_25cm_50cm/I");    

    tree->Branch("shower_convert_inf_30cm_20cm_50cm",&shower_convert_inf_30cm_20cm_50cm,"shower_convert_inf_30cm_20cm_50cm/I");   
    tree->Branch("shower_convert_inf_30cm_10cm_50cm",&shower_convert_inf_30cm_10cm_50cm,"shower_convert_inf_30cm_10cm_50cm/I");    
    tree->Branch("shower_convert_inf_30cm_15cm_50cm",&shower_convert_inf_30cm_15cm_50cm,"shower_convert_inf_30cm_15cm_50cm/I");    



    tree->Branch("shower_convert_x",&shower_convert_x,"shower_convert_x/D");    
    tree->Branch("shower_convert_y",&shower_convert_y,"shower_convert_y/D");    
    tree->Branch("shower_convert_z",&shower_convert_z,"shower_convert_z/D");    

    tree->Branch("shower_multi_enter",&shower_multi_enter,"shower_multi_enter/I");

    tree->Branch("shower_bdw",&shower_bdw,"shower_bdw/D");



    //new 
    tree->Branch("trk_start_ina",&trk_start_ina,"trk_start_ina/i");
    tree->Branch("trk_pdg",&trk_pdg,"trk_pdg/i");    

    tree->Branch("trk_enter",&trk_enter,"trk_enter/i");
    tree->Branch("trk_exit",&trk_exit,"trk_exit/i");

    tree->Branch("nu_pdg",&nu_pdg,"nu_pdg/I");
    tree->Branch("nu_inf",&nu_inf,"nu_inf/I");
    tree->Branch("nu_CC",&nu_CC,"nu_CC/I");

    tree->Branch("nu_int_x",&nu_int_x,"nu_int_x/D");
    tree->Branch("nu_int_y",&nu_int_y,"nu_int_y/D");
    tree->Branch("nu_int_z",&nu_int_z,"nu_int_z/D");


    tree->Branch("nu_neutron",&nu_neutron,"nu_neutron/I");
    tree->Branch("nu_neutron_ina",&nu_neutron_ina,"nu_neutron_ina/I");

    event = 0; 
    //all_count=0;
    return true;

  }
  
  void DirtAnalysis::ctr_reset() {
    shower_E=0;
    shower_pdg=0;
    shower_start_ina=0;
    shower_start_in_sliver=0;
    shower_convert_ina=0;
    shower_convert_inf_5cm_5cm_50cm=0;
    shower_convert_inf_30cm_5cm_50cm=0;
    shower_convert_inf_30cm_25cm_50cm=0;
    shower_convert_inf_30cm_20cm_50cm=0;
    shower_convert_inf_30cm_10cm_50cm=0;
    shower_convert_inf_30cm_15cm_50cm=0;

    shower_extra_photons=0;

    shower_birth_ina=0;
    shower_birth_pdg=0;
    shower_mom_pdg=0;
    shower_mom_start_ina=0;

    shower_birth_end_ina=0;

    shower_vertex_Ntrk=0;
    shower_vertex_E=0;
    shower_vertex_L=0;

    shower_bdw=0;

    shower_convert_x = 0;
    shower_convert_y = 0;
    shower_convert_z = 0;

    trk_start_ina=0;
    trk_pdg=0;

    trk_enter=0;
    trk_exit=0;

    nu_int_x=0;
    nu_int_y=0;
    nu_int_z=0;

    nu_pdg = 0;
    nu_inf = 0;
    nu_CC = 0;
    nu_neutron = 0;
    nu_neutron_ina = 0;
    shower_multi_enter = 0;

  }

  bool DirtAnalysis::analyze(storage_manager* storage) {

    //Nu Mu events 
    auto ev_mctruth = storage->get_data<event_mctruth>("generator");
    if (!ev_mctruth) { std::cout << "FAIL!" << std::endl; return false; }

    for( size_t i = 0; i < ev_mctruth->size(); ++i){
    
      auto neutrino = ev_mctruth->at(i).GetNeutrino();
      auto part_list = ev_mctruth->at(i).GetParticles();

      if(neutrino.CCNC() == 1){nu_CC = 1;}
      else{nu_CC = 0;}
      
      nu_pdg = neutrino.Nu().PdgCode();

      nu_int_x = neutrino.Nu().Trajectory().at(0).Position().X();
      nu_int_y = neutrino.Nu().Trajectory().at(0).Position().Y();
      nu_int_z = neutrino.Nu().Trajectory().at(0).Position().Z();

      int nu_ina = 0;

      if( neutrino.Nu().Trajectory().at(0).Position().X() > TPC_Xmin &&
          neutrino.Nu().Trajectory().at(0).Position().X() < TPC_Xmax &&
          neutrino.Nu().Trajectory().at(0).Position().Y() > TPC_Ymin &&
          neutrino.Nu().Trajectory().at(0).Position().Y() < TPC_Ymax &&
          neutrino.Nu().Trajectory().at(0).Position().Z() > TPC_Zmin &&
          neutrino.Nu().Trajectory().at(0).Position().Z() < TPC_Zmax)
	nu_ina=1;
    
      if( neutrino.Nu().Trajectory().at(0).Position().X() > TPC_Xmin+17 && 
	  neutrino.Nu().Trajectory().at(0).Position().X() < TPC_Xmax-17 &&
	  neutrino.Nu().Trajectory().at(0).Position().Y() > TPC_Ymin+17 && 
	  neutrino.Nu().Trajectory().at(0).Position().Y() < TPC_Ymax-17 &&
	  neutrino.Nu().Trajectory().at(0).Position().Z() > TPC_Zmin+17 && 
	  neutrino.Nu().Trajectory().at(0).Position().Z() < TPC_Zmax-17) 
	nu_inf=1;
      else 
	nu_inf=0;

      int neu_ina = 0;
      int neu = 0;
      int neu_mom = 0;
      
      if( part_list.size() != 0 && nu_ina == 0){
	for(int part = 0; part < part_list.size(); part++){
	  neu_mom = 0;	  
	  if(part_list.at(part).PdgCode() == 2112){
	    
	      neu++;

	      
	      for(int k = 0; k < part_list.at(part).Trajectory().size(); k++){

		if(part_list.at(part).Trajectory().at(k).Position().X() > TPC_Xmin &&
		   part_list.at(part).Trajectory().at(k).Position().X() < TPC_Xmax &&
		   part_list.at(part).Trajectory().at(k).Position().Y() > TPC_Ymin &&
		   part_list.at(part).Trajectory().at(k).Position().Y() < TPC_Ymax &&
		   part_list.at(part).Trajectory().at(k).Position().Z() > TPC_Zmin &&
		   part_list.at(part).Trajectory().at(k).Position().Z() < TPC_Zmax){
		  
		  neu_ina++;
		}
	      }
	  }
	}
      }

      if(neu > 0){nu_neutron = 1;}
      else{nu_neutron = 0;}
 
      if(neu_ina > 0){ nu_neutron_ina = 1;}
      else{nu_neutron_ina = 0;}

      tree->Fill();  
      
    }
    

    //Shower
    auto ev_mcs = storage->get_data<event_mcshower>("mcreco");
    if (!ev_mcs) { std::cout << "FAIL!" << std::endl; return false; }

    auto ev_mct = storage->get_data<event_mctrack>("mcreco");
    if (!ev_mct) { std::cout << "FAIL!" << std::endl; return false; }
    
    for( size_t i = 0; i < ev_mcs->size(); ++i){

      auto this_shower = ev_mcs->at(i);    
      // for(auto const& this_shower : *ev_mcs) {
      
      ctr_reset();
      
      ShowerStartPos.SetX(this_shower.End().Position().X());
      ShowerStartPos.SetY(this_shower.End().Position().Y());
      ShowerStartPos.SetZ(this_shower.End().Position().Z());

      ShowerStartDir.SetX(this_shower.Start().Momentum().Px());
      ShowerStartDir.SetY(this_shower.Start().Momentum().Py());
      ShowerStartDir.SetZ(this_shower.Start().Momentum().Pz());
 
      shower_pdg = this_shower.PdgCode();
      shower_birth_pdg = this_shower.AncestorPdgCode();
      shower_mom_pdg = this_shower.MotherPdgCode();

      shower_E = this_shower.Start().Momentum().E(); //energy
 
      shower_bdw = BackwardsDistToWall(ShowerStartPos,ShowerStartDir,0.3);

      shower_start_x = this_shower.Start().Position().X();
      shower_start_y = this_shower.Start().Position().Y();
      shower_start_z = this_shower.Start().Position().Z();    

      shower_convert_x = this_shower.End().Position().X();
      shower_convert_y = this_shower.End().Position().Y();
      shower_convert_z = this_shower.End().Position().Z();    
      
      if( this_shower.AncestorStart().Position().X() > TPC_Xmin &&
          this_shower.AncestorStart().Position().X() < TPC_Xmax &&
          this_shower.AncestorStart().Position().Y() > TPC_Ymin &&
          this_shower.AncestorStart().Position().Y() < TPC_Ymax &&
          this_shower.AncestorStart().Position().Z() > TPC_Zmin &&
          this_shower.AncestorStart().Position().Z() < TPC_Zmax)
	shower_birth_ina=1;
      else
	shower_birth_ina=0;

      //shower_birth_end_ina
      if( this_shower.AncestorEnd().Position().X() > TPC_Xmin &&
          this_shower.AncestorEnd().Position().X() < TPC_Xmax &&
          this_shower.AncestorEnd().Position().Y() > TPC_Ymin &&
          this_shower.AncestorEnd().Position().Y() < TPC_Ymax &&
          this_shower.AncestorEnd().Position().Z() > TPC_Zmin &&
          this_shower.AncestorEnd().Position().Z() < TPC_Zmax)
        shower_birth_end_ina=1;
      else
        shower_birth_end_ina=0;
      
      if( this_shower.MotherStart().Position().X() > TPC_Xmin &&
          this_shower.MotherStart().Position().X() < TPC_Xmax &&
          this_shower.MotherStart().Position().Y() > TPC_Ymin &&
          this_shower.MotherStart().Position().Y() < TPC_Ymax &&
          this_shower.MotherStart().Position().Z() > TPC_Zmin &&
          this_shower.MotherStart().Position().Z() < TPC_Zmax)
	shower_mom_start_ina=1;
      else
	shower_mom_start_ina=0;


      if( this_shower.Start().Position().X() > (TPC_Xmin/2)-50 &&
          this_shower.Start().Position().X() < (TPC_Xmin/2)+50 &&
          this_shower.Start().Position().Y() > -50 &&
          this_shower.Start().Position().Y() < 50 &&
          this_shower.Start().Position().Z() > -20 &&
          this_shower.Start().Position().Z() < 0) 
	shower_start_in_sliver = 1;
      else
	shower_start_in_sliver = 0;


      if( this_shower.Start().Position().X() > TPC_Xmin && 
	  this_shower.Start().Position().X() < TPC_Xmax &&
	  this_shower.Start().Position().Y() > TPC_Ymin && 
	  this_shower.Start().Position().Y() < TPC_Ymax &&
	  this_shower.Start().Position().Z() > TPC_Zmin && 
	  this_shower.Start().Position().Z() < TPC_Zmax) 
	shower_start_ina=1;
      else 
	shower_start_ina=0;
      
      if( this_shower.End().Position().X() > TPC_Xmin && 
	  this_shower.End().Position().X() < TPC_Xmax &&
	  this_shower.End().Position().Y() > TPC_Ymin && 
	  this_shower.End().Position().Y() < TPC_Ymax &&
	  this_shower.End().Position().Z() > TPC_Zmin && 
	  this_shower.End().Position().Z() < TPC_Zmax) 
	shower_convert_ina=1;
      else 
	shower_convert_ina=0;
      

      if(this_shower.End().Position().X() > TPC_Xmin+25 &&
	 this_shower.End().Position().X() < TPC_Xmax-25 &&
	 this_shower.End().Position().Y() > TPC_Ymin+25 &&
	 this_shower.End().Position().Y() < TPC_Ymax-25 &&
	 this_shower.End().Position().Z() > TPC_Zmin+30 &&
	 this_shower.End().Position().Z() < TPC_Zmax-50)
	shower_convert_inf_30cm_25cm_50cm=1;
      else
	shower_convert_inf_30cm_25cm_50cm=0;

      if(this_shower.End().Position().X() > TPC_Xmin+5 &&
	 this_shower.End().Position().X() < TPC_Xmax-5 &&
	 this_shower.End().Position().Y() > TPC_Ymin+5 &&
	 this_shower.End().Position().Y() < TPC_Ymax-5 &&
	 this_shower.End().Position().Z() > TPC_Zmin+30 &&
	 this_shower.End().Position().Z() < TPC_Zmax-50)
	shower_convert_inf_30cm_5cm_50cm=1;
      else
	shower_convert_inf_30cm_5cm_50cm=0;

      if(this_shower.End().Position().X() > TPC_Xmin+5 &&
	 this_shower.End().Position().X() < TPC_Xmax-5 &&
	 this_shower.End().Position().Y() > TPC_Ymin+5 &&
	 this_shower.End().Position().Y() < TPC_Ymax-5 &&
	 this_shower.End().Position().Z() > TPC_Zmin+5 &&
	 this_shower.End().Position().Z() < TPC_Zmax-50)
	shower_convert_inf_5cm_5cm_50cm=1;
      else
	shower_convert_inf_5cm_5cm_50cm=0;

      if(this_shower.End().Position().X() > TPC_Xmin+20 &&
         this_shower.End().Position().X() < TPC_Xmax-20 &&
         this_shower.End().Position().Y() > TPC_Ymin+20 &&
         this_shower.End().Position().Y() < TPC_Ymax-20 &&
         this_shower.End().Position().Z() > TPC_Zmin+30 &&
         this_shower.End().Position().Z() < TPC_Zmax-50)
	shower_convert_inf_30cm_20cm_50cm=1;
      else
	shower_convert_inf_30cm_20cm_50cm=0;

      if(this_shower.End().Position().X() > TPC_Xmin+10 &&
         this_shower.End().Position().X() < TPC_Xmax-10 &&
         this_shower.End().Position().Y() > TPC_Ymin+10 &&
         this_shower.End().Position().Y() < TPC_Ymax-10 &&
         this_shower.End().Position().Z() > TPC_Zmin+30 &&
         this_shower.End().Position().Z() < TPC_Zmax-50)
	shower_convert_inf_30cm_10cm_50cm=1;
      else
	shower_convert_inf_30cm_10cm_50cm=0;

      if(this_shower.End().Position().X() > TPC_Xmin+15 &&
         this_shower.End().Position().X() < TPC_Xmax-15 &&
         this_shower.End().Position().Y() > TPC_Ymin+15 &&
         this_shower.End().Position().Y() < TPC_Ymax-15 &&
         this_shower.End().Position().Z() > TPC_Zmin+30 &&
         this_shower.End().Position().Z() < TPC_Zmax-50)
	shower_convert_inf_30cm_15cm_50cm=1;
      else
	shower_convert_inf_30cm_15cm_50cm=0;


      int enter = 0;
      int mult = 0;
      //Two showers in event...
      for( size_t j = 0; j < ev_mcs->size(); ++j){
	auto all_showers = ev_mcs->at(j);
	if(all_showers.Start().Position().X() > TPC_Xmin &&
	   all_showers.Start().Position().X() < TPC_Xmax &&
	   all_showers.Start().Position().Y() > TPC_Ymin &&
	   all_showers.Start().Position().Y() < TPC_Ymax &&
	   all_showers.Start().Position().Z() > TPC_Zmin &&
	   all_showers.Start().Position().Z() < TPC_Zmax &&
	   all_showers.End().Position().X() > TPC_Xmin &&
	   all_showers.End().Position().X() < TPC_Xmax &&
	   all_showers.End().Position().Y() > TPC_Ymin &&
	   all_showers.End().Position().Y() < TPC_Ymax &&
	   all_showers.End().Position().Z() > TPC_Zmin &&
	   all_showers.End().Position().Z() < TPC_Zmax &&
	   this_shower.Start().Momentum().E()*0.001 > 0.025){enter++;}

	if(this_shower.TrackID() != all_showers.TrackID() &&
	   all_showers.PdgCode() == 22 &&
	   abs(all_showers.Start().Position().X() - this_shower.Start().Position().X()) < 1 &&
	   abs(all_showers.Start().Position().Y() - this_shower.Start().Position().Y()) < 1 &&
	   abs(all_showers.Start().Position().Z() - this_shower.Start().Position().Z()) < 1 ){mult++;}
      }

      if(enter > 1){ shower_multi_enter=1;}
      else{shower_multi_enter=0;}
      
      shower_extra_photons = mult;
      
      //Vetrices 
      int N_trk = 0;
      double E_vert = 0;
      for( size_t k = 0; k < ev_mct->size(); ++k){     
	auto this_track = ev_mct->at(k);
	
	//Building a vertex
	if(abs(this_track.Start().Position().X() - this_shower.Start().Position().X()) < 1 &&
	   abs(this_track.Start().Position().Y() - this_shower.Start().Position().Y()) < 1 &&
	   abs(this_track.Start().Position().Z() - this_shower.Start().Position().Z()) < 1 ){
	  //veto below threshold protons
	  if(abs(this_track.PdgCode()) ==  2212){if(this_track.Start().Momentum().E()*0.001 < 0.02) continue;}
	  
	  N_trk++;
	  E_vert += this_track.Start().Momentum().E();
	  
	}
      }
      
      if(N_trk > 0)
	shower_vertex_L = sqrt( pow((this_shower.Start().Position().X() - this_shower.End().Position().X()),2) +
				pow((this_shower.Start().Position().Y() - this_shower.End().Position().Y()),2) +
				pow((this_shower.Start().Position().Z() - this_shower.End().Position().Z()),2));
      else
	shower_vertex_L = 0;

	  

    shower_vertex_Ntrk = N_trk;
    shower_vertex_E = E_vert;


    //Muons  
    for( size_t k = 0; k < ev_mct->size(); ++k){     
      auto this_track = ev_mct->at(k);
      trk_pdg = this_track.PdgCode();


      if(abs(this_track.PdgCode()) == 13){
	
	if( this_track.Start().Position().X() > TPC_Xmin && 
	    this_track.Start().Position().X() < TPC_Xmax &&
	    this_track.Start().Position().Y() > TPC_Ymin && 
	    this_track.Start().Position().Y() < TPC_Ymax &&
	    this_track.Start().Position().Z() > TPC_Zmin && 
	    this_track.Start().Position().Z() < TPC_Zmax){
	  trk_start_ina = 1;}
	else{trk_start_ina = 0;}
	
	if(this_track.size() > 0){trk_enter = 1;}
	else{trk_enter = 0;}
      }
      else{continue;}
      
      /*      if(trk_start_ina == 1){
	      for(int point = 0; point < this_track.size(); point++){
	      if(IsActive(this_track.at(point).Position())){trk_exit = 0;}
	      else{trk_exit = 1; continue;}
	      }
	      }
      */
      
      if(trk_enter == 1 && trk_start_ina == 0){break;}
      
      
    }
    
    tree->Fill();  
    }
    
    return true;
    
    
    
  }
  


  bool DirtAnalysis::finalize() {
    if(_fout)
      tree->Write();
    return true;
  }


  //Functions
  bool DirtAnalysis::IsActive(const TLorentzVector & startPos){
    
    if( startPos.X() > TPC_Xmin &&
	startPos.X() < TPC_Xmax &&
	startPos.Y() > TPC_Ymin &&
	startPos.Y() < TPC_Ymax &&
	startPos.Z() > TPC_Zmin &&
	startPos.Z() < TPC_Zmax)
      return true;
    else
      return false;
  }
  
  bool DirtAnalysis::IsFiducial(const TVector3 & startPos){
    
    if( startPos.X() > TPC_Xmin+fid &&
	startPos.X() < TPC_Xmax-fid &&
	startPos.Y() > TPC_Ymin+fid &&
	startPos.Y() < TPC_Ymax-fid &&
	startPos.Z() > TPC_Zmin+fidz_min &&
	startPos.Z() < TPC_Zmax-fidz_max)
      return true;
    else
      return false;
  }

  double DirtAnalysis::BackwardsDistToWall(const TVector3 & pos, 
					   const TVector3 & direc, 
					   double P){

    double _xyz_min[3] = {0., -116., 0.}; 
    double _xyz_max[3] = {256., 116., 1030.};
    
    double point[3] = {pos.X(), pos.Y(), pos.Z()};
    double dir[3] = {direc.X(), direc.Y(), direc.Z()};
    
    //This function computes the distance from a point to the closest wall of the box
    // along the specified direction (both taken from input arguments). The box is
    // pre-defined by _xyz_min and _xyz_max values. Specify 0 for backwards, 1 for forwards. 
    // The function only works only if the point is inside the box for now because
    // otherwise it adds a complication to the problem.
    // 
    // The function proceeds in the following steps of computation:
    //

    // (1) Check if a point is within the box. If not, return -1.
    // (2) Normalize dir to make it into a unit vector.
    // (3) Compute distance to reach YZ plane (i.e. x=0 plane)
    // (4) Compute distance to reach ZX plane (i.e. y=0 plane)
    // (5) Compute distance to reach XY plane (i.e. z=0 plane)
    // (6) Return the minimum of (3), (4), and (5)
    //

    //
    // (1) Check if a point is inside the box. If not, return -1.
    //

    //Already checked that shit, yo

    //
    // (2) Normalize dir vector
    //

    double dir_magnitude = sqrt( pow(dir[0],2) + pow(dir[1],2) + pow(dir[2],2) );
    dir[0] /= dir_magnitude;
    dir[1] /= dir_magnitude;
    dir[2] /= dir_magnitude;

    //
    // (2.5) Swap direction if user wants backwards direction
    //  

    dir[0] *= -1 ;
    dir[1] *= -1 ;
    dir[2] *= -1 ;

    //
    // (3) Compute distance to reach YZ plane
    //

    double dist_to_yz = 0;
    if(dir[0] < 0 )
      dist_to_yz = (point[0] - _xyz_min[0]) / (-1. * dir[0]);
    else
      dist_to_yz = (_xyz_max[0] - point[0]) / dir[0];



    //
    // (4) Compute distance to reach XY plane
    //

    double dist_to_xy = 0;
    if(dir[2] < 0)
      dist_to_xy = (point[2] -  _xyz_min[2]) / (-1. * dir[2]);
    else
      dist_to_xy = (_xyz_max[2] - point[2]) / dir[2];


    //
    // (5) Compute distance to reach XZ plane
    //

    double dist_to_zx = 0;
    if(dir[1] < 0)
      dist_to_zx = (point[1] - _xyz_min[1]) / (-1. * dir[1]);
    else
      dist_to_zx = (_xyz_max[1] - point[1]) / dir[1];

    //
    //(6) Return the minimum of (3), (4), and (5)
    //
    double dist = ( dist_to_yz < dist_to_zx ? dist_to_yz : dist_to_zx );
    dist = ( dist < dist_to_xy ? dist : dist_to_xy );
    return dist;

  }


  int DirtAnalysis::IntersectsPlane(const TVector3 & startPos, 
				    const TVector3 & startDir,
				    const TVector3 & planeCorner1,
				    const TVector3 & planeCorner2,
				    const TVector3 & planeCorner3){
    
    if (startDir.Mag() == 0) return 0;

    // a and b are defined to be vectors parallel to the plane:
    TVector3 a = planeCorner2 - planeCorner1;
    TVector3 b = planeCorner3 - planeCorner1;

    // Normal vector to the plane
    TVector3 n = a.Cross(b);

    //Check that the Normal vector isn't 0 - that the vectors aren't parallel
    if (n.Mag() == 0){
      return 0;
    }

    // Check that the line is not parallel to the plane with dot product to normal vector:
    if (abs(n.Dot(startDir)/(n.Mag()*startDir.Mag())) < 1e-10){
      return 0;
    }
    
    // Create the matrix:
    TMatrixD mat(3,3);
    // format is mat(row_n, col_n)
    mat(0,0) = -startDir.X();
    mat(0,1) = a.X();
    mat(0,2) = b.X();
    mat(1,0) = -startDir.Y();
    mat(1,1) = a.Y();
    mat(1,2) = b.Y();
    mat(2,0) = -startDir.Z();
    mat(2,1) = a.Z();
    mat(2,2) = b.Z();

    TMatrix inv = mat.Invert();


    // Create the vector to multiply.
    TMatrix t(3,1);
    t(0,0) = startPos.X() - planeCorner1.X();
    t(1,0) = startPos.Y() - planeCorner1.Y();
    t(2,0) = startPos.Z() - planeCorner1.Z();

    // Do the matrix multiplication:
    TMatrix result = inv*t;

    // t is  largely irrelevant in this function, but u and v are important.
    // if u and v are both within [0,1] then the line intersects the plane in the desired range


    if (result(0,0) > 0){ // Intersects in forward direction
      if (result(1,0) >= 0 && result (1,0) <= 1)
	{
	  if (result(2,0) >= 0 && result (2,0) <= 1)
	    {
	      return 1;
	    }
	}
      // then success! they intersect
    }
    return 0;

  }



}
#endif
