/* ------------------------------------------------------------
author: " Henrik Frisk "
copyright: "(c) dinergy 2018 "
license: " BSD "
name: "Channel mapping for Studio 114(C)"
version: " 0.1 "
Code generated with Faust 2.6.3 (https://faust.grame.fr)
Compilation options: cpp, -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	int fSamplingFreq;
	float fConst0;
	float fRec0[2];
	FAUSTFLOAT fVbargraph0;
	float fRec1[2];
	FAUSTFLOAT fVbargraph1;
	float fRec2[2];
	FAUSTFLOAT fVbargraph2;
	float fRec3[2];
	FAUSTFLOAT fVbargraph3;
	float fRec4[2];
	FAUSTFLOAT fVbargraph4;
	float fRec5[2];
	FAUSTFLOAT fVbargraph5;
	float fRec6[2];
	FAUSTFLOAT fVbargraph6;
	float fRec7[2];
	FAUSTFLOAT fVbargraph7;
	float fRec8[2];
	FAUSTFLOAT fVbargraph8;
	float fRec9[2];
	FAUSTFLOAT fVbargraph9;
	float fRec10[2];
	FAUSTFLOAT fVbargraph10;
	float fRec11[2];
	FAUSTFLOAT fVbargraph11;
	float fRec12[2];
	FAUSTFLOAT fVbargraph12;
	float fRec13[2];
	FAUSTFLOAT fVbargraph13;
	float fRec14[2];
	FAUSTFLOAT fVbargraph14;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", " Henrik Frisk ");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("copyright", "(c) dinergy 2018 ");
		m->declare("filename", "KMH114_channel_map");
		m->declare("license", " BSD ");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "Channel mapping for Studio 114(C)");
		m->declare("version", " 0.1 ");
	}

	virtual int getNumInputs() {
		return 15;
		
	}
	virtual int getNumOutputs() {
		return 15;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			case 2: {
				rate = 1;
				break;
			}
			case 3: {
				rate = 1;
				break;
			}
			case 4: {
				rate = 1;
				break;
			}
			case 5: {
				rate = 1;
				break;
			}
			case 6: {
				rate = 1;
				break;
			}
			case 7: {
				rate = 1;
				break;
			}
			case 8: {
				rate = 1;
				break;
			}
			case 9: {
				rate = 1;
				break;
			}
			case 10: {
				rate = 1;
				break;
			}
			case 11: {
				rate = 1;
				break;
			}
			case 12: {
				rate = 1;
				break;
			}
			case 13: {
				rate = 1;
				break;
			}
			case 14: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			case 2: {
				rate = 1;
				break;
			}
			case 3: {
				rate = 1;
				break;
			}
			case 4: {
				rate = 1;
				break;
			}
			case 5: {
				rate = 1;
				break;
			}
			case 6: {
				rate = 1;
				break;
			}
			case 7: {
				rate = 1;
				break;
			}
			case 8: {
				rate = 1;
				break;
			}
			case 9: {
				rate = 1;
				break;
			}
			case 10: {
				rate = 1;
				break;
			}
			case 11: {
				rate = 1;
				break;
			}
			case 12: {
				rate = 1;
				break;
			}
			case 13: {
				rate = 1;
				break;
			}
			case 14: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = (1.0f / std::min(192000.0f, std::max(1.0f, float(fSamplingFreq))));
		
	}
	
	virtual void instanceResetUserInterface() {
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0f;
			
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec7[l7] = 0.0f;
			
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec9[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec11[l11] = 0.0f;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec12[l12] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec13[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec14[l14] = 0.0f;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openHorizontalBox("Channel mapping for Studio 114(C)");
		ui_interface->openHorizontalBox("lower ring");
		ui_interface->openVerticalBox("0");
		ui_interface->declare(&fVbargraph0, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c468bbf0", &fVbargraph0, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("1");
		ui_interface->declare(&fVbargraph1, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c468fbe0", &fVbargraph1, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("2");
		ui_interface->declare(&fVbargraph2, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c4693b20", &fVbargraph2, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("3");
		ui_interface->declare(&fVbargraph3, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c4697b10", &fVbargraph3, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("4");
		ui_interface->declare(&fVbargraph4, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c469bbb0", &fVbargraph4, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("5");
		ui_interface->declare(&fVbargraph5, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c469fd00", &fVbargraph5, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("6");
		ui_interface->declare(&fVbargraph6, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c46a3f00", &fVbargraph6, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("7");
		ui_interface->declare(&fVbargraph7, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c46a81b0", &fVbargraph7, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("8");
		ui_interface->declare(&fVbargraph8, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c46ac510", &fVbargraph8, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("9");
		ui_interface->declare(&fVbargraph9, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c46b0920", &fVbargraph9, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("upper ring");
		ui_interface->openVerticalBox("0");
		ui_interface->declare(&fVbargraph10, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c46b4d30", &fVbargraph10, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("1");
		ui_interface->declare(&fVbargraph11, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c46b8bc0", &fVbargraph11, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("2");
		ui_interface->declare(&fVbargraph12, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c46bca50", &fVbargraph12, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("3");
		ui_interface->declare(&fVbargraph13, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c46c0990", &fVbargraph13, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("vog");
		ui_interface->openVerticalBox("0");
		ui_interface->declare(&fVbargraph14, "unit", "dB");
		ui_interface->addVerticalBargraph("0x7fd4c46c4980", &fVbargraph14, -70.0f, 5.0f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* input2 = inputs[2];
		FAUSTFLOAT* input3 = inputs[3];
		FAUSTFLOAT* input4 = inputs[4];
		FAUSTFLOAT* input5 = inputs[5];
		FAUSTFLOAT* input6 = inputs[6];
		FAUSTFLOAT* input7 = inputs[7];
		FAUSTFLOAT* input8 = inputs[8];
		FAUSTFLOAT* input9 = inputs[9];
		FAUSTFLOAT* input10 = inputs[10];
		FAUSTFLOAT* input11 = inputs[11];
		FAUSTFLOAT* input12 = inputs[12];
		FAUSTFLOAT* input13 = inputs[13];
		FAUSTFLOAT* input14 = inputs[14];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		FAUSTFLOAT* output3 = outputs[3];
		FAUSTFLOAT* output4 = outputs[4];
		FAUSTFLOAT* output5 = outputs[5];
		FAUSTFLOAT* output6 = outputs[6];
		FAUSTFLOAT* output7 = outputs[7];
		FAUSTFLOAT* output8 = outputs[8];
		FAUSTFLOAT* output9 = outputs[9];
		FAUSTFLOAT* output10 = outputs[10];
		FAUSTFLOAT* output11 = outputs[11];
		FAUSTFLOAT* output12 = outputs[12];
		FAUSTFLOAT* output13 = outputs[13];
		FAUSTFLOAT* output14 = outputs[14];
		for (int i = 0; (i < count); i = (i + 1)) {
			float fTemp0 = float(input0[i]);
			fRec0[0] = std::max((fRec0[1] - fConst0), std::fabs(fTemp0));
			fVbargraph0 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec0[0]))));
			output0[i] = FAUSTFLOAT(fTemp0);
			float fTemp1 = float(input1[i]);
			fRec1[0] = std::max((fRec1[1] - fConst0), std::fabs(fTemp1));
			fVbargraph1 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec1[0]))));
			output1[i] = FAUSTFLOAT(fTemp1);
			float fTemp2 = float(input13[i]);
			fRec2[0] = std::max((fRec2[1] - fConst0), std::fabs(fTemp2));
			fVbargraph2 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec2[0]))));
			output2[i] = FAUSTFLOAT(fTemp2);
			float fTemp3 = float(input14[i]);
			fRec3[0] = std::max((fRec3[1] - fConst0), std::fabs(fTemp3));
			fVbargraph3 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec3[0]))));
			output3[i] = FAUSTFLOAT(fTemp3);
			float fTemp4 = float(input6[i]);
			fRec4[0] = std::max((fRec4[1] - fConst0), std::fabs(fTemp4));
			fVbargraph4 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec4[0]))));
			output4[i] = FAUSTFLOAT(fTemp4);
			float fTemp5 = float(input3[i]);
			fRec5[0] = std::max((fRec5[1] - fConst0), std::fabs(fTemp5));
			fVbargraph5 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec5[0]))));
			output5[i] = FAUSTFLOAT(fTemp5);
			float fTemp6 = float(input7[i]);
			fRec6[0] = std::max((fRec6[1] - fConst0), std::fabs(fTemp6));
			fVbargraph6 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec6[0]))));
			output6[i] = FAUSTFLOAT(fTemp6);
			float fTemp7 = float(input2[i]);
			fRec7[0] = std::max((fRec7[1] - fConst0), std::fabs(fTemp7));
			fVbargraph7 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec7[0]))));
			output7[i] = FAUSTFLOAT(fTemp7);
			float fTemp8 = float(input5[i]);
			fRec8[0] = std::max((fRec8[1] - fConst0), std::fabs(fTemp8));
			fVbargraph8 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec8[0]))));
			output8[i] = FAUSTFLOAT(fTemp8);
			float fTemp9 = float(input4[i]);
			fRec9[0] = std::max((fRec9[1] - fConst0), std::fabs(fTemp9));
			fVbargraph9 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec9[0]))));
			output9[i] = FAUSTFLOAT(fTemp9);
			float fTemp10 = float(input8[i]);
			fRec10[0] = std::max((fRec10[1] - fConst0), std::fabs(fTemp10));
			fVbargraph10 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec10[0]))));
			output10[i] = FAUSTFLOAT(fTemp10);
			float fTemp11 = float(input9[i]);
			fRec11[0] = std::max((fRec11[1] - fConst0), std::fabs(fTemp11));
			fVbargraph11 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec11[0]))));
			output11[i] = FAUSTFLOAT(fTemp11);
			float fTemp12 = float(input11[i]);
			fRec12[0] = std::max((fRec12[1] - fConst0), std::fabs(fTemp12));
			fVbargraph12 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec12[0]))));
			output12[i] = FAUSTFLOAT(fTemp12);
			float fTemp13 = float(input10[i]);
			fRec13[0] = std::max((fRec13[1] - fConst0), std::fabs(fTemp13));
			fVbargraph13 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec13[0]))));
			output13[i] = FAUSTFLOAT(fTemp13);
			float fTemp14 = float(input12[i]);
			fRec14[0] = std::max((fRec14[1] - fConst0), std::fabs(fTemp14));
			fVbargraph14 = FAUSTFLOAT((20.0f * std::log10(std::max(0.000316227757f, fRec14[0]))));
			output14[i] = FAUSTFLOAT(fTemp14);
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			
		}
		
	}

	
};

#endif
