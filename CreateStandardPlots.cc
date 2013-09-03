#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"

int main(){

  const char* filename = "/afs/cern.ch/work/c/cpena/data/2012C_NewTag/deriveCalibConst.dflag2.pe1.step3.iter11.root";
  const char* filename1 = "/afs/cern.ch/work/c/cpena/data/2012C_NewTag/deriveCalibConst.dflag3.pe2.step3.iter11.root";


  TFile* f = new TFile(filename);
  TH1F* Pi_number_pi0 = (TH1F*)f->Get("hh_res_ieta_1");
  TH1F* SB_pi0 = (TH1F*)f->Get("hh_res_ieta_3");
  Pi_number_pi0->Scale(1./720.);
  Pi_number_pi0->SetStats(0);
  Pi_number_pi0->SetTitle("");
  Pi_number_pi0->SetYTitle("Number of #pi^{0} per crystal");
  Pi_number_pi0->SetXTitle("Crystal #eta index");
  Pi_number_pi0->SetMarkerStyle(20);
  Pi_number_pi0->SetMarkerColor(1);
  Pi_number_pi0->GetYaxis()->SetTitleSize(0.05);
  Pi_number_pi0->GetYaxis()->SetTitleOffset(0.95);
  Pi_number_pi0->GetXaxis()->SetTitleSize(0.05);
  Pi_number_pi0->GetXaxis()->SetTitleOffset(0.8);
  Pi_number_pi0->SetBarOffset(-2.5);
  Pi_number_pi0->SetLabelOffset(0.001,  "Y");
  Pi_number_pi0->SetLabelSize( 0.023, "Y");
  Pi_number_pi0->SetMarkerSize(1.5);
  
  TCanvas* C0 = new TCanvas("C0", "C0", 1024, 1024);
  Pi_number_pi0->Draw();
  C0->SaveAs("pi0Number_2012CNewLaserTag.pdf");
  C0->SaveAs("pi0Number_2012CNewLaserTag.png");

  SB_pi0->SetStats(0);
  SB_pi0->SetTitle("");
  SB_pi0->SetYTitle("Signal/Background");
  SB_pi0->SetXTitle("Crystal #eta index");
  SB_pi0->SetMarkerStyle(20);
  SB_pi0->SetMarkerColor(1);
  SB_pi0->SetMarkerSize(1.5);			
  SB_pi0->GetYaxis()->SetTitleSize(0.05);
  SB_pi0->GetYaxis()->SetTitleOffset(0.95);
  SB_pi0->GetXaxis()->SetTitleSize(0.05);
  SB_pi0->GetXaxis()->SetTitleOffset(0.8);
  SB_pi0->Draw();
  C0->SaveAs("SB_pi0NewLaserTag.pdf");
  C0->SaveAs("SB_pi0NewLaserTag.png");
  
  TFile* f1 = new TFile(filename1);
  TH1F* Pi_number_Eta = (TH1F*)f1->Get("hh_res_ieta_1");
  TH1F* SB_Eta = (TH1F*)f1->Get("hh_res_ieta_3");
  Pi_number_Eta->Scale(1./720.);
  Pi_number_Eta->SetStats(0);
  Pi_number_Eta->SetTitle("");
  Pi_number_Eta->SetYTitle("Number of #eta per crystal");
  Pi_number_Eta->SetXTitle("Crystal #eta index");
  Pi_number_Eta->SetMarkerStyle(20);
  Pi_number_Eta->SetMarkerColor(1);
  Pi_number_Eta->GetYaxis()->SetTitleSize(0.05);
  Pi_number_Eta->GetYaxis()->SetTitleOffset(0.95);
  Pi_number_Eta->GetXaxis()->SetTitleSize(0.05);
  Pi_number_Eta->GetXaxis()->SetTitleOffset(0.8);
  Pi_number_Eta->SetBarOffset(-2.5);
  Pi_number_Eta->SetLabelOffset(0.001,  "Y");
  Pi_number_Eta->SetLabelSize( 0.023, "Y");
  Pi_number_Eta->SetMarkerSize(1.5);
  
  //TCanvas* C0 = new TCanvas("C0", "C0", 1024, 1024);
  Pi_number_Eta->Draw();
  C0->SaveAs("Eta0Number_2012CNewLaserTag.pdf");
  C0->SaveAs("Eta0Number_2012CNewLaserTag.png");

  SB_Eta->SetStats(0);
  SB_Eta->SetTitle("");
  SB_Eta->SetYTitle("Signal/Background");
  SB_Eta->SetXTitle("Crystal #eta index");
  SB_Eta->SetMarkerStyle(20);
  SB_Eta->SetMarkerColor(1);
  SB_Eta->SetMarkerSize(1.5);			
  SB_Eta->GetYaxis()->SetTitleSize(0.05);
  SB_Eta->GetYaxis()->SetTitleOffset(0.95);
  SB_Eta->GetXaxis()->SetTitleSize(0.05);
  SB_Eta->GetXaxis()->SetTitleOffset(0.8);
  SB_Eta->Draw();
  C0->SaveAs("SB_eta0NewLaserTag.pdf");
  C0->SaveAs("SB_eta0NewLaserTag.png");
  
  return 0;
}
