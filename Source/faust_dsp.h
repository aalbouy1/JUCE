//----------------------------------------------------------
// name: "karplus32"
// version: "1.0"
// author: "Grame"
// license: "BSD"
// copyright: "(c)GRAME 2006"
//
// Code generated with Faust 0.9.73 (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
/************************************************************************
 ************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 
 This is sample code. This file is provided as an example of minimal
 FAUST architecture file. Redistribution and use in source and binary
 forms, with or without modification, in part or in full are permitted.
 In particular you can create a derived work of this FAUST architecture
 and distribute that work under terms of your choice.
 
 This sample code is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 ************************************************************************
 ************************************************************************/

#include <math.h>
#include <algorithm>

#include "faust/gui/UI.h"
#include "faust/gui/meta.h"
#include "faust/audio/dummy-audio.h"

using std::max;
using std::min;

/******************************************************************************
 *******************************************************************************
 
 VECTOR INTRINSICS
 
 *******************************************************************************
 *******************************************************************************/


/******************************************************************************
 *******************************************************************************
 
 ABSTRACT USER INTERFACE
 
 *******************************************************************************
 *******************************************************************************/
//----------------------------------------------------------
// name: "karplus32"
// version: "1.0"
// author: "Grame"
// license: "BSD"
// copyright: "(c)GRAME 2006"
//
// Code generated with Faust 0.9.81 (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif


#ifndef FAUSTCLASS
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
private:
    FAUSTFLOAT 	fslider0;
    FAUSTFLOAT 	fslider1;
    FAUSTFLOAT 	fslider2;
    FAUSTFLOAT 	fslider3;
    int 	iRec1[2];
    FAUSTFLOAT 	fbutton0;
    float 	fVec0[2];
    FAUSTFLOAT 	fslider4;
    float 	fRec2[2];
    int 	IOTA;
    float 	fVec1[512];
    FAUSTFLOAT 	fslider5;
    float 	fRec0[3];
    float 	fVec2[2048];
    FAUSTFLOAT 	fslider6;
    float 	fRec3[3];
    float 	fVec3[4096];
    float 	fRec4[3];
    float 	fVec4[4096];
    float 	fRec5[3];
    float 	fVec5[4096];
    float 	fRec6[3];
    float 	fVec6[4096];
    float 	fRec7[3];
    float 	fVec7[4096];
    float 	fRec8[3];
    float 	fVec8[4096];
    float 	fRec9[3];
    float 	fVec9[4096];
    float 	fRec10[3];
    float 	fVec10[4096];
    float 	fRec11[3];
    float 	fVec11[4096];
    float 	fRec12[3];
    float 	fVec12[4096];
    float 	fRec13[3];
    float 	fVec13[4096];
    float 	fRec14[3];
    float 	fVec14[4096];
    float 	fRec15[3];
    float 	fVec15[4096];
    float 	fRec16[3];
    float 	fVec16[4096];
    float 	fRec17[3];
    float 	fVec17[1024];
    float 	fRec18[3];
    float 	fVec18[2048];
    float 	fRec19[3];
    float 	fVec19[4096];
    float 	fRec20[3];
    float 	fVec20[4096];
    float 	fRec21[3];
    float 	fVec21[4096];
    float 	fRec22[3];
    float 	fVec22[4096];
    float 	fRec23[3];
    float 	fVec23[4096];
    float 	fRec24[3];
    float 	fVec24[4096];
    float 	fRec25[3];
    float 	fVec25[4096];
    float 	fRec26[3];
    float 	fVec26[4096];
    float 	fRec27[3];
    float 	fVec27[4096];
    float 	fRec28[3];
    float 	fVec28[4096];
    float 	fRec29[3];
    float 	fVec29[4096];
    float 	fRec30[3];
    float 	fVec30[4096];
    float 	fRec31[3];
    float 	fVec31[4096];
    float 	fRec32[3];
    float 	fVec32[4096];
    float 	fRec33[3];
    int fSamplingFreq;
    
