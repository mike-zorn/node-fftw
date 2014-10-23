/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Mar  4 13:49:07 EST 2014 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_r2cf.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -n 7 -name r2cf_7 -include r2cf.h */

/*
 * This function contains 24 FP additions, 18 FP multiplications,
 * (or, 9 additions, 3 multiplications, 15 fused multiply/add),
 * 25 stack variables, 6 constants, and 14 memory accesses
 */
#include "r2cf.h"

static void r2cf_7(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DK(KP801937735, +0.801937735804838252472204639014890102331838324);
     DK(KP974927912, +0.974927912181823607018131682993931217232785801);
     DK(KP692021471, +0.692021471630095869627814897002069140197260599);
     DK(KP554958132, +0.554958132087371191422194871006410481067288862);
     DK(KP356895867, +0.356895867892209443894399510021300583399127187);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(28, rs), MAKE_VOLATILE_STRIDE(28, csr), MAKE_VOLATILE_STRIDE(28, csi)) {
	       E T1, Tg, Tc;
	       {
		    E Th, T4, Ti, Ta, Tj, T7, Td, T5, T6, Tl, Tk;
		    T1 = R0[0];
		    {
			 E T2, T3, T8, T9;
			 T2 = R1[0];
			 T3 = R0[WS(rs, 3)];
			 T8 = R1[WS(rs, 1)];
			 T9 = R0[WS(rs, 2)];
			 T5 = R0[WS(rs, 1)];
			 Th = T3 - T2;
			 T4 = T2 + T3;
			 T6 = R1[WS(rs, 2)];
			 Ti = T9 - T8;
			 Ta = T8 + T9;
		    }
		    Tj = T6 - T5;
		    T7 = T5 + T6;
		    Td = FNMS(KP356895867, T4, Ta);
		    Tl = FMA(KP554958132, Ti, Th);
		    Tk = FMA(KP554958132, Tj, Ti);
		    {
			 E Tm, Tf, Tb, Te;
			 Tm = FNMS(KP554958132, Th, Tj);
			 Cr[0] = T1 + T4 + T7 + Ta;
			 Tf = FNMS(KP356895867, T7, T4);
			 Tb = FNMS(KP356895867, Ta, T7);
			 Te = FNMS(KP692021471, Td, T7);
			 Ci[WS(csi, 2)] = KP974927912 * (FNMS(KP801937735, Tk, Th));
			 Ci[WS(csi, 3)] = KP974927912 * (FNMS(KP801937735, Tm, Ti));
			 Tg = FNMS(KP692021471, Tf, Ta);
			 Tc = FNMS(KP692021471, Tb, T4);
			 Cr[WS(csr, 2)] = FNMS(KP900968867, Te, T1);
			 Ci[WS(csi, 1)] = KP974927912 * (FMA(KP801937735, Tl, Tj));
		    }
	       }
	       Cr[WS(csr, 1)] = FNMS(KP900968867, Tg, T1);
	       Cr[WS(csr, 3)] = FNMS(KP900968867, Tc, T1);
	  }
     }
}

static const kr2c_desc desc = { 7, "r2cf_7", {9, 3, 15, 0}, &GENUS };

void X(codelet_r2cf_7) (planner *p) {
     X(kr2c_register) (p, r2cf_7, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_r2cf.native -compact -variables 4 -pipeline-latency 4 -n 7 -name r2cf_7 -include r2cf.h */

/*
 * This function contains 24 FP additions, 18 FP multiplications,
 * (or, 12 additions, 6 multiplications, 12 fused multiply/add),
 * 20 stack variables, 6 constants, and 14 memory accesses
 */
#include "r2cf.h"

static void r2cf_7(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP222520933, +0.222520933956314404288902564496794759466355569);
     DK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DK(KP623489801, +0.623489801858733530525004884004239810632274731);
     DK(KP433883739, +0.433883739117558120475768332848358754609990728);
     DK(KP781831482, +0.781831482468029808708444526674057750232334519);
     DK(KP974927912, +0.974927912181823607018131682993931217232785801);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(28, rs), MAKE_VOLATILE_STRIDE(28, csr), MAKE_VOLATILE_STRIDE(28, csi)) {
	       E T1, Ta, Tb, T4, Td, T7, Tc, T8, T9;
	       T1 = R0[0];
	       T8 = R1[0];
	       T9 = R0[WS(rs, 3)];
	       Ta = T8 + T9;
	       Tb = T9 - T8;
	       {
		    E T2, T3, T5, T6;
		    T2 = R0[WS(rs, 1)];
		    T3 = R1[WS(rs, 2)];
		    T4 = T2 + T3;
		    Td = T3 - T2;
		    T5 = R1[WS(rs, 1)];
		    T6 = R0[WS(rs, 2)];
		    T7 = T5 + T6;
		    Tc = T6 - T5;
	       }
	       Ci[WS(csi, 2)] = FNMS(KP781831482, Tc, KP974927912 * Tb) - (KP433883739 * Td);
	       Ci[WS(csi, 1)] = FMA(KP781831482, Tb, KP974927912 * Td) + (KP433883739 * Tc);
	       Cr[WS(csr, 2)] = FMA(KP623489801, T7, T1) + FNMA(KP900968867, T4, KP222520933 * Ta);
	       Ci[WS(csi, 3)] = FMA(KP433883739, Tb, KP974927912 * Tc) - (KP781831482 * Td);
	       Cr[WS(csr, 3)] = FMA(KP623489801, T4, T1) + FNMA(KP222520933, T7, KP900968867 * Ta);
	       Cr[WS(csr, 1)] = FMA(KP623489801, Ta, T1) + FNMA(KP900968867, T7, KP222520933 * T4);
	       Cr[0] = T1 + Ta + T4 + T7;
	  }
     }
}

static const kr2c_desc desc = { 7, "r2cf_7", {12, 6, 12, 0}, &GENUS };

void X(codelet_r2cf_7) (planner *p) {
     X(kr2c_register) (p, r2cf_7, &desc);
}

#endif				/* HAVE_FMA */
