#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TLegend.h"

int main(){

  const char* filename = "../Pi0Constants/2012A_NewLaserTag/combineCalibConstant_2012A_newLaserTag.root";//EB FILE
  TFile* file = new TFile(filename);
  
  TH1F* piIC = (TH1F*)file->Get("hh_res_csmallietaTTAbs_0_2");
  TH1F* etaIC = (TH1F*)file->Get("hh_res_csmallietaTTAbs_1_2");
  TH1F* combIC = (TH1F*)file->Get("hh_res_wtavg_csmallietaTTAbs_2");
  
  piIC->SetTitle("");
  piIC->SetStats(0);
  piIC->SetXTitle("Crystal |#eta| index");
  piIC->SetYTitle("#sigma_{c}(%)");
  piIC->GetYaxis()->SetTitleSize(0.05);
  piIC->GetYaxis()->SetTitleOffset(0.95);
  piIC->GetXaxis()->SetTitleSize(0.05);
  piIC->GetXaxis()->SetTitleOffset(0.8);
  piIC->SetMarkerStyle(22);
  piIC->SetMarkerColor(4);
  piIC->SetMarkerSize(1.5);
  piIC->SetLineColor(4);
  piIC->GetYaxis()->SetRangeUser(0.3, 2.2);
  
  etaIC->SetTitle("");
  etaIC->SetStats(0);
  etaIC->SetXTitle("Crystal |#eta| index");
  etaIC->SetYTitle("#sigma_{c}(%)");
  etaIC->GetYaxis()->SetTitleSize(0.05);
  etaIC->GetYaxis()->SetTitleOffset(0.95);
  etaIC->GetXaxis()->SetTitleSize(0.05);
  etaIC->GetXaxis()->SetTitleOffset(0.8);
  etaIC->SetMarkerStyle(22);
  etaIC->SetMarkerColor(2);
  etaIC->SetMarkerSize(1.5);
  etaIC->SetLineColor(2);
  etaIC->GetYaxis()->SetRangeUser(0.3, 2.2);

  combIC->SetTitle("");
  combIC->SetStats(0);
  combIC->SetXTitle("Crystal |#eta| index");
  combIC->SetYTitle("#sigma_{c}(%)");
  combIC->GetYaxis()->SetTitleSize(0.05);
  combIC->GetYaxis()->SetTitleOffset(0.95);
  combIC->GetXaxis()->SetTitleSize(0.05);
  combIC->GetXaxis()->SetTitleOffset(0.8);
  combIC->SetMarkerStyle(22);
  combIC->SetMarkerColor(8);
  combIC->SetMarkerSize(1.5);
  combIC->SetLineColor(8);
  combIC->GetYaxis()->SetRangeUser(0.3, 2.9);

  TCanvas* C0 = new TCanvas("C0", "C0", 1024, 1024);
  combIC->Draw();
  piIC->Draw("same");
  etaIC->Draw("same");
  TLegend* leg = new TLegend(0.6,0.7,0.2,0.89);
  leg->AddEntry(piIC,"#pi^{0}","f");
  leg->AddEntry(etaIC,"#eta","f");
  leg->AddEntry(combIC,"#pi^{0}, #eta combined","f");
  leg->SetHeader("Inter Calibration Precision");
  leg->Draw();
  
  C0->SaveAs("IC_Precision_2012A_EB_NewIC.pdf");
  C0->SaveAs("IC_Precision_2012A_EB_NewIC.png");

  const char* filename1 = "combineCalibConstantEndcapv1_2012D_NewLaserTag_V2_FixedLT.root";//EE FILE
  TFile* file1 = new TFile(filename1);
  
  TH1F* piIC1 = (TH1F*)file1->Get("hh_res_cc_ietaring_0_2_2");
  TH1F* etaIC1 = (TH1F*)file1->Get("hh_res_cc_ietaring_1_2_2");
  TH1F* combIC1 = (TH1F*)file1->Get("hh_res_ccwtavg_ietaring_2_2");
  
  piIC1->SetTitle("");
  piIC1->SetStats(0);
  piIC1->SetXTitle("Crystal |#eta| index");
  piIC1->SetYTitle("#sigma_{c}(%)");
  piIC1->GetYaxis()->SetTitleSize(0.05);
  piIC1->GetYaxis()->SetTitleOffset(0.95);
  piIC1->GetXaxis()->SetTitleSize(0.05);
  piIC1->GetXaxis()->SetTitleOffset(0.8);
  piIC1->SetMarkerStyle(22);
  piIC1->SetMarkerColor(4);
  piIC1->SetMarkerSize(1.5);
  piIC1->SetLineColor(4);
  piIC1->GetYaxis()->SetRangeUser(1.5, 20.);
  
  etaIC1->SetTitle("");
  etaIC1->SetStats(0);
  etaIC1->SetXTitle("Crystal |#eta| index");
  etaIC1->SetYTitle("#sigma_{c}(%)");
  etaIC1->GetYaxis()->SetTitleSize(0.05);
  etaIC1->GetYaxis()->SetTitleOffset(0.95);
  etaIC1->GetXaxis()->SetTitleSize(0.05);
  etaIC1->GetXaxis()->SetTitleOffset(0.8);
  etaIC1->SetMarkerStyle(22);
  etaIC1->SetMarkerColor(2);
  etaIC1->SetMarkerSize(1.5);
  etaIC1->SetLineColor(2);
  etaIC1->GetYaxis()->SetRangeUser(1.5, 20.);

  combIC1->SetTitle("");
  combIC1->SetStats(0);
  combIC1->SetXTitle("Crystal |#eta| index");
  combIC1->SetYTitle("#sigma_{c}(%)");
  combIC1->GetYaxis()->SetTitleSize(0.05);
  combIC1->GetYaxis()->SetTitleOffset(0.95);
  combIC1->GetXaxis()->SetTitleSize(0.05);
  combIC1->GetXaxis()->SetTitleOffset(0.8);
  combIC1->SetMarkerStyle(22);
  combIC1->SetMarkerColor(8);
  combIC1->SetMarkerSize(1.5);
  combIC1->SetLineColor(8);
  combIC1->GetYaxis()->SetRangeUser(1.5, 20.);

  //TCanvas* C0 = new TCanvas("C0", "C0", 1024, 1024);
  combIC1->Draw();
  piIC1->Draw("same");
  etaIC1->Draw("same");
  TLegend* leg1 = new TLegend(0.6,0.7,0.2,0.89);
  leg1->AddEntry(piIC1,"#pi^{0}","f");
  leg1->AddEntry(etaIC1,"#eta","f");
  leg1->AddEntry(combIC1,"#pi^{0}, #eta combined","f");
  leg1->SetHeader("Inter Calibration Precision");
  leg1->Draw();
  
  C0->SaveAs("IC_Precision_2012D_EE_NewIC_FixedLT.pdf");
  C0->SaveAs("IC_Precision_2012D_EE_NewIC_FixedLT.png");
  
  
  
  return 0;

}
