// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 20:41:58

//------- decoder information -------
// decoder file = ../decoders/KMH114_AE_7h7v_pinv_even_energy_rV_max_rE_2_band.dsp
// description = KMH114_AE_7h7v_pinv_even_energy_rV_max_rE_2_band
// speaker array name = KMH114_AE
// horizontal order   = 7
// vertical order     = 7
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HV
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 66S 65S 64S 63S 62S 61S 60C 61C 62C 63C 64C 65C 66C 77S 76S 75S 74S 73S 72S 71S 70C 71C 72C 73C 74C 75C 76C 77C 
// output speaker order: L R RSF RSR RR RL LSR LSF ULF URF URR URL VOG 
//-------


// start decoder configuration
declare name "KMH114_AE_7h7v_normal_2";

// bands
nbands = 2;

// decoder type
decoder_type = 2;

// crossover frequency in Hz
xover_freq = hslider("xover [unit:Hz]",400,200,800,20): dezipper;

// lfhf_balance
lfhf_ratio = hslider("lf/hf [unit:dB]", 0, -3, +3, 0.1): mu.db2linear : dezipper;


// decoder order
decoder_order = 7;

// ambisonic order of each input component
co = ( 0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7);

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
gamma(0) = (             1,             1,             1,             1,             1,             1,             1,             1);
gamma(1) = (  0.8111630452,  0.7789516443,  0.7164475214,  0.6273610497,  0.5169491507,  0.3916690065,  0.2587546268,  0.1257455323);

