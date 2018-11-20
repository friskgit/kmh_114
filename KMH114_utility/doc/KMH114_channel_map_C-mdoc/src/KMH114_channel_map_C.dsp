declare name	"Channel mapping for Studio 114";
declare version " 0.1 ";
declare author " Henrik Frisk " ;
declare license " BSD ";
declare copyright "(c) dinergy 2018 ";

//---------------`Channel mapping plugin` --------------------------
//
// Channel mapping plugin that takes 15 channels of input (center speaker included)
// and maps it to the channel/speaker configuration of the studio 114 according to:
//
// * 1 -> 1 (L)
// * 2 -> 2 (R)
// * 3 -> 3 (C)
// * 4 -> 5 (LSR)
// * 5 -> 6 (RSR)
// * 6 -> 7 (LSF)
// * 7 -> 8 (RSF)
// * 8 -> 9 (RL)
// * 9 -> 10 (RR)
// * 10 -> 11 (ULF)
// * 11 -> 12 (URF)
// * 12 -> 13 (URL)
// * 13 -> 14 (URR)
// * 14 -> 15 (VOG)
//
//---------------------------------------------------

import("stdfaust.lib");

vmeter(x)	= attach(x, envelop(x) : vbargraph("[unit:dB]", -70, +5));
hmeter(x)	= attach(x, envelop(x) : hbargraph("[2][unit:dB]", -70, +5));
envelop         = abs : max ~ -(1.0/ma.SR) : max(ba.db2linear(-70)) : ba.linear2db;

process(L, C, R, RSF, RSR, RR, RL, LSR, LSF, ULF, URF, URL, URR, VOG, x) =
  vgroup("", (L, R, C, x, LSR, RSR, LSF, RSF, RL, RR) : hgroup("lower ring", par(i, 10, vgroup("%i", vmeter)))),
  vgroup("", (ULF, URF, URR, URL) : hgroup("upper ring", par(i, 4, vgroup("%i", vmeter)))),
  vgroup("", (VOG) : hgroup("vog", par(i, 1, vgroup("%i", vmeter))));
