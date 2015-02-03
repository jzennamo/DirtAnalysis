/**
 * \file DirtAnalysis.h
 *
 * \ingroup SampleJosephMCShowerAna
 * 
 * \brief Class def header for a class DirtAnalysis
 *
 * @author jzennamo
 */

/** \addtogroup SampleJosephMCShowerAna

    @{*/

#ifndef LARLITE_DIRTANALYSIS_H
#define LARLITE_DIRTANALYSIS_H

#include "Analysis/ana_base.h"
#include "TVector3.h"


namespace larlite {
  /**
     \class DirtAnalysis
     User custom analysis class made by jzennamo
   */
  class DirtAnalysis : public ana_base{
  
  public:

    /// Default constructor
    DirtAnalysis(){ _name="DirtAnalysis"; _fout=0;};

    /// Default destructor
    virtual ~DirtAnalysis(){};

    /** IMPLEMENT in DirtAnalysis.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in DirtAnalysis.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in DirtAnalysis.cc! 
        Finalize method to be called after all events processed.
    */
    virtual bool finalize();

    void ctr_reset();
    double BackwardsDistToWall(const TVector3 & startPoint, const TVector3 & startDir, double precision);
    bool IsActive(const TLorentzVector & startPos);
    bool IsFiducial(const TVector3 & startPos);
    int IntersectsPlane(const TVector3 & startPos,
			const TVector3 & startDir,
			const TVector3 & planeCorner1,
			const TVector3 & planeCorner2,
			const TVector3 & planeCorner3);

    protected:


    double TPC_Xmin;
    double TPC_Xmax;
    double TPC_Ymin;
    double TPC_Ymax; 
    double TPC_Zmin; 
    double TPC_Zmax;
    
    TVector3 top_front_right;
    TVector3 top_back_right;
    TVector3 top_back_left;

    TVector3 bottom_front_right;
    TVector3 bottom_back_left;
    TVector3 bottom_back_right;
    TVector3 bottom_front_left;

    double fid, fidz_min, fidz_max;
    double fid_mu, fid_mu_z;    

    TVector3 ShowerStartPos;
    TVector3 ShowerStartDir;

    TVector3 TrackStartPos;
    TVector3 TrackStartDir;

    TTree* tree;


    double shower_E;
    int shower_pdg;
    int shower_birth_ina;
    int shower_birth_end_ina;
    int shower_start_ina;
    int shower_start_in_sliver;
    int shower_convert_ina;

    int shower_birth_pdg;
    int shower_mom_pdg;
    int shower_mom_start_ina;

    int shower_vertex_Ntrk;
    double shower_vertex_E;
    double shower_vertex_L;


    int shower_convert_inf_5cm_5cm_50cm;
    int shower_convert_inf_30cm_5cm_50cm;
    int shower_convert_inf_30cm_25cm_50cm;
    int shower_convert_inf_30cm_20cm_50cm;
    int shower_convert_inf_30cm_10cm_50cm;
    int shower_convert_inf_30cm_15cm_50cm;
    
    double shower_start_x;
    double shower_start_y;
    double shower_start_z;

    int shower_extra_photons;

    double shower_convert_x;
    double shower_convert_y;
    double shower_convert_z;

    double shower_bdw;

    int trk_start_ina;
    int trk_pdg;

    int trk_enter;
    int trk_exit;

    double nu_int_x;
    double nu_int_y;
    double nu_int_z;

    int nu_pdg;
    int nu_inf;
    int nu_CC;
    int nu_neutron;
    int nu_neutron_ina;

    int event;
    int shower_multi_enter;

  };
}
#endif

//**************************************************************************
// 
// For Analysis framework documentation, read Manual.pdf here:
//
// http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
//
//**************************************************************************

/** @} */ // end of doxygen group 
