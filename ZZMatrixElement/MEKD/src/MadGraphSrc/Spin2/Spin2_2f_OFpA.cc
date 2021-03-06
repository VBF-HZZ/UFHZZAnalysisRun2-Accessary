//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 2.0.2, 2014-02-07
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "Spin2_2f_OFpA.h"
#include "../HelAmps_HEF_MEKD2_1.h"	// Changed by Convert_source 0.2

using namespace MG5_HEF_MEKD2_1;

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: xg > e- e+ mu- mu+ a S2QQ=1 / h zp

//--------------------------------------------------------------------------
// Initialize process.

void Spin2_2f_OFpA::initProc(string param_card_name) 
{
  // Instantiate the model class and set parameters that stay fixed during run
  pars = Parameters_MEKD::getInstance();	// Changed by Convert_source 0.2 
  SLHAReader_MEKD slha(param_card_name);
  pars->setIndependentParameters(slha);
  pars->setIndependentCouplings();
	ntry = 0, sum_hel = 0, ngood = 0;	// Moved here by Convert_source 0.2
  // Set external particle masses for this matrix element
  mME.push_back(pars->MXG);
  mME.push_back(pars->Me);
  mME.push_back(pars->Me);
  mME.push_back(pars->MM);
  mME.push_back(pars->MM);
  mME.push_back(pars->ZERO);
  jamp2[0] = new double[1];
	for( int count=0; count<namplitudes; count++ ) amp[count] = 0;
}

//--------------------------------------------------------------------------
// Update process.	// Created here by Convert_source 0.2

