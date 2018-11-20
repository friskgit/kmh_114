// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 27-Sep-2018 17:15:22

//------- decoder information -------
// decoder file = ../decoders/KMH114_AE_7h7p_allrad_5200_rE_max_2_band.dsp
// description = KMH114_AE_7h7p_allrad_5200_rE_max_2_band
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
declare name "KMH114_AE_7h7p_normal_6";

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
s(00,0) = (  0.0776028829,  0.0544238257, -0.0586801181,  0.1889789999,  0.1171979617, -0.0423706944, -0.0894925939, -0.1095150193,  0.1857775602,  0.1464979288, -0.0862068153,  -0.017405834,  0.0529292626, -0.0804879535, -0.0912091631,   0.126121281,  0.1268719639, -0.1042255995, -0.0144254356,  0.0201106008,  0.0485251092,  0.0250394166,   -0.04339214, -0.0460833127,  0.0497517055,  0.0714275919, -0.0886624995, -0.0032925643,  0.0169502041,  0.0162060519,  0.0035728342,  0.0658683971, -0.0139218115, -0.0199545939, -0.0015771973, -0.0062367957,  0.0099811038,  -0.051487536,  0.0060158926,  0.0027312779,  0.0336270824, -0.0094759172, -0.0449748578,  0.0179774581,  0.0538446137, -0.0293900097, -0.0090275331,  0.0213279948, -0.0245598837, -0.0300688897, -0.0136693963,  0.0091601968, -0.0084377215,   0.043204679, -0.0154577585, -0.0149828133, -0.0201010282, -0.0431975898,  0.0215968268,  0.0314866112, -0.0233059283, -0.0053834168,  0.0183461794, -0.0119547115);
s(01,0) = (  0.0639068736, -0.0568013531, -0.0647403664,  0.1502917971, -0.1223901752,  0.0440944482, -0.0617058268, -0.1261106786,  0.1360364296, -0.1531949756,  0.0896461079,  0.0185656948,  0.0747308139, -0.0412314786, -0.1124954799,  0.0735165859, -0.1332581006,   0.108203073,  0.0161878143, -0.0210005028,  0.0243013277,  0.0654437613,  -0.008290856, -0.0674213905,  0.0023081059, -0.0764241825,  0.0917745038,  0.0055589994, -0.0177517797, -0.0176304793,  -0.033223966,  0.0388217207,  0.0299518584,  0.0080355609, -0.0190412956, -0.0421553692, -0.0137847859,  0.0530043106, -0.0030954091, -0.0029646159, -0.0367555285,  0.0098334472, -0.0337823638, -0.0383062811,   0.034515714,  0.0117532123,  0.0110070129,  0.0098017502, -0.0458020423,  0.0264088121,  0.0138612253, -0.0054933206,  0.0087131316,  -0.047701693,  0.0158745809,  0.0167499663,  0.0235024958, -0.0383362374, -0.0313773338,  0.0184157101,  0.0101585181,  0.0077372237,  0.0128456619, -0.0192610906);
s(02,0) = (  0.0607457469,  -0.137005127, -0.0617960463,  0.0689785002, -0.1431430266,  0.1154948672, -0.0585046076, -0.0555015229, -0.1045101599,  0.0240859278,  0.1092067602,  0.0373569898,  0.0716562506,  -0.021033588,   0.087380332, -0.1672812393,  0.1289556926, -0.0281933295,  0.0158544501, -0.0605953978,  0.0228280684,  0.0277217269,  0.0057537808,   0.123789315, -0.0502514709,  0.0783884115,  -0.094373202,  0.0068986906, -0.0245500599,  -0.034953067,  -0.032519357,  0.0198663832, -0.0240248034,  0.0023246926,  0.0225460723,  0.0567792973,  0.0052876386, -0.0390090054,  0.0065150554,  0.0079960069, -0.0408460402,  0.0359733624, -0.0316971826, -0.0146755219, -0.0258905038, -0.0073357753,  0.0064937352, -0.0451555111,  0.0561759804, -0.0107600762,  0.0072291442, -0.0028687945, -0.0048233912,  0.0040398408,   0.023403995,  0.0346166588,  0.0231747812, -0.0191903804,  0.0252680874, -0.0502425823,  0.0103369763,  0.0074354987, -0.0232697078,   0.029028593);
s(03,0) = (  0.0663344431, -0.1701255931, -0.0473590334, -0.0195538548,  0.0463484626,  0.0941289589,  -0.078820297,   0.014375343, -0.1956759403,  0.1809387306, -0.0323974257,  0.0756470889,  0.0402516092,   0.006889188,  0.0997183748,  0.0687228083, -0.0787647914, -0.0897247708, -0.0068631817, -0.0178853147,  0.0445929592,  -0.006271879,  0.0447114512, -0.0474192637,  0.1374703954, -0.0803786684,  0.0551853927,  -0.019506395,  0.0052786574, -0.0615135654,  0.0088562095, -0.0064170705,   0.010664019,  -0.002532626,  -0.070279185, -0.0732796921,  0.0541451165,  0.0469519167, -0.0035418019,  -0.024081845,   0.013949574, -0.0218307249,  -0.039684391,   0.002242631, -0.0570015554,  0.0003358713, -0.0020921766,   0.054074891, -0.0251790297, -0.0160135349, -0.0448992128, -0.0067543664,  0.0047911494,  0.0474239199, -0.0042432007,  0.0393907112, -0.0238850421,   0.005709807, -0.0187447942,  0.0205645229, -0.0232393834, -0.0089984317,  0.0241461493,   0.027237448);
s(04,0) = (  0.1160592082, -0.0897001506, -0.0985153583, -0.2571153695,  0.1574092516,  0.0717901054, -0.1193377693,   0.165827716,  0.1851540236, -0.1250849174, -0.1156332819,  0.0251102787,  0.0879314949,   0.087989912, -0.0891019567, -0.0454699502,  0.0216927172,  0.0800219273, -0.0152857439, -0.0319338736,  0.0578669189,   -0.03562638, -0.0335168855, -0.0142117874, -0.0449028783,  0.0612537885,  0.0016627395,  0.0032562061,  0.0164779306, -0.0249675453, -0.0024168865, -0.0812411898,  -0.029997316,  0.0122992148,  0.0588579615,  0.0426732849,  -0.064493147, -0.0542806801, -0.0035691012,  0.0107354677,  0.0451853647,  0.0154931026, -0.0623410382, -0.0154406441,  0.0530212116,  0.0409886821, -0.0061587431, -0.0291992622,  0.0056399371,  0.0099577353,   0.040545434,  0.0077214901,  -0.017188845, -0.0388292278, -0.0177868813,  0.0228142548, -0.0151620713,  0.0540101322,  0.0286454434, -0.0065967871, -0.0155255648, -0.0008938269, -0.0208376189, -0.0311019048);
s(05,0) = (  0.1029711303,  0.0907073893, -0.1068084001, -0.2214266878, -0.1599267093, -0.0717477727, -0.0916836548,  0.1875130182,  0.1447479001,  0.1288453416,  0.1154320413, -0.0266555107,  0.1137389958,  0.0501417833, -0.1159875168, -0.0117132323, -0.0258235483, -0.0795821093,  0.0185521979,  0.0316397825,  0.0345294399, -0.0809015855,  -0.003807456,  0.0109543087,  -0.064916299, -0.0578366351, -0.0023113161, -0.0077126348, -0.0156785977,  0.0271447909, -0.0432676569, -0.0583560452,  0.0147584504, -0.0053702265,  0.0414304442,  0.0479621845,  0.0626133758,  0.0549701161,  0.0081890152, -0.0121883656, -0.0493579946, -0.0147839863,  -0.054522639,  0.0445577833,  0.0425523972,  0.0057594029, -0.0001673165, -0.0221640739,  0.0107583819, -0.0097962184, -0.0410525369, -0.0114150994,  0.0191670676,  0.0441225395,  0.0158562472, -0.0253568158,  0.0312290898,  0.0563475806, -0.0225673087, -0.0067778983,  0.0049596177,  0.0009811588, -0.0189096558, -0.0398914739);
s(06,0) = (  0.0663390769,  0.1701377836,  -0.047348099, -0.0196053416, -0.0464625651, -0.0941055771, -0.0788466516,  0.0143604473, -0.1956819717,  -0.180924773,   0.032357517, -0.0756980666,  0.0402387758,  0.0069236524,   0.099706104,  0.0688619548,  0.0788685282,  0.0897381168,  0.0068999819,   0.017884395,  0.0446234087, -0.0062210538,  0.0447513817, -0.0473577264,  0.1374320983,   0.080324536, -0.0551308311,  0.0195276884, -0.0051585263,  0.0615287255,  0.0088832157, -0.0064259869,  0.0106525261, -0.0025546905,   -0.07032717, -0.0732964375, -0.0540598301,  -0.047028375,  0.0035497499,   0.024045688, -0.0139864236,  0.0219053665, -0.0397180369,  0.0021540675, -0.0570080476,  0.0002049203, -0.0020911354,  0.0540613167, -0.0251285039,  0.0160375397,  0.0449395442,  0.0067688008, -0.0048641447, -0.0474078209,  0.0041633084, -0.0394865456, -0.0239233217,  0.0057649929, -0.0187987973,  0.0205928253, -0.0231907357, -0.0090424823,  0.0242305317,  0.0270818985);
s(07,0) = (  0.0620889058,  0.1390646551, -0.0631917118,  0.0718116805,  0.1474027249, -0.1172591107, -0.0597675008, -0.0579364877, -0.1031164761, -0.0192019475, -0.1126769042, -0.0378707164,  0.0732868468, -0.0217656495,  0.0862149193, -0.1688340958, -0.1256491914,  0.0243124777, -0.0161469165,  0.0614628452,  0.0232632506,   0.029010641,  0.0056518465,  0.1249505309, -0.0546884134, -0.0782867852,  0.0917396112, -0.0067932315,  0.0254038816,  0.0355039774, -0.0332084847,  0.0205616619, -0.0236296012,  0.0023119929,  0.0258544549,  0.0510214644, -0.0086099734,  0.0386844658, -0.0062384157, -0.0075553787,  0.0419989186, -0.0364853716, -0.0324608678, -0.0154519016, -0.0256019613,  -0.007310168,  0.0062106571, -0.0409312182,  0.0514007183,  0.0053782513, -0.0052392547,  0.0029760189,  0.0049768897, -0.0027053082, -0.0243033272, -0.0351885492,   0.023798079,  -0.019923238,  0.0248864794, -0.0508004274,  0.0104915998,  0.0068662924, -0.0196495548,  0.0271540148);
s(08,0) = (  0.1130599913,  0.1638181571,  0.1767763077,  0.1459191465,   0.130083141,  0.2134985594,  -0.006673117,  0.2034154748, -0.0230121584,  0.0058131051,  0.1621856109,  0.0626652452, -0.1717348948,  0.0824145821, -0.0133992312, -0.0310230705, -0.0016701846,  0.0038525758,  0.0633087726,   -0.08598615, -0.1128947417, -0.0646762097,  0.0189105421, -0.0179794942,  0.0126698761,   0.009611217,  0.0008592425, -0.0050542857, -0.0331210457, -0.0562016045,  0.0380175632, -0.0699888862,  0.0231084309,  0.0233529432,  0.0297825218, -0.0056876729,  -0.007653859,  0.0092618605,  0.0031183995, -0.0093312223, -0.0142441743,  0.0478104202,  0.0597645799,  0.0187683573, -0.0107177921,  0.0312312017,  0.0372072435, -0.0029158285, -0.0118813286, -0.0070119193, -0.0119484548, -0.0002024378, -0.0001068647, -0.0018158533,  0.0482939709,  0.0460732765,  -0.029638354,  0.0488537468, -0.0282123233, -0.0086594791,   0.023832627,  0.0049399084, -0.0076253274, -0.0016872981);
s(09,0) = (  0.1206169159,  -0.163269333,  0.1811081038,    0.16726028, -0.1286828074,   -0.21294944,  -0.023085793,  0.2150620141,    0.00390741, -0.0037079566, -0.1606539761, -0.0630291533, -0.1854201632,  0.0584837188,  0.0022606286, -0.0032303239,  0.0040829443, -0.0012750754, -0.0637292814,  0.0849322265, -0.0976460627, -0.0894877592, -0.0032118984,  -0.000791124,  0.0372775595, -0.0073934071,  0.0024145783,  0.0050302991,  0.0308023808,  0.0559277887,  0.0602243915, -0.0525167381, -0.0038845361,  0.0049479738,  0.0456813159,  0.0131122724,  0.0090641838,  -0.005815161, -0.0025420813,  0.0061178917,  0.0131216236, -0.0466314947,  0.0516837775,  0.0529335153,  0.0018354306,  0.0055623421,  0.0234361619,  0.0094601334,   -3.7802e-05,  0.0074966648,  0.0148506549,  0.0014049658, -0.0033744283, -0.0004857967, -0.0461434785, -0.0449621096, -0.0561711831,  0.0437759605,  0.0047178971, -0.0007416473,  0.0025444501, -0.0043707515,   9.97821e-05,  0.0033647998);
s(10,0) = (  0.1026666754, -0.1453717595,  0.1705854761, -0.1316162437,  0.1199590024, -0.2040277742,  0.0156619296, -0.1949461939, -0.0205683039, -0.0087817833,  0.1580468843,  -0.083954024, -0.1522909035, -0.0978280763, -0.0139266212,   0.042767805, -0.0198931962, -0.0069740431,  0.0735466351,  0.0655478936, -0.1329534358,  0.0468545959,  0.0149306745,  0.0292049945,  -0.006839456,  0.0169697485, -0.0110435934,  0.0053612686, -0.0250026113,  0.0731090855,  0.0067885935,   0.079771474,  0.0231489112, -0.0268846915,  0.0134027451, -0.0021474427, -0.0102029482,  0.0080431302,  0.0136846892,  0.0129556679, -0.0235010179, -0.0189015092,   0.068996054,  0.0050487092, -0.0047908723, -0.0459994492,  0.0438380752,  0.0009324882,  0.0090740948, -0.0036834198, -0.0143139619, -0.0138497082,  0.0166071914,   0.004302625,   0.036369503, -0.0535023445,  0.0069144948, -0.0488848644, -0.0264217995,  0.0030917821,  0.0436304319,  0.0028640681,  0.0019859085,  -0.005882397);
s(11,0) = (  0.1177838765,  0.1446583713,  0.1797626873, -0.1728721534,  -0.118283712,  0.2031679069,  -0.016646586, -0.2190630608,  0.0260762937,  0.0064021082, -0.1557890331,  0.0842738367, -0.1810311443, -0.0531336213,    0.01629842,  0.0040371771,  0.0223925014,  0.0034274995, -0.0735171357,  -0.063931763, -0.1044722835,  0.0975543152, -0.0202618818,  0.0003603692,  0.0156817967, -0.0189520089,    0.01517285,  -0.006197315,  0.0218280786, -0.0722812323,  0.0526618654,  0.0505800074,  -0.027531791, -0.0064851172,  0.0341549939, -0.0073202328,  0.0113515995, -0.0117259531, -0.0119416498, -0.0089504116,  0.0209429578,  0.0172490428,  0.0568984112, -0.0630361309,  0.0093912106, -0.0054322105,  0.0382509621, -0.0085013152,  0.0021214961,  0.0034358277,  0.0167391817,  0.0115865323, -0.0202954159,   1.58961e-05, -0.0339900008,  0.0512615442, -0.0462790023, -0.0469411791,  0.0324534444,  0.0030397346,  0.0193794146, -0.0019413157,  0.0012934092,  0.0048763269);
s(12,0) = (  0.1475660167,    -8.907e-06,  0.3553593355,   1.25946e-05,   -7.3488e-06,  -1.15651e-05,  0.3667265665,    1.7067e-05,    5.4957e-06,   -7.5517e-06,   -9.9127e-06,    -5.577e-07,  0.2135048238,    4.3415e-06,    6.6695e-06,    4.3178e-06,   2.87174e-05,  -1.13386e-05,   -3.4704e-06,   1.36528e-05,  0.0276775066,  -1.14701e-05,     3.388e-07,    6.0526e-06, -0.0143705462,  -1.41649e-05,   4.11039e-05,   -7.0096e-06,    5.8398e-06,   1.37585e-05, -0.0714875581,  -1.12673e-05,   -7.6245e-06,   -1.2528e-06, -0.0275772752,   -7.0557e-06,   -7.1322e-06,  -1.91304e-05,   1.90207e-05,    2.1241e-06,    7.1778e-06,   -1.9629e-06, -0.0605827714,    2.1446e-06,   -7.3063e-06,  -1.72919e-05, -0.0299422792,  -1.32793e-05,  -2.95189e-05,    2.4553e-06,  -1.07986e-05,   -5.8828e-06,  -2.37441e-05,    6.8725e-06,    -1.769e-07,   -1.5643e-05, -0.0023348604,    8.0283e-06,    2.1736e-06,  -2.73734e-05, -0.0172524309,  -1.58046e-05,   -4.7745e-05,    2.5279e-05);


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
