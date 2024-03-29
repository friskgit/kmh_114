// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 18:12:20

//------- decoder information -------
// decoder file = ../decoders/KMH114_AEC_7H7P_Slepian41_2_band.dsp
// description = KMH114_AEC_7H7P_Slepian41_2_band
// speaker array name = KMH114_AEC
// horizontal order   = 7
// vertical order     = 7
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HP
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 66S 65S 64S 63S 62S 61S 60C 61C 62C 63C 64C 65C 66C 77S 76S 75S 74S 73S 72S 71S 70C 71C 72C 73C 74C 75C 76C 77C 
// output speaker order: L C R RSF RSR RR RL LSR LSF ULF URF URR URL VOG 
//-------


// start decoder configuration
declare name "KMH114_AEC_7H7P_full_5";

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
ns = 14;

// radius for each speaker in meters
rs = (          3.26,          3.27,           3.3,          3.35,          3.27,         3.364,         3.376,         3.262,         3.296,          3.02,          3.02,          3.05,          3.02,           1.6);

// per order gains, 0 for LF, 1 for HF.
//  Used to implement shelf filters, or to modify velocity matrix
//  for max_rE decoding, and so forth.  See Appendix A of BLaH6.
gamma(0) = (             1,             1,             1,             1,             1,             1,             1,             1);
gamma(1) = (             1,  0.9602898565,  0.8832349127,  0.7734093083,  0.6372937645,  0.4828486811,  0.3189921291,  0.1550188129);

