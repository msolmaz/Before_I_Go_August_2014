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
void pile_up_dependence(){
  TFile *file1 =  new TFile("HTo2LongLivedTo4F_MH1000_MFF350_CTau35To3500_analysis_20140504_weighted_2saMu_no_lifetime_extended.root","READ");
  TEfficiency *eff1 =0;
  TEfficiency *eff2 =0;
  TH1F * histo1_all = (TH1F*)file1->Get("before_cosmic_pile_up_finalCollCuts");
  TH1F * histo1_passed = (TH1F*)file1->Get("after_cosmic_pile_up_finalCollCuts");
  eff1 = new TEfficiency(*histo1_passed, *histo1_all);

 c1=new TCanvas();
 eff1->Draw();
c1->Print("eff1.png");
 graph1 = new TGraphAsymmErrors();
 graph1 = eff1->GetPaintedGraph();
graph1->GetYaxis()->SetRangeUser(0, 1.5);

graph1->GetXaxis()->SetTitle("Number of Reconstructed Primary Vertices");
graph1->GetYaxis()->SetTitleOffset(1.2);
graph1->GetYaxis()->SetTitle("Cosmic Rejection Efficiency");
graph1->SetTitle("");
graph1->SetLineColor(4);
c_1 = new TCanvas("c_1", "", 750, 750);
graph1->Draw("AP");
c_1->Print("pileup_cosmic_high_stat.pdf");

TH1F * histo2_all = (TH1F*)file1->Get("before_track_pile_up_finalCollCuts");
  TH1F * histo2_passed = (TH1F*)file1->Get("after_track_pile_up_finalCollCuts");
  eff2 = new TEfficiency(*histo2_passed, *histo2_all);

c2=new TCanvas();
 eff2->Draw();
c2->Print("eff2.png");
 graph2 = new TGraphAsymmErrors();
 graph2 = eff2->GetPaintedGraph();
graph2->GetYaxis()->SetRangeUser(0, 1.5);

graph2->GetXaxis()->SetTitle("Number of Reconstructed Primary Vertices");
graph2->GetYaxis()->SetTitleOffset(1.2);
graph2->GetYaxis()->SetTitle("Track Rejection Efficiency");
graph2->SetTitle("");
graph2->SetLineColor(4);
c_2 = new TCanvas("c_2", "", 750, 750);
graph2->Draw("AP");
c_2->Print("pileup_track_high_stat.pdf");

TFile * file3 = new TFile ("effciency.root", "RECREATE");
eff1->Write();
eff2->Write();
c_1->Write();
c_2->Write();
file3->Close();
}
