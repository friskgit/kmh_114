// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 20:41:41

//------- decoder information -------
// decoder file = ../decoders/KMH114_AE_5h5v_pinv_even_energy_rV_max_rE_2_band.dsp
// description = KMH114_AE_5h5v_pinv_even_energy_rV_max_rE_2_band
// speaker array name = KMH114_AE
// horizontal order   = 5
// vertical order     = 5
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HV
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 
// output speaker order: L R RSF RSR RR RL LSR LSF ULF URF URR URL VOG 
//-------


// start decoder configuration
declare name "KMH114_AE_5h5v_normal_2";

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
gamma(1) = (   1.055276836,  0.9840134786,  0.8487054375,  0.6629775927,  0.4453321109,  0.2170834367);

// gain matrix
s(00,0) = (  0.1306401636,  0.0619852194,  -0.026382842,  0.1719898393,  0.1128331746,  -0.020468668, -0.0852826236, -0.0242033538,  0.1658512231,    0.17806949,   -0.03395422, -0.0491394596,   0.016403952, -0.1185434036,            -0,  0.0975958575,  0.1744816705, -0.0223578806, -0.0940358286,  0.0217828882,   0.063810567,  0.0257573648, -0.1070565042,  0.0264372697,  0.0178405311,   0.156227491,            -0, -0.1333270681,  0.0320495751,  0.0512143097, -0.0284880279,  0.1083392573,             0, -0.0461720694,  0.0343437472, -0.0644485194);
s(01,0) = (  0.1273624709, -0.0641658417, -0.0272337003,  0.1666043251,  -0.118494638,  0.0217309916, -0.0835957725, -0.0266083199,  0.1605602263, -0.1826034385,  0.0358245384,  0.0511643822,  0.0184422952, -0.1165592241,            -0,  0.0869137045, -0.1773268135,  0.0237367139,  0.0988581865, -0.0231262611,  0.0641638558,  0.0283167452, -0.1036411804,  0.0290642088, -0.0016634586, -0.1491539366,             0,  0.1372846797, -0.0338149789,  -0.053577785,   -0.02948104,  0.1082235871,             0, -0.0372800094,  0.0366628274, -0.0857154387);
s(02,0) = (  0.1326391245, -0.1448275147, -0.0365869828,  0.0649945985, -0.1473971005,  0.0364560886,  -0.090838331, -0.0217865437, -0.1220309781,  0.0321509749,  0.0490825291,  0.1086032465,  0.0296529978, -0.0517022365,            -0, -0.1855408419,  0.1764320566,  0.0398209047,  0.1257934478,  -0.038796804,  0.0753447575,    0.02318538,  0.0787706577,  0.0237973934, -0.0567412592,  0.1331638372,             0,  0.0064211356, -0.0463292693, -0.1078833689, -0.0398461068,  0.0540365579,             0,  0.1392697791,  0.0531689555,  0.1165713981);
s(03,0) = (  0.1307132898, -0.1891323455, -0.0072451472, -0.0401602803,  0.0547354611, -0.0083706389, -0.0774361718, -0.0067890719, -0.1789747331,  0.1843480611, -0.0092639943,  0.1112468059, -0.0098889386,  0.0208843821,            -0,  0.0923789633, -0.1516722155, -0.0091432304, -0.0411163844,  0.0089080878,  0.0425546387,   0.007224974,  0.1155276934,  0.0074156882,  0.1527978275, -0.0871900379,            -0, -0.1282919616,  0.0087443352, -0.0828911967,  -0.007115068, -0.0124089327,             0,    -0.0559469, -0.0021220964, -0.1820771206);
s(04,0) = (  0.1086401446, -0.0751226798,  -0.046470381, -0.1000842529,  0.1630198294,  0.0531488129, -0.0795512286,  0.0486834883,    0.00885697, -0.1169563094, -0.0560618906,  0.0750366621,   0.050559228,  0.0878831684,             0,  0.1125242449,  -0.048740884,  0.0580543306, -0.1402360591, -0.0565613087,  0.0826987192, -0.0518092815, -0.0057171495, -0.0531768664, -0.1858614151,  0.1730148274,             0,  0.1177238204,   0.052917127, -0.0914315715, -0.0512444091, -0.0988898984,            -0, -0.1114010418,  0.0778829178,   0.087057871);
s(05,0) = (  0.1096778975,  0.0750511723, -0.0467532932,  -0.098415976, -0.1631716946, -0.0530918211, -0.0803351535,  0.0485343644,  0.0105834856,  0.1166191364,  0.0561597385, -0.0749617399,   0.050623903,  0.0867800997,             0,  0.1139280253,   0.048374993, -0.0579920786,  0.1403951876,  0.0565006577,  0.0831654078, -0.0516505829, -0.0068316106, -0.0530139787, -0.1846644372, -0.1734165612,            -0, -0.1174575183, -0.0530094862,  0.0913379087, -0.0515444233, -0.0979277528,            -0, -0.1122163014,  0.0781619163,  0.0876450806);
s(06,0) = (  0.1296921502,  0.1892909423,  -0.006991754, -0.0418146797, -0.0541681704,  0.0081791648, -0.0766703248,  -0.006696386, -0.1806634788, -0.1836074442,  0.0089597189, -0.1114485228, -0.0099078484,  0.0219481223,            -0,  0.0909053489,  0.1524737096,  0.0089340836,  0.0405601985, -0.0087043198,  0.0421308208,   0.007126337,  0.1166177741,  0.0073144475,  0.1513452584,  0.0872436315,             0,  0.1276566723,  -0.008457128,   0.083166347,  -0.006848277, -0.0133058893,             0, -0.0550425872, -0.0023406664, -0.1830006724);
s(07,0) = (  0.1346273153,  0.1455560581, -0.0373695635,  0.0682068796,  0.1492308796, -0.0370320134, -0.0924154899,  -0.022547506,  -0.118368746, -0.0293363806, -0.0499970421, -0.1093639969,  0.0301593789, -0.0540850398,            -0, -0.1832640475,  -0.173642937, -0.0404499862, -0.1275482044,   0.039409707,  0.0765444304,  0.0239952009,   0.076406697,  0.0246285908, -0.0563267256, -0.1317451236,            -0, -0.0087202077,  0.0471924832,  0.1088327402, -0.0406921067,  0.0563800651,             0,   0.138341743,  0.0542035687,  0.1151788809);
s(08,0) = (  0.0980927554,  0.1050456973,   0.073443017,  0.0983248276,  0.1335552721,   0.112864893, -0.0218155594,   0.104644149,   0.000857287,  0.0820512219,   0.164166473,  -0.002672381, -0.1074930366, -0.0030474517,             0, -0.0971319549,  0.0230318916,  0.1232820725,  0.0163023345, -0.1201115454, -0.0497155945, -0.1113629767, -0.0005533764,  -0.114302572, -0.1166116919, -0.0755895051,             0,  0.0314447929, -0.1549576372,  -0.066074678,  0.0823453904, -0.0608115919,            -0, -0.0152264846, -0.1452322434, -0.1043757592);
s(09,0) = (  0.0984693022, -0.1042213226,  0.0739336992,  0.0988060771, -0.1309816752, -0.1137231769, -0.0218911499,  0.1057193741,  0.0004429673, -0.0783609983, -0.1655461029,  0.0016987019,  -0.108362293, -0.0027547924,             0, -0.0960018734, -0.0190809702, -0.1242195741, -0.0188250784,  0.1210249366, -0.0502628654, -0.1125072382, -0.0002859342,  -0.115477038, -0.1122617555,  0.0768143423,            -0, -0.0345374802,  0.1562598774,  0.0673629715,   0.082902984, -0.0616925572,            -0, -0.0167905556, -0.1463238276, -0.0987971311);
s(10,0) = (   0.121149155, -0.1133023157,  0.0736682303, -0.1252956782,  0.1340053313, -0.1126618189, -0.0365952597, -0.1088948085,  0.0236432883, -0.1046862618,  0.1641873258,  0.0078394398, -0.1150986258,  0.0172416492,            -0,   0.070543992,  0.0279055693, -0.1230602551,  0.0160248439,  0.1198954326, -0.0466589758,  0.1158865559,  -0.015261677,   0.118945558, -0.0596038414,  0.0307665241,            -0, -0.0163188943, -0.1549773203,   0.061867072,   0.082955893,  0.0521581316,             0,  0.0360409825, -0.1515178067,  0.0747509513);
s(11,0) = (  0.1212756445,  0.1131359772,  0.0736794327,  -0.125137283, -0.1344475784,  0.1128408715, -0.0366606414, -0.1088569198,  0.0237495441,  0.1038431736, -0.1638931081, -0.0076397676, -0.1151287458,  0.0171653498,            -0,  0.0706682083,    -0.0288074,  0.1232558339, -0.0155556536, -0.1200859816,  -0.046634779,  0.1158462346, -0.0153302648,  0.1189041723, -0.0593935759, -0.0314822436,             0,  0.0170125283,  0.1546996065, -0.0621331014,  0.0829691285,  0.0521955611,             0,  0.0359300461, -0.1515509751,  0.0749462007);
s(12,0) = (  0.1397422184,  -6.88327e-05,  0.2157059023, -0.0072922596,  -6.91655e-05,   3.73084e-05,  0.2642194899,  0.0022935385,  0.0114752298, -0.0002849887,   6.37578e-05,   6.25317e-05,  0.2386829589,  0.0057184701,             0, -0.0089638471, -0.0002621523,   4.07518e-05,    8.4459e-05,  -3.97038e-05,  0.2040332749, -0.0024407984,  -0.007407229,  -0.002505227,  0.0279254501,  -0.000505582,             0,  0.0002168366,  -6.01813e-05,  -7.19755e-05,  0.2145753905,   -0.00590649,            -0,  0.0041871727,  0.0184430323,  0.0096030445);


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
