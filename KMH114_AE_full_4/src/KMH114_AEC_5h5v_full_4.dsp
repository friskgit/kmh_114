// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 18:11:58

//------- decoder information -------
// decoder file = ../decoders/KMH114_AEC_5h5v_pinv_energy_limit_050_rV_max_rE_2_band.dsp
// description = KMH114_AEC_5h5v_pinv_energy_limit_050_rV_max_rE_2_band
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
declare name "KMH114_AEC_5h5v_full_4";

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
s(00,0) = (  0.0496560341,  0.0479686275, -0.0485693422,  0.0786104642,  0.0946926739, -0.0346395803,  -0.046668905, -0.0837887537,  0.1626377569,  0.1803784543, -0.0520955267, -0.0482972298,   0.062725738, -0.0939101665,            -0,  0.0558890522,  0.1660162231, -0.0378367368, -0.0936543189,  0.0368636643,  0.0697067674,  0.0891685308, -0.1049822206,    0.09152227, -0.1590881619,  0.1602110238,            -0,  -0.145616571,  0.0491732543,  0.0591098322, -0.0540452568,  0.1248635221,             0,  0.0266672245,  0.0893334074, -0.2758717154);
s(01,0) = (  0.1211148682, -0.0031069543,  0.0199278146,  0.1604003786, -0.0034089286,  0.0024866187, -0.0671943422,  0.0736049643,   0.059903881, -0.0113050201,  0.0029133033,  0.0032609785, -0.0597665144, -0.0580165844,             0,  0.1282248736,  -0.006243229,  0.0027161281,  0.0040196332, -0.0026462756, -0.0004443813, -0.0783308767, -0.0386677889, -0.0803985394,  0.3296277425, -0.0137623855,             0,  0.0093660599, -0.0027498831, -0.0040803218,  0.0238489163,  0.0013976618,            -0, -0.1407129406, -0.0639683797,  0.3857916772);
s(02,0) = (  0.0492443204, -0.0452083883, -0.0489472058,  0.0777754214, -0.0956489302,  0.0330791592, -0.0465794643, -0.0845033977,  0.1609670635, -0.1717474134,  0.0513943386,  0.0457545242,  0.0633304644, -0.0937891979,            -0,  0.0520935091, -0.1655469186,  0.0361322923,  0.0938337307, -0.0352030541,  0.0700352328,  0.0899290596, -0.1039037927,   0.092302874, -0.1658625942,  -0.140738382,             0,  0.1387225938,  -0.048511399, -0.0561569177, -0.0544714655,  0.1251996406,             0,  0.0297204851,  0.0901221045, -0.2830417379);
s(03,0) = (   0.110935888, -0.1215945302, -0.0488617619,  0.0517299173, -0.1300712442,   0.056681235, -0.0880156775, -0.0253992789, -0.1305295935,  0.0441266028,  0.0768919859,  0.1054243986,  0.0400312028, -0.0455528404,            -0, -0.1733773784,  0.1852273589,  0.0619127874,  0.1319749555,  -0.060320535,  0.0761109168,  0.0270300761,  0.0842564903,  0.0277435761, -0.0233847852,   0.120163957,             0,  0.0138602285, -0.0725787686, -0.1175893011, -0.0532354528,  0.0513576692,             0,  0.1339681387,   0.071351864,  0.1586315945);
s(04,0) = (  0.1074145263, -0.1784808861,   0.000875687, -0.0252393225,  0.0309417455,   -0.02339426, -0.0654251379, -0.0128551428, -0.1803205543,  0.2073693524, -0.0070166255,  0.0965171918, -0.0275548646,  0.0084334861,            -0,  0.0772007781,  -0.145022452, -0.0255534983, -0.0243542631,   0.024896322,  0.0200233332,  0.0136805257,  0.1163964173,   0.014041644,   0.199360705, -0.1136947195,            -0, -0.1549289808,  0.0066230314, -0.0621698862,  0.0022745204,  0.0010991847,             0, -0.0413005251, -0.0228203982, -0.1676529178);
s(05,0) = (  0.0689771856, -0.0237586571, -0.0718323125, -0.0796215166,  0.1499804057,  0.0911479636, -0.0691447644,  0.0806668059,  0.0324159006, -0.1415647763, -0.0919204574,  0.0643405475,   0.087632786,  0.0928238806,             0,  0.0902759138, -0.0414334524,  0.0995607186, -0.1542106226, -0.0970002493,  0.0976618676, -0.0858461339, -0.0209243738, -0.0881121733, -0.2307783966,  0.1958606038,             0,  0.1628596947,  0.0867642255,  -0.105932756,  -0.079678277, -0.1221186114,            -0,  -0.120975262,  0.1279981161,  0.1053808797);
s(06,0) = (   0.069160977,  0.0238830954, -0.0728188863, -0.0789241276, -0.1499572196, -0.0912141717, -0.0696543097,  0.0788865003,  0.0352529275,    0.14186747,  0.0918879083, -0.0644529176,  0.0889636329,  0.0914242912,             0,   0.091230501,  0.0413768474, -0.0996330376,  0.1541753311,  0.0970707084,  0.0988099829, -0.0839515213, -0.0227556668, -0.0861675495, -0.2340372648, -0.1954033359,            -0, -0.1631101902, -0.0867335023,  0.1060615921,  -0.080778872, -0.1199365664,            -0,  -0.120254588,   0.129858244,  0.1000366714);
s(07,0) = (  0.1072510942,  0.1781713264,  0.0017988283, -0.0258882885, -0.0307129219,  0.0234600004, -0.0649517941, -0.0111895423, -0.1829958482, -0.2078952832,  0.0069057763,  -0.096291714, -0.0287983301,  0.0097407626,            -0,  0.0762697384,  0.1455878707,  0.0256253064,  0.0241373395, -0.0249662834,  0.0189535674,   0.011907983,  0.1181233121,  0.0122223123,  0.2023511766,  0.1122240655,             0,  0.1553267787, -0.0065184002,  0.0619519132,  0.0033042626, -0.0009405815,             0, -0.0419496601, -0.0245594721, -0.1627092119);
s(08,0) = (  0.1114019186,  0.1219028516, -0.0507686878,  0.0532257454,  0.1317137921, -0.0573221463, -0.0890639701, -0.0288093811, -0.1251011173, -0.0417404181, -0.0780493074, -0.1059633168,  0.0425860865, -0.0483316808,            -0, -0.1716818722, -0.1820441046, -0.0626128534, -0.1337578919,   0.061002597,  0.0783588356,  0.0306591287,   0.080752424,  0.0314684231, -0.0299252602, -0.1192940249,            -0,  -0.015925289,  0.0736711707,  0.1184025602, -0.0553619076,  0.0556147504,             0,  0.1354365091,  0.0749332322,   0.148019238);
s(09,0) = (  0.0747507476,   0.084980331,  0.0837505765,  0.0981302629,  0.1079734111,   0.133508777, -0.0091698792,  0.1324916758,   0.000402254,  0.0616477222,  0.1854353342,  0.0208922314,  -0.128790957,  0.0122839637,             0, -0.0701318438,  0.0385003418,  0.1458313412,  0.0460964539, -0.1420808995, -0.0751543355, -0.1409984939, -0.0002596538, -0.1447203638, -0.0483173049, -0.0678746958,             0,  0.0606186807, -0.1750334323, -0.0971761524,  0.0942079953,  -0.089756237,            -0, -0.0542345122, -0.1706010666, -0.0368212113);
s(10,0) = (  0.0746453844, -0.0856180563,  0.0840895346,  0.0978202679, -0.1062798734, -0.1337810092, -0.0089764441,  0.1330900688, -0.0003211462, -0.0613851189, -0.1865471605, -0.0206504183, -0.1292541727,  0.0128006803,             0, -0.0700840257, -0.0347280265, -0.1461286998, -0.0478838951,  0.1423706108, -0.0755689988, -0.1416353076,   0.000207299, -0.1453739872, -0.0465676521,  0.0647458966,            -0, -0.0609991264,  0.1760828913,  0.0971494515,  0.0945864218, -0.0905262568,            -0, -0.0547205976, -0.1712449488, -0.0343807573);
s(11,0) = (  0.0877792857, -0.1053990753,  0.0808776401, -0.1165521061,  0.1072092254, -0.1338628269, -0.0189278286, -0.1316201638,   0.022227743, -0.0865933394,  0.1864582028, -0.0085817621, -0.1293388081, -0.0005268538,            -0,  0.0511029996,  0.0372495193, -0.1462180691,  0.0472284523,  0.1424576817, -0.0703628081,  0.1400710253, -0.0143479464,  0.1437684132, -0.0266615778, -0.0067611476,            -0, -0.0443875932, -0.1759989236,  0.0876577713,  0.0912206606,  0.0799349012,             0,  0.0661590296, -0.1687347865,  0.0295624683);
s(12,0) = (  0.0878351803,  0.1055614464,  0.0810242114, -0.1165456793, -0.1074742807,  0.1339070846, -0.0189007442, -0.1313382607,  0.0218877236,   0.086595646, -0.1862462816,  0.0085065072, -0.1295518355, -0.0003767942,            -0,    0.05103071, -0.0379858502,  0.1462664117, -0.0469250281, -0.1425047811, -0.0705133815,  0.1397710221, -0.0141284648,   0.143460491, -0.0260816317,  0.0073011138,             0,  0.0444196796,    0.17579889, -0.0876250154,  0.0913849248,  0.0796459567,             0,    0.06599275, -0.1690234262,  0.0304089038);
s(13,0) = (  0.1070271549,   1.18401e-05,   0.196914857, -0.0134061042,   -3.9173e-06,    1.1996e-06,  0.2561703366,  0.0013267874,  0.0127062396,  -1.70535e-05,   1.52854e-05,   -6.5952e-06,  0.2281384651,  0.0089343129,             0, -0.0141866392,  -8.08231e-05,    1.3103e-06,   1.20734e-05,   -1.2766e-06,  0.1860552419, -0.0014119757, -0.0082018424, -0.0014492469,  0.0177849847,  -6.16583e-05,            -0,   1.21909e-05,   -1.4428e-05,    4.4892e-06,  0.1953786004, -0.0078647737,            -0,  0.0083759355,  0.0250623055, -0.0024050051);


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
