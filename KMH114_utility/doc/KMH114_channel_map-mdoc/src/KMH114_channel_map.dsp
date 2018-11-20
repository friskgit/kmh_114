declare name	"Channel mapping for Studio 114(C)";
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
// * 3 -> 5 (LSR)  
// * 4 -> 6 (RSR)  
// * 5 -> 7 (LSF)  
// * 6 -> 8 (RSF)  
// * 7 -> 9 (RL)   
// * 8 -> 10 (RR)  
// * 9 -> 11 (ULF) 
// * 10 -> 12 (URF) 
// * 11 -> 13 (URL) 
// * 12 -> 14 (URR) 		 
// * 13 -> 15 (VOG) 
// * 14 -> -        
//
//---------------------------------------------------

import("stdfaust.lib");

vmeter(x)	= attach(x, envelop(x) : vbargraph("[unit:dB]", -70, +5));
hmeter(x)	= attach(x, envelop(x) : hbargraph("[2][unit:dB]", -70, +5));
envelop         = abs : max ~ -(1.0/ma.SR) : max(ba.db2linear(-70)) : ba.linear2db;

process(L, R, RSF, RSR, RR, RL, LSR, LSF, ULF, URF, URL, URR, VOG, x1, x2) =
  hgroup("", (L, R, x1, x2, LSR, RSR, LSF, RSF, RL, RR) : hgroup("lower ring", par(i, 10, vgroup("%i", vmeter)))),
  hgroup("", (ULF, URF, URR, URL) : hgroup("upper ring", par(i, 4, vgroup("%i", vmeter)))),
  hgroup("", (VOG) : hgroup("vog", par(i, 1, vgroup("%i", vmeter))));
