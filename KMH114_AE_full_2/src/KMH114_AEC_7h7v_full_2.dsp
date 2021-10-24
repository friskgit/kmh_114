// Faust Decoder Configuration File
// Written by Ambisonic Decoder Toolbox, version 8.0
// run by henrik_frisk on  (x86_64-apple-darwin17.6.0) at 25-Sep-2018 18:10:32

//------- decoder information -------
// decoder file = ../decoders/KMH114_AEC_7h7v_pinv_even_energy_rV_max_rE_2_band.dsp
// description = KMH114_AEC_7h7v_pinv_even_energy_rV_max_rE_2_band
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
declare name "KMH114_AEC_7h7v_full_2";

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
s(00,0) = (   0.085793203,   0.050203705, -0.0118274581,  0.1033393961,  0.0888302862, -0.0054813968, -0.0496833309, -0.0074051322,  0.0623855992,  0.1114693499, -0.0075805105, -0.0337376879,  0.0120718274, -0.0673273994,            -0,  0.0179739043,   0.115993159, -0.0059873176,  -0.062073267,  0.0058333377,  0.0422688966,  0.0078805893, -0.0402697311,  0.0080886094, -0.0091806455,  0.1002941181,            -0, -0.0778929562,  0.0071552856,  0.0299835728, -0.0130033451,   0.057700797,             0, -0.0062647052,  0.0191832793, -0.0737289405,  0.0639714235,   0.006024452, -0.0778105765,  0.0050544859,  0.0545846834, -0.0044162921, -0.0441851487, -0.0059662214,  0.0326222107, -0.0068283939,  0.0207394162,  0.0081387765, -0.1082727878,  0.0161537543,  0.0077562323, -0.0629593173,             0,   0.067206094, -0.0045980943, -0.0281640742,  0.0059190366, -0.0527308649,            -0,  0.0008097323, -0.0144448561,  0.0565886213,             0,  -0.115277566);
s(01,0) = (  0.0829148782,  -0.001480888, -0.0011236554,  0.1044902623, -0.0025421236,  -3.25368e-05, -0.0445536965,   0.000833811,  0.1232266047, -0.0033342432,    2.6833e-06,  0.0008890811, -0.0042015346, -0.0635314704,             0,  0.1230828869, -0.0038625927,  -3.55399e-05,  0.0016426093,   3.46259e-05,  0.0281385174, -0.0008873471, -0.0795424313,   -0.00091077,    0.12156151, -0.0042227304,            -0,  0.0021806841,   -2.5328e-06, -0.0006832232, -0.0009722184,  0.0497222901,            -0,  -0.082044925, -0.0024705264,  0.1335817669, -0.0041685032,   3.57603e-05,  0.0025911059,   3.00027e-05, -0.0013321876,  -2.62145e-05, -0.0271472853,   0.000671791,   0.064436734,  0.0007688708, -0.0834237409, -0.0009164187,  0.1232803874, -0.0035248343,   -2.7455e-06,  0.0028881258,             0, -0.0017725577,    1.6276e-06,  0.0005682128, -0.0034091449, -0.0420689596,             0,  0.0678951543,  0.0018602866, -0.0911867578,            -0,  0.1172269085);
s(02,0) = (  0.0858768166, -0.0505537421, -0.0123181661,  0.1028786291, -0.0899275508,  0.0067603728, -0.0498972207, -0.0079704345,  0.0609696027,  -0.111664157,  0.0091377462,  0.0346507072,  0.0128115496, -0.0673540462,            -0,  0.0132097736, -0.1132583021,  0.0073843402,  0.0637539464, -0.0071944322,  0.0428939422,  0.0084821877, -0.0393557093,  0.0087060879, -0.0179476496, -0.0919647287,             0,  0.0789931424, -0.0086251689, -0.0314780719, -0.0135545925,  0.0580633908,             0, -0.0026842034,  0.0201709108, -0.0824061091, -0.0487147476, -0.0074301392,  0.0759759787, -0.0062338507, -0.0568294378,   0.005446747, -0.0449506411, -0.0064216784,  0.0318817684, -0.0073496684,  0.0273711815,  0.0087600847, -0.1143213145,  0.0044342507, -0.0093495658,  0.0561676139,            -0, -0.0688590962,  0.0055426634,  0.0300377405,  0.0063419887, -0.0533045786,            -0, -0.0024630525, -0.0151885347,  0.0629725723,             0, -0.1144914678);
s(03,0) = (  0.0908034309, -0.1041865167, -0.0151976431,   0.051549828, -0.1005351922,  0.0087446675,  -0.053603894, -0.0110916802,  -0.066097511,  0.0105720718,  0.0172660557,  0.0685779008,  0.0166426378, -0.0376267462,            -0, -0.1177408154,  0.1025717127,   0.009551781,  0.0756767801, -0.0093061315,   0.047852291,  0.0118038374,  0.0426657599,  0.0121154177, -0.0445890822,  0.0872490203,             0, -0.0003515273, -0.0162975249, -0.0594986861, -0.0167642412,  0.0364475988,             0,  0.0863019366,  0.0255572913,  0.0525038835,  0.0044649869, -0.0096110229, -0.0688071966, -0.0080636014,  -0.071098333,  0.0070454682, -0.0507893207, -0.0089364266, -0.0345632158, -0.0102278203,   0.049336885,  0.0121905597,  0.0966692023, -0.0861609616, -0.0176662955,  -0.066949018,            -0, -0.0048330163,   0.010473035,   0.054891891,  0.0084454643, -0.0363047235,            -0, -0.0774007666, -0.0192444362, -0.0255488945,             0,  0.0464787973);
s(04,0) = (  0.0932658174, -0.1222500083, -0.0066513054, -0.0345078189,  0.0544492488,    6.8967e-05, -0.0522029738, -0.0042223757, -0.1055666023,   0.097737141,  0.0063690323,  0.0749002099,  0.0029631909,  0.0188250799,            -0,  0.0705453804, -0.0951708695,   7.53325e-05,  -0.031169769,  -7.33952e-05,  0.0378531459,  0.0044934793,  0.0681429488,  0.0046120916,  0.0755145088, -0.0432208428,            -0, -0.0645946644, -0.0060117646, -0.0592554816, -0.0071243556,  -0.012331582,             0, -0.0434546501,  0.0077172837, -0.1112085418,  0.1194567051,  -7.57998e-05,  0.0638425601,  -6.35956e-05,  0.0216379473,   5.55659e-05, -0.0386201432, -0.0034019147, -0.0552020977, -0.0038935219, -0.0447909094,  0.0046406966, -0.0100509508, -0.0392304829, -0.0065166711,  0.0291984922,             0,  0.0530295376,  0.0038632505,  0.0506312193,  0.0004879711,  0.0085575406,            -0,  0.0332285572,  -0.005811053,  0.0790939646,             0,  0.0985054815);
s(05,0) = (  0.0789057775,  -0.067174999, -0.0159148889, -0.0696659732,  0.1021577928,  0.0158321166, -0.0471038449,   0.018946268,  -0.007591098, -0.0638534109, -0.0293879725,  0.0497847285,  0.0194752085,  0.0530113001,             0,  0.0756409369, -0.0344759372,  0.0172933859, -0.0842935578, -0.0168486403,  0.0455400159, -0.0201627404,  0.0049000327, -0.0206949666, -0.0919815771,  0.1010865823,             0,  0.0542589492,  0.0277394689, -0.0489232647, -0.0176561442, -0.0533555097,            -0, -0.0644207439,  0.0284066285,  0.0401659398, -0.0981752254, -0.0174006426,  0.0231271617, -0.0145990545,  0.0849541509,  0.0127557363, -0.0482876573,  0.0152647688, -0.0039694802,  0.0174706646,   0.083294465, -0.0208233205,  0.0662544141,  0.0100034364,  0.0300692072, -0.0827046718,            -0, -0.0538512797, -0.0178258005,  0.0491724242,  0.0103641468,   0.054412001,             0,  0.0640240307, -0.0213899644, -0.0442678381,            -0, -0.1054963806);
s(06,0) = (  0.0788507706,  0.0669315949, -0.0158953921, -0.0697515154, -0.1025398749, -0.0158862915,  -0.047066094,  0.0189600656, -0.0076393063,  0.0633401419,  0.0293291617, -0.0496652687,   0.019453258,   0.053071221,             0,  0.0756299929,  0.0338199699,  -0.017352561,   0.084503467,  0.0169062937,  0.0455012442, -0.0201774238,   0.004931151, -0.0207100376, -0.0919771287, -0.1019493698,            -0, -0.0539605974, -0.0276839571,  0.0488615533, -0.0176346081, -0.0534112171,            -0, -0.0644239838,  0.0283733598,  0.0402513642,  0.0971150987,  0.0174601848, -0.0226871255,  0.0146490101, -0.0850908399, -0.0127993844, -0.0482416675,  0.0152758853, -0.0039946889,  0.0174833876,  0.0832661941,  -0.020838485,  0.0663777937, -0.0111323169, -0.0300090332,   0.083337607,             0,  0.0536378894,  0.0177901277, -0.0491450368,  0.0103528667,   0.054466016,             0,  0.0640347739, -0.0213649133, -0.0443381058,            -0, -0.1053675519);
s(07,0) = (  0.0933094204,  0.1225036588, -0.0066633971, -0.0344518743, -0.0540188229,   -6.6653e-05, -0.0522307809, -0.0042321302,  -0.105532207, -0.0971934328, -0.0063740108, -0.0750542745,  0.0029775675,  0.0187854923,            -0,  0.0705345278,  0.0957652379,   -7.2805e-05,  0.0308888215,   7.09326e-05,  0.0378813082,  0.0045038602,  0.0681207467,  0.0046227464,  0.0754599683,  0.0438255026,             0,  0.0642367927,  0.0060164638,  0.0593758824, -0.0071377496, -0.0122943921,             0, -0.0434400637,  0.0077385291, -0.1113017896,  -0.118912334,   7.32565e-05, -0.0642412746,   6.14619e-05, -0.0214075301,  -5.37015e-05, -0.0386516898, -0.0034097738,  -0.055184112, -0.0039025167, -0.0447381743,  0.0046514175, -0.0101503798,  0.0396355457,   0.006521765, -0.0296099343,            -0, -0.0527368713, -0.0038662703,   -0.05073295,  0.0004955335,  0.0085212267,            -0,  0.0332108599, -0.0058270506,   0.079165885,             0,    0.09844662);
s(08,0) = (  0.0913749646,  0.1048109616, -0.0153559303,  0.0523400204,  0.1016946965, -0.0088549764,  -0.053973044, -0.0112064798, -0.0656335161, -0.0090954086, -0.0174194956,  -0.069020552,  0.0168204356, -0.0381733498,            -0, -0.1177313973, -0.1010388458, -0.0096722711, -0.0765210508,  0.0094235228,  0.0482136211,  0.0119260079,  0.0423662525,   0.012240813, -0.0449039677, -0.0859653757,            -0,  -0.000708969,  0.0164423578,  0.0599152758, -0.0169390643,  0.0369490831,             0,   0.086382893,  0.0258270572,  0.0515637286, -0.0037528799,  0.0097322603,  0.0677789183,   0.008165319,     0.0718693, -0.0071343426,   -0.05120171, -0.0090289192, -0.0343205871, -0.0103336789,  0.0497531606,  0.0123167328,  0.0954899295,  0.0861454074,  0.0178232923,  0.0661794026,             0,  0.0057689118, -0.0105661067, -0.0552991547,  0.0085367382, -0.0367865777,            -0, -0.0775345182, -0.0194475678, -0.0248089432,             0,  0.0454742789);
s(09,0) = (  0.0791994949,  0.0720605926,  0.0436357377,  0.0704683663,   0.089419952,   0.055893043, -0.0255337386,  0.0588983869,  0.0111760093,  0.0666274979,  0.0848431353, -0.0135952263, -0.0684763267, -0.0109784615,             0, -0.0592893911,  0.0032928377,   0.061051847, -0.0047409973, -0.0594817361, -0.0250672855, -0.0626800424,  -0.007214083, -0.0643345775, -0.0808368601, -0.0552227659,             0, -0.0016213164, -0.0800839023, -0.0230198393,  0.0491518493, -0.0269042535,            -0, -0.0055148289, -0.0899891774, -0.0531247501,  -0.074613564, -0.0614305017, -0.0022089027, -0.0515398921, -0.0442815325,  0.0450323187,  0.0412062422,  0.0474536863,  0.0058440751,   0.054311169, -0.0141720772, -0.0647335923, -0.0096641259,   -0.06819687, -0.0868098615, -0.0129877463,            -0, -0.0314049788,  0.0514631216,  0.0457682849, -0.0396134521,  0.0504892308,             0,  0.0390281757,  0.0677611319, -0.0171166829,            -0,  0.0468651034);
s(10,0) = (  0.0778284251,  -0.071744062,  0.0440744036,  0.0685104486, -0.0885059978, -0.0563416601, -0.0246244142,  0.0592297605,  0.0099812599, -0.0654569393, -0.0854006154,  0.0131563256, -0.0689849733, -0.0095984672,             0,  -0.059300939, -0.0023772422, -0.0615418704,  0.0038029304,  0.0599591572, -0.0260004784, -0.0630326923, -0.0064428756, -0.0646965362, -0.0799253067,  0.0550286147,            -0,  0.0005063572,  0.0806101108,   0.023637853,  0.0496371247, -0.0281954344,            -0, -0.0057588563, -0.0907495583, -0.0506052554,  0.0726515828,  0.0619235643,  0.0015947026,  0.0519535692,  0.0453576508, -0.0453937638,  0.0422838292,  0.0477206698,  0.0052193257,   0.054616734, -0.0153615171, -0.0650977959, -0.0065715409,  0.0645446059,  0.0873802643,  0.0135235044,             0,  0.0325837701, -0.0518012711, -0.0465055933, -0.0398782163,   0.051746593,             0,   0.039422753,  0.0683336927, -0.0191210401,            -0,  0.0493619076);
s(11,0) = (  0.0889846541, -0.0809065518,  0.0435207278, -0.0875667969,  0.0882671957, -0.0591550503, -0.0311288704, -0.0593768054,  0.0091181728, -0.0572035594,  0.0895720815,   0.017230311, -0.0697477164,  0.0211877234,            -0,  0.0477091438,  0.0129704092, -0.0646149304, -0.0010439595,  0.0629531852, -0.0223159276,  0.0631891783, -0.0058857552,  0.0648571529, -0.0584890945,   0.032410523,            -0,  -0.007089403, -0.0845475806,  0.0221167958,  0.0490937353,  0.0191221601,             0,  0.0135377831, -0.0909173707,  0.0552705477, -0.0507603896,  0.0650156839,  -0.008700815,  0.0545478425, -0.0499586865, -0.0476604768,  0.0380870024,  -0.047839142,  0.0047680067, -0.0547523265, -0.0298689165,  0.0652594088, -0.0197702334,  0.0461168724, -0.0916484281,  0.0313715994,             0,  0.0404721502,  0.0543315485, -0.0465210651, -0.0405871357, -0.0440675045,            -0, -0.0458999189,  0.0684600541,  0.0160951468,             0, -0.0186313064);
s(12,0) = (  0.0891179391,  0.0809082039,  0.0434781576, -0.0873722441, -0.0881976912,  0.0590688222, -0.0312176568, -0.0594078207,  0.0092318254,  0.0572798928, -0.0896778971, -0.0172784266, -0.0696992851,  0.0210516419,            -0,  0.0477200458, -0.0129801385,  0.0645207436,  0.0009330193, -0.0628614207, -0.0222259605,   0.063222185, -0.0059591176,  0.0648910309, -0.0585438109, -0.0326637725,             0,  0.0069734262,  0.0846474605, -0.0220266624,  0.0490466876,  0.0192484798,             0,   0.013554127, -0.0908443263,  0.0550479668,  0.0501573998,  -0.064920913,  0.0087073416, -0.0544683302,  0.0501085759,  0.0475910039,  0.0379824285, -0.0478641307,   0.004827437, -0.0547809262,  -0.029776692,  0.0652934969, -0.0200619793, -0.0470225059,  0.0917566965, -0.0311224354,            -0,  -0.040326361, -0.0543957328,  0.0464038161, -0.0405621324, -0.0441898598,            -0, -0.0459315127,  0.0684050522,  0.0162737874,             0, -0.0188971574);
s(13,0) = (  0.1059609017,   -1.1762e-05,  0.1357607354, -0.0033598621,  -1.69671e-05,   -7.9416e-06,  0.1586708396,   0.000458875,  0.0010117309,  -3.06616e-05,   -9.4235e-06,    2.8644e-06,   0.153236521,  0.0023081566,             0, -0.0044546585,   -5.5443e-05,   -8.6746e-06,    5.0678e-06,    8.4515e-06,  0.1373739266, -0.0004883377, -0.0006530695, -0.0005012281,  0.0134262867,  -9.53405e-05,            -0,   1.42494e-05,    8.8949e-06,    2.5334e-06,  0.1349008959, -0.0021019876,            -0,  0.0025979816,  0.0140273179,  0.0013895757, -0.0001398063,    8.7284e-06,   3.71923e-05,    7.3231e-06,    1.2395e-06,   -6.3984e-06,  0.1437195125,  0.0003697098,  0.0005290467,  0.0004231362,  0.0016552752, -0.0005043369, -0.0022322091, -0.0001680308,    9.6419e-06,   7.17032e-05,             0,   -7.0556e-06,    -5.716e-06,   -5.8733e-06,  0.1487374387,  0.0020092846,             0, -0.0018656927, -0.0105624584, -0.0013543094,            -0,  -0.003069067);


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
