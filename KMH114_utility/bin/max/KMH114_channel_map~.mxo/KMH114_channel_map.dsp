declare name	"KMH114_channel_map";
declare version " 0.1 ";
declare author " Henrik Frisk " ;
declare license " BSD ";
declare copyright "(c) dinergy 2018 ";

//---------------`Channel mapping plugin` --------------------------
//
// Channel mapping plugin that takes 15 channels of input (center speaker included)
// and maps it to the channel/speaker configuration of the studio 114 according to:
//
// * 1 -> 1 
// * 2 -> 2 
// * 3 -> 14 
// * 4 -> 15 
// * 5 -> 7 
// * 6 -> 4 
// * 7 -> 8 
// * 8 -> 3 
// * 9 -> 6 
// * 10 -> 5 
// * 11 -> 9
// * 12 -> 10
// * 13 -> 12
// * 14 -> 11
// * 15 -> 13
// * 16 -> 16
//
// Method: traverse the channel order of the ambisonics output and define the speaker
// number in the studio configuration
//---------------------------------------------------

import("stdfaust.lib");

vmeter(x)	= attach(x, envelop(x) : vbargraph("[unit:dB]", -70, +5));
hmeter(x)	= attach(x, envelop(x) : hbargraph("[2][unit:dB]", -70, +5));
envelop         = abs : max ~ -(1.0/ma.SR) : max(ba.db2linear(-70)) : ba.linear2db;
 
process(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15) =
  s0, s1, s13, s14, s6, s3, s7, s2, s5, s4, s8, s9, s11, s10, s12, s15;
