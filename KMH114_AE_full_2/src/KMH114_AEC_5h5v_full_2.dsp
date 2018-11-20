// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 18:10:15

//------- decoder information -------
// decoder file = ../decoders/KMH114_AEC_5h5v_pinv_even_energy_rV_max_rE_2_band.dsp
// description = KMH114_AEC_5h5v_pinv_even_energy_rV_max_rE_2_band
// speaker array name = KMH114_AEC
// horizontal order   = 5
// vertical order     = 5
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HV
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 
// output speaker order: L C R RSF RSR RR RL LSR LSF ULF URF URR URL VOG 
//-------


// start decoder configuration
declare name "KMH114_AEC_5h5v_full_2";

// bands
nbands = 2;

// decoder type
decoder_type = 2;

// crossover frequency in Hz
xover_freq = hslider("xover [unit:Hz]",400,200,800,20): dezipper;

// lfhf_balance
lfhf_ratio = hslider("lf/hf [unit:dB]", 0, -3, +3, 0.1): mu.db2linear : dezipper;


// decoder order
decoder_order = 5;

// ambisonic order of each input component
co = ( 0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5);

// use full or reduced input set
input_full_set = 1;

// delay compensation
delay_comp = 1;

// level compensation
level_comp = 1;

// nfc on input or output
nfc_output = 1;
nfc_input  = 0;

// enable output gain and muting controls
output_gain_muting = 1;

// number of speakers
ns = 14;

// radius for each speaker in meters
rs = (          3.26,          3.27,           3.3,          3.35,          3.27,         3.364,         3.376,         3.262,         3.296,          3.02,          3.02,          3.05,          3.02,           1.6);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1,             1,             1);
gamma(1) = (   1.095112527,   1.021159046,  0.8807432558,  0.6880043625,  0.4621429721,  0.2252781288);

