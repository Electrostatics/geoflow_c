///  @file GeometricFlowWrap.cpp
///  @author  Elizabeth Jurrus
///  @brief c interface for the C++ GeometricFlowClass 
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
/// Copyright (c) 2010-2015 Battelle Memorial Institute. Developed at the
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
#include "GeometricFlowWrap.h"
#include "GeometricFlow.h"

#include <iostream>


using namespace std;

struct GeometricFlowInput getGeometricFlowParams()
{
   // create the Geoflow Class
   geoflow::GeometricFlow GF;
   // get the struct for use in the c code
   GeometricFlowInput GFI(GF);

   return GFI;
}

//
//  for testing only!
//
struct GeometricFlowOutput runGeometricFlowWrap
   ( struct GeometricFlowInput geoflowParams )
{

   //cout << "boo from GeometricFlowWrap!" << endl; 

   geoflow::GeometricFlow GF( geoflowParams );
   
   geoflow::AtomList emptyAtomList; // need to fill this with atoms
   geoflow::AtomList AL( "imidazole.xyzr", GF.getRadExp(), GF.getFFModel() ); 

   struct GeometricFlowOutput GFO = GF.run( AL ); //emptyAtomList );
   
   return GFO;
}

//
//  print the geometric flow structure for debugging
//
void printGeometricFlowStruct( struct GeometricFlowInput geoflowIn )
{
   printf("GeometricFlowInput: %i, %f, %f, %f, %f, %f, %f, %f, %f, %f, %i, %f\n", 
         geoflowIn.m_boundaryCondition,
         geoflowIn.m_grid[0],
         geoflowIn.m_grid[1],
         geoflowIn.m_grid[2],
         geoflowIn.m_gamma, 
         geoflowIn.m_pdie,
         geoflowIn.m_sdie,
         geoflowIn.m_press,
         geoflowIn.m_tol,
         geoflowIn.m_bconc,
         geoflowIn.m_vdwdispersion,
         geoflowIn.m_etolSolvation );
}
