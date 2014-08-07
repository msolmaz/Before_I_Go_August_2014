#include <iostream> 
#include "TH1.h" 
#include "TH2.h"
#include "TFile.h"
#include "TString.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "TLegend.h"

using namespace std;
void trigger_efficiency_vs_Lxy(){
  //file = ROOT.TFile("trigEff.root","RECREATE")
//  gROOT->SetBatch(True);
    gStyle->SetFillColor(0);
// cout << "Bonjour "<<endl;
  TFile *file1 =  new TFile("/uscms_data/d3/msolmaz/myworkingspace/phys_698_spring_2014/CMSSW_5_3_8/src/AnalysisMacros/MuonHits_Signal_Check_May_31/WeightedFiles/HTo2LongLivedTo4F_MH1000_MFF350_CTau35To3500_analysis_20140530_weighted_2saMu.root","READ");
//  TEfficiency *eff1=0;
//  TEfficiency *eff2;
//  TEfficiency *eff3;
// cout << " Hola " << endl;
  TH1F * histo1_all = (TH1F*)file1->Get("gen_lxy_all_DecayMode_withinAcc");
//  cout << histo1_all << endl;
  TH1F * histo1_passed = (TH1F*)file1->Get("gen_lxy_all_DecayMode_withinAcc_trigFired");
//  histo1_passed->Rebin(2);
//  histo1_all->Rebin(2);
//  cout << "all = " << histo1_all;
//  cout << "passed = " << histo1_passed;
  //histo1_all_clone = histo1_all.Clone("histo1_all")
  //histo1_passed_clone = histo1_passed.Clone("histo1_passed")
// cout << " Italia " << endl;
  TEfficiency *eff1 = new TEfficiency(*histo1_passed, *histo1_all);
  eff1->SetTitle("; generated L_{xy} [cm]; Trigger Efficiency");
  eff1->SetLineColor(1);
//  eff1->SetMarkerColor(1);
//  eff1->SetMarkerStyle(2);
//  c1->Print("trig_eff1.png");
//  TGraphAsymmErrors *graph1 = new TGraphAsymmErrors();
//  graph1 = eff1->GetPaintedGraph();
//  graph1->GetYaxis()->SetRangeUser(0, 1.0);

//  graph1->GetXaxis()->SetTitle("L_{xy} [cm] (gen)");
//  graph1->GetYaxis()->SetTitle("Trigger Efficiency");
//  graph1->SetLineColor(1);

  TFile * file2 = new TFile("/uscms_data/d3/msolmaz/myworkingspace/phys_698_spring_2014/CMSSW_5_3_8/src/AnalysisMacros/MuonHits_Signal_Check_May_31/WeightedFiles/HTo2LongLivedTo4F_MH400_MFF150_CTau40To4000_analysis_20140602_weighted_2saMu.root","READ");


  TH1F * histo2_all = (TH1F*)file2->Get("gen_lxy_all_DecayMode_withinAcc");
  TH1F * histo2_passed = (TH1F*)file2->Get("gen_lxy_all_DecayMode_withinAcc_trigFired");
//  histo2_passed->Rebin(2);
//  histo2_all->Rebin(2);
  //histo1_all_clone = histo1_all.Clone("histo1_all")
  //histo1_passed_clone = histo1_passed.Clone("histo1_passed")
  TEfficiency *eff2 = new TEfficiency(*histo2_passed, *histo2_all);
//  cout << " Lala " << endl;
  eff2->SetLineColor(2);
//  eff2->SetMarkerColor(2);
//  eff2->SetMarkerStyle(3);

  TFile * file3 = new TFile("/uscms_data/d3/msolmaz/myworkingspace/phys_698_spring_2014/CMSSW_5_3_8/src/AnalysisMacros/MuonHits_Signal_Check_May_31/WeightedFiles/HTo2LongLivedTo4F_MH125_MFF50_CTau50To5000_analysis_20140602_weighted_2saMu.root","READ");

  TH1F * histo3_all = (TH1F*)file3->Get("gen_lxy_all_DecayMode_withinAcc");
  TH1F * histo3_passed = (TH1F*)file3->Get("gen_lxy_all_DecayMode_withinAcc_trigFired");
//  histo3_passed->Rebin(2);
//  histo3_all->Rebin(2);
  //histo1_all_clone = histo1_all.Clone("histo1_all")
  //histo1_passed_clone = histo1_passed.Clone("histo1_passed")
  TEfficiency *eff3 = new TEfficiency(*histo3_passed, *histo3_all);
//  cout << " Italia "<< endl;
  eff3->SetTitle("; generated L_{xy} [cm]; Trigger Efficiency");
  eff3->SetLineColor(4);
//  eff3->SetMarkerColor(3);
//  eff3->SetMarkerStyle(4);

  TLegend *leg = new TLegend(0.5,0.5,0.85,0.85);
  leg->SetFillColor(0);
  leg->SetLineColor(0);
  leg->AddEntry(eff1, "M_{H} = 1000 GeV/c^{2}, M_{X} = 350 GeV/c^{2}");
  leg->AddEntry(eff2, "M_{H} = 400 GeV/c^{2}, M_{X} = 150 GeV/c^{2}");
  leg->AddEntry(eff3, "M_{H} = 125 GeV/c^{2}, M_{X} = 50 GeV/c^{2}");

  TCanvas *c1=new TCanvas("c1", "", 500, 500);
  eff1->Draw();
  eff2->Draw("SAME");
  eff3->Draw("SAME");
  leg->Draw("P");
  c1->SaveAs("trig_eff_vs_lxy_3_samples.pdf");


/*
TFile * file4 = new TFile("/uscms_data/d3/msolmaz/myworkingspace/phys_590_summer_2013/CMSSW_5_3_8/src/AnalysisMacros/DileptonMacros/WeightedFiles/minAbsD0Sig5_cut/HTo2LongLivedTo4F_MH1000_MFF50_CTau4To400_analysis_20130509_weighted_2saMu.root","READ");

  TEfficiency *eff4 =0;

  TH1F * histo4_all = (TH1F*)file4->Get("trig_Lxy_all");
  TH1F * histo4_passed = (TH1F*)file4->Get("trig_Lxy_pass");
  //histo1_all_clone = histo1_all.Clone("histo1_all")
  //histo1_passed_clone = histo1_passed.Clone("histo1_passed")
  eff4 = new TEfficiency(*histo4_passed, *histo4_all);

 c4 = new TCanvas();
 eff4->Draw();
 c4->Print("trig_eff4.png");
 graph4 = new TGraphAsymmErrors();
 graph4 = eff4->GetPaintedGraph();

graph4->GetYaxis()->SetRangeUser(0, 1.0);
graph4->GetXaxis()->SetTitle("L_{xy} [cm]");
graph4->GetYaxis()->SetTitle("Trigger Efficiency");
graph4->SetLineColor(4);
c_4 = new TCanvas();
graph4->Draw("AP");
c_4->Print("trigeff_MH1000_MFF50.png");

TFile * file5 = new TFile("/uscms_data/d3/msolmaz/myworkingspace/phys_590_summer_2013/CMSSW_5_3_8/src/AnalysisMacros/DileptonMacros/WeightedFiles/minAbsD0Sig5_cut/HTo2LongLivedTo4F_MH400_MFF50_CTau8To800_analysis_20130509_weighted_2saMu.root","READ");


  TEfficiency *eff5 =0;
  TH1F * histo5_all = (TH1F*)file5->Get("trig_Lxy_all");
  TH1F * histo5_passed = (TH1F*)file5->Get("trig_Lxy_pass");
  //histo1_all_clone = histo1_all.Clone("histo1_all")
  //histo1_passed_clone = histo1_passed.Clone("histo1_passed")
  eff5 = new TEfficiency(*histo5_passed, *histo5_all);

 c5 = new TCanvas();
 eff5->Draw();
 c5->Print("trig_eff5.png");
 graph5 = new TGraphAsymmErrors();
 graph5 = eff5->GetPaintedGraph();

graph5->GetYaxis()->SetRangeUser(0, 1.0);
graph5->GetXaxis()->SetTitle("L_{xy} [cm]");
graph5->GetYaxis()->SetTitle("Trigger Efficiency");
graph5->SetLineColor(4);
c_5 = new TCanvas();
graph5->Draw("AP");
c_5->Print("trigeff_MH400_MFF50.png");



TFile * file6 = new TFile("/uscms_data/d3/msolmaz/myworkingspace/phys_590_summer_2013/CMSSW_5_3_8/src/AnalysisMacros/DileptonMacros/WeightedFiles/minAbsD0Sig5_cut/HTo2LongLivedTo4F_MH200_MFF50_CTau20To2000_analysis_20130509_weighted_2saMu.root","READ");


  TEfficiency *eff6 =0;
  TH1F * histo6_all = (TH1F*)file6->Get("trig_Lxy_all");
  TH1F * histo6_passed = (TH1F*)file6->Get("trig_Lxy_pass");
  //histo1_all_clone = histo1_all.Clone("histo1_all")
  //histo1_passed_clone = histo1_passed.Clone("histo1_passed")
  eff6 = new TEfficiency(*histo6_passed, *histo6_all);

 c6 = new TCanvas();
 eff6->Draw();
 c6->Print("trig_eff6.png");
 graph6 = new TGraphAsymmErrors();
 graph6 = eff6->GetPaintedGraph();

graph6->GetYaxis()->SetRangeUser(0, 1.0);
graph6->GetXaxis()->SetTitle("L_{xy} [cm]");
graph6->GetYaxis()->SetTitle("Trigger Efficiency");
graph6->SetLineColor(4);
c_6 = new TCanvas();
graph6->Draw("AP");
c_6->Print("trigeff_MH200_MFF50.png");


TFile * file7 = new TFile("/uscms_data/d3/msolmaz/myworkingspace/phys_590_summer_2013/CMSSW_5_3_8/src/AnalysisMacros/DileptonMacros/WeightedFiles/minAbsD0Sig5_cut/HTo2LongLivedTo4F_MH125_MFF50_CTau50To5000_analysis_20130509_weighted_2saMu.root","READ");


  TEfficiency *eff7 =0;
  TH1F * histo7_all = (TH1F*)file7->Get("trig_Lxy_all");
  TH1F * histo7_passed = (TH1F*)file7->Get("trig_Lxy_pass");
  //histo1_all_clone = histo1_all.Clone("histo1_all")
  //histo1_passed_clone = histo1_passed.Clone("histo1_passed")
  eff7 = new TEfficiency(*histo7_passed, *histo7_all);

 c7 = new TCanvas();
 eff7->Draw();
 c7->Print("trig_eff7.png");
 graph7 = new TGraphAsymmErrors();
 graph7 = eff7->GetPaintedGraph();

graph7->GetYaxis()->SetRangeUser(0, 1.0);
graph7->GetXaxis()->SetTitle("L_{xy} [cm]");
graph7->GetYaxis()->SetTitle("Trigger Efficiency");
graph7->SetLineColor(4);
c_7 = new TCanvas();
graph7->Draw("AP");
c_7->Print("trigeff_MH125_MFF50.png");

TFile * file8 = new TFile("/uscms_data/d3/msolmaz/myworkingspace/phys_590_summer_2013/CMSSW_5_3_8/src/AnalysisMacros/DileptonMacros/WeightedFiles/minAbsD0Sig5_cut/HTo2LongLivedTo4F_MH1000_MFF20_CTau1p5To150_analysis_20130509_weighted_2saMu.root","READ");


  TEfficiency *eff8 =0;
  TH1F * histo8_all = (TH1F*)file8->Get("trig_Lxy_all");
  TH1F * histo8_passed = (TH1F*)file8->Get("trig_Lxy_pass");
  //histo1_all_clone = histo1_all.Clone("histo1_all")
  //histo1_passed_clone = histo1_passed.Clone("histo1_passed")
  eff8 = new TEfficiency(*histo8_passed, *histo8_all);

 c8 = new TCanvas();
 eff8->Draw();
 c8->Print("trig_eff8.png");
 graph8 = new TGraphAsymmErrors();
 graph8 = eff8->GetPaintedGraph();

graph8->GetYaxis()->SetRangeUser(0, 1.0);
graph8->GetXaxis()->SetTitle("L_{xy} [cm]");
graph8->GetYaxis()->SetTitle("Trigger Efficiency");
graph8->SetLineColor(4);
c_8 = new TCanvas();
graph8->Draw("AP");
c_8->Print("trigeff_MH1000_MFF20.png");

TFile * file9 = new TFile("/uscms_data/d3/msolmaz/myworkingspace/phys_590_summer_2013/CMSSW_5_3_8/src/AnalysisMacros/DileptonMacros/WeightedFiles/minAbsD0Sig5_cut/HTo2LongLivedTo4F_MH400_MFF20_CTau4To400_analysis_20130509_weighted_2saMu.root","READ");


  TEfficiency *eff9 =0;
  TH1F * histo9_all = (TH1F*)file9->Get("trig_Lxy_all");
  TH1F * histo9_passed = (TH1F*)file9->Get("trig_Lxy_pass");
  //histo1_all_clone = histo1_all.Clone("histo1_all")
  //histo1_passed_clone = histo1_passed.Clone("histo1_passed")
  eff9 = new TEfficiency(*histo9_passed, *histo9_all);

 c9 = new TCanvas();
 eff9->Draw();
 c9->Print("trig_eff9.png");
 graph9 = new TGraphAsymmErrors();
 graph9 = eff9->GetPaintedGraph();

graph9->GetYaxis()->SetRangeUser(0, 1.0);
graph9->GetXaxis()->SetTitle("L_{xy} [cm]");
graph9->GetYaxis()->SetTitle("Trigger Efficiency");
graph9->SetLineColor(4);
c_9 = new TCanvas();
graph9->Draw("AP");
c_9->Print("trigeff_MH400_MFF20.png");

TFile * file10 = new TFile("/uscms_data/d3/msolmaz/myworkingspace/phys_590_summer_2013/CMSSW_5_3_8/src/AnalysisMacros/DileptonMacros/WeightedFiles/minAbsD0Sig5_cut/HTo2LongLivedTo4F_MH200_MFF20_CTau7To700_analysis_20130509_weighted_2saMu.root","READ");


  TEfficiency *eff10 =0;
  TH1F * histo10_all = (TH1F*)file10->Get("trig_Lxy_all");
  TH1F * histo10_passed = (TH1F*)file10->Get("trig_Lxy_pass");
  //histo1_all_clone = histo1_all.Clone("histo1_all")
  //histo1_passed_clone = histo1_passed.Clone("histo1_passed")
  eff10 = new TEfficiency(*histo10_passed, *histo10_all);

 c10 = new TCanvas();
 eff10->Draw();
 c10->Print("trig_eff10.png");
 graph10 = new TGraphAsymmErrors();
 graph10 = eff10->GetPaintedGraph();

graph10->GetYaxis()->SetRangeUser(0, 1.0);
graph10->GetXaxis()->SetTitle("L_{xy} [cm]");
graph10->GetYaxis()->SetTitle("Trigger Efficiency");
graph10->SetLineColor(4);
c_10 = new TCanvas();
graph10->Draw("AP");
c_10->Print("trigeff_MH200_MFF20.png");

TFile * file11 = new TFile("/uscms_data/d3/msolmaz/myworkingspace/phys_590_summer_2013/CMSSW_5_3_8/src/AnalysisMacros/DileptonMacros/WeightedFiles/minAbsD0Sig5_cut/HTo2LongLivedTo4F_MH125_MFF20_CTau13To1300_analysis_20130509_weighted_2saMu.root","READ");


  TEfficiency *eff11 =0;
  TH1F * histo11_all = (TH1F*)file11->Get("trig_Lxy_all");
  TH1F * histo11_passed = (TH1F*)file11->Get("trig_Lxy_pass");
  //histo1_all_clone = histo1_all.Clone("histo1_all")
  //histo1_passed_clone = histo1_passed.Clone("histo1_passed")
  eff11 = new TEfficiency(*histo11_passed, *histo11_all);

 c11 = new TCanvas();
 eff11->Draw();
 c11->Print("trig_eff11.png");
 graph11 = new TGraphAsymmErrors();
 graph11 = eff11->GetPaintedGraph();

graph11->GetYaxis()->SetRangeUser(0, 1.0);
graph11->GetXaxis()->SetTitle("L_{xy} [cm]");
graph11->GetYaxis()->SetTitle("Trigger Efficiency");
graph11->SetLineColor(4);
c_11 = new TCanvas();
graph11->Draw("AP");
c_11->Print("trigeff_MH125_MFF20.png");
*/

}