// gain matrix
s(00,0) = (  0.0998384691,  0.0661351804, -0.0321106677,   0.127853754,  0.1196422227, -0.0221161995, -0.0675085647, -0.0465746999,  0.1494980033,  0.1905773753, -0.0365186782, -0.0525807785,  0.0345983031, -0.1037364775,            -0,  0.0563242536,  0.1856130099, -0.0241574756,  -0.100032397,  0.0235362018,  0.0661853983,  0.0495650953, -0.0965005462,  0.0508734414, -0.0904149959,  0.1687793841,            -0, -0.1428514938,  0.0344701813,  0.0549302681, -0.0353928669,  0.1101490141,             0, -0.0018832865,  0.0535454007, -0.1947253998);
s(01,0) = (  0.1434306784, -0.0020074136,  0.0040144087,  0.1825622786, -0.0023461865,  0.0010052894, -0.0809164791,  0.0353688504,  0.1285653957, -0.0067700365,  0.0014877047,  0.0017784442, -0.0291969953, -0.0924751642,             0,   0.161156331, -0.0051228867,  0.0010980754,  0.0024434372, -0.0010698354,  0.0319926416, -0.0376397582, -0.0829886061,  -0.038633317,  0.2732546392, -0.0093138488,             0,  0.0052414371, -0.0014042527, -0.0020133297,  0.0056484684,  0.0517399281,            -0, -0.1334561843, -0.0266578529,  0.3006226501);
s(02,0) = (  0.0990915317, -0.0663659087,  -0.032746303,  0.1259962842, -0.1232795846,  0.0222236825, -0.0673338886, -0.0477277144,  0.1459136949, -0.1882891778,  0.0367899388,  0.0527807849,  0.0356091066, -0.1032288715,            -0,  0.0484869042,  -0.183874181,  0.0242748791,  0.1025496897, -0.0236505859,  0.0667128272,  0.0507921408,  -0.094186885,  0.0521328767, -0.1033435615, -0.1521238972,             0,  0.1414196227, -0.0347262256, -0.0551533229, -0.0361095099,  0.1104443106,             0,  0.0041763034,  0.0548669504, -0.2083356554);
s(03,0) = (   0.141958547,  -0.152144497, -0.0378292453,  0.0722422939, -0.1548522292,  0.0383403961, -0.0969810175, -0.0205635295, -0.1270846463,  0.0333744156,   0.051619896,  0.1141133055,  0.0292406927, -0.0554724293,            -0, -0.1913954621,  0.1849775408,  0.0418791297,  0.1321901427, -0.0408020962,  0.0786704588,  0.0218838404,  0.0820327864,  0.0224614977, -0.0495690567,  0.1393108188,             0,  0.0070429653, -0.0487243039, -0.1133778583, -0.0411292047,  0.0562782725,             0,  0.1422134138,  0.0538351388,  0.1343515924);
s(04,0) = (  0.1394240608, -0.1986331336,   -0.00711841,  -0.038929172,  0.0573637856, -0.0087291284, -0.0825944061, -0.0052332778, -0.1871171125,  0.1932177256, -0.0096477406,  0.1168689946, -0.0119285254,  0.0209803691,            -0,  0.0996594783, -0.1594075377, -0.0095348076, -0.0430525866,  0.0092895946,  0.0443151533,  0.0055692879,  0.1207835767,  0.0057162977,   0.168467064, -0.0919157589,            -0, -0.1344309523,  0.0091065555, -0.0871193455, -0.0068817438, -0.0134247507,             0, -0.0619440742, -0.0038609433, -0.1814652277);
s(05,0) = (  0.1122056553, -0.0788193749, -0.0489164292, -0.1076044596,   0.171181252,  0.0557710243, -0.0824302671,   0.050316306,  0.0078315768, -0.1226342703, -0.0588849618,  0.0787328517,  0.0537262207,  0.0933802951,             0,  0.1158599231, -0.0510649758,  0.0609185663, -0.1472670695,  -0.059351883,  0.0866144198, -0.0535469366, -0.0050552611, -0.0549603895, -0.1998101524,  0.1818171437,             0,  0.1234709079,  0.0555818395, -0.0959378763, -0.0539666288, -0.1042222262,            -0, -0.1148474482,  0.0823883466,  0.0860313662);
s(06,0) = (  0.1125747377,  0.0788542092, -0.0493580498, -0.1068821165, -0.1712164307, -0.0557746045, -0.0828335418,  0.0495979082,   0.009353963,  0.1226559457,  0.0588989933,  -0.078756139,  0.0542526125,  0.0925455128,             0,  0.1164838191,  0.0509385673, -0.0609224769,   0.147298539,   0.059355693,  0.0871851682,  -0.052782413, -0.0060379572, -0.0541756852, -0.2009925146, -0.1817424823,            -0, -0.1234879639, -0.0555950838,  0.0959584495, -0.0544558773, -0.1031282525,            -0, -0.1147145209,  0.0831653428,  0.0837411999);
s(07,0) = (  0.1390974496,  0.1985975158, -0.0067073968, -0.0395998559, -0.0569887813,  0.0086620268, -0.0822259697, -0.0045644954, -0.1885751741,  -0.193142683,  0.0095062313, -0.1168838388, -0.0124150374,  0.0217564132,            -0,  0.0989987379,   0.159819214,  0.0094615126,  0.0427221585, -0.0092181846,  0.0437927818,  0.0048575654,  0.1217247515,  0.0049857882,  0.1694523494,  0.0910827828,             0,  0.1343303551,  -0.008972984,  0.0871716204, -0.0064265708, -0.0144423127,             0, -0.0620149502, -0.0045813614, -0.1794466832);
s(08,0) = (  0.1429083735,  0.1527310333, -0.0388653712,  0.0739878295,  0.1565823057,  -0.038831521, -0.0979710405, -0.0222182989, -0.1237412835, -0.0310344759, -0.0524256898,  -0.114740771,  0.0304715203, -0.0574452982,            -0, -0.1903642154,  -0.182435033, -0.0424155843,  -0.133810071,  0.0413247545,  0.0800379371,  0.0236448566,  0.0798746551,  0.0242689986, -0.0529334729, -0.1386064976,            -0, -0.0089636805,   0.049484897,  0.1141706267, -0.0422768687,   0.058837692,             0,  0.1427880424,  0.0556547581,  0.1283727981);
s(09,0) = (  0.1114336987,  0.1099543406,  0.0788609742,    0.11546752,  0.1398533908,  0.1186942742, -0.0278757458,  0.1167455153,  0.0041355935,  0.0850237702,   0.172618097, -0.0024938826, -0.1184741181, -0.0069345502,             0, -0.0917872551,  0.0234986826,  0.1296494926,  0.0175144371, -0.1263152104, -0.0533267231, -0.1242413286, -0.0026695141, -0.1275208676, -0.0926454177, -0.0807580275,             0,  0.0339058294, -0.1629351715, -0.0697376168,  0.0885702093, -0.0650496172,            -0, -0.0279521966, -0.1583952871,  -0.073982158);
s(10,0) = (  0.1111816728,  -0.109704752,  0.0792503308,  0.1150465448, -0.1378241975, -0.1191862173, -0.0275767111,  0.1173781083,  0.0034266475, -0.0832920119, -0.1735241847,  0.0020723076, -0.1189814669,   -0.00633119,             0,  -0.091371323, -0.0206611972,  -0.130186841, -0.0193900719,  0.1268387394, -0.0538340605, -0.1249145382, -0.0022118914, -0.1282118476, -0.0902598191,  0.0793320836,            -0, -0.0354248918,  0.1637904327,  0.0703681087,  0.0890036853, -0.0659087966,            -0, -0.0287077401, -0.1591150471, -0.0707218597);
s(11,0) = (  0.1236606121, -0.1188438088,  0.0769206109, -0.1364585892,  0.1407837577, -0.1183275243, -0.0363529928, -0.1162717163,  0.0225044087,  -0.109561646,  0.1722780986,  0.0081378924, -0.1192216295,  0.0200477246,            -0,  0.0697676868,   0.029516892, -0.1292488925,  0.0167015797,  0.1259249127, -0.0490814731,  0.1237371087, -0.0145265334,   0.127003338, -0.0726547912,  0.0327347704,            -0, -0.0173970175, -0.1626142452,  0.0650540631,  0.0865711555,  0.0543964966,             0,  0.0421569398, -0.1574378187,  0.0667457953);
s(12,0) = (  0.1237705623,  0.1188636014,  0.0769475825, -0.1363260873, -0.1410301474,  0.1183994329, -0.0364047648,  -0.116202975,  0.0225441999,  0.1093435661,  -0.172129553, -0.0081107313, -0.1192759353,  0.0200041355,            -0,  0.0698494883, -0.0300181041,  0.1293274381, -0.0164497782, -0.1260014383, -0.0490828602,  0.1236639537, -0.0145522185,   0.126928252, -0.0724263314, -0.0326137352,             0,  0.0175958756,  0.1624740322, -0.0651189795,  0.0866021261,  0.0543894268,             0,  0.0420506268, -0.1575030577,  0.0669776233);
s(13,0) = (  0.1433163857,    3.6985e-06,  0.2262267226, -0.0123343198,   1.46548e-05,    -6.403e-07,  0.2793619274,  0.0010177323,  0.0092519682,  -4.27622e-05,    8.7492e-06,   -2.6147e-06,  0.2517089994,  0.0081091541,             0, -0.0136225506,  -8.83384e-05,    -6.994e-07,   -3.9963e-06,     6.814e-07,  0.2137823271, -0.0010830772, -0.0059721198, -0.0011116667,  0.0207571649, -0.0001838304,            -0,   2.77982e-05,   -8.2584e-06,    2.4539e-06,  0.2249729495, -0.0070257127,            -0,  0.0082375415,  0.0204539016,  0.0003511853);


