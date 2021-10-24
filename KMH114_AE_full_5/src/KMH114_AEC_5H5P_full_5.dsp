// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 18:12:19

//------- decoder information -------
// decoder file = ../decoders/KMH114_AEC_5H5P_Slepian24_2_band.dsp
// description = KMH114_AEC_5H5P_Slepian24_2_band
// speaker array name = KMH114_AEC
// horizontal order   = 5
// vertical order     = 5
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HP
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 
// output speaker order: L C R RSF RSR RR RL LSR LSF ULF URF URR URL VOG 
//-------


// start decoder configuration
declare name "KMH114_AEC_5H5P_full_5";

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
gamma(1) = (             1,  0.9324695142,  0.8042490924,  0.6282499246,  0.4220050093,  0.2057123111);

// gain matrix
s(00,0) = ( -0.0063079887,  0.0273214472, -0.0867338623, -0.0101124522,  0.0561867433, -0.0211050721, -0.0315013589, -0.0692311721,  0.1793033623,  0.1540261323, -0.0527006097, -0.0507102672,  0.2430914662, -0.0392560914, -0.0154400229,  0.0468129878,  0.1165661133, -0.0401782967, -0.0841624604,  0.0358260208,  0.1576716005,  0.1212290796,  -0.182406607,  0.1179411931, -0.1961666854,  0.1822976062,  0.0822532064, -0.1891998698,  0.0579311799,  0.0915335254, -0.2762198568,  0.1697857857,  -0.010241568,  0.1072859271, -0.1494612188, -0.3674433405);
s(01,0) = (  0.0517741927, -0.0039599204,  0.0941868106,  0.1414542196, -0.0029225481,  0.0016011245, -0.0819862825,   0.066869098, -0.0611995498, -0.0149658461,  0.0027412172,  0.0062516535, -0.3016356395,   -0.12985806,   0.005269965,  0.0977383861, -0.0029014123,  0.0029499697,  0.0043777024, -0.0026476731,  -0.086733938, -0.1219985274,  0.0622587445, -0.1394651333,  0.3283558502, -0.0227398785,   -0.00204734,  0.0171777301, -0.0030132849, -0.0094119279,  0.3243948567,  0.0081544329,  0.0034956363, -0.2641094531,  0.2415850764,   0.490963814);
s(02,0) = ( -0.0063634679, -0.0219911378, -0.0871396036, -0.0101065828, -0.0560732284,  0.0200165812, -0.0315815509, -0.0695539175,  0.1800558427, -0.1392655398,  0.0525941379,  0.0430987266,  0.2442504174,  -0.039506637, -0.0155048199,  0.0470952707, -0.1229001208,  0.0383100103,  0.0839924258, -0.0341242602,  0.1583603477,  0.1217922566, -0.1831721108,  0.1184804059, -0.1971510272, -0.1543825026,  -0.086722708,    0.17357382, -0.0578141407, -0.0816851297, -0.2775261428,  0.1706466008, -0.0102845487,   0.107715224, -0.1502062308, -0.3691100237);
s(03,0) = (  0.0349712464, -0.0492801279, -0.0417467763,  0.0223558296, -0.1057614659,  0.0418946245, -0.1134668605, -0.0122442039, -0.1147862387,  0.0660838551,  0.0991994448,  0.0943377452,  0.0851469431, -0.0377094873,  0.0098843777, -0.1366402076,  0.1515574483,  0.0617488483,  0.1584207353, -0.0712971654,  0.1473688391,  0.0205428509,  0.1167728706,  0.0247802461,  0.0031565195,  0.1358832413,  0.1069443401,  0.0189306462, -0.1090450549, -0.1751685547, -0.1122733917,  0.0616151785,  0.0065564363,  0.1540867114,  -0.004864399,  0.1834532305);
s(04,0) = (  0.0382920821, -0.1112262255,  0.0473657814,  0.0115288884,  0.0057862679, -0.0242768207, -0.0729279685, -0.0153468858, -0.1796942459,  0.1757792452, -0.0054272561,  0.1234210884, -0.1619625115, -0.0262445254,  0.0154736824,  0.0827559637, -0.1244890473, -0.0660347105, -0.0086672855,  0.0465226577, -0.0205700485,  0.0263600029,  0.1828042557,  0.0205852781,  0.1965901372,  -0.141759886, -0.0878439111,  -0.241248914,  0.0059659149, -0.0812164175,   0.169802665,  0.0556308353,  0.0102638947, -0.0482163629,  0.1431188875, -0.1422285162);
s(05,0) = (  0.0017872386,  0.0320510013, -0.1144532769, -0.0479086771,  0.1143574282,  0.0718059858, -0.0677211543,  0.0621445309,   0.075408812, -0.1111419845, -0.1072620665,  0.0132491447,  0.3123062116,  0.1078444464, -0.0064935413,  0.0155515675,  -0.046900986,  0.1333641681,  -0.171296679, -0.1265424106,  0.2270776696, -0.1066981911, -0.0767139298, -0.1008187259, -0.2329016427,   0.225395671, -0.0330950082,  0.2685914265,  0.1179078971, -0.1479322488, -0.3589966886, -0.2269179906, -0.0043072504, -0.1416891606, -0.1793838156,  0.1149736802);
s(06,0) = (  0.0016358513, -0.0303263195, -0.1165853222, -0.0481647751, -0.1160923965, -0.0716634919,  -0.068505002,  0.0604425693,  0.0798285543,  0.1134209572,  0.1088893878, -0.0153392849,  0.3182786774,  0.1068889349, -0.0068741305,  0.0166933496,  0.0401030454, -0.1329936227,  0.1738954983,  0.1262294609,  0.2309603745, -0.1037176468, -0.0812101656, -0.0979177889, -0.2377142791, -0.2176128634,  0.0282981389, -0.2701710559, -0.1196967311,  0.1498107412,  -0.365784579, -0.2227538189, -0.0045597001, -0.1390416515, -0.1830513103,  0.1059340014);
s(07,0) = (  0.0384308347,  0.1097946536,  0.0493085172,  0.0117605938, -0.0045314185,  0.0242102715, -0.0722158086, -0.0137960802, -0.1837188657, -0.1779320079,  0.0042502645,    -0.1216472, -0.1674053443, -0.0253717762,  0.0158202471,  0.0817135957,  0.1296351413,  0.0658290973,  0.0067876391, -0.0463531951, -0.0241064803,  0.0236442306,  0.1868985305,  0.0179423114,  0.2009775206,  0.1351691177,  0.0914751786,  0.2429235967,  -0.004672106,  0.0795203946,  0.1759882814,  0.0518343414,  0.0104937756, -0.0506265367,  0.1464621612, -0.1339931157);
s(08,0) = (  0.0346845177,  0.0497723282, -0.0457115007,  0.0218902622,  0.1066355719,  -0.042236274, -0.1149110164,  -0.015408926, -0.1065846575, -0.0635036942, -0.1000193165, -0.0952222493,  0.0962576328, -0.0394997686,  0.0091781299, -0.1345042649, -0.1498276458, -0.0623966597,  -0.159730064,  0.0718752597,  0.1545792685,  0.0260846444,  0.1084293427,  0.0301722806, -0.0058063759, -0.1326965167, -0.1057237298, -0.0220681237,  0.1099462994,  0.1767155795,  -0.124898902,  0.0693721739,  0.0060879729,  0.1589954219, -0.0116936218,   0.166653635);
s(09,0) = (  0.0184967747,  0.0515230001,  0.0820344495,   0.085283068,  0.0583642361,    0.09041693, -0.0034566605,  0.0906684927,  -0.026932541,  0.0687754012,  0.1728657939,  0.0019249113, -0.2421889036, -0.0408983926,  0.0023191927,  -0.060489811,  0.0620231609,  0.1589269838,  0.0403248749,  -0.159792171, -0.1255303616, -0.1614886574,  0.0273986687, -0.1644823568, -0.0299514934, -0.0637243584,  0.0437657541,  0.1381016524, -0.2299370834, -0.1696631673,  0.2706447015, -0.1261913519,  0.0015383507, -0.1525210389, -0.0117600682,  0.0092209238);
s(10,0) = (  0.0185397541, -0.0533658993,  0.0824902691,  0.0853160886, -0.0562477681, -0.0906425071, -0.0033165299,  0.0910319057, -0.0278421879, -0.0708405153, -0.1748509446,  0.0002532658, -0.2434746803, -0.0406667665,  0.0023975235, -0.0607597838, -0.0540554998,  -0.159467437,  -0.043495145,  0.1602545589, -0.1263405021,  -0.162124274,  0.0283240591, -0.1650974459, -0.0288953301,  0.0555932577, -0.0381434883, -0.1369289671,  0.2321192616,  0.1678497788,  0.2721016892, -0.1271088293,  0.0015903085, -0.1530573969, -0.0109572474,  0.0111322169);
s(11,0) = (  0.0177973525, -0.0708382677,  0.0820391485, -0.0451757573,  0.0475071588, -0.0927363105, -0.0016450431, -0.0935927322, -0.0292676111, -0.0906461889,  0.1830492387,  0.0209381795,  -0.241615529, -0.0124022466,  0.0025202683,  0.1114396475,   0.021054465, -0.1645029789,  0.0565877562,  0.1645600828, -0.1268549082,  0.1650991772,  0.0297741524,  0.1613502387, -0.0317373535, -0.0216103459,  0.0148567813, -0.1254954934, -0.2411312417,  0.1505385423,  0.2702789794,  0.1863507846,  0.0016717268,  0.1028757925, -0.0129868932,  0.0106478277);
s(12,0) = (  0.0178089288,  0.0702025638,   0.082192927, -0.0451586311, -0.0467646882,   0.092655036, -0.0015902059, -0.0934700026, -0.0295842113,  0.0899513082, -0.1837456423, -0.0201894304, -0.2420468573, -0.0123316354,  0.0025475312,  0.1113556925, -0.0182728044,  0.1643097267, -0.0576999074, -0.1643945392, -0.1271337212,  0.1648842983,  0.0300962321,  0.1611413188, -0.0313885444,  0.0188142855, -0.0128939424,  0.1258756783,  0.2418967639, -0.1511549117,  0.2707689287,  0.1860487504,  0.0016898105,  0.1026866716, -0.0127212073,  0.0112985136);
s(13,0) = (  0.0108528102,    -8.163e-06,  0.0905777117, -0.0084754711,    5.5734e-06,      6.22e-08,  0.1782440252,   0.000562576,  0.0120068964,  -1.45047e-05,   -5.2276e-06,   1.04476e-05,  0.1882869349,  0.0112217798, -0.0010339279,  -0.010719497,   2.51039e-05,    -3.018e-07,   -8.3485e-06,     1.952e-07,  0.2402770038,  -0.000666312, -0.0122147025,  0.0007545938,    0.01286852,  -3.86968e-05,   1.77142e-05,   1.26531e-05,    5.7465e-06,  -1.08388e-05,  0.2917615142, -0.0125665077, -0.0006858178,  0.0105660272,   0.014118593,  -0.004485496);


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
