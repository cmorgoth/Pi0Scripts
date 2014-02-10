#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "TROOT.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include <stdlib.h> 
#include <sstream>

int main(){
  
  gROOT->Reset();
  
  std::map<std::string, float> caltech;
  TH1F* h1 = new TH1F("h1", "h1", 500, 0.7, 1.3);
  float eta_ring_mean[170];
  
  std::ifstream ifs ("IC_Files/Caltech/deriveCalibConst.dflag2.pe1.step4.iter30_RUNC_NoCorrections.txt", std::ifstream::in);
  int ctr = 0, eta_ctr = 0, phi_ctr = 0;
  std::string s1, s2;
  float IC = 0, mean_ring = 0;
  if(ifs.is_open()){
    while(ifs.good()){
      if(ifs.eof())break;
      ifs >> s1 >> s2 >> IC;
      if(IC != -1.0){
	mean_ring += IC;
	phi_ctr++;
	caltech[s1+s2] = IC;
	h1->Fill(IC);
      }
      if(atoi(s2.c_str()) == 359){
	eta_ring_mean[eta_ctr] = mean_ring/phi_ctr;
	eta_ctr++;
	mean_ring = 0;
	phi_ctr = 0;
      }
      
    }
  }else{
    std::cout << "Unable to locate the file!" << std::endl;
  }
  ifs.close();
  
  for(int i = 0; i < 170; i++){
    //std::cout << "ieta: " << i << " " << eta_ring_mean[i] << std::endl;
  }
  

  //Eta Corrected Caltech Constants
  
  TH1F* h1_corr = new TH1F("h1_corr", "h1_corr", 500, 0.7, 1.3);
  TH2F* h2d_corr = new TH2F("h2d_corr", "h2d_corr", 170, -85, 85, 360, 1, 361);
  std::map<std::string, float> caltech_corr;
  
  std::ifstream ifs1 ("IC_Files/Caltech/deriveCalibConst.dflag2.pe1.step4.iter30_RUNC_NoCorrections.txt", std::ifstream::in);
  eta_ctr = 0;
  if(ifs1.is_open()){
    while(ifs1.good()){
      std::stringstream ss1, ss2;
      if(ifs1.eof())break;
      ifs1 >> s1 >> s2 >> IC;
      if(IC != -1.0){
	//caltech_corr[s1+s2] = IC/eta_ring_mean[eta_ctr];
	h1_corr->Fill(IC/eta_ring_mean[eta_ctr]);
	if(atoi(s1.c_str()) < 85){
	  h2d_corr->Fill(atoi(s1.c_str()) - 85, atoi(s2.c_str()) + 1, IC/eta_ring_mean[eta_ctr]);
	  
	  ss1 << atoi(s1.c_str()) - 85;
	  ss2 << atoi(s2.c_str()) + 1;
	  caltech_corr[ss1.str()+" "+ss2.str()] = IC/eta_ring_mean[eta_ctr];
	  //std::cout << "ieta: " << ieta << " iphi: " << iphi << std::endl;
	  //std::cout << "ieta: " << ss1.str() << " iphi: " << ss2.str() << " " << ss1.str()+" "+ss2.str() << std::endl;
	}else{
	  h2d_corr->Fill(atoi(s1.c_str()) - 84, atoi(s2.c_str()) + 1, IC/eta_ring_mean[eta_ctr]);
	  ss1 << atoi(s1.c_str()) - 84;
	  ss2 << atoi(s2.c_str()) + 1;
	  //std::cout << "ieta: " << ss1.str() << " iphi: " << ss2.str() << " " << ss1.str()+ss2.str() << std::endl;
	  caltech_corr[ss1.str()+" "+ss2.str()] = IC/eta_ring_mean[eta_ctr];
	}
      }
      if(atoi(s2.c_str()) == 359){
	eta_ctr++;
      }
      
    }
  }else{
    std::cout << "Unable to locate the file!" << std::endl;
  }
  ifs.close();
  
  std::map<std::string, float> luca;
  TH1F* h2 = new TH1F("h2", "h2", 500, 0.7, 1.3);
  TH2F* h2d_luca = new TH2F("h2d_luca", "h2d_luca", 170, -85, 85, 360, 1, 361);
  std::ifstream ifs2 ("IC_Files/Luca/IC_Ecal_EtaRing_noErr.txt", std::ifstream::in);
  int ctr1 = 0, det = -2;
  double err;
  
  if(ifs2.is_open()){
    while(ifs2.good()){
      if(ifs2.eof())break;
      ifs2 >> s1 >> s2 >> det >> IC >> err;
      if(IC != -1.0 && det == 0){
	luca[s1+" "+s2] = IC;
	h2->Fill(IC);
	h2d_luca->Fill(atoi(s1.c_str()), atoi(s2.c_str()), IC);
      }
      
    }
  }else{
    std::cout << "Unable to locate the file!" << std::endl;
  }
  ifs2.close();
  int ieta, iphi;
  TH1F* diff = new TH1F("diff", "diff", 500, 0.5,1.5);
  TH1F* ratio = new TH1F("ratio", "ratio", 500, 0.5,1.5);
  TH2F* ratio_2d = new TH2F("ratio_2d", "ratio_2d", 170, -85, 85, 360, 1, 361);
  for(std::map<std::string, float>::iterator it = caltech_corr.begin(); it != caltech_corr.end(); ++it){
    std::stringstream ss;
    ss << it->first;
    ss >> ieta >> iphi;
    diff->Fill(it->second - luca[it->first]);
    ratio->Fill(luca[it->first]/it->second);
    ratio_2d->Fill(ieta, iphi, luca[it->first]/it->second);
    if(ieta == 0)std::cout << it->first << " => " << it->second << std::endl;
    //std::cout << "luca: " << luca[it->first] << std::endl;
    //h1->Fill((float)it->second);
  }
  
  
  TFile* f = new TFile("caltech_histo.root", "RECREATE");
  
  h1->Write();
  h1_corr->Write();
  h2d_corr->Write();
  h2->Write();
  h2d_luca->Write();
  diff->Write();
  ratio->Write();
  ratio_2d->Write();
  f->Close();
  
  return 0;
}