// ----- do not change anything below here ----

// mask for full ambisonic set to channels in use
input_mask(0) = bus(nc);
input_mask(1) = (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_);


// Start of decoder implementation.  No user serviceable parts below here!
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//declare name		"Fill in name in configuration section below";
declare version 	"1.2";
declare author 		"AmbisonicDecoderToolkit";
declare license 	"BSD 3-Clause License";
declare copyright	"(c) Aaron J. Heller 2013";

/*
Copyright (c) 2013, Aaron J. Heller
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
  Author: Aaron J. Heller <heller@ai.sri.com>
  $Id: 21810b615fa65b96af41a7c8783d7435b41084b8 $
*/

// v 1.2, 28-Oct-2017 ajh
//  . add 6th-order NFC filters
//  . fixed error in speaker_chain and speaker_chain2, where speaker 
//    distance was being indexed by order, not speaker number

// v 1.1 remove dependancies on Faust Libraries, 23-Nov-2016 ajh
//   m = library("math.lib");
//   mu = library("music.lib");

m = environment {
  // from the old math.lib
  take (1, (xs, xxs)) = xs;
  take (1, xs) = xs;
  take (nn, (xs, xxs)) = take (nn-1, xxs);

  bus(2) = _,_; // avoids a lot of "bus(1)" labels in block diagrams
  bus(n) = par(i, n, _);

  SR = min(192000, max(1, fconstant(int fSamplingFreq, <math.h>)));
  //PI = 3.1415926535897932385;
  // quad precision value
  PI = 3.14159265358979323846264338327950288;
};

