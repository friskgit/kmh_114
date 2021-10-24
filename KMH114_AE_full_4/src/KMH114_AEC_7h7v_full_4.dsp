// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 18:12:15

//------- decoder information -------
// decoder file = ../decoders/KMH114_AEC_7h7v_pinv_energy_limit_050_rV_max_rE_2_band.dsp
// description = KMH114_AEC_7h7v_pinv_energy_limit_050_rV_max_rE_2_band
// speaker array name = KMH114_AEC
// horizontal order   = 7
// vertical order     = 7
// coefficient order  = acn
// coefficient scale  = SN3D
// input scale        = SN3D
// mixed-order scheme = HV
// input channel order: W Y Z X V T R S U Q O M K L N P 44S 43S 42S 41S 40C 41C 42C 43C 44C 55S 54S 53S 52S 51S 50C 51C 52C 53C 54C 55C 66S 65S 64S 63S 62S 61S 60C 61C 62C 63C 64C 65C 66C 77S 76S 75S 74S 73S 72S 71S 70C 71C 72C 73C 74C 75C 76C 77C 
// output speaker order: L C R RSF RSR RR RL LSR LSF ULF URF URR URL VOG 
//-------


// start decoder configuration
declare name "KMH114_AEC_7h7v_full_4";

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
gamma(1) = (  0.8417836741,  0.8083563236,    0.74349273,  0.6510433292,  0.5364634866,  0.4064541368,  0.2685223665,  0.1304923059);

