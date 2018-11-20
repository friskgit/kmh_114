declare name	"KMH114_channel_map_C";
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
// * 2 -> 3 
// * 3 -> 2 
// * 4 -> 15 
// * 5 -> 8 
// * 6 -> 5 
// * 7 -> 9 
// * 8 -> 4 
// * 9 -> 7 
// * 10 -> 6 
// * 11 -> 10
// * 12 -> 11
// * 13 -> 13
// * 14 -> 14
// * 15 -> 16
//---------------------------------------------------

import("stdfaust.lib");

vmeter(x)	= attach(x, envelop(x) : vbargraph("[unit:dB]", -70, +5));
hmeter(x)	= attach(x, envelop(x) : hbargraph("[2][unit:dB]", -70, +5));
envelop         = abs : max ~ -(1.0/ma.SR) : max(ba.db2linear(-70)) : ba.linear2db;

process(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15) =
  s0, s2, s1, s14*0, s7, s4, s8, s3, s6, s5, s9, s10, s12, s11, s13, s15*0;