mu = environment {
   // from the old music.lib
   db2linear(x)	= pow(10, x/20.0);
};



// m.SR from math.lib is an integer, we need a float
SR = float(m.SR);

// descriptive statistics
total(c) = c:>_;

average(c) = total(c)/count(c);

count(c) = R(c) :>_ with {
 R((c,cl)) = R(c),(R(cl));
 R(c)      = 1;
};

rms(c) = R(c) :> /(count(c)) : sqrt with {
 R((c,cl)) = R(c),R(cl);
 R(c)      = (c*c);
};

sup(c) = R(c) with {
 R((c,cl)) = max(R(c),R(cl));
 R(c)      = c;
};

inf(c) = R(c) with {
 R((c,cl)) = min(R(c),R(cl));
 R(c)      = c;
};

// bus
bus(n)   = par(i,n,_);

// bus with gains
gain(c) = R(c) with {
  R((c,cl)) = R(c),R(cl);
  R(1)      = _;
  R(0)      = !:0;  // need to preserve number of outputs, faust will optimize away
  R(float(0)) = R(0);
  R(float(1)) = R(1);
  R(c)      = *(c);
};

// fir filter  (new improved, better behaved)
fir(c) = R(c) :>_ with {
  R((c,lc)) = _<: R(c), (mem:R(lc));
  R(c)      = gain(c);
};

// --- phase-matched bandsplitter from BLaH3
xover(freq,n) = par(i,n,xover1) with {

	sub(x,y) = y-x;

	k = tan(m.PI*float(freq)/m.SR);
	k2 = k^2;
	d =  (k2 + 2*k + 1);
	//d = (k2,2*k,1):>_;
	// hf numerator
	b_hf = (1/d,-2/d,1/d);
	// lf numerator
	b_lf = (k2/d, 2*k2/d, k2/d);
	// denominator
	a = (2 * (k2-1) / d, (k2 - 2*k + 1) / d);
	// 
	xover1 = _:sub ~ fir(a) <: fir(b_lf),fir(b_hf):_,*(-1);
};

shelf(freq,g_lf,g_hf) = xover(freq,1) : gain(g_lf),gain(g_hf):>_;

// from http://old.nabble.com/Re%3A--Faudiostream-devel---ANN--Faust-0.9.24-p28597267.html
//   (not used currently, do we need to worry about denormals?)
anti_denormal = pow(10,-20);
anti_denormal_ac = 1 - 1' : *(anti_denormal) : + ~ *(-1); 

// UI "dezipper"
smooth(c) = *(1-c) : +~*(c);
dezipper = smooth(0.999);

// physical constants     

temp_celcius = 20;                        
c = 331.3 * sqrt(1.0 + (temp_celcius/273.15)); // speed of sound m/s