void Spin2_2f_OFpA::updateProc(SLHAReader_MEKD &slha)
{
	pars->setIndependentParameters(slha);
	pars->setIndependentCouplings();
	ntry = 0, sum_hel = 0, ngood = 0;	// needed when altering couplings
	
	// Set external particle masses for this matrix element
	// Should correspond to initProc
	mME[0]=(pars->MXG);
	mME[1]=(pars->Me);
	mME[2]=(pars->Me);
	mME[3]=(pars->MM);
	mME[4]=(pars->MM);
	mME[5]=(pars->ZERO);
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void Spin2_2f_OFpA::sigmaKin() 
{
  // Set the parameters which change event by event
  pars->setDependentParameters();
  pars->setDependentCouplings();
	// Deleted by Convert_source 0.2
	
  // Reset color flows
  for(int i = 0;i < 1;i++ )
    jamp2[0][i] = 0.;

  // Local variables and constants
  const int ncomb = 160;
  static bool goodhel[ncomb] = {ncomb * false};
//	static int ntry = 0, sum_hel = 0, ngood = 0;	// Moved by Convert_source 0.2
  static int igood[ncomb];
  static int jhel;
//	std::complex<double> * * wfs;	// Changed by Convert_source 0.2
  double t[nprocesses];
  // Helicities for the process
  static const int helicities[ncomb][nexternal] = {{-2, -1, -1, -1, -1, -1},
      {-2, -1, -1, -1, -1, 1}, {-2, -1, -1, -1, 1, -1}, {-2, -1, -1, -1, 1, 1},
      {-2, -1, -1, 1, -1, -1}, {-2, -1, -1, 1, -1, 1}, {-2, -1, -1, 1, 1, -1},
      {-2, -1, -1, 1, 1, 1}, {-2, -1, 1, -1, -1, -1}, {-2, -1, 1, -1, -1, 1},
      {-2, -1, 1, -1, 1, -1}, {-2, -1, 1, -1, 1, 1}, {-2, -1, 1, 1, -1, -1},
      {-2, -1, 1, 1, -1, 1}, {-2, -1, 1, 1, 1, -1}, {-2, -1, 1, 1, 1, 1}, {-2,
      1, -1, -1, -1, -1}, {-2, 1, -1, -1, -1, 1}, {-2, 1, -1, -1, 1, -1}, {-2,
      1, -1, -1, 1, 1}, {-2, 1, -1, 1, -1, -1}, {-2, 1, -1, 1, -1, 1}, {-2, 1,
      -1, 1, 1, -1}, {-2, 1, -1, 1, 1, 1}, {-2, 1, 1, -1, -1, -1}, {-2, 1, 1,
      -1, -1, 1}, {-2, 1, 1, -1, 1, -1}, {-2, 1, 1, -1, 1, 1}, {-2, 1, 1, 1,
      -1, -1}, {-2, 1, 1, 1, -1, 1}, {-2, 1, 1, 1, 1, -1}, {-2, 1, 1, 1, 1, 1},
      {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, 1}, {-1, -1, -1, -1, 1,
      -1}, {-1, -1, -1, -1, 1, 1}, {-1, -1, -1, 1, -1, -1}, {-1, -1, -1, 1, -1,
      1}, {-1, -1, -1, 1, 1, -1}, {-1, -1, -1, 1, 1, 1}, {-1, -1, 1, -1, -1,
      -1}, {-1, -1, 1, -1, -1, 1}, {-1, -1, 1, -1, 1, -1}, {-1, -1, 1, -1, 1,
      1}, {-1, -1, 1, 1, -1, -1}, {-1, -1, 1, 1, -1, 1}, {-1, -1, 1, 1, 1, -1},
      {-1, -1, 1, 1, 1, 1}, {-1, 1, -1, -1, -1, -1}, {-1, 1, -1, -1, -1, 1},
      {-1, 1, -1, -1, 1, -1}, {-1, 1, -1, -1, 1, 1}, {-1, 1, -1, 1, -1, -1},
      {-1, 1, -1, 1, -1, 1}, {-1, 1, -1, 1, 1, -1}, {-1, 1, -1, 1, 1, 1}, {-1,
      1, 1, -1, -1, -1}, {-1, 1, 1, -1, -1, 1}, {-1, 1, 1, -1, 1, -1}, {-1, 1,
      1, -1, 1, 1}, {-1, 1, 1, 1, -1, -1}, {-1, 1, 1, 1, -1, 1}, {-1, 1, 1, 1,
      1, -1}, {-1, 1, 1, 1, 1, 1}, {0, -1, -1, -1, -1, -1}, {0, -1, -1, -1, -1,
      1}, {0, -1, -1, -1, 1, -1}, {0, -1, -1, -1, 1, 1}, {0, -1, -1, 1, -1,
      -1}, {0, -1, -1, 1, -1, 1}, {0, -1, -1, 1, 1, -1}, {0, -1, -1, 1, 1, 1},
      {0, -1, 1, -1, -1, -1}, {0, -1, 1, -1, -1, 1}, {0, -1, 1, -1, 1, -1}, {0,
      -1, 1, -1, 1, 1}, {0, -1, 1, 1, -1, -1}, {0, -1, 1, 1, -1, 1}, {0, -1, 1,
      1, 1, -1}, {0, -1, 1, 1, 1, 1}, {0, 1, -1, -1, -1, -1}, {0, 1, -1, -1,
      -1, 1}, {0, 1, -1, -1, 1, -1}, {0, 1, -1, -1, 1, 1}, {0, 1, -1, 1, -1,
      -1}, {0, 1, -1, 1, -1, 1}, {0, 1, -1, 1, 1, -1}, {0, 1, -1, 1, 1, 1}, {0,
      1, 1, -1, -1, -1}, {0, 1, 1, -1, -1, 1}, {0, 1, 1, -1, 1, -1}, {0, 1, 1,
      -1, 1, 1}, {0, 1, 1, 1, -1, -1}, {0, 1, 1, 1, -1, 1}, {0, 1, 1, 1, 1,
      -1}, {0, 1, 1, 1, 1, 1}, {1, -1, -1, -1, -1, -1}, {1, -1, -1, -1, -1, 1},
      {1, -1, -1, -1, 1, -1}, {1, -1, -1, -1, 1, 1}, {1, -1, -1, 1, -1, -1},
      {1, -1, -1, 1, -1, 1}, {1, -1, -1, 1, 1, -1}, {1, -1, -1, 1, 1, 1}, {1,
      -1, 1, -1, -1, -1}, {1, -1, 1, -1, -1, 1}, {1, -1, 1, -1, 1, -1}, {1, -1,
      1, -1, 1, 1}, {1, -1, 1, 1, -1, -1}, {1, -1, 1, 1, -1, 1}, {1, -1, 1, 1,
      1, -1}, {1, -1, 1, 1, 1, 1}, {1, 1, -1, -1, -1, -1}, {1, 1, -1, -1, -1,
      1}, {1, 1, -1, -1, 1, -1}, {1, 1, -1, -1, 1, 1}, {1, 1, -1, 1, -1, -1},
      {1, 1, -1, 1, -1, 1}, {1, 1, -1, 1, 1, -1}, {1, 1, -1, 1, 1, 1}, {1, 1,
      1, -1, -1, -1}, {1, 1, 1, -1, -1, 1}, {1, 1, 1, -1, 1, -1}, {1, 1, 1, -1,
      1, 1}, {1, 1, 1, 1, -1, -1}, {1, 1, 1, 1, -1, 1}, {1, 1, 1, 1, 1, -1},
      {1, 1, 1, 1, 1, 1}, {2, -1, -1, -1, -1, -1}, {2, -1, -1, -1, -1, 1}, {2,
      -1, -1, -1, 1, -1}, {2, -1, -1, -1, 1, 1}, {2, -1, -1, 1, -1, -1}, {2,
      -1, -1, 1, -1, 1}, {2, -1, -1, 1, 1, -1}, {2, -1, -1, 1, 1, 1}, {2, -1,
      1, -1, -1, -1}, {2, -1, 1, -1, -1, 1}, {2, -1, 1, -1, 1, -1}, {2, -1, 1,
      -1, 1, 1}, {2, -1, 1, 1, -1, -1}, {2, -1, 1, 1, -1, 1}, {2, -1, 1, 1, 1,
      -1}, {2, -1, 1, 1, 1, 1}, {2, 1, -1, -1, -1, -1}, {2, 1, -1, -1, -1, 1},
      {2, 1, -1, -1, 1, -1}, {2, 1, -1, -1, 1, 1}, {2, 1, -1, 1, -1, -1}, {2,
      1, -1, 1, -1, 1}, {2, 1, -1, 1, 1, -1}, {2, 1, -1, 1, 1, 1}, {2, 1, 1,
      -1, -1, -1}, {2, 1, 1, -1, -1, 1}, {2, 1, 1, -1, 1, -1}, {2, 1, 1, -1, 1,
      1}, {2, 1, 1, 1, -1, -1}, {2, 1, 1, 1, -1, 1}, {2, 1, 1, 1, 1, -1}, {2,
      1, 1, 1, 1, 1}};
  // Denominators: spins, colors and identical particles
  const int denominators[nprocesses] = {5};

  ntry = ntry + 1;

  // Reset the matrix elements
  for(int i = 0;i < nprocesses;i++ )
  {
    matrix_element[i] = 0.;
  }
  // Define permutation
  int perm[nexternal];
  for(int i = 0;i < nexternal;i++ )
  {
    perm[i] = i;
  }

  if (sum_hel == 0 || ntry < 10)
  {
    // Calculate the matrix element for all helicities
    for(int ihel = 0;ihel < ncomb;ihel++ )
    {
      if (goodhel[ihel] || ntry < 2)
      {
        calculate_wavefunctions(perm, helicities[ihel]);
        t[0] = matrix_xg_emepmummupa_no_hzp();

        double tsum = 0;
        for(int iproc = 0;iproc < nprocesses;iproc++ )
        {
          matrix_element[iproc] += t[iproc];
          tsum += t[iproc];
        }
        // Store which helicities give non-zero result
        if (tsum != 0. && !goodhel[ihel])
        {
          goodhel[ihel] = true;
          ngood++;
          igood[ngood] = ihel;
        }
      }
    }
    jhel = 0;
    sum_hel = min(sum_hel, ngood);
  }
  else
  {
    // Only use the "good" helicities
    for(int j = 0;j < sum_hel;j++ )
    {
      jhel++;
      if (jhel >= ngood)
        jhel = 0;
      double hwgt = double(ngood)/double(sum_hel);
      int ihel = igood[jhel];
      calculate_wavefunctions(perm, helicities[ihel]);
      t[0] = matrix_xg_emepmummupa_no_hzp();

      for(int iproc = 0;iproc < nprocesses;iproc++ )
      {
        matrix_element[iproc] += t[iproc] * hwgt;
      }
    }
  }

  for (int i = 0;i < nprocesses;i++ )
    matrix_element[i] /= denominators[i];



}

//--------------------------------------------------------------------------
// Evaluate |M|^2, including incoming flavour dependence.

double Spin2_2f_OFpA::sigmaHat() 
{
  // Select between the different processes
  if(id1 == 9000007 && id2 == 11)
  {
    // Add matrix elements for processes with beams (9000007, 11)
    return matrix_element[0];
  }
  else
  {
    // Return 0 if not correct initial state assignment
    return 0.;
  }
}

//==========================================================================
// Private class member functions

//--------------------------------------------------------------------------
// Evaluate |M|^2 for each subprocess

void Spin2_2f_OFpA::calculate_wavefunctions(const int perm[], const int hel[])
{
  // Calculate wavefunctions for all processes
//	int i, j;	// Changed by Convert_source 0.2

  // Calculate all wavefunctions
  txxxxx(p[perm[0]], mME[0], hel[0], -1, w[0]);
  oxxxxx(p[perm[1]], mME[1], hel[1], +1, w[1]);
  ixxxxx(p[perm[2]], mME[2], hel[2], -1, w[2]);
  oxxxxx(p[perm[3]], mME[3], hel[3], +1, w[3]);
  ixxxxx(p[perm[4]], mME[4], hel[4], -1, w[4]);
  vxxxxx(p[perm[5]], mME[5], hel[5], +1, w[5]);
  FFV2P0_3(w[2], w[1], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[6]);
  FFV2_1(w[3], w[6], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[7]);
  FFV2_1(w[7], w[5], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[8]);
  FFV2_2(w[4], w[6], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[9]);
  FFV2_2(w[9], w[5], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[10]);
  FFV5_7_3(w[2], w[1], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[11]);
  FFV5_7_1(w[3], w[11], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[12]);
  FFV2_1(w[12], w[5], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[13]);
  FFV5_7_2(w[4], w[11], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[14]);
  FFV2_2(w[14], w[5], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[15]);
  FFV2_1(w[3], w[5], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[16]);
  FFV2_1(w[16], w[6], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[17]);
  FFV5_7_1(w[16], w[11], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[18]);
  FFV5_7_3(w[4], w[16], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[19]);
  FFV2_2(w[4], w[5], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[20]);
  FFV2_2(w[20], w[6], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[21]);
  FFV5_7_2(w[20], w[11], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[22]);
  FFV5_7_3(w[20], w[3], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[23]);
  FFV2_1(w[1], w[5], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[24]);
  FFV2P0_3(w[2], w[24], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[25]);
  FFV2_1(w[3], w[25], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[26]);
  FFV2_2(w[4], w[25], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[27]);
  FFV5_7_3(w[2], w[24], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[28]);
  FFV5_7_1(w[3], w[28], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[29]);
  FFV5_7_2(w[4], w[28], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[30]);
  FFV2P0_3(w[4], w[3], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[31]);
  FFV2_1(w[24], w[31], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[32]);
  FFV2_2(w[2], w[31], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[33]);
  FFV5_7_3(w[4], w[3], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[34]);
  FFV5_7_1(w[24], w[34], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->Me, pars->ZERO,
      w[35]);
  FFV5_7_2(w[2], w[34], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->Me, pars->ZERO,
      w[36]);
  FFV2_2(w[2], w[5], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[37]);
  FFV2P0_3(w[37], w[1], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[38]);
  FFV2_1(w[3], w[38], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[39]);
  FFV2_2(w[4], w[38], pars->HEF_MEKD2_1_GC_5, pars->MM, pars->ZERO, w[40]);
  FFV5_7_3(w[37], w[1], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MZ, pars->WZ, w[41]);
  FFV5_7_1(w[3], w[41], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[42]);
  FFV5_7_2(w[4], w[41], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->MM, pars->ZERO,
      w[43]);
  FFV2_1(w[1], w[31], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[44]);
  FFV2_2(w[37], w[31], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[45]);
  FFV5_7_1(w[1], w[34], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->Me, pars->ZERO,
      w[46]);
  FFV5_7_2(w[37], w[34], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->Me, pars->ZERO,
      w[47]);
  FFV2_1(w[44], w[5], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[48]);
  FFV2_2(w[33], w[5], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[49]);
  FFV2_1(w[46], w[5], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[50]);
  FFV2_2(w[36], w[5], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[51]);
  FFV2P0_3(w[4], w[16], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[52]);
  FFV2_1(w[1], w[52], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[53]);
  FFV2_2(w[2], w[52], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[54]);
  FFV5_7_1(w[1], w[19], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->Me, pars->ZERO,
      w[55]);
  FFV5_7_2(w[2], w[19], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->Me, pars->ZERO,
      w[56]);
  FFV2P0_3(w[20], w[3], pars->HEF_MEKD2_1_GC_5, pars->ZERO, pars->ZERO, w[57]);
  FFV2_1(w[1], w[57], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[58]);
  FFV2_2(w[2], w[57], pars->HEF_MEKD2_1_GC_5, pars->Me, pars->ZERO, w[59]);
  FFV5_7_1(w[1], w[23], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->Me, pars->ZERO,
      w[60]);
  FFV5_7_2(w[2], w[23], pars->HEF_MEKD2_1_GC_181, pars->HEF_MEKD2_1_GC_188, pars->Me, pars->ZERO,
      w[61]);

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  FFT1_2_3_5_0(w[4], w[8], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[0]);
  FFT1_2_3_5_0(w[10], w[3], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[1]);
  FFT1_2_3_5_0(w[4], w[13], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[2]);
  FFT1_2_3_5_0(w[15], w[3], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[3]);
  FFT1_2_3_5_0(w[4], w[17], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[4]);
  FFT1_2_3_5_0(w[9], w[16], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[5]);
  FFT1_2_3_5_0(w[4], w[18], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[6]);
  FFT1_2_3_5_0(w[14], w[16], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[7]);
//   VVT10_11_12_13_2_3_6_7_8_9_0(w[11], w[19], w[0], pars->HEF_MEKD2_1_GC_75, pars->HEF_MEKD2_1_GC_81,
//       pars->HEF_MEKD2_1_GC_67, pars->HEF_MEKD2_1_GC_71, pars->HEF_MEKD2_1_GC_90, pars->HEF_MEKD2_1_GC_92, pars->HEF_MEKD2_1_GC_63,
//       pars->HEF_MEKD2_1_GC_85, pars->HEF_MEKD2_1_GC_79, pars->HEF_MEKD2_1_GC_83, amp[8]);	// ZZ
  FFT1_2_3_5_0(w[20], w[7], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[9]);
  FFT1_2_3_5_0(w[21], w[3], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[10]);
  FFT1_2_3_5_0(w[20], w[12], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[11]);
  FFT1_2_3_5_0(w[22], w[3], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[12]);
//   VVT10_11_12_13_2_3_6_7_8_9_0(w[11], w[23], w[0], pars->HEF_MEKD2_1_GC_75, pars->HEF_MEKD2_1_GC_81,
//       pars->HEF_MEKD2_1_GC_67, pars->HEF_MEKD2_1_GC_71, pars->HEF_MEKD2_1_GC_90, pars->HEF_MEKD2_1_GC_92, pars->HEF_MEKD2_1_GC_63,
//       pars->HEF_MEKD2_1_GC_85, pars->HEF_MEKD2_1_GC_79, pars->HEF_MEKD2_1_GC_83, amp[13]);	// ZZ
  FFT1_2_3_5_0(w[4], w[26], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[14]);
  FFT1_2_3_5_0(w[27], w[3], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[15]);
  FFT1_2_3_5_0(w[4], w[29], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[16]);
  FFT1_2_3_5_0(w[30], w[3], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[17]);
  FFT1_2_3_5_0(w[2], w[32], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[18]);
  FFT1_2_3_5_0(w[33], w[24], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[19]);
//   VVT10_11_12_13_2_3_6_7_8_9_0(w[28], w[34], w[0], pars->HEF_MEKD2_1_GC_75, pars->HEF_MEKD2_1_GC_81,
//       pars->HEF_MEKD2_1_GC_67, pars->HEF_MEKD2_1_GC_71, pars->HEF_MEKD2_1_GC_90, pars->HEF_MEKD2_1_GC_92, pars->HEF_MEKD2_1_GC_63,
//       pars->HEF_MEKD2_1_GC_85, pars->HEF_MEKD2_1_GC_79, pars->HEF_MEKD2_1_GC_83, amp[20]);	// ZZ
  FFT1_2_3_5_0(w[2], w[35], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[21]);
  FFT1_2_3_5_0(w[36], w[24], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[22]);
  FFT1_2_3_5_0(w[4], w[39], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[23]);
  FFT1_2_3_5_0(w[40], w[3], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[24]);
  FFT1_2_3_5_0(w[4], w[42], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[25]);
  FFT1_2_3_5_0(w[43], w[3], w[0], pars->HEF_MEKD2_1_GC_145, pars->HEF_MEKD2_1_GC_142, pars->HEF_MEKD2_1_GC_143,
      pars->HEF_MEKD2_1_GC_144, amp[26]);
  FFT1_2_3_5_0(w[37], w[44], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[27]);
  FFT1_2_3_5_0(w[45], w[1], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[28]);
//   VVT10_11_12_13_2_3_6_7_8_9_0(w[41], w[34], w[0], pars->HEF_MEKD2_1_GC_75, pars->HEF_MEKD2_1_GC_81,
//       pars->HEF_MEKD2_1_GC_67, pars->HEF_MEKD2_1_GC_71, pars->HEF_MEKD2_1_GC_90, pars->HEF_MEKD2_1_GC_92, pars->HEF_MEKD2_1_GC_63,
//       pars->HEF_MEKD2_1_GC_85, pars->HEF_MEKD2_1_GC_79, pars->HEF_MEKD2_1_GC_83, amp[29]);	// ZZ
  FFT1_2_3_5_0(w[37], w[46], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[30]);
  FFT1_2_3_5_0(w[47], w[1], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[31]);
  FFT1_2_3_5_0(w[2], w[48], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[32]);
  FFT1_2_3_5_0(w[49], w[1], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[33]);
  FFT1_2_3_5_0(w[2], w[50], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[34]);
  FFT1_2_3_5_0(w[51], w[1], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[35]);
  FFT1_2_3_5_0(w[2], w[53], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[36]);
  FFT1_2_3_5_0(w[54], w[1], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[37]);
  FFT1_2_3_5_0(w[2], w[55], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[38]);
  FFT1_2_3_5_0(w[56], w[1], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[39]);
  FFT1_2_3_5_0(w[2], w[58], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[40]);
  FFT1_2_3_5_0(w[59], w[1], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[41]);
  FFT1_2_3_5_0(w[2], w[60], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[42]);
  FFT1_2_3_5_0(w[61], w[1], w[0], pars->HEF_MEKD2_1_GC_135, pars->HEF_MEKD2_1_GC_132, pars->HEF_MEKD2_1_GC_133,
      pars->HEF_MEKD2_1_GC_134, amp[43]);

}
double Spin2_2f_OFpA::matrix_xg_emepmummupa_no_hzp() 
{
  int i, j;
  // Local variables
	// Commented out by Convert_source 0.2
//  const int ngraphs = 44;
  const int ncolor = 1;
  std::complex<double> ztemp;
  std::complex<double> jamp[ncolor];
  // The color matrix;
  static const double denom[1] = {1.};
  static const double cf[1][1] = {{1.}};

  // Calculate color flows
  jamp[0] = +amp[0] + amp[1] + amp[2] + amp[3] + amp[4] + amp[5] + amp[6] +
      amp[7] + amp[8] + amp[9] + amp[10] + amp[11] + amp[12] + amp[13] +
      amp[14] + amp[15] + amp[16] + amp[17] + amp[18] + amp[19] + amp[20] +
      amp[21] + amp[22] + amp[23] + amp[24] + amp[25] + amp[26] + amp[27] +
      amp[28] + amp[29] + amp[30] + amp[31] + amp[32] + amp[33] + amp[34] +
      amp[35] + amp[36] + amp[37] + amp[38] + amp[39] + amp[40] + amp[41] +
      amp[42] + amp[43];

  // Sum and square the color flows to get the matrix element
  double matrix = 0;
  for(i = 0;i < ncolor;i++ )
  {
    ztemp = 0.;
    for(j = 0;j < ncolor;j++ )
      ztemp = ztemp + cf[i][j] * jamp[j];
    matrix = matrix + real(ztemp * conj(jamp[i]))/denom[i];
  }

  // Store the leading color flows for choice of color
  for(i = 0;i < ncolor;i++ )
    jamp2[0][i] += real(jamp[i] * conj(jamp[i]));

  return matrix;
}