// gain matrix
s(00,0) = (  0.0670392802,  0.0446783036, -0.0164336528,  0.0901477244,  0.0832685137, -0.0079933002, -0.0421304778, -0.0117372035,  0.0487477162,  0.1080501526, -0.0110138549,  -0.031726262,  0.0185599526,  -0.061615664,            -0,  0.0097989016,  0.1162417493, -0.0087310641, -0.0606270712,  0.0085065215,  0.0404757139,  0.0124908075, -0.0314665155,  0.0128205214, -0.0080716096,  0.1034674904,            -0, -0.0775390644,  0.0103960382,  0.0299109687,    -0.0181554,  0.0558024968,             0,  0.0024325935,  0.0280883755, -0.0828411726,  0.0675256237,  0.0087852158,  -0.077977336,  0.0073707533,  0.0553604895,  -0.006440101, -0.0452295422, -0.0094565166,  0.0254907909, -0.0108230679,  0.0267640495,  0.0129000366, -0.1177451929,  0.0183407318,  0.0112691641, -0.0628438416,             0,  0.0683865853, -0.0066806507, -0.0292755537,  0.0095509664, -0.0531336808,            -0, -0.0088731585, -0.0211503225,   0.066661921,             0, -0.1233135835);
s(01,0) = (  0.0615593824, -0.0022660483,  0.0012287811,  0.0855257692, -0.0038835571,  -5.50315e-05, -0.0336643723,  0.0034679582,  0.1202649213, -0.0050544261,   1.96187e-05,  0.0013576034, -0.0090859516,  -0.050479182,             0,  0.1242264077, -0.0058012936,  -6.01108e-05,   0.002519076,   5.85649e-05,  0.0163048195, -0.0036906234, -0.0776306729,  -0.003788043,  0.1202166776, -0.0063327949,            -0,  0.0033013943,  -1.85182e-05, -0.0010400324,  0.0017362842,  0.0378121287,            -0,  -0.084801827, -0.0082793437,  0.1460404586, -0.0062309189,   6.04836e-05,  0.0038916261,   5.07454e-05, -0.0020518123,  -4.43382e-05, -0.0168255546,  0.0027940901,  0.0628880327,  0.0031978611, -0.0869367733, -0.0038115372,  0.1354177633, -0.0052440487,  -2.00735e-05,  0.0043369197,             0, -0.0026801398,   1.19001e-05,  0.0008623879, -0.0064304583, -0.0306681381,             0,  0.0717030227,  0.0062342797, -0.1019953632,            -0,  0.1273785248);
s(02,0) = (  0.0671509817, -0.0434251769, -0.0170673872,  0.0903249837, -0.0824977782,  0.0098840571, -0.0423895166, -0.0124434878,  0.0497196355, -0.1068466145,  0.0132521605,  0.0319917455,  0.0195568465, -0.0621100347,            -0,  0.0079911619, -0.1130656985,  0.0107963337,  0.0615272482, -0.0105186772,   0.041314751,  0.0132424398, -0.0320938867,  0.0135919942,  -0.014580018, -0.0951717153,             0,  0.0781789564, -0.0125087872, -0.0312631535, -0.0188693641,  0.0566200331,             0,  0.0041646969,  0.0293972346, -0.0890366098, -0.0522818618, -0.0108632945,  0.0758467764, -0.0091142513, -0.0573592608,    0.00796346, -0.0462225334, -0.0100255609,  0.0259990197, -0.0114743443,  0.0321248619,  0.0136762942,  -0.122108851,  0.0024838208, -0.0135593553,  0.0555235263,            -0, -0.0700197425,   0.008038335,  0.0313134995,  0.0101280605, -0.0541617378,            -0, -0.0107099033, -0.0221358829,  0.0714927923,             0, -0.1215939628);
s(03,0) = (  0.0731668364, -0.0938724428, -0.0214877226,  0.0420549618, -0.0926856204,  0.0123146123, -0.0471952948, -0.0166939616, -0.0687115548,  0.0191458479,  0.0265056577,      0.064212,  0.0256798845, -0.0348727103,            -0, -0.1148987703,  0.1058642221,  0.0134512237,   0.076379468, -0.0131052896,  0.0485232347,  0.0177658213,  0.0443531179,  0.0182347772,  -0.036877705,  0.0807522823,             0, -0.0033113104, -0.0250188361, -0.0582039224, -0.0238084522,  0.0376549633,             0,  0.0886768191,  0.0378601018,  0.0546983766,  0.0009676921, -0.0135346506, -0.0710158791,  -0.011355506, -0.0769081852,  0.0099217275, -0.0547208659,  -0.013450114, -0.0359301321, -0.0153937759,  0.0535150722,  0.0183478726,  0.0934924702, -0.0903541187, -0.0271200783, -0.0657681266,            -0,  -0.004492253,  0.0160774808,  0.0554540343,  0.0135367424, -0.0399529051,            -0, -0.0826332352, -0.0285083543, -0.0219855041,             0,  0.0367115831);
s(04,0) = (  0.0761462491, -0.1137220076, -0.0076448941, -0.0307067418,  0.0473899638, -0.0017624207, -0.0448013375, -0.0080901446, -0.1027187312,  0.1051332565,  0.0126927292,  0.0686774652,  0.0026944382,  0.0143845587,            -0,  0.0626477914, -0.0909230474, -0.0019250882, -0.0226642593,  0.0018755794,  0.0313427228,   0.008609584,  0.0663046559,   0.008836847,  0.0839661453, -0.0547051191,            -0,  -0.070877604,  -0.011980737, -0.0532295362, -0.0081536075, -0.0064843273,             0, -0.0352934632,  0.0082990891,  -0.113752406,  0.1280047333,  0.0019370279,  0.0609930344,   0.001625157,  0.0111609592, -0.0014199601, -0.0346305091, -0.0065181273, -0.0537129102, -0.0074600551, -0.0500182202,  0.0088916548, -0.0206074053, -0.0398190543,  -0.012986956,  0.0386239264,             0,  0.0592641584,   0.007699002,  0.0446300259,   3.26118e-05,  0.0017576044,            -0,  0.0242580731, -0.0062491478,  0.0843020047,             0,  0.1002593378);
s(05,0) = (  0.0557465953, -0.0434985593, -0.0224582829, -0.0564157013,  0.0911072158,  0.0248323506, -0.0373299854,   0.030116069,   0.000754614,  -0.071540709, -0.0478786923,  0.0402024877,  0.0304057939,  0.0509989264,             0,  0.0641846339, -0.0318397965,  0.0271243215, -0.0887067612, -0.0264267473,  0.0455525084, -0.0320497145, -0.0004871012, -0.0328957155, -0.0920698729,  0.1054494482,             0,  0.0661789529,  0.0451929611,  -0.046785334, -0.0250592889, -0.0585128293,            -0, -0.0653261488,  0.0424324966,  0.0460073097, -0.1092326454, -0.0272925515,  0.0213587848,  -0.022898318,   0.099017006,  0.0200071112, -0.0509921485,  0.0242641364,  0.0003945971,  0.0277705214,  0.0940144958, -0.0330997407,  0.0757779495,  0.0114673955,  0.0489885555, -0.0937698279,            -0, -0.0689160749, -0.0290416774,  0.0515514258,  0.0167961148,  0.0640340573,             0,  0.0713101433,  -0.031951331, -0.0582892735,            -0, -0.1123132044);
s(06,0) = (   0.055649018,  0.0430377133,  -0.022417211,  -0.056570808, -0.0918307754, -0.0249200995, -0.0372607042,  0.0301471714,  0.0006759632,  0.0706111731,  0.0477900906, -0.0399682129,  0.0303571645,  0.0511108997,             0,  0.0641755435,   0.030729217, -0.0272201695,  0.0891184906,  0.0265201303,  0.0454759468, -0.0320828138, -0.0004363324, -0.0329296886, -0.0920528792, -0.1068269533,            -0, -0.0656307646, -0.0451093295,   0.046653137, -0.0250138035, -0.0586201426,            -0, -0.0653437572,  0.0423604959,  0.0461872713,  0.1076208392,  0.0273889939, -0.0206137854,  0.0229792326, -0.0993002909, -0.0200778094, -0.0509008004,  0.0242891952,  0.0003534696,  0.0277992014,  0.0939483696, -0.0331339245,  0.0760268116, -0.0131172784,    -0.0488979,  0.0947814871,             0,  0.0685170876,  0.0289879344, -0.0514795344,  0.0167705787,  0.0641402235,             0,   0.071342827, -0.0318971151, -0.0584391391,            -0, -0.1120615152);
s(07,0) = (  0.0761807433,  0.1141444284, -0.0076597104, -0.0306558588, -0.0466854103,  0.0017892626,  -0.044825254, -0.0081028699, -0.1026775585, -0.1042330629, -0.0126766691, -0.0689214811,  0.0027135582,  0.0143464479,            -0,  0.0626479692,  0.0919429309,  0.0019544076,  0.0222195006, -0.0019041448,  0.0313712312,  0.0086231263,   0.066278079,  0.0088507469,  0.0839179025,    0.05582806,             0,  0.0703025673,  0.0119655777,  0.0534062311, -0.0081700936, -0.0064465101,             0, -0.0352839165,  0.0083263288,  -0.113838804, -0.1268732548, -0.0019665292, -0.0616771931, -0.0016499084, -0.0108097726,  0.0014415863, -0.0346633636,   -0.00652838, -0.0536913805, -0.0074717893, -0.0499651535,  0.0089056408, -0.0207010177,  0.0408049422,  0.0129705235, -0.0394083524,            -0, -0.0588074392, -0.0076892604, -0.0447683682,    4.2995e-05,  0.0017193669,            -0,  0.0242427763, -0.0062696591,  0.0843719651,             0,   0.100209108);
s(08,0) = (  0.0737786735,  0.0947586676, -0.0217263376,  0.0429841341,  0.0943457204, -0.0124602649, -0.0476183296, -0.0168793289, -0.0681633122, -0.0169713243, -0.0267169811, -0.0648342653,  0.0259666353, -0.0355429704,            -0, -0.1148553059, -0.1034848137, -0.0136103197, -0.0775830164,  0.0132602941,  0.0489879824,  0.0179630904,  0.0439992288,  0.0184372536, -0.0371849142, -0.0785376739,            -0,  0.0017623807,  0.0252183055,  0.0587838624, -0.0240729161,  0.0382968402,             0,  0.0887888495,   0.038281798,  0.0535235914,  0.0006256077,  0.0136947334,  0.0694197234,  0.0114898147,  0.0780030315,  -0.010039078,  -0.055265942, -0.0135994621, -0.0356434491, -0.0155647061,  0.0540416778,  0.0185516048,  0.0919876081,  0.0910274004,  0.0273363004,  0.0644000994,             0,  0.0058501386, -0.0162056629, -0.0560172964,  0.0136882396, -0.0405876093,            -0, -0.0828338488, -0.0288258882, -0.0210231081,             0,  0.0353960106);
s(09,0) = (  0.0562224761,  0.0581873513,    0.04440985,  0.0584109246,  0.0748029718,  0.0560581909, -0.0161647838,  0.0620253786,  0.0188493103,   0.064163649,  0.0868159967, -0.0050094204, -0.0748597516, -0.0018866347,             0, -0.0491586245,  0.0053748224,  0.0612322377,  0.0059261537, -0.0596574874, -0.0384374664,  -0.066007807, -0.0121671775, -0.0677501836, -0.0779318111,  -0.054495411,             0,  0.0001337899,  -0.081946097,  -0.029907289,  0.0502781251, -0.0359811473,            -0, -0.0145905319, -0.0957343298, -0.0486043436, -0.0733624983, -0.0616120111, -0.0036055405, -0.0516921776, -0.0540418998,  0.0451653762,  0.0499570045,   0.049973064,  0.0098565403,  0.0571946193, -0.0204876262, -0.0681703826,  -0.010768815, -0.0773436723, -0.0888284552, -0.0136290078,            -0, -0.0329436743,   0.052659796,  0.0517267163, -0.0441541931,  0.0597009301,             0,   0.048316132,  0.0720871858, -0.0229952211,            -0,  0.0479805429);
s(10,0) = (  0.0545174276, -0.0580924657,  0.0451527878,  0.0557414028, -0.0739231673, -0.0568573417, -0.0149574122,  0.0626191318,  0.0171493968, -0.0628368331, -0.0877907345,   0.004514763, -0.0757739406,   7.24565e-05,             0, -0.0493255095, -0.0042218786, -0.0621051483,  -0.007102729,  0.0605079489, -0.0398251471,  -0.066639683, -0.0110698881, -0.0683987389, -0.0768601054,  0.0541383541,            -0, -0.0016183207,  0.0828661573,  0.0307811574,  0.0511025964, -0.0378886611,            -0, -0.0149310807, -0.0970644585, -0.0450208555,  0.0704476896,  0.0624903357,  0.0028321222,  0.0524290877,  0.0555478962, -0.0458092419,  0.0515932987,  0.0504514435,  0.0089676343,  0.0577421289, -0.0222175542, -0.0688229603, -0.0062802554,  0.0719422641,  0.0898257881,  0.0145909729,             0,  0.0346314101, -0.0532510406, -0.0528462599, -0.0446417604,  0.0616071617,             0,  0.0489436876,  0.0730887621, -0.0259563755,            -0,  0.0516660083);
s(11,0) = (  0.0707630391, -0.0753230933,  0.0444037316, -0.0810134844,   0.074322459, -0.0625775851, -0.0246581844, -0.0631842219,  0.0111442036, -0.0461451509,  0.0963106841,  0.0119415268, -0.0775143199,  0.0150947779,            -0,  0.0388830765,  0.0182993596, -0.0683533575,  0.0121651733,  0.0665954687, -0.0349266163,  0.0672410555, -0.0071935525,  0.0690159855, -0.0430057557,  0.0176848195,            -0, -0.0170031371, -0.0909081847,  0.0283656729,   0.050402315,   0.026239309,             0,  0.0222672652, -0.0978601654,  0.0508968034,  -0.034480683,  0.0687772975, -0.0122755836,   0.057703818, -0.0644813752, -0.0504179698,  0.0456101965, -0.0509067294,  0.0058274435, -0.0582632077, -0.0455325444,  0.0694440352, -0.0302803367,  0.0433847715, -0.0985432365,  0.0444255152,             0,  0.0506217213,  0.0584189685, -0.0534559532, -0.0461269269, -0.0519236246,            -0, -0.0553019562,   0.073687923,  0.0224876287,             0, -0.0005511244);
s(12,0) = (  0.0709513868,  0.0752843506,  0.0443247205, -0.0807183519, -0.0742627547,  0.0624334493, -0.0247910701, -0.0632454837,  0.0113108912,  0.0462493979, -0.0964846867, -0.0119965389, -0.0774192216,  0.0148805814,            -0,  0.0389001221, -0.0182552586,  0.0681959182, -0.0123123661, -0.0664420784,  -0.034777961,  0.0673062507, -0.0073011489,  0.0690829016, -0.0430783993, -0.0179356949,             0,  0.0168247185,  0.0910724266, -0.0282351023,  0.0503147375,  0.0264456575,             0,  0.0223025166, -0.0977204127,  0.0505311337,  0.0337642868, -0.0686188818,  0.0122459997,  -0.057570908,  0.0646993076,  0.0503018414,  0.0454341493, -0.0509560872,  0.0059146066, -0.0583196982, -0.0453775901,  0.0695113664, -0.0307620178, -0.0445264598,  0.0987212725, -0.0441257691,            -0,  -0.050390714, -0.0585245128,  0.0532771218, -0.0460766524, -0.0521284477,            -0, -0.0553667998,  0.0735826904,  0.0227904006,             0, -0.0009952303);
s(13,0) = (  0.0907515015,  -2.47435e-05,  0.1261395073, -0.0035232581,  -4.08646e-05,   -4.3636e-06,  0.1552630447,  0.0008519153,  0.0008184207,  -5.73446e-05,   -4.3806e-06,   1.27686e-05,  0.1510752656,   0.002622922,             0, -0.0054442884,  -7.56993e-05,   -4.7663e-06,   2.36426e-05,    4.6437e-06,  0.1311160641, -0.0009066138, -0.0005282883, -0.0009305452,  0.0166897389,  -9.98512e-05,            -0,   3.46159e-05,    4.1349e-06,   -7.4582e-06,  0.1249126239,  -0.002588287,            -0,  0.0029540611,  0.0200152267,  0.0017852394, -0.0001209067,    4.7959e-06,   5.07806e-05,    4.0237e-06,   -1.6668e-05,   -3.5157e-06,  0.1352667401,  0.0006863774,  0.0004279624,  0.0007855651,  0.0040173824, -0.0009363167,  -0.001735232, -0.0001265446,    4.4822e-06,   7.15323e-05,             0,  -2.58841e-05,   -2.6571e-06,    4.3302e-06,  0.1446556384,   0.002608157,             0, -0.0019280349, -0.0150713059, -0.0019764035,            -0, -0.0056077784);


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