// gain matrix
s(00,0) = (  0.0951771663,  0.0495424924,  -0.011779458,  0.1171643709,  0.0876809701, -0.0054589526, -0.0549436257, -0.0069899492,   0.082435177,  0.1099942903, -0.0075359176, -0.0333205189,  0.0107228594, -0.0755666309,            -0,    0.03908387,  0.1143643794, -0.0059628018, -0.0613035411,  0.0058094525,  0.0447956337,  0.0074387489,  -0.053211678,   0.007635106,  0.0118106098,  0.0986660672,            -0, -0.0769002504,   0.007113194,  0.0296402121, -0.0128866118,  0.0639636485,             0, -0.0205429507,  0.0180619726, -0.0484471028,  0.0625656057,  0.0059997842,  -0.076717958,  0.0050337898,  0.0539358414, -0.0043982092, -0.0469464283, -0.0056317138,  0.0431063859, -0.0064455469,  0.0058057698,  0.0076824603, -0.0847701767,   0.015183542,  0.0077106057, -0.0618773494,             0,  0.0663773573, -0.0045710456,  -0.027860389,  0.0049297133, -0.0578848329,            -0,  0.0127836841, -0.0136005211,  0.0390985517,             0, -0.0930452044);
s(01,0) = (  0.0935453722, -0.0505775858, -0.0122666155,  0.1141848079, -0.0899501178,  0.0067151519, -0.0541916172, -0.0076207409,  0.0774242488, -0.1117261283,  0.0090875082,  0.0346406056,  0.0116905602, -0.0740866113,            -0,   0.030594147, -0.1134164506,  0.0073349455,  0.0637371428, -0.0071463078,  0.0449438485,  0.0081100415, -0.0499771377,  0.0083241184, -0.0006089809,  -0.092315487,             0,  0.0789997889,  -0.008577749, -0.0314427656, -0.0134453509,  0.0631746833,             0, -0.0144484645,  0.0192297461, -0.0614890248, -0.0492961545, -0.0073804382,   0.076082068, -0.0061921517, -0.0567873308,   0.005410313, -0.0471885799, -0.0061399347,  0.0404861088, -0.0070272102,  0.0150246874,  0.0083757461, -0.0948483845,  0.0036879887, -0.0092981633,  0.0564458338,            -0, -0.0688380707,  0.0055121907,  0.0299864663,  0.0055228657, -0.0575058103,            -0,  0.0074070927, -0.0144798453,  0.0484964771,             0, -0.0960931594);
s(02,0) = (  0.0935660303, -0.1037185708, -0.0151209499,  0.0560030265, -0.1001743859,  0.0086924963, -0.0551356797, -0.0109107364, -0.0590686351,  0.0102413374,  0.0171690021,   0.068262844,  0.0161400347, -0.0402549181,            -0, -0.1101696358,  0.1016797379,  0.0094947945,  0.0753832767, -0.0092506105,  0.0485122916,  0.0116112759,    0.03812864,  0.0119177732, -0.0375189212,  0.0864153743,             0,  -0.000172389, -0.0162059156, -0.0592180926, -0.0166590455,  0.0384160338,             0,  0.0811566521,  0.0250923065,  0.0602746542,  0.0041046772, -0.0095536829, -0.0682088418, -0.0080154935, -0.0708055202,  0.0070034345,  -0.051507101, -0.0087906425, -0.0308877286, -0.0100609691,  0.0442406506,  0.0119916894,  0.1035498647, -0.0859560014, -0.0175669922, -0.0663376176,            -0, -0.0049496363,  0.0104141654,   0.054627916,  0.0080919992,  -0.037901064,            -0, -0.0730675038, -0.0188943064, -0.0309728071,             0,  0.0532210804);
s(03,0) = (  0.0948589844, -0.1216394363,  -0.006616252, -0.0312270674,  0.0540034236,   6.67519e-05, -0.0530966853, -0.0041174029, -0.1006089052,  0.0970044474,  0.0063334128,  0.0745251025,  0.0026716271,  0.0168733815,            -0,  0.0746778931, -0.0948403848,    7.2913e-05, -0.0309042323,  -7.10378e-05,  0.0382334855,  0.0043817667,  0.0649427691,  0.0044974301,  0.0795576893, -0.0432028099,            -0, -0.0641117154, -0.0059781432, -0.0589575949, -0.0070732321, -0.0108520483,             0, -0.0462677732,  0.0074551174, -0.1052705138,   0.118558739,  -7.33652e-05,  0.0636208642,   -6.1553e-05,   0.021443041,   5.37812e-05, -0.0390467007, -0.0033173395, -0.0526096558, -0.0037967248,  -0.047702425,  0.0045253239, -0.0051050184, -0.0391961574, -0.0064802259,  0.0291882803,             0,   0.052634052,  0.0038416448,  0.0503758153,  0.0002804938,  0.0073431879,            -0,   0.035601257, -0.0056136439,  0.0749792937,             0,   0.102557946);
s(04,0) = (  0.0779682801,  -0.066762259, -0.0158440612, -0.0700925171,  0.1016368685,  0.0157433882, -0.0465523363,  0.0187924106, -0.0089217725, -0.0634188812, -0.0292221013,  0.0494835083,  0.0194948062,  0.0531884562,             0,  0.0737442875, -0.0341967255,   0.017196468, -0.0838537262,  -0.016754215,  0.0451952334, -0.0199990043,  0.0057589794, -0.0205269085, -0.0928907442,  0.1006069657,             0,   0.053904149,  0.0275829022, -0.0486315239, -0.0175827958, -0.0534026108,            -0, -0.0630493794,  0.0283655075,  0.0381178748, -0.0975300974, -0.0173031236,  0.0229398608, -0.0145172365,  0.0845037661,   0.012684249, -0.0478977596,  0.0151408078, -0.0046653065,  0.0173287902,  0.0838730975, -0.0206542201,  0.0641971523,   0.010022512,   0.029899491, -0.0823000031,            -0, -0.0535078126, -0.0177251883,  0.0488818521,  0.0103969334,  0.0543803442,             0,  0.0628072242, -0.0213590006, -0.0427426272,            -0, -0.1064745307);
s(05,0) = (  0.0779006097,  0.0665869394, -0.0158249888, -0.0701978229, -0.1019024708, -0.0157957027, -0.0465074158,  0.0188051926, -0.0090013727,  0.0630572117,  0.0291631056, -0.0494047253,  0.0194756483,  0.0532599249,             0,  0.0736999326,  0.0337148931, -0.0172536111,  0.0839883325,  0.0168098885,  0.0451538018, -0.0200126069,  0.0058103611, -0.0205408702, -0.0929189713, -0.1012793031,            -0, -0.0537046579, -0.0275272159,  0.0486008463, -0.0175618425,  -0.053466834,            -0, -0.0630297488,  0.0283348212,  0.0381621464,  0.0966581771,  0.0173606211, -0.0226166379,  0.0145654767,  -0.084579348, -0.0127263982, -0.0478486188,  0.0151511061, -0.0047069305,  0.0173405766,  0.0838687088, -0.0206682684,  0.0642822663, -0.0109921613, -0.0298391278,  0.0828023263,             0,  0.0533745551,  0.0176894034, -0.0488800958,  0.0103876178,  0.0544411565,             0,  0.0627985825, -0.0213358941,  -0.042784119,            -0,  -0.106381668);
s(06,0) = (  0.0948943524,  0.1217310542, -0.0066283774, -0.0311837315, -0.0538508172,  -6.80925e-05, -0.0531197915, -0.0041275692, -0.1005933957, -0.0968233279, -0.0063375975, -0.0745819391,  0.0026873528,  0.0168412902,            -0,  0.0746474148,  0.0950173852,  -7.43773e-05,  0.0308031121,   7.24645e-05,  0.0382595506,  0.0043925858,  0.0649327577,  0.0045085347,  0.0794841426,  0.0433525667,             0,   0.063990898,  0.0059820932,  0.0590033381, -0.0070867277,  -0.010820536,             0, -0.0462398927,  0.0074774727, -0.1053869104, -0.1184617466,   7.48386e-05, -0.0637395997,   6.27892e-05, -0.0213587508,  -5.48613e-05, -0.0390758251, -0.0033255304, -0.0526015457, -0.0038060993, -0.0476360966,  0.0045364975, -0.0052257171,   0.039224954,  0.0064845077, -0.0292884578,            -0, -0.0525340051, -0.0038441832, -0.0504155022,  0.0002890494,  0.0073115297,            -0,  0.0355723964, -0.0056304772,  0.0750672571,             0,  0.1024789067);
s(07,0) = (   0.094165634,  0.1040960042, -0.0152780034,  0.0568363069,  0.1009098122, -0.0088076921, -0.0555204765, -0.0110231549, -0.0585359801, -0.0093182297, -0.0173204663, -0.0685569018,  0.0163115124, -0.0408266069,            -0, -0.1100854118, -0.1007835825, -0.0096206225, -0.0759525724,  0.0093732026,  0.0488793915,  0.0117309124,  0.0377848127,  0.0120405677, -0.0377585633, -0.0858239473,            -0, -0.0005256761,  0.0163488834,  0.0595201613, -0.0168322634,  0.0389359112,             0,  0.0811863207,  0.0253560093,  0.0594294241, -0.0040707553,  0.0096802914,  0.0676076825,  0.0081217174,  0.0713526115, -0.0070962463, -0.0519260579, -0.0088812167, -0.0306091967,  -0.010164632,  0.0446018429,  0.0121152455,  0.1024598869,  0.0853729574,  0.0177219674,  0.0660410401,             0,  0.0055906264, -0.0105060387, -0.0549396718,  0.0081788976,  -0.038397512,            -0, -0.0731577235, -0.0190928725, -0.0302992662,             0,   0.052299914);
s(08,0) = (  0.0786684437,  0.0716938033,   0.043332842,  0.0696873867,  0.0889839355,  0.0555780665, -0.0253202528,  0.0584851778,  0.0100123746,  0.0663407873,    0.08436304, -0.0135426769, -0.0679015184, -0.0107259349,             0, -0.0602049365,  0.0033766605,  0.0607077989,   -0.00475934,  -0.059146536, -0.0248134683, -0.0622403025,   -0.00646296, -0.0638832301, -0.0815530569, -0.0547992397,             0, -0.0016708878, -0.0796307376, -0.0228710901,   0.048805769, -0.0268542528,            -0,  -0.004595436, -0.0892846692, -0.0545534207, -0.0740827356, -0.0610843197, -0.0022651328,  -0.051249447,  -0.043994368,  0.0447785461,  0.0409066583,  0.0471207689,   0.005235596,   0.053930142, -0.0131561543, -0.0642794455, -0.0112203281, -0.0677202729, -0.0863186372, -0.0129906015,            -0, -0.0311797674,  0.0511719112,  0.0454941196, -0.0392646057,  0.0502534971,             0,  0.0380307973,  0.0672306429, -0.0157770626,            -0,  0.0451137697);
s(09,0) = (  0.0772891337,  -0.071297372,   0.043769178,   0.067717363, -0.0879352463, -0.0560221722, -0.0244070868,   0.058814206,   0.008792266, -0.0649957214, -0.0849183415,  0.0130573116, -0.0684054776, -0.0093398084,             0, -0.0602496853, -0.0022599042, -0.0611928945,  0.0037356622,  0.0596191561, -0.0257460726, -0.0625904565, -0.0056753833, -0.0642426269, -0.0806796554,  0.0548304964,            -0,   0.000443929,  0.0801548898,  0.0235231117,  0.0492883691, -0.0281488647,            -0, -0.0048157219, -0.0900394175, -0.0520868031,  0.0723515071,   0.061572424,  0.0015159898,  0.0516589642,  0.0451386032, -0.0451363564,  0.0419832188,  0.0473858628,  0.0045975859,  0.0542335444, -0.0143157199, -0.0646410714, -0.0081807319,  0.0642721524,   0.086886811,   0.013369692,             0,  0.0324479333, -0.0515087393, -0.0462583603, -0.0395264891,  0.0515126934,             0,  0.0384044952,  0.0677989623, -0.0177435081,            -0,   0.047562932);
s(10,0) = (  0.0884028512, -0.0804378801,  0.0432649717, -0.0872513661,  0.0877876129, -0.0588203876, -0.0309021968, -0.0590589233,  0.0086890681, -0.0568550285,  0.0890656401,  0.0171261257, -0.0693066255,  0.0211682117,            -0,  0.0470221824,  0.0129258581,  -0.064249379, -0.0010506318,  0.0625970349, -0.0221840246,  0.0628508862, -0.0056087693,   0.064509931, -0.0585611806,  0.0322585943,            -0, -0.0070657709, -0.0840695477,  0.0219969749,  0.0488036931,  0.0189455368,             0,  0.0137507461, -0.0903580313,  0.0544125394, -0.0504427748,  0.0646478653, -0.0086709292,  0.0542392445, -0.0496660328, -0.0473908432,  0.0378791583, -0.0475830285,  0.0045436225, -0.0544592022, -0.0293954163,  0.0649100334, -0.0201631646,  0.0458818474,  -0.091130247,  0.0311728401,             0,  0.0402567197,  0.0540243574, -0.0462624053, -0.0403254457, -0.0437681798,            -0, -0.0458886996,   0.068038876,  0.0163895292,             0, -0.0189952403);
s(11,0) = (  0.0885499058,  0.0804613978,  0.0432229472, -0.0870353916, -0.0876810293,  0.0587351596, -0.0309987372, -0.0590887728,  0.0088369584,  0.0569795751, -0.0891710507, -0.0171870848, -0.0692613306,  0.0210196491,            -0,  0.0470698407, -0.0128799277,  0.0641562846,  0.0009160099, -0.0625063348, -0.0220912473,  0.0628826522, -0.0057042321,  0.0645425355, -0.0585796248, -0.0324499499,             0,  0.0069186637,  0.0841690455,  -0.021897292,  0.0487573724,  0.0190810195,             0,  0.0137418926, -0.0902879426,  0.0542358022,  0.0499024656, -0.0645541936,  0.0086401182, -0.0541606544,  0.0498348769,  0.0473221761,  0.0377712829, -0.0476070778,  0.0046209562, -0.0544867269, -0.0293297704,  0.0649428401, -0.0204120926, -0.0467327625,  0.0912381011, -0.0309664798,            -0,   -0.04008594, -0.0540882961,  0.0461374691, -0.0403026309, -0.0438978148,            -0, -0.0458989088,  0.0679860997,  0.0165360827,             0, -0.0192209546);
s(12,0) = (  0.1063409125,  -4.34733e-05,  0.1349846308, -0.0019553902,  -7.13746e-05,   -8.6096e-06,  0.1572285943,  0.0004831846,   0.002883644, -0.0001017444,   -9.2561e-06,   2.19187e-05,  0.1522682461,  0.0014613763,             0, -0.0024942043, -0.0001373381,   -9.4043e-06,   4.02922e-05,    9.1624e-06,  0.1368907423, -0.0005142081, -0.0018613842, -0.0005277814,  0.0152671777, -0.0001845049,            -0,   6.07589e-05,    8.7369e-06,  -1.21267e-05,  0.1341342464, -0.0014472356,            -0,  0.0012828009,  0.0138730683,   0.003611805, -0.0002273687,    9.4626e-06,   9.21292e-05,    7.9391e-06,  -2.73905e-05,   -6.9367e-06,  0.1425970073,  0.0003892957,  0.0015078935,  0.0004455524,  0.0003031257, -0.0005310548, -0.0001682935, -0.0002415475,    9.4707e-06,  0.0001326698,             0,  -4.48758e-05,   -5.6144e-06,     6.333e-06,  0.1478186374,  0.0014615403,             0, -0.0007709232, -0.0104463096, -0.0028806748,            -0, -0.0011133181);


// ----- do not change anything below here ----

// mask for full ambisonic set to channels in use
input_mask(0) = bus(nc);
input_mask(1) = (_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_);


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
