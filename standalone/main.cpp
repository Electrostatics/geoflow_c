///  @file    main.cpp
///  @author  Andrew Stevens
///  @brief this is a wrapper to set the geoflow parameters, see fort.12
///  @ingroup Geoflow
///  @version $Id$
///  @attention
///  @verbatim
///
/// APBS -- Adaptive Poisson-Boltzmann Solver
///
///  Nathan A. Baker (nathan.baker@pnnl.gov)
///  Pacific Northwest National Laboratory
///
///  Additional contributing authors listed in the code documentation.
///
/// Copyright (c) 2010-2012 Battelle Memorial Institute. Developed at the
/// Pacific Northwest National Laboratory, operated by Battelle Memorial
/// Institute, Pacific Northwest Division for the U.S. Department of Energy.
///
/// Portions Copyright (c) 2002-2010, Washington University in St. Louis.
/// Portions Copyright (c) 2002-2010, Nathan A. Baker.
/// Portions Copyright (c) 1999-2002, The Regents of the University of
/// California.
/// Portions Copyright (c) 1995, Michael Holst.
/// All rights reserved.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions are met:
///
/// Redistributions of source code must retain the above copyright notice, this
/// list of conditions and the following disclaimer.
///
/// Redistributions in binary form must reproduce the above copyright notice,
/// this list of conditions and the following disclaimer in the documentation
/// and/or other materials provided with the distribution.
///
/// Neither the name of the developer nor the names of its contributors may be
/// used to endorse or promote products derived from this software without
/// specific prior written permission.
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
/// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
/// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
/// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
/// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
/// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
/// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
/// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
/// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
/// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
/// THE POSSIBILITY OF SUCH DAMAGE.
///
/// @endverbatim

#include <iostream>
#include <string>

#include "cpbconcz2.h"


int main( int argc, char *argv[] )
{

   //
   //  set up some defaults
   //
	//int nmol = 17,		// nmol
	double pres_i = 0.008;
	double gama_i = 0.0001;
	int npiter = 1;
	int ngiter = 1;
	double tauval = 1.40;
	double prob = 0.0;
	int ffmodel = 1;
	double sigmas = 1.5828;
	double epsilonw = 0.1554;
	int vdwdispersion = 0;
	double extvalue = 1.90;
	// 0,		// iprec
	// 10,		// istep
	int iadi = 0;
	double alpha = 0.50;
	// 1,		// IPBIN
	double tol = 1e-4;
	double tottf = 3.5;
	double dcel = 0.25;
	int maxstep = 20;
	double epsilons = 80.00;
	double epsilonp = 1.5;
	int radexp = 1;
	double crevalue = 0.01;
	// 0,		// idacsl
	double density = 0.03346;

   if( argc < 3 )
   {
      std::cout << "Usage: " << argv[0]
                << " <atom_name.xyzr> <experimental value> [param_file.param] " << std::endl ;
      exit( 1 );
   }

   //
   //  read in xyzr file name
   //
   std::string xyzr_filename = argv[1];
   std::cout << "xyzr filename: " << xyzr_filename << std::endl ;

   //
   //  read in experimental value
   //
   double exper_value = atof( argv[2] );
   std::cout << "experimental value: " << exper_value << std::endl ;

   //
   //  read in new values for the params
   //
   std::string param_filename;
   if( argc > 3 )
   {
       param_filename = argv[3];
       std::cout << "param filename: " << param_filename << std::endl ;
       // TODO - process this param file to replace default values above
   }


	pbconcz2_simple( pres_i, gama_i, npiter, ngiter, tauval, prob,
      ffmodel, sigmas, epsilonw, vdwdispersion, extvalue, iadi, alpha,
      tol, tottf, dcel, maxstep, epsilons, epsilonp, radexp, crevalue,
      density, xyzr_filename, exper_value );
}