// gain matrix
s(00,0) = (  0.0183239182,  0.0243761706, -0.0029070746,   0.049647964,  0.0617712883,  -0.001776539, -0.0408426238, -0.0051609398,  0.0273814292,  0.0961302834, -0.0018376502, -0.0334687963,  0.0198929836, -0.0692106539, -0.0019959903, -0.0028302617,  0.1042473097, -0.0062141992, -0.0647997864,  0.0033246171,  0.0668631453,  0.0096791755, -0.0295573033,  0.0036879845, -0.0136386225,  0.0939207995, -0.0075764519, -0.0933808803,  0.0015416771,  0.0388654901, -0.0113278864,  0.0822746681,  0.0022630423,  0.0052420243,  0.0227610889, -0.1051140718,  0.0555021747, -0.0021206536,  -0.089069291,  0.0048638758,  0.0647885189, -0.0025059973, -0.0612339097, -0.0080322422,  0.0307372733, -0.0041377974,  0.0261138881,  0.0068831797, -0.0935494735,  0.0280141346,  0.0402924284, -0.0829362235, -0.0047999908,  0.0995355011,  0.0107370298, -0.0428039103,  0.0112314474, -0.0931506509,  0.0044439614, -0.0087613052,  -0.018305042,  0.0985126301, -0.0669136813, -0.1426431475);
s(01,0) = (  0.0146233199,  -0.001655115,  0.0032428374,  0.0390333582, -0.0041514728,  -3.33806e-05, -0.0308633715,  0.0002227916,  0.0795060982, -0.0066596061, -0.0003268396,   0.002175862, -0.0041090089, -0.0514700504,  -0.006779653,  0.1052938958,   -0.00703791,  0.0001437349,  0.0040990826,   6.57918e-05,  0.0386129096, -0.0004529993, -0.0855085878, -0.0125963614,   0.095713882, -0.0065835381,  0.0005114989,  0.0062478011,   0.000555471, -0.0023519968,  0.0134117297,  0.0558840719,  0.0087391305, -0.1061670776, -0.0294877485,  0.1595182057,   -0.00463267,  0.0005146252,  0.0060132166,  -1.33243e-05, -0.0037447073, -0.0001270841, -0.0259605113,  0.0017882141,  0.0883219852,  0.0119627994, -0.0964103583, -0.0114671652,  0.1170894403, -0.0044077989, -0.0033241709,  0.0062572893,  0.0003240554,  -0.006368664, -0.0011722751,  0.0023664217,  -0.008957905, -0.0563065549,  0.0077090192,    0.11798581,   0.014922477, -0.1497649138,  0.0802718483,  0.1546039191);
s(02,0) = (  0.0183250085, -0.0234060949, -0.0031409125,  0.0500610223, -0.0598256383,  0.0035533745,   -0.04091776, -0.0055623065,  0.0299303018,  -0.090715539,  0.0071823251,  0.0332961223,  0.0207336127, -0.0700121375, -0.0021980106, -0.0017186775, -0.1005829408,  0.0093043647,  0.0658289841, -0.0066896579,   0.067486565,  0.0104380808,  -0.032303523,   0.004316816, -0.0181170665, -0.0877067979,  0.0073101341,  0.0907762561, -0.0093998316, -0.0407609276, -0.0122716478,  0.0836294235,  0.0025094374,  0.0046990738,  0.0247640613, -0.1083380858, -0.0429267886, -0.0024100808,  0.0859384405, -0.0084723469, -0.0700602652,  0.0059721033, -0.0621997541,  -0.008790368,  0.0335832331, -0.0048730381,  0.0310405223,  0.0078514413, -0.0958508086,   0.003160096, -0.0316306668,  0.0721257138,  0.0046312676, -0.1002492684, -0.0049923584,  0.0475776132,  0.0119848882, -0.0951879628,  0.0047720203, -0.0088862709, -0.0195465636,  0.1024476573, -0.0686171184, -0.1390652269);
s(03,0) = (  0.0209769013, -0.0448199371, -0.0056335907,  0.0232845704, -0.0640176191,   0.002823687, -0.0474733286, -0.0090556132, -0.0452404946,  0.0094121398,  0.0315692498,  0.0613124087,  0.0310561306, -0.0366146345,  0.0034512793, -0.0826473735,  0.0885943241, -0.0008844261,  0.0840145497, -0.0052660752,   0.082655923,  0.0171012106,  0.0487863496,  0.0191361747, -0.0597950284,  0.0841400619, -0.0064388294, -0.0095004108, -0.0450125325, -0.0708024271, -0.0222736146,   0.050922564, -0.0040771458,   0.090850607,  0.0458068974,  0.0400214046,  0.0019302859,  -0.001545624, -0.0756953216,  0.0007607792,  -0.107296236,  0.0037186378, -0.0795937563, -0.0165793268, -0.0506403745, -0.0197624688,  0.0784915602,  0.0167462747,  0.0939499821, -0.1378310797, -0.0011655701, -0.0741116079, -0.0040792605,  0.0106659665,  0.0185588327,  0.0775367372,  0.0202853354, -0.0668892961, -0.0065324274, -0.1106892006, -0.0331949082, -0.0139657512,  0.0677427143,  0.0564395167);
s(04,0) = (   0.018754983,   -0.05815296,  0.0003189933, -0.0131870451,   0.037813427,  -0.004125309, -0.0407783472, -0.0095556527, -0.0642810636,  0.0920998258,  0.0344496638,  0.0744898644,  0.0085255675,  0.0114638246,  0.0052624571,   0.059888717, -0.0904852654, -0.0211810446, -0.0194505198,  0.0078848711,  0.0597025392,  0.0181026625,  0.0692042971,  0.0158442324,  0.0491709467, -0.0498879768,  0.0065762586, -0.1008973563, -0.0511201404, -0.0767942287,  0.0017022754, -0.0012930022, -0.0065832692,  -0.043084392, -0.0049243994, -0.1222612855,  0.1052703724,  0.0209098814,  0.0773109489,  0.0218991365, -0.0084902421, -0.0101014392, -0.0491082881, -0.0189153152, -0.0716152869, -0.0192421717, -0.0427107997,  0.0279981966, -0.0081816495, -0.0785247134,  0.0733439547,  0.0673992915,  0.0041663275,  0.1224159195,  0.0421731179,  0.0719943668,  0.0008822769, -0.0140368665, -0.0073885251,  0.0261489365, -0.0012467302,  0.1385132371, -0.0038131406,  0.1287514739);
s(05,0) = (  0.0123472193, -0.0082370927, -0.0061879239, -0.0197685881,  0.0547002824,  0.0151939815, -0.0288369059,  0.0167248994, -0.0088637187, -0.0740608144, -0.0626326462,   0.020606137,  0.0285974343,  0.0368032633,  0.0004972044,  0.0521457832, -0.0416245392,  0.0322856425, -0.0920510573, -0.0287273923,  0.0562655699, -0.0316178027,  0.0096158246, -0.0320773774, -0.0902297643,  0.1219217243,  0.0030251747,   0.092760036,  0.0906473505,  -0.040769722, -0.0247018004, -0.0602209653, -0.0004044516, -0.0726068054,  0.0515639479,  0.0523008569, -0.0731112929, -0.0381168448,  0.0355641618, -0.0348516644,  0.1399436836,  0.0289276538, -0.0586759462,  0.0314877084,  -0.010090544,  0.0350713459,  0.1067342388,  -0.037933426,  0.0891148544,  0.0455196754, -0.0477971931, -0.1503023923,  0.0019165713, -0.1260384441, -0.0515417058,  0.0666678002,  0.0211923529,   0.088822714, -0.0022247603,  0.1061473088, -0.0347848014,  -0.090689149,  0.0632151132, -0.1315464385);
s(06,0) = (  0.0127652239,  0.0078300796, -0.0062484032, -0.0186462647, -0.0556815313, -0.0153450952, -0.0297667902,  0.0166171864,  -0.008302723,  0.0723002169,  0.0621332102, -0.0201607328,  0.0290302635,    0.03524435,  0.0004567153,  0.0520534485,  0.0399312877, -0.0325084461,  0.0927799989,  0.0290140878,  0.0577753764, -0.0314159443,  0.0090101194, -0.0320089495, -0.0904290396, -0.1237322387, -0.0029021131, -0.0913096033,  -0.089898187,  0.0404575825,  -0.024936654, -0.0583778371, -0.0003589786, -0.0724736541,  0.0520331739,  0.0499833761,  0.0711702142,  0.0385873177, -0.0341174414,  0.0351424715, -0.1402573575, -0.0292347193, -0.0600487768,  0.0313234027,  -0.009460411,  0.0349953143,  0.1072069225, -0.0378005835,  0.0870381539, -0.0489286717,  0.0464337872,  0.1524220262, -0.0018386068,  0.1248339093,  0.0508421346, -0.0665868678,  0.0214297605,  0.0867485169, -0.0021315729,  0.1059505548, -0.0351713901, -0.0885400305,   0.061731132, -0.1348899952);
s(07,0) = (  0.0184043994,  0.0586444818,  0.0003694597, -0.0141278935, -0.0366253432,  0.0042966363, -0.0399985265, -0.0094657559,  -0.064748762, -0.0899832747, -0.0338792625, -0.0750347523,  0.0081634773,  0.0127704165,  0.0052961926,  0.0599673865,  0.0925330144,   0.021429945,  0.0185484287, -0.0082099633,  0.0584369371,  0.0179341997,   0.069709276,  0.0157875356,  0.0493331358,  0.0520594489, -0.0067250842,  0.0991390529,  0.0502632751,  0.0771919746,  0.0018982075, -0.0028373571, -0.0066211358, -0.0431966669, -0.0053157324,   -0.12032115, -0.1029888982, -0.0214511753, -0.0790605533, -0.0222273532,  0.0089164729,   0.010450717, -0.0479579472, -0.0187783475, -0.0721406435, -0.0191792151, -0.0431018044,  0.0278878494, -0.0064424403,  0.0824599114, -0.0717401078, -0.0699136538, -0.0042606146, -0.1209330411, -0.0413604204, -0.0721312367,  0.0006839926, -0.0122994653, -0.0074663201,  0.0263138181, -0.0009238651,   0.136715094,  -0.002570391,  0.1315597007);
s(08,0) = (  0.0210458999,  0.0456560021, -0.0056307141,  0.0234472584,  0.0660551124, -0.0025920786, -0.0476228201, -0.0090513207, -0.0452880806, -0.0058633937, -0.0307744163, -0.0622767793,  0.0310813773,  -0.036828076,  0.0034557076, -0.0827238002, -0.0850954815,  0.0011997472, -0.0856657912,  0.0048263301,  0.0828710505,   0.017092796,  0.0488374095,  0.0191128741, -0.0595814954, -0.0805266196,  0.0061845416,  0.0064735979,  0.0438114252,  0.0715904221, -0.0222604782,  0.0511525133, -0.0040831927,  0.0909024843,  0.0457741918,  0.0398159555,  0.0016148158,  0.0007688498,  0.0727058974, -0.0011959745,  0.1082753917,  -0.003239971,   -0.07976741,  -0.016564751, -0.0506928875, -0.0197345686,  0.0782985325,  0.0167149367,  0.0937335361,  0.1435515599,   0.003665155,  0.0700778852,  0.0039181589, -0.0079922803, -0.0173486087, -0.0779792485,  0.0202830946, -0.0671198582, -0.0065350855, -0.1107148294, -0.0331904538, -0.0138272454,  0.0675912882,  0.0556902291);
s(09,0) = (  0.0092528926,  0.0236144915,   0.017778912,  0.0285173117,  0.0422448983,  0.0278854773, -0.0146665827,  0.0327572008,  0.0201934825,  0.0677347916,   0.068657637, -0.0134848518, -0.0590790033, -0.0169041066, -0.0016138606, -0.0380625873,  0.0097751144,  0.0510674358, -0.0041121863, -0.0527646134, -0.0170986404,  -0.061989676,  -0.021752687, -0.0627094741, -0.0801748208, -0.0755925396, -0.0007104326, -0.0228749586, -0.1008706303, -0.0186685295,  0.0719269388, -0.0206941249,  0.0019814873, -0.0133611363, -0.1204380462, -0.0610722196, -0.1049511056, -0.0676853346, -0.0083518943, -0.0591196136, -0.0515417524,  0.0544791673,  0.0480226713,  0.0640487161,  0.0225345636,  0.0716108579, -0.0157219888, -0.0805043062, -0.0129576871, -0.1074299925, -0.0756583355, -0.0202011963,  -0.000450088, -0.0321090857,  0.0750219241,  0.0650430772, -0.0561371883,  0.0749999987,  0.0025285636,  0.0804312668,  0.1137349878, -0.0480489742, -0.0097698709,  0.0554692361);
s(10,0) = (  0.0081128806, -0.0233536259,  0.0179703499,  0.0254099305, -0.0415171787,   -0.02814476, -0.0121222917,  0.0330964382,  0.0183746715, -0.0669127038, -0.0693818856,  0.0129759198, -0.0603546281,  -0.012562116, -0.0014805429, -0.0379368234, -0.0085965162, -0.0515679737,  0.0029495055,  0.0532550204,  -0.021286529, -0.0626261832,  -0.019789579, -0.0629673716,  -0.079123639,  0.0762756041,  0.0006247748,  0.0217310688,  0.1019170563,  0.0195321022,  0.0726743819, -0.0258738921,  0.0018295474, -0.0136626771, -0.1219447098, -0.0543869688,  0.1041968985,  0.0682408843,  0.0073448956,  0.0596661176,  0.0532559954, -0.0549697205,   0.051875854,  0.0645827294,  0.0204935333,  0.0719015552, -0.0175695641, -0.0809763453, -0.0070336515,  0.1038205849,   0.075171606,  0.0202903085,  0.0003958203,  0.0337822481, -0.0755985423, -0.0663434976, -0.0568700176,  0.0808872729,  0.0022372487,  0.0809819788,  0.1149299688, -0.0543557192, -0.0055299555,  0.0641813721);
s(11,0) = (  0.0119707383, -0.0417156353,  0.0193762399,  -0.031077622,  0.0348346108, -0.0351101638, -0.0200932725, -0.0357051193, -0.0032969675,  -0.014774217,  0.0880259619,  0.0329037175, -0.0634158961,  0.0184603642,  0.0003227361,  0.0506869916,    0.00753933, -0.0703563815,  0.0145430241,  0.0664582502, -0.0125588925,  0.0675752539,  0.0035325426,  0.0677055921, -0.0433261253,  0.0277027952,  -0.000547941, -0.0405995323,  -0.129078745,  0.0059608104,   0.078433972,   0.022427189, -0.0004540457,   0.005606168, -0.1344386882,  0.0575697951,  -0.073235306,   0.089207545, -0.0064416317,  0.0797414677, -0.0852308988, -0.0690647612,  0.0472934592, -0.0698400373, -0.0036233029, -0.0775275392, -0.0546047475,  0.0879876582, -0.0212881397,  0.0377835878, -0.0542907529,  0.0869842604, -0.0003471429,  0.1154717474,  0.0928956554, -0.0637581663, -0.0610063483, -0.0814358138, -0.0001000817, -0.0781018058,  0.1217884902,  0.0601273154, -0.0149355226,  0.0087067977);
s(12,0) = (  0.0118135683,   0.041722832,  0.0193978158, -0.0314975728, -0.0347826451,  0.0349880742, -0.0197439975, -0.0356666178, -0.0034952086,  0.0146980351, -0.0883829882, -0.0329898758, -0.0635744571,  0.0190425434,  0.0003369539,  0.0507272497, -0.0074766887,  0.0701349464, -0.0147995548, -0.0662271483, -0.0131234941,  0.0675031339,  0.0037466119,  0.0676829958,  -0.043273511,  -0.027838005,  0.0005433883,  0.0404988235,  0.1296002923, -0.0057228487,  0.0785175775,   0.021740898, -0.0004699164,  0.0055533958, -0.1346051429,  0.0584251348,  0.0725695837, -0.0889156084,  0.0063881107, -0.0794898633,  0.0857665502,  0.0688293946,  0.0478048497, -0.0697820338, -0.0038460602,  -0.077502614, -0.0547579339,  0.0879425324, -0.0205187391, -0.0397531807,   0.053838224, -0.0865146006,  0.0003442586, -0.1151347602, -0.0932423614,  0.0633193433, -0.0610918625, -0.0806660389, -0.0001334868, -0.0780284463,  0.1219276665,  0.0593388252, -0.0143860133,  0.0099818499);
s(13,0) = (  0.0231811789,    6.2464e-06,  0.0430630265,  0.0044332496,   -5.3643e-06,   7.59293e-05,   0.062832975, -0.0004720949, -0.0039119431,   9.03347e-05,   0.000223523,   3.93518e-05,  0.1257513015, -0.0061789283,  0.0002921276,  0.0055820333,    6.6919e-06,  0.0001363919,  0.0001325633, -0.0001437425,  0.1608666174,  0.0008868563,  0.0042205743,  -4.04917e-05, -0.0028539206,  0.0001264483,    -4.864e-07,   2.20279e-05, -0.0003270293, -0.0001323523,  0.1557593275,  0.0073412857, -0.0003386603, -0.0051701162,  0.0118277674,  -0.004168153,  0.0004428201,  -0.000184373,   -5.7176e-06,  -0.000155945, -0.0003079517,  0.0001467838,  0.2005156915, -0.0007439564,  -0.004384818,  -7.83879e-05,  0.0102079238,  0.0004890033,  0.0106143414,  0.0012499544,  0.0003021427,  -0.000331745,    -3.081e-07, -0.0001677728,  0.0002225933,  0.0002568222,  0.2280298817, -0.0082960047, -0.0005981402,  0.0051767834, -0.0100221327,  0.0041976785,  0.0076168054, -0.0019683881);


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
