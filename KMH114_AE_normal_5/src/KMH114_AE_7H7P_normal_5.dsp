// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 20:43:45

//------- decoder information -------
// decoder file = ../decoders/KMH114_AE_7H7P_Slepian41_2_band.dsp
// description = KMH114_AE_7H7P_Slepian41_2_band
// speaker array name = KMH114_AE
// horizontal order   = 7
// vertical order     = 7
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HP
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 66S 65S 64S 63S 62S 61S 60C 61C 62C 63C 64C 65C 66C 77S 76S 75S 74S 73S 72S 71S 70C 71C 72C 73C 74C 75C 76C 77C 
// output speaker order: L R RSF RSR RR RL LSR LSF ULF URF URR URL VOG 
//-------


// start decoder configuration
declare name "KMH114_AE_7H7P_normal_5";

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
gamma(1) = (             1,  0.9602898565,  0.8832349127,  0.7734093083,  0.6372937645,  0.4828486811,  0.3189921291,  0.1550188129);

// gain matrix
s(00,0) = (   0.020557693,  0.0241233447, -0.0024117173,  0.0556104768,   0.061137133,  -0.001781638, -0.0455571361, -0.0051269074,  0.0395263265,      0.095113, -0.0018875763, -0.0331364241,  0.0192653149, -0.0770729247, -0.0030316114,  0.0132538322,  0.1031722388, -0.0061922431,  -0.064173634,  0.0033346671,  0.0727614327,  0.0096099779, -0.0426191066,  0.0017638363,  0.0009820832,  0.0929151359, -0.0074983183, -0.0924265019,  0.0016265277,  0.0385062125, -0.0092791872,  0.0908111997,   0.003597982, -0.0109754519,   0.018256709, -0.0807469821,  0.0547945145, -0.0020420424, -0.0881507464,  0.0048618405,  0.0642164988, -0.0025254099,  -0.065199489, -0.0077590848,  0.0442288351, -0.0023104285,  0.0113867926,   0.005131521, -0.0756635596,  0.0273408244,   0.039784647, -0.0819803958, -0.0047504899,  0.0985626604,  0.0105579597, -0.0424424293,   0.009863089, -0.1017517185,  0.0056215471,   0.009261533, -0.0160255697,  0.0756353976, -0.0546518124, -0.1190267362);
s(01,0) = (  0.0196304819, -0.0235538526, -0.0028514134,  0.0535456628, -0.0601962543,  0.0035503945, -0.0436730381, -0.0055424171,  0.0370280813, -0.0913100646,   0.007153147,  0.0334903689,  0.0203667876, -0.0746070438, -0.0028032532,  0.0076812662, -0.1012112389,  0.0093171964,  0.0661949231, -0.0066837844,  0.0709336706,    0.01039764, -0.0399371651,   0.003192296, -0.0095723631, -0.0882945327,  0.0073557974,  0.0913340185, -0.0093502429, -0.0409708984, -0.0110743371,  0.0886183844,  0.0032896092, -0.0047788218,  0.0221315899, -0.0940973537, -0.0433403628, -0.0023641384,  0.0864752608, -0.0084735364,  -0.070394568,  0.0059607581, -0.0645173372, -0.0086307281,  0.0414680367, -0.0038050784,  0.0224336421,  0.0068277285, -0.0853978365,  0.0027665969, -0.0319274268,  0.0726843232,  0.0046601971, -0.1008178207, -0.0050970113,  0.0477888717,  0.0111851856, -0.1002146403,  0.0054602306,  0.0016467231, -0.0182143834,  0.0890776347, -0.0614509778, -0.1252632099);
s(02,0) = (  0.0220910509, -0.0449460402, -0.0053865192,  0.0262585189, -0.0643339194,  0.0028211437, -0.0498248065, -0.0090386387, -0.0391829312,  0.0089047449,  0.0315443479,  0.0614781875,  0.0307430655, -0.0405361337,  0.0029347381, -0.0746250398,  0.0880581063,  -0.000873475,  0.0843268585, -0.0052610625,  0.0855978375,  0.0170666966,   0.042271457,  0.0181764589, -0.0525025952,  0.0836384626, -0.0063998583, -0.0090243913, -0.0449702113, -0.0709816256, -0.0212517759,  0.0551803671, -0.0034113122,  0.0827617456,  0.0435602282,  0.0521750842,  0.0015773232, -0.0015064147, -0.0752371751,   0.000759764,  -0.107581545,  0.0037089553, -0.0815716857, -0.0164430829, -0.0439111294, -0.0188510241,  0.0711460626,  0.0158725922,  0.1028710174, -0.1381669096, -0.0014188384, -0.0736348656, -0.0040545708,  0.0101807385,  0.0184695171,  0.0777170347,  0.0196028333, -0.0711792881, -0.0059450778,  -0.101699871, -0.0320579659, -0.0253763283,  0.0738586201,  0.0682187772);
s(03,0) = (  0.0197452635, -0.0582650432,  0.0005385958, -0.0105437348,  0.0375322923, -0.0041275696,  -0.042868392, -0.0095405654, -0.0588969691,  0.0916488422,  0.0344275304,  0.0746372121,  0.0082473084,  0.0079783106,  0.0048033439,  0.0670191422, -0.0909618675,  -0.021171311, -0.0191729329,  0.0078893264,   0.062317377,  0.0180719857,  0.0634137184,   0.014991216,  0.0556526204, -0.0503338091,  0.0066108969, -0.1004742598, -0.0510825243, -0.0769535042,  0.0026105079,   0.002491426, -0.0059914617, -0.0502739484,  -0.006921288,   -0.11145883,  0.1049566514,  0.0209447315,  0.0777181595,  0.0218982342, -0.0087438309, -0.0101100452, -0.0508663148, -0.0187942187, -0.0656341871, -0.0184320597, -0.0492396382,  0.0272216486, -0.0002524387, -0.0788232063,  0.0731188443,  0.0678230305,  0.0041882723,  0.1219846383,  0.0420937323,  0.0721546191,  0.0002756542, -0.0178499049,  -0.006866476,  0.0341388487, -0.0002361911,  0.1283712673,    0.00162281,  0.1392211376);
s(04,0) = (  0.0113446226, -0.0081236156, -0.0064102577, -0.0224447734,  0.0549849136,  0.0151962701, -0.0267208671,  0.0167096244, -0.0143147754, -0.0736042219, -0.0626102376,  0.0204569567,  0.0288791541,  0.0403321268,  0.0009620275,  0.0449266766, -0.0411420096,  0.0322757878, -0.0923320966, -0.0287319031,  0.0536182112, -0.0315867444,   0.015478421,  -0.031213752, -0.0967920509,  0.1223731015,  0.0029901055,  0.0923316774,  0.0906092666, -0.0406084656, -0.0256213286, -0.0640524607, -0.0010036194, -0.0653278321,  0.0535856719,  0.0413640507, -0.0727936701, -0.0381521283,  0.0351518867, -0.0348507508,  0.1402004263,  0.0289363669, -0.0568960548,  0.0313651057, -0.0161460311,  0.0342511585,  0.1133442769, -0.0371472201,  0.0810870276,  0.0458218807,  -0.047569283, -0.1507314014,  0.0018943536,  -0.125601799, -0.0514613329,  0.0665055548,  0.0218065203,  0.0926831754, -0.0027533022,  0.0980580256, -0.0358079087,  -0.080421043,  0.0577115555, -0.1421463139);
s(05,0) = (  0.0118367757,  0.0079351643,  -0.006454294, -0.0211245288, -0.0554179505, -0.0153429759, -0.0278072461,  0.0166030412, -0.0133506389,  0.0727230414,  0.0621539616, -0.0202988803,  0.0292911483,  0.0385122313,  0.0008871617,  0.0453682414,  0.0403781311,  -0.032517572,  0.0925197444,  0.0290099106,  0.0553238069, -0.0313871829,  0.0144391389, -0.0312091949, -0.0965060027, -0.1233142438, -0.0029345886,  -0.091706282, -0.0899334544,   0.040606913, -0.0257881771, -0.0619259687, -0.0009138341, -0.0657330079,  0.0539053784,  0.0398554172,  0.0714643467,  0.0385546437, -0.0344992261,  0.0351433175, -0.1400196026, -0.0292266506, -0.0584005199,  0.0312098673, -0.0150680558,  0.0342357851,  0.1133281056, -0.0370725225,  0.0796040368, -0.0486488165,  0.0466448419,  0.1520247451, -0.0018591814,  0.1252382617,  0.0509165635, -0.0667371141,  0.0219985062,  0.0903234723, -0.0026210257,  0.0984595263,  -0.036118832, -0.0790313172,  0.0566345979, -0.1447059414);
s(06,0) = (  0.0193314657,  0.0585395534,   0.000575044, -0.0116533179, -0.0368885318,  0.0042945201, -0.0419551541, -0.0094516317, -0.0597083591, -0.0904054699, -0.0338999829, -0.0748968104,  0.0079029808,   0.009507399,  0.0048663868,  0.0666426438,   0.092086836,  0.0214390573,  0.0188082959, -0.0082057923,  0.0608848578,  0.0179054812,  0.0642883366,  0.0149889712,  0.0554010543,  0.0516420761,  -0.006692657,  0.0995351412,    0.05029849,  0.0770428664,  0.0027484633,  0.0007054936, -0.0060671061, -0.0499272807, -0.0071851504, -0.1102082651, -0.1032825929, -0.0214185499, -0.0786793368, -0.0222281979,  0.0086790718,  0.0104426603, -0.0496037509, -0.0186649811, -0.0665413448, -0.0184208163,  -0.049213877,   0.027160872,  0.0009806124,  0.0821804727, -0.0719508484,  -0.069516964, -0.0042400707, -0.1213367917, -0.0414347385,  -0.071981214,  0.0001160934,    -0.0158691, -0.0069775958,  0.0337936974,   2.21667e-05,  0.1272205329,  0.0025185578,  0.1413610374);
s(07,0) = (  0.0222233854,  0.0455227305, -0.0053695973,  0.0265902664,  0.0657208313, -0.0025947665,  -0.050107972, -0.0090333812,  -0.038886164, -0.0063996324, -0.0308007338, -0.0621015765,  0.0307505155, -0.0409724998,  0.0029098026, -0.0742454224, -0.0856621816,  0.0012113209, -0.0853357286,  0.0048316278,  0.0859802036,    0.01705632,  0.0419521659,  0.0180986015, -0.0518745105, -0.0810567331,  0.0062257281,  0.0069766776,  0.0438561524,  0.0714010368, -0.0211805513,  0.0556523589, -0.0033795085,  0.0823537969,  0.0433998066,  0.0526605332,  0.0012417882,   0.000810288,  0.0731900881, -0.0011970474,  0.1079738638, -0.0032502039, -0.0818577783, -0.0164207621, -0.0435811062, -0.0187713112,  0.0705354666,  0.0157915883,  0.1031617038,  0.1431966392,  0.0033974892,  0.0705817288,  0.0039442522,  -0.008505092, -0.0174430016, -0.0777887017,  0.0195617945, -0.0716537226, -0.0059143469, -0.1012144849, -0.0319888799, -0.0258864775,  0.0740548639,  0.0681391031);
s(08,0) = (  0.0082628199,  0.0237265512,  0.0175593555,  0.0258745561,   0.042525974,  0.0278877373, -0.0125769764,  0.0327421167,  0.0148105178,  0.0681856806,  0.0686797657, -0.0136321687, -0.0588008026, -0.0134193241, -0.0011548438, -0.0451915161,  0.0102516165,  0.0510577042, -0.0043897149, -0.0527690678, -0.0197129295, -0.0619590057, -0.0159633235, -0.0618566368, -0.0866551343, -0.0751468008, -0.0007450636, -0.0232979663, -0.1009082385, -0.0185092874,  0.0710188969,  -0.024477759,   0.001389804, -0.0061730886, -0.1184415767, -0.0718724082, -0.1046374505, -0.0677201774, -0.0087590194, -0.0591187115, -0.0512882168,  0.0544877716,  0.0497803291,   0.063927645,  0.0165547189,  0.0708009159, -0.0091945204, -0.0797279211, -0.0208852338, -0.1071315622, -0.0754332723, -0.0206248464, -0.0004720281, -0.0316778949,  0.0751012931,  0.0648828585, -0.0555306928,   0.078812237,   0.002006624,  0.0724430312,  0.1127246607, -0.0379091327, -0.0152046806,  0.0450017695);
s(09,0) = (  0.0070258569,  -0.023230593,  0.0177292937,   0.022508388, -0.0412085792, -0.0281422787, -0.0098280647,  0.0330798769,  0.0124645902, -0.0664176624,   -0.06935759,  0.0128141772, -0.0600491851, -0.0087360928, -0.0009765778, -0.0457638392, -0.0080733536, -0.0515786582,  0.0026448005,  0.0532501298, -0.0241568174, -0.0625925095, -0.0134333029, -0.0620310218,  -0.086238525,  0.0767649911,  0.0005867526,  0.0212666389,  0.1018757654,  0.0197069377,  0.0716774218, -0.0300280314,  0.0011799246, -0.0057707534, -0.1197527397, -0.0662447456,  0.1045412678,  0.0682026296,  0.0068979035,  0.0596671081,   0.053534358, -0.0549602737,  0.0538056271,  0.0644498026,  0.0139281235,  0.0710123012, -0.0104029056, -0.0801239342, -0.0157374884,  0.1041482384,  0.0754187081,  0.0198251732,  0.0003717316,  0.0342556623, -0.0755114013, -0.0665194054, -0.0562041323,  0.0850728175,  0.0016641992,  0.0722115103,  0.1138207073, -0.0432229528, -0.0114969588,  0.0526888986);
s(10,0) = (  0.0116165955, -0.0416755523,  0.0192977059, -0.0320229192,  0.0349351498, -0.0351093554, -0.0193458333, -0.0357105148, -0.0052224205, -0.0146129368,  0.0880338771,  0.0328510231, -0.0633163855,  0.0197068493,  0.0004869235,   0.048137018,  0.0077097718, -0.0703598624,  0.0144437539,  0.0664566569, -0.0134940074,  0.0675862245,   0.005603362,  0.0680106468, -0.0456440932,  0.0278622332, -0.0005603283, -0.0407508396, -0.1290921973,  0.0060177703,  0.0781091711,  0.0210738066, -0.0006656871,  0.0081772879, -0.1337245635,  0.0537066348, -0.0731231135,   0.089195082, -0.0065872579,  0.0797417903, -0.0851402107, -0.0690616836,  0.0479221624, -0.0698833437, -0.0057622561, -0.0778172504, -0.0522699126,  0.0882653663, -0.0241237739,  0.0378903345, -0.0542102492,  0.0868327234, -0.0003549908,  0.1156259817,  0.0929240452, -0.0638154755, -0.0607894087, -0.0800721998, -0.0002867763,  -0.080959148,  0.1214271025,  0.0637542737, -0.0168795203,  0.0049626499);
s(11,0) = (  0.0114269189,  0.0417665943,  0.0193120732, -0.0325296384, -0.0346728777,  0.0349889568, -0.0189279514, -0.0356725085, -0.0055973978,  0.0148741191, -0.0883743464, -0.0330474069, -0.0634658124,  0.0204034426,   0.000516212,  0.0479432156, -0.0072906021,   0.070131146,  -0.014907937, -0.0662288879, -0.0141444427,  0.0675151115,  0.0060075105,  0.0680160512, -0.0458042437, -0.0276639323,   0.000529864,  0.0403336279,  0.1295856053, -0.0056606605,  0.0781629633,  0.0202632894, -0.0007009843,  0.0083605173, -0.1338254691,  0.0542073773,  0.0726920743, -0.0889292154,  0.0062291177,  -0.079489511,  0.0858655625,  0.0688327548,  0.0484912613, -0.0698293152, -0.0061813468, -0.0778189176, -0.0522087859,  0.0882457312, -0.0236146545, -0.0396366358,  0.0539261171, -0.0866800471,  0.0003356904, -0.1149663688, -0.0932113657,  0.0632567736, -0.0608550101, -0.0791772596, -0.0003373179, -0.0811480622,  0.1215331072,  0.0632986998, -0.0165084494,  0.0058940291);
s(12,0) = (  0.0228851237,   3.97549e-05,  0.0429973739,  0.0036430029,    7.8684e-05,   7.66051e-05,  0.0634578169, -0.0004766054, -0.0055215774,  0.0002251612,    0.00023014,   -4.6994e-06,  0.1258344901, -0.0051368956,  0.0004293846,  0.0034503143,  0.0001491773,  0.0001334819,   4.95756e-05, -0.0001450745,  0.1600848828,  0.0008960275,  0.0059517315,  0.0002145269, -0.0047916882,  0.0002597348,  -1.08419e-05, -0.0001044615,  -0.000338275,  -8.47351e-05,  0.1554878014,  0.0062098892, -0.0005155876, -0.0030207192,  0.0124247592, -0.0073976659,  0.0005366105, -0.0001947918, -0.0001274577, -0.0001556753, -0.0002321385,  0.0001493567,  0.2010412729, -0.0007801596, -0.0061729336, -0.0003205797,  0.0121597919,  0.0007211608,  0.0082438166,  0.0013391921,  0.0003694419, -0.0004584264,   -6.8688e-06,  -3.88365e-05,  0.0002463265,   0.000208913,  0.2282112383, -0.0071560549, -0.0007542125,  0.0027881112, -0.0103242445,   0.007229732,  0.0059916682, -0.0050984092);


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