// ---- NFC filters ----
//  see BesselPoly.m for coefficient calculations
//
// [1] J. Daniel, “Spatial Sound Encoding Including Near Field Effect:
//     Introducing Distance Coding Filters and a Viable, New Ambisonic 
//     Format ,” Preprints 23rd AES International Conference, Copenhagen,
//     2003.
// [2] Weisstein, Eric W. "Bessel Polynomial." From MathWorld--A Wolfram 
//     Web Resource. http://mathworld.wolfram.com/BesselPolynomial.html
// [3] F. Adriaensen, “Near Field filters for Higher Order
//     Ambisonics,” Jul. 2006.
// [4] J. O. Smith, “Digital State-Variable Filters,” CCRMA, May 2013.
//
// [5] "A Filter Primer", https://www.maximintegrated.com/en/app-notes/index.mvp/id/733

// first and second order state variable filters see [4]
//   FIXME FIXME this code needs to be refactored, so that the roots are 
//               passed in rather then hardwired in the code, or another 
//               API layer, or ...
svf1(g,d1)    = _ : *(g) :       (+      <: +~_, _ ) ~ *(d1)                   : !,_ ;
svf2(g,d1,d2) = _ : *(g) : (((_,_,_):> _ <: +~_, _ ) ~ *(d1) : +~_, _) ~ *(d2) : !,_ ;

//  these are Bessel filters, see [1,2]
nfc1(r,gain) = svf1(g,d1)  // r in meters
 with {
   omega = c/(float(r)*SR);
   //  1  1
   b1 = omega/2.0;
   g1 = 1.0 + b1;
   d1 = 0.0 - (2.0 * b1) / g1;
   g = gain/g1;
};

nfc2(r,gain) = svf2(g,d1,d2)
 with {
   omega = c/(float(r)*SR);
   r1 = omega/2.0;
   r2 = r1 * r1;

   // 1.000000000000000   3.00000000000000   3.00000000000000
   b1 = 3.0 * r1;
   b2 = 3.0 * r2;
   g2 = 1.0 + b1 + b2;

   d1 = 0.0 - (2.0 * b1 + 4.0 * b2) / g2;  // fixed
   d2 = 0.0 - (4.0 * b2) / g2;
   g = gain/g2;
};

nfc3(r,gain) = svf2(g,d1,d2):svf1(1.0,d3)
 with {
   omega = c/(float(r)*SR);

   r1 = omega/2.0;
   r2 = r1 * r1;

   // 1.000000000000000   3.677814645373914   6.459432693483369
   b1 = 3.677814645373914 * r1;
   b2 = 6.459432693483369 * r2;         
   g2 = 1.0 + b1 + b2;
   d1 = 0.0 - (2.0 * b1 + 4.0 * b2) / g2;  // fixed
   d2 = 0.0 - (4.0 * b2) / g2;

   // 1.000000000000000   2.322185354626086
   b3 = 2.322185354626086 * r1;
   g3 = 1.0 + b3;
   d3 = 0.0 - (2.0 * b3) / g3;

   g = gain/(g3*g2);
};

nfc4(r,gain) = svf2(g,d1,d2):svf2(1.0,d3,d4)
 with {
   omega = c/(float(r)*SR);

   r1 = omega/2.0;
   r2 = r1 * r1;
   
   // 1.000000000000000   4.207578794359250  11.487800476871168
   b1 =  4.207578794359250 * r1;
   b2 = 11.487800476871168 * r2;         
   g2 = 1.0 + b1 + b2;
   d1 = 0.0 - (2.0 * b1 + 4.0 * b2) / g2;  // fixed
   d2 = 0.0 - (4.0 * b2) / g2;

   // 1.000000000000000   5.792421205640748   9.140130890277934
   b3 = 5.792421205640748 * r1;
   b4 = 9.140130890277934 * r2;         
   g3 = 1.0 + b3 + b4;
   d3 = 0.0 - (2.0 * b3 + 4.0 * b4) / g3;  // fixed
   d4 = 0.0 - (4.0 * b4) / g3;
   
   g = gain/(g3*g2);
};

