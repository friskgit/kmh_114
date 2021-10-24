// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 20:43:44

//------- decoder information -------
// decoder file = ../decoders/KMH114_AE_5H5P_Slepian24_2_band.dsp
// description = KMH114_AE_5H5P_Slepian24_2_band
// speaker array name = KMH114_AE
// horizontal order   = 5
// vertical order     = 5
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HP
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 
// output speaker order: L R RSF RSR RR RL LSR LSF ULF URF URR URL VOG 
//-------


// start decoder configuration
declare name "KMH114_AE_5H5P_normal_5";

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
ns = 13;

// radius for each speaker in meters
rs = (          3.26,           3.3,          3.35,          3.27,         3.364,         3.376,         3.262,         3.296,          3.02,          3.02,          3.05,          3.02,           1.6);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1,             1,             1);
gamma(1) = (             1,  0.9324695142,  0.8042490924,  0.6282499246,  0.4220050093,  0.2057123111);

// gain matrix
s(00,0) = (  0.0274692952,  0.0247380104, -0.0252867499,  0.0821717358,  0.0542800841, -0.0200605047, -0.0849888938, -0.0256060302,  0.1393770118,   0.144262472, -0.0509122502, -0.0466317125,  0.0463055369, -0.1239749894,  -0.012001918,  0.1105771344,   0.114673243, -0.0382537478, -0.0813064642,  0.0340986891,  0.1010867135,  0.0416377103, -0.1417892419,  0.0269546774,  0.0180514064,  0.1674621971,  0.0809175296, -0.1779931849,  0.0559653245,    0.08539322, -0.0645859019,  0.1751057064, -0.0079610283, -0.0650180627,  0.0081479544, -0.0471404396);
s(01,0) = (  0.0261231625, -0.0244758597,  -0.028040428,  0.0786513624, -0.0579070328,  0.0210212349,   -0.08302529, -0.0275957225,  0.1416551057, -0.1486561239,   0.054314163,  0.0470214368,  0.0549838149, -0.1209883672, -0.0121980874,   0.108422945, -0.1247206632,  0.0401610208,  0.0867392924, -0.0357855894,  0.1039376084,  0.0452421287, -0.1441067634,   0.030970548,  0.0088816429, -0.1686510405, -0.0880073476,  0.1843522898, -0.0597048794, -0.0875908099, -0.0739788679,  0.1757632436,   -0.00809115, -0.0580049109,  0.0013805867, -0.0610461185);
s(02,0) = (  0.0350583202, -0.0492867877,  -0.041588373,  0.0225937272,  -0.105766381,  0.0418973173, -0.1136047449, -0.0121317436,  -0.114889164,  0.0660586856,   0.099204055,  0.0943482592,  0.0846396525, -0.0379278825,  0.0098932407, -0.1364758312,  0.1515525687,  0.0617538095,  0.1584280978, -0.0713016183,    0.14722297,  0.0203376739,  0.1168775773,  0.0245456938,  0.0037087481,  0.1358449974,  0.1069408969,  0.0189595357, -0.1090501226, -0.1751843837, -0.1117278247,  0.0616288927,  0.0065623152,  0.1536425324, -0.0044581015,   0.184278933);
s(03,0) = (  0.0233485921, -0.1100832809,  0.0201808155, -0.0292987828,  0.0066297976, -0.0247389503, -0.0492644186, -0.0346471905, -0.1620303324,  0.1800988098, -0.0062184486,  0.1216166852, -0.0749019717,  0.0112361676,   0.013952622,  0.0545459131,  -0.123651618, -0.0668861548, -0.0099308137,  0.0472868508,  0.0044638085,  0.0615722134,  0.1648346288,   0.060838843,  0.1018173922, -0.1351965167, -0.0872529912, -0.2462068907,  0.0068356337, -0.0784998701,  0.0761731742,  0.0532772363,  0.0092549556,  0.0280130628,  0.0733906313, -0.2839344987);
s(04,0) = (  0.0209333538,  0.0305866213, -0.0796229603,  0.0044011445,  0.1132766689,  0.0723980822, -0.0980397112,  0.0868727475,  0.0527771964, -0.1166763598, -0.1062483634,  0.0155610084,  0.2007612431,  0.0598228889, -0.0045447063,   0.051695258, -0.0479739293,  0.1344550679, -0.1696778031,  -0.127521521,   0.195003428, -0.1518132907, -0.0536906235, -0.1523929826, -0.1114755307,  0.2169864557, -0.0338521153,  0.2749437573,  0.1167935833, -0.1514127831, -0.2390353533, -0.2239024784, -0.0030145628, -0.2393569318,  -0.090045567,   0.296532276);
s(05,0) = (   0.021817107, -0.0318698717, -0.0798718938,  0.0069731929, -0.1172315874, -0.0710393836,  -0.100462741,  0.0865077245,  0.0559733535,  0.1075873642,  0.1099578971, -0.0129024295,  0.2007029961,  0.0562710772, -0.0048199311,  0.0547911598,  0.0389720931,  -0.131843743,  0.1756018993,  0.1251974146,  0.1971520292,  -0.151271908, -0.0569420973, -0.1522804236, -0.1097232271, -0.2264767255,  0.0275000986, -0.2634752844, -0.1208712907,  0.1461420307, -0.2393374975,  -0.219575272,  -0.003197123, -0.2419898606,  -0.088882962,  0.2973086182);
s(06,0) = (  0.0225891516,  0.1110062959,  0.0204895723, -0.0315210646, -0.0036371877,  0.0237203651, -0.0471299378, -0.0342564487, -0.1649932453, -0.1733528116,  0.0034115166, -0.1235600587, -0.0751119454,  0.0143617306,   0.014207762,  0.0518079523,  0.1305229051,  0.0649264761,  0.0054481653, -0.0455430695,  0.0024320612,  0.0609729056,  0.1678488215,  0.0606153563,  0.1005083667,  0.1421269847,  0.0921016164,   0.237667616, -0.0037501119,  0.0824002228,  0.0767310982,  0.0493392771,  0.0094241933,  0.0301847333,  0.0725428198, -0.2842164753);
s(07,0) = (  0.0364058612,  0.0496406722, -0.0425800592,  0.0265932096,  0.1065384056, -0.0421830412, -0.1176368253, -0.0131857201, -0.1086193671, -0.0640012657, -0.0999281789, -0.0950143997,  0.0862291123,  -0.043817177,  0.0093533412, -0.1312547437, -0.1499241094, -0.0622985816, -0.1595845179,  0.0717872322,  0.1516956137,   0.022028543,  0.1104992676,  0.0255354646,   0.005110515, -0.1334525525,  -0.105791798, -0.0214970134,  0.1098461163,  0.1764026599, -0.1141137027,  0.0696432854,  0.0062041928,  0.1502145395, -0.0036616103,  0.1829767748);
s(08,0) = ( -0.0020945924,  0.0530979194,  0.0445749531,  0.0290246195,   0.059526577,   0.089780139,  0.0291505043,  0.0640736572, -0.0025925691,   0.074727541,   0.171775571, -0.0005614644, -0.1222239203,  0.0107480907,  0.0002232492, -0.0993618219,  0.0631770958,  0.1577537369,  0.0385837975,  -0.158739152, -0.0910349835, -0.1129680273,  0.0026374393, -0.1090149975, -0.1605435022, -0.0546803703,  0.0445800117,  0.1312698135, -0.2287386552, -0.1659199035,  0.1416280388, -0.1294344913,  0.0001480841, -0.0474807785, -0.1078420487, -0.1860426923);
s(09,0) = ( -0.0016808795, -0.0518193354,  0.0457052052,  0.0300705348, -0.0551063544, -0.0912678332,  0.0287035653,  0.0649158919, -0.0039404405, -0.0649955398, -0.1759215388, -0.0021883443, -0.1256695842,  0.0100498573,   0.000339316, -0.0989319308, -0.0529223407, -0.1606195603, -0.0452048755,   0.161288619, -0.0924661897, -0.1144772245,  0.0040086387, -0.1106287383, -0.1571361195,   0.064474415, -0.0373438909, -0.1436378034,   0.233296113,  0.1715256477,  0.1454078829, -0.1302935782,  0.0002250727, -0.0499083142, -0.1053093379,  -0.180615812);
s(10,0) = (  0.0099060714, -0.0702347075,   0.067683452, -0.0667358232,  0.0479526056, -0.0929803495,  0.0108510822, -0.1037847375, -0.0199397428, -0.0883651355,  0.1826314298,  0.0199853196, -0.1956410486,  0.0073903643,  0.0017170346,  0.0965426296,  0.0214966903, -0.1649526053,  0.0559205188,  0.1649636339, -0.1136351582,  0.1836938596,  0.0202848445,  0.1826071335, -0.0817844555, -0.0181443958,  0.0151688313, -0.1281136761, -0.2406719651,  0.1519730827,  0.2208356011,  0.1851079082,  0.0011389314,  0.1431306342, -0.0498086308, -0.0641835361);
s(11,0) = (  0.0098796392,  0.0708090311,  0.0677680862, -0.0668225413, -0.0463170959,  0.0924098215,  0.0109661071, -0.1037110979, -0.0202114153,  0.0922433483, -0.1841654635, -0.0211468798, -0.1958509402,  0.0075563069,  0.0017404287,  0.0963869229,  -0.017828449,  0.1638579347, -0.0583703586, -0.1639890444, -0.1138502982,  0.1835685422,  0.0205612189,  0.1825005977, -0.0816766988,  0.0222969294, -0.0125803894,  0.1232448851,  0.2423582527, -0.1497134619,  0.2210874058,  0.1847998876,   0.001154449,  0.1431354011, -0.0497202972, -0.0638932764);
s(12,0) = (  0.0119793413,  -9.43251e-05,  0.0926270796, -0.0053976331,   -5.8017e-05,   3.49004e-05,   0.176460123,  0.0020175503,  0.0106752832, -0.0003401398,   5.44173e-05,  0.0001464745,  0.1817237823,  0.0083962574, -0.0009192612,  -0.008592852,  -3.80266e-05,   6.38852e-05,    8.6904e-05,  -5.74143e-05,  0.2383897996, -0.0033208224, -0.0108600428, -0.0022799646,  0.0200130655, -0.0005334835,   -2.6833e-05,  0.0003864155,  -5.98182e-05, -0.0002156287,  0.2988198743, -0.0123890791, -0.0006097579,  0.0048193899,  0.0193751328,  0.0061971622);


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
//route(n_inputs,n_outputs,outs) = m.bus(n_inputs)
//                               <: par(i,n_outputs,(0,gate_bus(i,outs)):>_)


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
