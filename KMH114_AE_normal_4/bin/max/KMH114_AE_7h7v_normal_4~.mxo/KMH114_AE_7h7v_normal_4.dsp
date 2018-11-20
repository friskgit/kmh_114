// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 20:43:40

//------- decoder information -------
// decoder file = ../decoders/KMH114_AE_7h7v_pinv_energy_limit_050_rV_max_rE_2_band.dsp
// description = KMH114_AE_7h7v_pinv_energy_limit_050_rV_max_rE_2_band
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
declare name "KMH114_AE_7h7v_normal_4";

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
s(00,0) = (  0.0783558108,   0.043844938, -0.0158195618,  0.1080277691,  0.0818329139, -0.0079948524, -0.0485133574, -0.0105241447,  0.0781010106,  0.1061963444, -0.0109855352, -0.0312167797,  0.0155835173, -0.0719022529,            -0,  0.0410115696,  0.1141520109, -0.0087327596, -0.0596827116,  0.0085081734,  0.0424758063,  0.0111998625, -0.0504139855,  0.0114954999,   0.022010989,  0.1012623025,            -0, -0.0763140644,  0.0103693071,  0.0295091253, -0.0173646487,  0.0632018892,             0, -0.0191339176,  0.0252063618, -0.0440837394,  0.0654561902,  0.0087869218, -0.0765754968,  0.0073721846,  0.0545794082, -0.0064413516, -0.0476818421, -0.0084791704,   0.040839996, -0.0097044865,  0.0043934641,  0.0115667971, -0.0816806598,   0.016708262,   0.011240188, -0.0613495234,             0,  0.0673810542, -0.0066634729, -0.0289331398,     0.0074989, -0.0588854146,            -0,  0.0095560373, -0.0189801891,  0.0393297426,             0, -0.0895360326);
s(01,0) = (  0.0764083059,  -0.043848672, -0.0165585464,  0.1049564311, -0.0832138535,  0.0098509893, -0.0476088095, -0.0114455365,  0.0737698292, -0.1077914177,  0.0132319722,  0.0322330183,  0.0171119082, -0.0705247789,            -0,   0.033594324, -0.1141888099,  0.0107602138,  0.0619768664, -0.0104834862,  0.0429428075,  0.0121804136,   -0.04761822,  0.0125019342,  0.0101237743,   -0.09648594,             0,  0.0787787712, -0.0124897314, -0.0314339185, -0.0182151922,  0.0626695597,             0, -0.0135281089,  0.0270263199, -0.0571983376, -0.0536912416, -0.0108269506,  0.0766001824, -0.0090837588, -0.0577120426,  0.0079368176, -0.0482187946, -0.0092215242,   0.038575167,  -0.010554117,  0.0137509663,  0.0125794735, -0.0924688784,  0.0011714249, -0.0135386991,  0.0564430631,            -0, -0.0704931725,  0.0080260895,  0.0314438697,  0.0084435627, -0.0588612952,            -0,  0.0044107285,  -0.020350603,  0.0490387742,             0, -0.0938435591);
s(02,0) = (  0.0766999457, -0.0938017779, -0.0212577005,  0.0478440822, -0.0927848714,  0.0122843773, -0.0491801635, -0.0162768902, -0.0589187627,  0.0186178871,  0.0264590873,  0.0641522103,  0.0246808549, -0.0381899745,            -0, -0.1044030774,  0.1050039714,  0.0134181981,  0.0764144539, -0.0130731133,  0.0490925403,  0.0173219713,  0.0380318978,  0.0177792111, -0.0269803147,  0.0798835769,             0, -0.0029850595, -0.0249748781, -0.0581383879, -0.0235179586,   0.040025517,             0,  0.0814178211,  0.0368735768,  0.0670670214,  0.0003436579, -0.0135014202, -0.0704388054, -0.0113276258, -0.0769101129,  0.0098973676, -0.0554278565, -0.0131140848, -0.0308093585, -0.0150091875,  0.0461258617,   0.017889481,  0.1048303108, -0.0906243293, -0.0270724284, -0.0651527609,            -0, -0.0047425866,  0.0160492328,  0.0553839489,   0.012854128,  -0.041782309,            -0, -0.0764250775, -0.0277655089, -0.0307350028,             0,  0.0474436719);
s(03,0) = (  0.0784050865, -0.1135276971, -0.0074971151, -0.0266454686,  0.0469770133, -0.0017663479, -0.0460765436, -0.0078157188, -0.0959734514,  0.1045205107,   0.012676249,  0.0685563294,  0.0020405406,  0.0120474575,            -0,  0.0692738721, -0.0910393161, -0.0019293779, -0.0224079918,  0.0018797588,  0.0316955116,  0.0083175383,  0.0619505965,  0.0085370924,  0.0903112185, -0.0550031775,            -0, -0.0704752933, -0.0119651812, -0.0531313973, -0.0079663846, -0.0048024811,             0, -0.0398846196,   0.007655606, -0.1050186261,  0.1272541137,  0.0019413443,  0.0610710298,  0.0016287784,  0.0109627062, -0.0014231242, -0.0350803381, -0.0062970259,  -0.050185719, -0.0072070026, -0.0547637241,   0.008590041, -0.0127677173, -0.0400551521, -0.0129700937,  0.0388292524,             0,  0.0589359267,  0.0076890056,  0.0445443892, -0.0004148969,  0.0004496573,            -0,  0.0281908264, -0.0057646102,  0.0781418808,             0,   0.107287673);
s(04,0) = (  0.0545039654, -0.0432334569, -0.0224918036, -0.0579102056,   0.090947329,  0.0247894787, -0.0366158361,  0.0299216814, -0.0021686833, -0.0711930403, -0.0477964603,  0.0400167266,  0.0306845071,  0.0518079315,             0,  0.0608230741, -0.0315512042,  0.0270774927, -0.0885522059, -0.0263811228,  0.0452940529, -0.0318428459,  0.0013998791, -0.0326833863, -0.0948126105,  0.1053721558,             0,  0.0659164321,  0.0451153419, -0.0466125759,  -0.025108172, -0.0590349646,            -0,  -0.062955056,  0.0426831179,  0.0419323405, -0.1087504437, -0.0272454322,  0.0211651912, -0.0228587851,  0.0988451607,  0.0199725698, -0.0506720081,  0.0241075207, -0.0011340317,  0.0275912734,  0.0960448727, -0.0328860946,  0.0719090422,  0.0116109686,  0.0489044173, -0.0936788623,            -0, -0.0686752816, -0.0289917981,  0.0513838771,  0.0169944445,  0.0643891039,             0,  0.0692482373, -0.0321400469,  -0.055355314,            -0, -0.1154495855);
s(05,0) = (  0.0543835213,  0.0429253729, -0.0224524168, -0.0581025693,  -0.091409349, -0.0248732809, -0.0365336033,  0.0299497664, -0.0023112743,  0.0706028981,  0.0477063439, -0.0398738431,  0.0306430198,  0.0519410717,             0,  0.0607457163,  0.0308288484, -0.0271690296,  0.0887941664,  0.0264703056,  0.0452143225, -0.0318727341,  0.0014919211, -0.0327140634,  -0.094860844, -0.1063259316,            -0, -0.0655897343, -0.0450302805,  0.0465502457,  -0.025064806, -0.0591571887,            -0, -0.0629252181,  0.0426182025,  0.0420265384,  0.1075554269,  0.0273375369, -0.0206806202,  0.0229360605, -0.0989900579, -0.0200400882, -0.0505764096,  0.0241301484, -0.0012085943,   0.027617171,  0.0960278877,  -0.032916962,  0.0720780853, -0.0129103015,  -0.048812212,  0.0944000985,             0,  0.0684559557,  0.0289371364, -0.0513698022,  0.0169737779,  0.0645065929,             0,  0.0692401726, -0.0320911661, -0.0554443979,            -0, -0.1152724425);
s(06,0) = (  0.0784278969,  0.1136477249, -0.0075126222, -0.0266134166,  -0.046790462,  0.0017857378, -0.0460938235, -0.0078297985, -0.0959637978, -0.1042931345, -0.0126571398, -0.0686192391,  0.0020629643,  0.0120201385,            -0,  0.0692406429,  0.0912889502,  0.0019505574,   0.022299506, -0.0019003936,    0.03172213,  0.0083325219,  0.0619443651,  0.0085524715,  0.0902311013,   0.055286106,             0,   0.070339624,  0.0119471439,  0.0531694174,  -0.007983758, -0.0047723773,             0, -0.0398519476,   0.007686052, -0.1051464275, -0.1269480369, -0.0019626551, -0.0612384895, -0.0016466581, -0.0108856612,  0.0014387464, -0.0351107575, -0.0063083697,  -0.050180671, -0.0072199856, -0.0546868384,  0.0086055155,  -0.012899734,  0.0403476963,  0.0129505416, -0.0390382711,            -0, -0.0588358198, -0.0076774146, -0.0445677967, -0.0004022383,  0.0004173737,            -0,  0.0281557371, -0.0057875358,  0.0782410921,             0,  0.1072014716);
s(07,0) = (  0.0773559824,  0.0942355915, -0.0214930118,  0.0488447387,  0.0936697038, -0.0124408303, -0.0496281096, -0.0164564886, -0.0582481786, -0.0174504114, -0.0266654826, -0.0645033314,  0.0249539639, -0.0389008582,            -0, -0.1042281463, -0.1037772526, -0.0135890914, -0.0771144919,  0.0132396117,  0.0495635275,  0.0175131011,  0.0375990376,  0.0179753861, -0.0271607138, -0.0789251766,            -0,  0.0020940268,  0.0251696957,  0.0585104948,  -0.023778285,  0.0406960244,             0,  0.0814385131,  0.0372816713,  0.0660586189,   1.65682e-05,  0.0136733734,  0.0696158974,  0.0114718938,  0.0775942738, -0.0100234198, -0.0559810961,  -0.013258785, -0.0304587016, -0.0151747982,  0.0465570621,  0.0180868727,  0.1034808053,  0.0902632602,   0.027283608,  0.0646449245,             0,  0.0055662805, -0.0161744255, -0.0557747852,  0.0129963459,  -0.042438766,            -0, -0.0765472701, -0.0280728007, -0.0298904476,             0,  0.0462729628);
s(08,0) = (   0.054668847,  0.0581017151,  0.0441436625,  0.0558878596,  0.0747523685,  0.0559031865, -0.0153283449,   0.061623267,  0.0145091818,  0.0642373473,  0.0865747779, -0.0050416534, -0.0741247469, -0.0005612407,             0, -0.0536331593,  0.0056647176,  0.0610629267,  0.0058081916, -0.0594925308, -0.0384538093, -0.0655798773, -0.0093656366, -0.0673109579, -0.0820984777, -0.0540131448,             0,  -3.26768e-05, -0.0817184092, -0.0297881606,  0.0499626771, -0.0367860273,            -0, -0.0113255169, -0.0949307011, -0.0543968773, -0.0728313716, -0.0614416501, -0.0038000081, -0.0515492455, -0.0538095227,  0.0450404912,  0.0500155903,  0.0496490878,  0.0075870328,  0.0568238256, -0.0170817183, -0.0677284328, -0.0162744763, -0.0768822758, -0.0885816447, -0.0138158055,            -0, -0.0327161205,  0.0525134803,  0.0515525781,  -0.043676942,  0.0602003741,             0,  0.0453981282,  0.0714820598, -0.0187112532,            -0,  0.0426985096);
s(09,0) = (  0.0529505928, -0.0577706727,  0.0448846261,  0.0531972427, -0.0734692058, -0.0566950963, -0.0141139055,  0.0622144685,  0.0127700798, -0.0623876395, -0.0875507769,  0.0044063355, -0.0750334351,  0.0014093745,             0, -0.0538449766, -0.0039134766, -0.0619279281, -0.0072459211,  0.0603352863, -0.0398422061, -0.0662090377, -0.0082430511, -0.0679567261, -0.0810727114,   0.054311706,            -0, -0.0017922152,  0.0826396601,  0.0307688562,  0.0507848065, -0.0387011101,            -0, -0.0116344079, -0.0962548298, -0.0508756465,  0.0705652384,  0.0623120164,  0.0026252399,  0.0522794786,  0.0555277936, -0.0456785229,  0.0516528411,  0.0501254114,  0.0066776346,  0.0573689822, -0.0187762686, -0.0683782061, -0.0118457565,  0.0720307089,  0.0895802682,  0.0143273891,             0,  0.0346792506, -0.0531054901, -0.0527599602, -0.0441609329,   0.062111877,             0,  0.0459981798,  0.0724791182, -0.0216279595,            -0,   0.046329074);
s(10,0) = (  0.0702125759, -0.0750690584,  0.0442527327, -0.0812854975,  0.0741164009, -0.0624097532, -0.0243978088, -0.0630646769,  0.0101723257, -0.0459271477,  0.0960572274,  0.0118776444, -0.0772035799,  0.0153266552,            -0,  0.0377301906,  0.0183270545, -0.0681700351,   0.012139915,  0.0664168609, -0.0348895309,  0.0671138349,  -0.006566208,  0.0688854068, -0.0438092515,  0.0176633634,            -0, -0.0170198707, -0.0906689455,  0.0283147807,  0.0502285978,  0.0259837707,             0,  0.0229390377, -0.0974895407,  0.0494445073, -0.0342683327,  0.0685928381, -0.0122941619,  0.0575490574, -0.0643171556, -0.0502827497,   0.045548264, -0.0508104135,  0.0053192364, -0.0581529733, -0.0447118381,  0.0693126466, -0.0314294382,  0.0433122148, -0.0982839044,  0.0442887822,             0,  0.0505371689,  0.0582652298, -0.0533340902,   -0.04593506, -0.0516495699,            -0, -0.0557838551,  0.0734088456,  0.0233630976,             0, -0.0016210045);
s(11,0) = (   0.070425194,  0.0750793272,  0.0441755432, -0.0809508706,   -0.07397295,  0.0622670849, -0.0245444203, -0.0631227169,  0.0104068585,  0.0461400472, -0.0962314837, -0.0119618681,  -0.077116091,  0.0150900333,            -0,   0.037819829, -0.0181585298,  0.0680141989, -0.0123413246, -0.0662650324,  -0.034737537,  0.0671756015, -0.0067175983,  0.0689488038, -0.0438123543, -0.0177779264,             0,  0.0167706998,   0.090833427, -0.0281620029,  0.0501433058,  0.0262059017,             0,  0.0229238267,  -0.097357358,  0.0491703005,  0.0336867762, -0.0684360353,  0.0121811121, -0.0574175007,  0.0645791524,  0.0501678037,  0.0453677536, -0.0508571756,  0.0054418766,  -0.058206493, -0.0446092871,  0.0693764369, -0.0318259019, -0.0443396435,  0.0984622001, -0.0440826426,            -0, -0.0502488921,  -0.058370928,  0.0531369816,  -0.045889967, -0.0518663647,            -0, -0.0558053526,  0.0733093131,  0.0236010452,             0, -0.0019855688);
s(12,0) = (  0.0914553124,  -7.95936e-05,  0.1257972229, -0.0019703695, -0.0001348437,   -5.6884e-06,  0.1542508571,   0.000942055,  0.0032535119, -0.0001794654,   -3.8298e-06,   4.56336e-05,   0.150412587,  0.0017212164,             0, -0.0028618344, -0.0002155639,   -6.2134e-06,   8.46498e-05,    6.0536e-06,  0.1309316129,  -0.001002541, -0.0021001329, -0.0010290046,  0.0191293658, -0.0002523331,            -0,  0.0001143851,    3.6149e-06,  -3.26399e-05,  0.1245861035,  -0.001929884,            -0,  0.0011774707,  0.0197580553,  0.0049219722, -0.0002706767,    6.2519e-06,  0.0001446047,    5.2453e-06,   -6.6402e-05,    -4.583e-06,  0.1346223687,  0.0007590018,  0.0017013021,  0.0008686844,  0.0021853597, -0.0010353867,  0.0011824796, -0.0002522934,    3.9185e-06,   0.000175957,             0,  -9.06453e-05,    -2.323e-06,   2.52142e-05,  0.1440754441,  0.0020880487,             0, -0.0004156214, -0.0148776578, -0.0041812202,            -0, -0.0028722695);


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
