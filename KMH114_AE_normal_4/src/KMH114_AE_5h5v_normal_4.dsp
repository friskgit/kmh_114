// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 20:43:23

//------- decoder information -------
// decoder file = ../decoders/KMH114_AE_5h5v_pinv_energy_limit_050_rV_max_rE_2_band.dsp
// description = KMH114_AE_5h5v_pinv_energy_limit_050_rV_max_rE_2_band
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
declare name "KMH114_AE_5h5v_normal_4";

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
s(00,0) = (  0.0990732868,  0.0444453554, -0.0333653372,  0.1482738607,  0.0897485586, -0.0324496545,  -0.073966355, -0.0340963223,  0.1677991233,   0.168670816, -0.0493194185, -0.0449433843,   0.022525967, -0.1094246243,            -0,  0.1093342709,   0.157915284, -0.0354446857,  -0.088729397,  0.0345331311,   0.057198321,  0.0362855256, -0.1083138683,  0.0372433373,  0.0279392617,  0.1476650771,            -0, -0.1362095312,  0.0465528705,  0.0551353397, -0.0361152881,  0.1071070711,             0, -0.0464229684,  0.0448623662, -0.0485820305);
s(01,0) = (  0.0953498489, -0.0454695206,  -0.034593163,  0.1428115718, -0.0947034299,  0.0341167889, -0.0720132995, -0.0377534176,  0.1654564757, -0.1740301579,  0.0523156493,  0.0464812604,  0.0255155218, -0.1080774307,            -0,  0.1021425891, -0.1646559884,  0.0372656929,  0.0937987149, -0.0363073062,  0.0581207627,    0.04017743, -0.1068016958,  0.0412379744,  0.0098821881, -0.1451462135,             0,  0.1410205275, -0.0493810292, -0.0573583376, -0.0375506165,   0.108251457,             0, -0.0388886937,  0.0482475382, -0.0693350203);
s(02,0) = (  0.1024202605, -0.1177718685, -0.0496394369,  0.0427109171,   -0.12616916,  0.0555842207, -0.0828574283, -0.0303757045, -0.1276609677,   0.044133084,  0.0754539644,  0.1024842399,  0.0437629778, -0.0427483253,            -0, -0.1741691668,  0.1812420013,  0.0607145211,  0.1285582148, -0.0591530853,  0.0757313571,  0.0323260201,  0.0824048003,  0.0331793147,  -0.042035675,  0.1178011996,             0,  0.0130228011, -0.0712214121, -0.1146021398, -0.0542350007,  0.0521470153,             0,  0.1382712626,  0.0749714718,  0.1313609069);
s(03,0) = (  0.0996829718, -0.1735867474, -0.0004124505, -0.0305787725,  0.0297803895, -0.0233506083, -0.0610187644, -0.0174548818, -0.1759500981,  0.2034758059, -0.0069730217,  0.0935440018, -0.0234481013,  0.0091905186,            -0,  0.0703041467, -0.1409031624, -0.0255058177, -0.0235773831,  0.0248498676,  0.0202667018,  0.0185755975,     0.1135753,  0.0190659287,  0.1783356363,  -0.110709554,            -0, -0.1523204901,  0.0065818735, -0.0598457453,  0.0007209442,  0.0032796325,             0, -0.0332455061, -0.0184900642, -0.1840525696);
s(04,0) = (  0.0683718946, -0.0219604416,  -0.070182141,  -0.074213919,  0.1458464021,  0.0898841469, -0.0683425145,  0.0811832932,  0.0328242257, -0.1389145734, -0.0904572118,  0.0625489848,  0.0849726856,  0.0897945584,             0,  0.0897437596, -0.0403591638,  0.0981802545, -0.1506284276, -0.0956552875,  0.0953121443,  -0.086395783, -0.0211879466, -0.0886763312,  -0.219203759,  0.1912424121,             0,  0.1601469297,  0.0853830599, -0.1037528659, -0.0778160325,  -0.120035758,            -0, -0.1210155274,  0.1245383831,   0.111506933);
s(05,0) = (  0.0699955488,  0.0218843757, -0.0706883097,  -0.071496722, -0.1460381803, -0.0897810909, -0.0696407206,  0.0809390879,  0.0356653224,  0.1384830436,  0.0906185418, -0.0624461077,   0.085061845,  0.0879972198,             0,  0.0921545896,  0.0399249071, -0.0980676866,  0.1508529606,  0.0955456147,  0.0960402981, -0.0861358981, -0.0230218666, -0.0884095863, -0.2169537403, -0.1916611829,            -0, -0.1597832325, -0.0855353402,  0.1036092731, -0.0783514924, -0.1184673003,            -0,  -0.122424677,   0.125016236,  0.1128713012);
s(06,0) = (  0.0980899193,   0.173707867,   3.92357e-05, -0.0332340163, -0.0291008225,   0.023039507, -0.0597609205, -0.0173025627, -0.1786447931, -0.2024128487,  0.0064367176, -0.0937881174,  -0.023468123,  0.0108997241,            -0,  0.0679227185,  0.1422474158,  0.0251660025,  0.0228038354, -0.0245187916,  0.0196064327,  0.0184134985,  0.1153147181,  0.0188995509,  0.1758784924,  0.1111262978,             0,  0.1513811405, -0.0060756531,  0.0602266876,  0.0011958393,  0.0018363633,             0,   -0.03178602, -0.0188686908,  -0.185739346);
s(07,0) = (  0.1049903505,  0.1184120564, -0.0508446462,  0.0471576594,  0.1281408669, -0.0565136016,  -0.085057059, -0.0315448133, -0.1222135416, -0.0405272651, -0.0769347195, -0.1033839662,  0.0445065201, -0.0461100369,            -0, -0.1703222451, -0.1774787943, -0.0617296817, -0.1307555869,  0.0601421384,  0.0773679088,  0.0335701933,  0.0788885019,  0.0344563297, -0.0404946734, -0.1154447336,            -0, -0.0161136554,  0.0726191051,  0.1158749219,  -0.055536092,  0.0555109993,             0,  0.1366146565,  0.0765356794,  0.1305965675);
s(08,0) = (  0.0555193104,  0.0830608084,  0.0764848709,  0.0719837618,  0.1053928642,  0.1300896154,  0.0006584824,  0.1122219105, -0.0001234845,  0.0621752905,  0.1806578895,  0.0201999086, -0.1118154101,  0.0172225949,             0, -0.0849194642,  0.0392031249,  0.1420965986,  0.0447789686, -0.1384422058, -0.0691683449, -0.1194272792,   7.97089e-05, -0.1225797441, -0.1093752347, -0.0629751619,             0,  0.0576730044, -0.1705239759,  -0.094563135,  0.0857495773, -0.0814145792,            -0, -0.0290593083,    -0.1511433, -0.1118943028);
s(09,0) = (  0.0566655161, -0.0823814486,  0.0772145087,  0.0734363137, -0.1023325214,  -0.131516317,  0.0001573272,  0.1141026285,  -0.000782653, -0.0570560399, -0.1830685903, -0.0213952942, -0.1133165753,  0.0173604721,             0,  -0.083610546, -0.0330715908, -0.1436549816, -0.0482597462,  0.1399605108, -0.0699149127, -0.1214287514,  0.0005052003, -0.1246340482, -0.1029815176,  0.0656295361,            -0, -0.0621425958,  0.1727994497,  0.0963701128,  0.0865889746, -0.0826598173,            -0, -0.0313534097, -0.1529339025, -0.1038267952);
s(10,0) = (  0.0898009864, -0.1027678695,   0.080440399, -0.1063849102,  0.1036716749, -0.1308983468, -0.0208227782,  -0.124221642,  0.0225066686, -0.0846811026,  0.1825567494, -0.0085736334, -0.1302739942, -0.0027113736,            -0,  0.0546522899,  0.0361995886, -0.1429799741,   0.047075713,  0.1393028629, -0.0702423237,  0.1321974708, -0.0145279921,  0.1356870243, -0.0073314216, -0.0083493758,            -0, -0.0434010096, -0.1723163203,  0.0858603529,  0.0908079193,  0.0771920951,             0,     0.0581925, -0.1691344729,  0.0491880734);
s(11,0) = (  0.0897170957,  0.1025643972,  0.0805253761, -0.1065726934, -0.1043246325,  0.1312534852, -0.0207223682, -0.1241227641,  0.0222130053,  0.0833437314, -0.1819906282,  0.0088922357, -0.1303395561, -0.0025423663,            -0,  0.0544584062, -0.0376137329,   0.143367891, -0.0463007228, -0.1396808035, -0.0703308308,  0.1320922442, -0.0143384332,  0.1355790201, -0.0073390124,  0.0072900445,             0,  0.0445553116,  0.1717819553, -0.0863267872,  0.0909003032,   0.076998746,             0,   0.058245648, -0.1692553062,  0.0493104638);
s(12,0) = (  0.1072050183, -0.0001080857,  0.1923672685, -0.0081357433, -0.0001347615,   9.90898e-05,  0.2475356456,  0.0041890214,  0.0136436958, -0.0004531978,  0.0001290832,  0.0001203185,  0.2198288131,  0.0072704418,             0, -0.0099620616, -0.0003141791,  0.0001082355,  0.0001675927,  -0.000105452,  0.1805267599, -0.0044579836, -0.0088069678, -0.0045756588,  0.0290460351, -0.0005847187,             0,  0.0003750171, -0.0001218424, -0.0001549852,   0.191016112, -0.0082785883,            -0,  0.0034078826,  0.0220426037,  0.0115875408);


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