public:
    virtual void metadata(Meta* m) 	{
        m->declare("name", "karplus32");
        m->declare("version", "1.0");
        m->declare("author", "Grame");
        m->declare("license", "BSD");
        m->declare("copyright", "(c)GRAME 2006");
        m->declare("music.lib/name", "Music Library");
        m->declare("music.lib/author", "GRAME");
        m->declare("music.lib/copyright", "GRAME");
        m->declare("music.lib/version", "1.0");
        m->declare("music.lib/license", "LGPL with exception");
        m->declare("math.lib/name", "Math Library");
        m->declare("math.lib/author", "GRAME");
        m->declare("math.lib/copyright", "GRAME");
        m->declare("math.lib/version", "1.0");
        m->declare("math.lib/license", "LGPL with exception");
    }
    
    virtual int getNumInputs() 	{ return 0; }
    virtual int getNumOutputs() 	{ return 2; }
    static void classInit(int samplingFreq) {
    }
    virtual void instanceInit(int samplingFreq) {
        fSamplingFreq = samplingFreq;
        fslider0 = 0.5f;
        fslider1 = 1.0f;
        fslider2 = 0.1f;
        fslider3 = 0.5f;
        for (int i=0; i<2; i++) iRec1[i] = 0;
        fbutton0 = 0.0;
        for (int i=0; i<2; i++) fVec0[i] = 0;
        fslider4 = 128.0f;
        for (int i=0; i<2; i++) fRec2[i] = 0;
        IOTA = 0;
        for (int i=0; i<512; i++) fVec1[i] = 0;
        fslider5 = 128.0f;
        for (int i=0; i<3; i++) fRec0[i] = 0;
        for (int i=0; i<2048; i++) fVec2[i] = 0;
        fslider6 = 32.0f;
        for (int i=0; i<3; i++) fRec3[i] = 0;
        for (int i=0; i<4096; i++) fVec3[i] = 0;
        for (int i=0; i<3; i++) fRec4[i] = 0;
        for (int i=0; i<4096; i++) fVec4[i] = 0;
        for (int i=0; i<3; i++) fRec5[i] = 0;
        for (int i=0; i<4096; i++) fVec5[i] = 0;
        for (int i=0; i<3; i++) fRec6[i] = 0;
        for (int i=0; i<4096; i++) fVec6[i] = 0;
        for (int i=0; i<3; i++) fRec7[i] = 0;
        for (int i=0; i<4096; i++) fVec7[i] = 0;
        for (int i=0; i<3; i++) fRec8[i] = 0;
        for (int i=0; i<4096; i++) fVec8[i] = 0;
        for (int i=0; i<3; i++) fRec9[i] = 0;
        for (int i=0; i<4096; i++) fVec9[i] = 0;
        for (int i=0; i<3; i++) fRec10[i] = 0;
        for (int i=0; i<4096; i++) fVec10[i] = 0;
        for (int i=0; i<3; i++) fRec11[i] = 0;
        for (int i=0; i<4096; i++) fVec11[i] = 0;
        for (int i=0; i<3; i++) fRec12[i] = 0;
        for (int i=0; i<4096; i++) fVec12[i] = 0;
        for (int i=0; i<3; i++) fRec13[i] = 0;
        for (int i=0; i<4096; i++) fVec13[i] = 0;
        for (int i=0; i<3; i++) fRec14[i] = 0;
        for (int i=0; i<4096; i++) fVec14[i] = 0;
        for (int i=0; i<3; i++) fRec15[i] = 0;
        for (int i=0; i<4096; i++) fVec15[i] = 0;
        for (int i=0; i<3; i++) fRec16[i] = 0;
        for (int i=0; i<4096; i++) fVec16[i] = 0;
        for (int i=0; i<3; i++) fRec17[i] = 0;
        for (int i=0; i<1024; i++) fVec17[i] = 0;
        for (int i=0; i<3; i++) fRec18[i] = 0;
        for (int i=0; i<2048; i++) fVec18[i] = 0;
        for (int i=0; i<3; i++) fRec19[i] = 0;
        for (int i=0; i<4096; i++) fVec19[i] = 0;
        for (int i=0; i<3; i++) fRec20[i] = 0;
        for (int i=0; i<4096; i++) fVec20[i] = 0;
        for (int i=0; i<3; i++) fRec21[i] = 0;
        for (int i=0; i<4096; i++) fVec21[i] = 0;
        for (int i=0; i<3; i++) fRec22[i] = 0;
        for (int i=0; i<4096; i++) fVec22[i] = 0;
        for (int i=0; i<3; i++) fRec23[i] = 0;
        for (int i=0; i<4096; i++) fVec23[i] = 0;
        for (int i=0; i<3; i++) fRec24[i] = 0;
        for (int i=0; i<4096; i++) fVec24[i] = 0;
        for (int i=0; i<3; i++) fRec25[i] = 0;
        for (int i=0; i<4096; i++) fVec25[i] = 0;
        for (int i=0; i<3; i++) fRec26[i] = 0;
        for (int i=0; i<4096; i++) fVec26[i] = 0;
        for (int i=0; i<3; i++) fRec27[i] = 0;
        for (int i=0; i<4096; i++) fVec27[i] = 0;
        for (int i=0; i<3; i++) fRec28[i] = 0;
        for (int i=0; i<4096; i++) fVec28[i] = 0;
        for (int i=0; i<3; i++) fRec29[i] = 0;
        for (int i=0; i<4096; i++) fVec29[i] = 0;
        for (int i=0; i<3; i++) fRec30[i] = 0;
        for (int i=0; i<4096; i++) fVec30[i] = 0;
        for (int i=0; i<3; i++) fRec31[i] = 0;
        for (int i=0; i<4096; i++) fVec31[i] = 0;
        for (int i=0; i<3; i++) fRec32[i] = 0;
        for (int i=0; i<4096; i++) fVec32[i] = 0;
        for (int i=0; i<3; i++) fRec33[i] = 0;
    }
    virtual void init(int samplingFreq) {
        classInit(samplingFreq);
        instanceInit(samplingFreq);
    }
    virtual dsp* clone() {
        return new mydsp(*this);
    }
    virtual int getSampleRate() {
        return fSamplingFreq;
    }
    virtual void buildUserInterface(UI* ui_interface) {
        ui_interface->openVerticalBox("karplus32");
        ui_interface->openVerticalBox("excitator");
        ui_interface->addHorizontalSlider("excitation (samples)", &fslider4, 128.0f, 2.0f, 512.0f, 1.0f);
        ui_interface->addButton("play", &fbutton0);
        ui_interface->closeBox();
        ui_interface->openVerticalBox("noise generator");
        ui_interface->addHorizontalSlider("level", &fslider3, 0.5f, 0.0f, 1.0f, 0.1f);
        ui_interface->closeBox();
        ui_interface->addHorizontalSlider("output volume", &fslider0, 0.5f, 0.0f, 1.0f, 0.1f);
        ui_interface->openVerticalBox("resonator x32");
        ui_interface->addHorizontalSlider("attenuation", &fslider2, 0.1f, 0.0f, 1.0f, 0.01f);
        ui_interface->addHorizontalSlider("detune", &fslider6, 32.0f, 0.0f, 512.0f, 1.0f);
        ui_interface->addHorizontalSlider("duration (samples)", &fslider5, 128.0f, 2.0f, 512.0f, 1.0f);
        ui_interface->addHorizontalSlider("polyphony", &fslider1, 1.0f, 0.0f, 32.0f, 1.0f);
        ui_interface->closeBox();
        ui_interface->closeBox();
    }
    virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
        float 	fSlow0 = float(fslider0);
        float 	fSlow1 = float(fslider1);
        int 	iSlow2 = (fSlow1 > 0);
        float 	fSlow3 = (0.5f * (1.0f - float(fslider2)));
        float 	fSlow4 = (4.656613e-10f * float(fslider3));
        float 	fSlow5 = float(fbutton0);
        float 	fSlow6 = (1.0f / float(fslider4));
        float 	fSlow7 = float(fslider5);
        int 	iSlow8 = int((int((fSlow7 - 1.5f)) & 4095));
        int 	iSlow9 = (fSlow1 > 2);
        float 	fSlow10 = float(fslider6);
        int 	iSlow11 = int((int(((fSlow7 + (2 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow12 = (fSlow1 > 4);
        int 	iSlow13 = int((int(((fSlow7 + (4 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow14 = (fSlow1 > 6);
        int 	iSlow15 = int((int(((fSlow7 + (6 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow16 = (fSlow1 > 8);
        int 	iSlow17 = int((int(((fSlow7 + (8 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow18 = (fSlow1 > 10);
        int 	iSlow19 = int((int(((fSlow7 + (10 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow20 = (fSlow1 > 12);
        int 	iSlow21 = int((int((((12 * fSlow10) + fSlow7) - 1.5f)) & 4095));
        int 	iSlow22 = (fSlow1 > 14);
        int 	iSlow23 = int((int((((14 * fSlow10) + fSlow7) - 1.5f)) & 4095));
        int 	iSlow24 = (fSlow1 > 16);
        int 	iSlow25 = int((int((((16 * fSlow10) + fSlow7) - 1.5f)) & 4095));
        int 	iSlow26 = (fSlow1 > 18);
        int 	iSlow27 = int((int(((fSlow7 + (18 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow28 = (fSlow1 > 20);
        int 	iSlow29 = int((int(((fSlow7 + (20 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow30 = (fSlow1 > 22);
        int 	iSlow31 = int((int((((22 * fSlow10) + fSlow7) - 1.5f)) & 4095));
        int 	iSlow32 = (fSlow1 > 24);
        int 	iSlow33 = int((int(((fSlow7 + (24 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow34 = (fSlow1 > 26);
        int 	iSlow35 = int((int(((fSlow7 + (26 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow36 = (fSlow1 > 28);
        int 	iSlow37 = int((int(((fSlow7 + (28 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow38 = (fSlow1 > 30);
        int 	iSlow39 = int((int(((fSlow7 + (30 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow40 = (fSlow1 > 1);
        int 	iSlow41 = int((int(((fSlow7 + fSlow10) - 1.5f)) & 4095));
        int 	iSlow42 = (fSlow1 > 3);
        int 	iSlow43 = int((int(((fSlow7 + (3 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow44 = (fSlow1 > 5);
        int 	iSlow45 = int((int(((fSlow7 + (5 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow46 = (fSlow1 > 7);
        int 	iSlow47 = int((int(((fSlow7 + (7 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow48 = (fSlow1 > 9);
        int 	iSlow49 = int((int(((fSlow7 + (9 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow50 = (fSlow1 > 11);
        int 	iSlow51 = int((int((((11 * fSlow10) + fSlow7) - 1.5f)) & 4095));
        int 	iSlow52 = (fSlow1 > 13);
        int 	iSlow53 = int((int((((13 * fSlow10) + fSlow7) - 1.5f)) & 4095));
        int 	iSlow54 = (fSlow1 > 15);
        int 	iSlow55 = int((int((((15 * fSlow10) + fSlow7) - 1.5f)) & 4095));
        int 	iSlow56 = (fSlow1 > 17);
        int 	iSlow57 = int((int(((fSlow7 + (17 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow58 = (fSlow1 > 19);
        int 	iSlow59 = int((int(((fSlow7 + (19 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow60 = (fSlow1 > 21);
        int 	iSlow61 = int((int((((21 * fSlow10) + fSlow7) - 1.5f)) & 4095));
        int 	iSlow62 = (fSlow1 > 23);
        int 	iSlow63 = int((int(((fSlow7 + (23 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow64 = (fSlow1 > 25);
        int 	iSlow65 = int((int(((fSlow7 + (25 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow66 = (fSlow1 > 27);
        int 	iSlow67 = int((int(((fSlow7 + (27 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow68 = (fSlow1 > 29);
        int 	iSlow69 = int((int(((fSlow7 + (29 * fSlow10)) - 1.5f)) & 4095));
        int 	iSlow70 = (fSlow1 > 31);
        int 	iSlow71 = int((int(((fSlow7 + (31 * fSlow10)) - 1.5f)) & 4095));
        FAUSTFLOAT* output0 = output[0];
        FAUSTFLOAT* output1 = output[1];
        for (int i=0; i<count; i++) {
            iRec1[0] = (12345 + (1103515245 * iRec1[1]));
            fVec0[0] = fSlow5;
            fRec2[0] = ((((fSlow5 - fVec0[1]) > 0.0f) + fRec2[1]) - (fSlow6 * (fRec2[1] > 0)));
            float fTemp0 = (fSlow4 * (iRec1[0] * (1.5258789e-05f + (fRec2[0] > 0.0f))));
            fVec1[IOTA&511] = ((fSlow3 * (fRec0[1] + fRec0[2])) + fTemp0);
            fRec0[0] = fVec1[(IOTA-iSlow8)&511];
            fVec2[IOTA&2047] = ((fSlow3 * (fRec3[1] + fRec3[2])) + fTemp0);
            fRec3[0] = fVec2[(IOTA-iSlow11)&2047];
            fVec3[IOTA&4095] = ((fSlow3 * (fRec4[1] + fRec4[2])) + fTemp0);
            fRec4[0] = fVec3[(IOTA-iSlow13)&4095];
            fVec4[IOTA&4095] = ((fSlow3 * (fRec5[1] + fRec5[2])) + fTemp0);
            fRec5[0] = fVec4[(IOTA-iSlow15)&4095];
            fVec5[IOTA&4095] = ((fSlow3 * (fRec6[1] + fRec6[2])) + fTemp0);
            fRec6[0] = fVec5[(IOTA-iSlow17)&4095];
            fVec6[IOTA&4095] = ((fSlow3 * (fRec7[1] + fRec7[2])) + fTemp0);
            fRec7[0] = fVec6[(IOTA-iSlow19)&4095];
            fVec7[IOTA&4095] = ((fSlow3 * (fRec8[1] + fRec8[2])) + fTemp0);
            fRec8[0] = fVec7[(IOTA-iSlow21)&4095];
            fVec8[IOTA&4095] = ((fSlow3 * (fRec9[1] + fRec9[2])) + fTemp0);
            fRec9[0] = fVec8[(IOTA-iSlow23)&4095];
            fVec9[IOTA&4095] = ((fSlow3 * (fRec10[1] + fRec10[2])) + fTemp0);
            fRec10[0] = fVec9[(IOTA-iSlow25)&4095];
            fVec10[IOTA&4095] = ((fSlow3 * (fRec11[1] + fRec11[2])) + fTemp0);
            fRec11[0] = fVec10[(IOTA-iSlow27)&4095];
            fVec11[IOTA&4095] = ((fSlow3 * (fRec12[1] + fRec12[2])) + fTemp0);
            fRec12[0] = fVec11[(IOTA-iSlow29)&4095];
            fVec12[IOTA&4095] = ((fSlow3 * (fRec13[1] + fRec13[2])) + fTemp0);
            fRec13[0] = fVec12[(IOTA-iSlow31)&4095];
            fVec13[IOTA&4095] = ((fSlow3 * (fRec14[1] + fRec14[2])) + fTemp0);
            fRec14[0] = fVec13[(IOTA-iSlow33)&4095];
            fVec14[IOTA&4095] = ((fSlow3 * (fRec15[1] + fRec15[2])) + fTemp0);
            fRec15[0] = fVec14[(IOTA-iSlow35)&4095];
            fVec15[IOTA&4095] = ((fSlow3 * (fRec16[1] + fRec16[2])) + fTemp0);
            fRec16[0] = fVec15[(IOTA-iSlow37)&4095];
            fVec16[IOTA&4095] = ((fSlow3 * (fRec17[1] + fRec17[2])) + fTemp0);
            fRec17[0] = fVec16[(IOTA-iSlow39)&4095];
            output0[i] = (FAUSTFLOAT)(fSlow0 * ((((((((((((((((iSlow2 * fRec0[0]) + (iSlow9 * fRec3[0])) + (iSlow12 * fRec4[0])) + (iSlow14 * fRec5[0])) + (iSlow16 * fRec6[0])) + (iSlow18 * fRec7[0])) + (iSlow20 * fRec8[0])) + (iSlow22 * fRec9[0])) + (iSlow24 * fRec10[0])) + (iSlow26 * fRec11[0])) + (iSlow28 * fRec12[0])) + (iSlow30 * fRec13[0])) + (iSlow32 * fRec14[0])) + (iSlow34 * fRec15[0])) + (iSlow36 * fRec16[0])) + (iSlow38 * fRec17[0])));
            fVec17[IOTA&1023] = ((fSlow3 * (fRec18[1] + fRec18[2])) + fTemp0);
            fRec18[0] = fVec17[(IOTA-iSlow41)&1023];
            fVec18[IOTA&2047] = ((fSlow3 * (fRec19[1] + fRec19[2])) + fTemp0);
            fRec19[0] = fVec18[(IOTA-iSlow43)&2047];
            fVec19[IOTA&4095] = ((fSlow3 * (fRec20[1] + fRec20[2])) + fTemp0);
            fRec20[0] = fVec19[(IOTA-iSlow45)&4095];
            fVec20[IOTA&4095] = ((fSlow3 * (fRec21[1] + fRec21[2])) + fTemp0);
            fRec21[0] = fVec20[(IOTA-iSlow47)&4095];
            fVec21[IOTA&4095] = ((fSlow3 * (fRec22[1] + fRec22[2])) + fTemp0);
            fRec22[0] = fVec21[(IOTA-iSlow49)&4095];
            fVec22[IOTA&4095] = ((fSlow3 * (fRec23[1] + fRec23[2])) + fTemp0);
            fRec23[0] = fVec22[(IOTA-iSlow51)&4095];
            fVec23[IOTA&4095] = ((fSlow3 * (fRec24[1] + fRec24[2])) + fTemp0);
            fRec24[0] = fVec23[(IOTA-iSlow53)&4095];
            fVec24[IOTA&4095] = ((fSlow3 * (fRec25[1] + fRec25[2])) + fTemp0);
            fRec25[0] = fVec24[(IOTA-iSlow55)&4095];
            fVec25[IOTA&4095] = ((fSlow3 * (fRec26[1] + fRec26[2])) + fTemp0);
            fRec26[0] = fVec25[(IOTA-iSlow57)&4095];
            fVec26[IOTA&4095] = ((fSlow3 * (fRec27[1] + fRec27[2])) + fTemp0);
            fRec27[0] = fVec26[(IOTA-iSlow59)&4095];
            fVec27[IOTA&4095] = ((fSlow3 * (fRec28[1] + fRec28[2])) + fTemp0);
            fRec28[0] = fVec27[(IOTA-iSlow61)&4095];
            fVec28[IOTA&4095] = ((fSlow3 * (fRec29[1] + fRec29[2])) + fTemp0);
            fRec29[0] = fVec28[(IOTA-iSlow63)&4095];
            fVec29[IOTA&4095] = ((fSlow3 * (fRec30[1] + fRec30[2])) + fTemp0);
            fRec30[0] = fVec29[(IOTA-iSlow65)&4095];
            fVec30[IOTA&4095] = ((fSlow3 * (fRec31[1] + fRec31[2])) + fTemp0);
            fRec31[0] = fVec30[(IOTA-iSlow67)&4095];
            fVec31[IOTA&4095] = ((fSlow3 * (fRec32[1] + fRec32[2])) + fTemp0);
            fRec32[0] = fVec31[(IOTA-iSlow69)&4095];
            fVec32[IOTA&4095] = ((fSlow3 * (fRec33[1] + fRec33[2])) + fTemp0);
            fRec33[0] = fVec32[(IOTA-iSlow71)&4095];
            output1[i] = (FAUSTFLOAT)(fSlow0 * ((((((((((((((((iSlow40 * fRec18[0]) + (iSlow42 * fRec19[0])) + (iSlow44 * fRec20[0])) + (iSlow46 * fRec21[0])) + (iSlow48 * fRec22[0])) + (iSlow50 * fRec23[0])) + (iSlow52 * fRec24[0])) + (iSlow54 * fRec25[0])) + (iSlow56 * fRec26[0])) + (iSlow58 * fRec27[0])) + (iSlow60 * fRec28[0])) + (iSlow62 * fRec29[0])) + (iSlow64 * fRec30[0])) + (iSlow66 * fRec31[0])) + (iSlow68 * fRec32[0])) + (iSlow70 * fRec33[0])));
            // post processing
            fRec33[2] = fRec33[1]; fRec33[1] = fRec33[0];
            fRec32[2] = fRec32[1]; fRec32[1] = fRec32[0];
            fRec31[2] = fRec31[1]; fRec31[1] = fRec31[0];
            fRec30[2] = fRec30[1]; fRec30[1] = fRec30[0];
            fRec29[2] = fRec29[1]; fRec29[1] = fRec29[0];
            fRec28[2] = fRec28[1]; fRec28[1] = fRec28[0];
            fRec27[2] = fRec27[1]; fRec27[1] = fRec27[0];
            fRec26[2] = fRec26[1]; fRec26[1] = fRec26[0];
            fRec25[2] = fRec25[1]; fRec25[1] = fRec25[0];
            fRec24[2] = fRec24[1]; fRec24[1] = fRec24[0];
            fRec23[2] = fRec23[1]; fRec23[1] = fRec23[0];
            fRec22[2] = fRec22[1]; fRec22[1] = fRec22[0];
            fRec21[2] = fRec21[1]; fRec21[1] = fRec21[0];
            fRec20[2] = fRec20[1]; fRec20[1] = fRec20[0];
            fRec19[2] = fRec19[1]; fRec19[1] = fRec19[0];
            fRec18[2] = fRec18[1]; fRec18[1] = fRec18[0];
            fRec17[2] = fRec17[1]; fRec17[1] = fRec17[0];
            fRec16[2] = fRec16[1]; fRec16[1] = fRec16[0];
            fRec15[2] = fRec15[1]; fRec15[1] = fRec15[0];
            fRec14[2] = fRec14[1]; fRec14[1] = fRec14[0];
            fRec13[2] = fRec13[1]; fRec13[1] = fRec13[0];
            fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
            fRec11[2] = fRec11[1]; fRec11[1] = fRec11[0];
            fRec10[2] = fRec10[1]; fRec10[1] = fRec10[0];
            fRec9[2] = fRec9[1]; fRec9[1] = fRec9[0];
            fRec8[2] = fRec8[1]; fRec8[1] = fRec8[0];
            fRec7[2] = fRec7[1]; fRec7[1] = fRec7[0];
            fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
            fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
            fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
            fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
            fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
            IOTA = IOTA+1;
            fRec2[1] = fRec2[0];
            fVec0[1] = fVec0[0];
            iRec1[1] = iRec1[0];
        }
    }
};