nfc5(r,gain) = svf2(g,d1,d2):svf2(1.0,d3,d4):svf1(1.0,d5)
 with {
   omega = c/(float(r)*SR);

   r1 = omega/2.0;
   r2 = r1 * r1;
   
   // 1.000000000000000   4.649348606363304  18.156315313452325
   b1 =  4.649348606363304 * r1;
   b2 = 18.156315313452325 * r2;         
   g2 = 1.0 + b1 + b2;
   d1 = 0.0 - (2.0 * b1 + 4.0 * b2) / g2;  // fixed
   d2 = 0.0 - (4.0 * b2) / g2;

   // 1.000000000000000   6.703912798306966  14.272480513279568
   b3 =  6.703912798306966 * r1;
   b4 = 14.272480513279568 * r2;         
   g3 = 1.0 + b3 + b4;
   d3 = 0.0 - (2.0 * b3 + 4 * b4) / g3;  // fixed
   d4 = 0.0 - (4.0 * b4) / g3;

   // 1.000000000000000   3.646738595329718
   b5 = 3.646738595329718 * r1;
   g4 = 1.0 + b5;
   d5 = 0.0 - (2.0 * b5) / g4;

   g = gain/(g4*g3*g2);
 };

nfc6(r,gain) = svf2(g,d11,d12):svf2(1.0,d21,d22):svf2(1.0,d31,d32)
with {
   omega = c/(float(r)*SR);

   r1 = omega/2.0;
   r2 = r1 * r1;

   // reverse Bessel Poly 6:
   //   1          21         210        1260        4725       10395       10395
   // factors:
   //   1.000000000000000   5.031864495621642  26.514025344067996
   //   1.000000000000000   7.471416712651683  20.852823177396761
   //   1.000000000000000   8.496718791726696  18.801130589570320


   // 1.000000000000000   5.031864495621642  26.514025344067996
   b11 =  5.031864495621642 * r1;
   b12 = 26.514025344067996 * r2;         
   g1 = 1.0 + b11 + b12;
   d11 = 0.0 - (2.0 * b11 + 4.0 * b12) / g1;
   d12 = 0.0 - (4.0 * b12) / g1;

   // 1.000000000000000   7.471416712651683  20.852823177396761
   b21 =  7.471416712651683 * r1;
   b22 = 20.852823177396761 * r2;         
   g2 = 1.0 + b21 + b22;
   d21 = 0.0 - (2.0 * b21 + 4.0 * b22) / g2;
   d22 = 0.0 - (4.0 * b22) / g2;

   // 1.000000000000000   8.496718791726696  18.801130589570320
   b31 =  8.496718791726696 * r1;
   b32 = 18.801130589570320 * r2;         
   g3 = 1.0 + b31 + b32;
   d31 = 0.0 - (2.0 * b31 + 4.0 * b32) / g3;
   d32 = 0.0 - (4.0 * b32) / g3;

   g = gain/(g3*g2*g1);
};


// ---- End NFC filters ----

nfc(0,r,g) = gain(g);
nfc(1,r,g) = nfc1(r,g);
nfc(2,r,g) = nfc2(r,g);
nfc(3,r,g) = nfc3(r,g);
nfc(4,r,g) = nfc4(r,g);
nfc(5,r,g) = nfc5(r,g);
nfc(6,r,g) = nfc6(r,g);

// null NFC filters to allow very high order decoders. FIXME!
nfc(o,r,g) = gain(g);

//declare name "nfctest";
//process = bus(6):(nfc(0,2,1),nfc(1,2,1),nfc(2,2,1),nfc(3,2,1),nfc(4,2,1),nfc(5,2,1)):bus(6);


// top level api to NFC filters
nfc_out(1,order,r,g) = nfc(order,r,g);
nfc_out(0,order,r,g) = _;

nfc_inp(1,order,r,g) = nfc(order,r,g);
nfc_inp(0,order,r,g) = _;



// ---- delay and level
delay(dc,r)  = R(dc,r) with {
 R(0,r) = _;  // delay_comp off
 R(1,0) = _;  // delay_comp on, but no delay
 R(1,float(0)) = R(1,0);
 R(1,r) = @(meters2samples(r));
 meters2samples(r) = int(m.SR * (float(r)/float(c)) + 0.5);
};

level(lc,r,rmax) = R(lc,r,rmax) with{
 R(0,r,rmax) = _;  // level_comp off
 R(1,r,rmax) = gain(float(r)/float(rmax));
};


delay_level(r) = R(r) with {  // delay_comp and level_comp are free variables (fix?)
 R((r,rl)) =   R(r), R(rl);
 R(r)      =   delay(delay_comp,(r_max-r)) : level(level_comp,r,r_max);
};

// ---- gates
gate(0) = !;
gate(1) = _;
dirac(i,j) = i==j;
gate_bus(order,(o,oss)) = (gate(order==o),gate_bus(order,oss));
gate_bus(order,o)       =  gate(order==o);


// route (not used)
route(n_inputs,n_outputs,outs) = m.bus(n_inputs)
                               <: par(i,n_outputs,(0,gate_bus(i,outs)):>_)
                               : m.bus(n_outputs);

//process = route(4,4,(3,1,1,2)); // test


// deinterleave 
deinterleave(n,span) = par(i,n,_) <: par(i,span, par(j,n,gate(%(j,span)==i)));


// 1 band speaker chain
speaker_chain(ispkr) = gain(s(ispkr,0))  // decoder matrix gains
		     // iterate over orders, select each order from matrix
		     <: par(jord,no,gate_bus(jord,co)
		            // sum and apply NFC filter for that order
			    // at the speaker distance
		            :> nfc_out(nfc_output,jord,m.take(ispkr+1,rs),1.0))
		     // sum the orders
	             :>_;

// 1 band speaker chain -- bad definition
// speaker_chain(i) = gain(s(i,0)) <: par(i,no,gate_bus(i,co):>nfc_out(nfc_output,i,m.take(i+1,rs),1.0)):>_;

// near field correction at input, nfc_input = 1
nfc_input_bus(nc) = par(i,nc, nfc_inp(nfc_input, m.take(i+1,co), r_bar, 1.0));

// per order gains
gamma_bus(n) = par(i,nc, gain( m.take(m.take(i+1,co)+1, gamma(n))));

// output gain and muting
output_gain = hslider("gain [unit:dB]", -10, -30, +10, 1): mu.db2linear :*(checkbox("mute")<0.5): dezipper;

gain_muting_bus(0,n) = bus(n);
gain_muting_bus(1,n) = par(i,n,*(output_gain));


// one band decoder
decoder(1,nc,ns) = nfc_input_bus(nc) 
                :  gamma_bus(0) 
                <: par(is,ns, speaker_chain(is)) 
                : delay_level(rs); 


// two band decoder
//   there are two variants of the two-band decoder
//     1. classic, with shelf-filters and one matrix
//     2. vienna,  bandsplitting filters and separate LF and HF matricies.

// classic shelf filter decoder
decoder(2,nc,ns) = nfc_input_bus(nc) 
                :  par(i,nc, shelf(xover_freq,m.take(m.take(i+1,co)+1, gamma(0))/lfhf_ratio,
                                              m.take(m.take(i+1,co)+1, gamma(1))*lfhf_ratio))
                <: par(is,ns, speaker_chain(is)) 
                :  delay_level(rs);

// vienna decoder
//   FIXME FIXME  need to incorporate lfhf_ratio
decoder(3,nc,ns) = bus(nc)
                   : nfc_input_bus(nc) 
                   : xover(xover_freq,nc) : deinterleave(2*nc,2) 
                   : (gamma_bus(0),gamma_bus(1)) : bus(2*nc)
                   <: par(j, ns, speaker_chain2(j,nc))
                   : delay_level(rs)
; 
// 2 band speaker chain for vienna decoder
// i is speaker, j is order
speaker_chain2(i,nc) = gain(s(i,0)), gain(s(i,1))
                       :> bus(nc)
                       <: par(j,no,gate_bus(j,co):>nfc_out(nfc_output,j,m.take(i+1,rs),1.0))
                       :>_ ;

//process = speaker_chain2(1,16); // test



// --------------------------------------
//  things calculated from decoder config 

// maximum and average speaker distance
r_max = sup(rs);
r_bar = (rs :> float) / float(count(rs));

// number of ambisonic orders, including 0
no = decoder_order+1;

// number of input component signals
nc = count(co);



// the top-level process
process = input_mask(input_full_set):decoder(decoder_type,nc,ns):gain_muting_bus(output_gain_muting,ns);


// End of decoder implementation.  No user serviceable parts above here!
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//EOF!
