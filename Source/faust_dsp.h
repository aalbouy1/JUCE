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
/* ------------------------------------------------------------
 author: "Yann Orlarey"
 name: "karplus"
 version: "1.0"
 Code generated with Faust 2.0.a46 (http://faust.grame.fr)
 ------------------------------------------------------------ */
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <math.h>


#ifndef FAUSTCLASS
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
    
private:
    
    float fVec1[4096];
    float fRec1[3];
    int iRec2[2];
    float fVec0[2];
    float fRec3[2];
    float fRec0[2];
    float fRec4[2];
    float fRec5[2];
    int fSamplingFreq;
    float fConst0;
    FAUSTFLOAT fEntry0;
    FAUSTFLOAT fHslider0;
    FAUSTFLOAT fHslider1;
    FAUSTFLOAT fEntry1;
    FAUSTFLOAT fButton0;
    FAUSTFLOAT fHslider2;
    int IOTA;
    FAUSTFLOAT fHslider3;
    FAUSTFLOAT fHslider4;
    
public:
    
    void metadata(Meta* m) {
        m->declare("author", "Yann Orlarey");
        m->declare("description", "Karplus-Strong string synth");
        m->declare("math.lib/author", "GRAME");
        m->declare("math.lib/copyright", "GRAME");
        m->declare("math.lib/license", "LGPL with exception");
        m->declare("math.lib/name", "Math Library");
        m->declare("math.lib/version", "1.0");
        m->declare("music.lib/author", "GRAME");
        m->declare("music.lib/copyright", "GRAME");
        m->declare("music.lib/license", "LGPL with exception");
        m->declare("music.lib/name", "Music Library");
        m->declare("music.lib/version", "1.0");
        m->declare("name", "karplus");
        m->declare("nvoices", "16");
        m->declare("version", "1.0");
    }
    
    virtual int getNumInputs() {
        return 0;
        
    }
    virtual int getNumOutputs() {
        return 2;
        
    }
    virtual int getInputRate(int channel) {
        int rate;
        switch (channel) {
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
            default: {
                rate = -1;
                break;
            }
                
        }
        return rate;
        
    }
    
    static void classInit(int samplingFreq) {
        
    }
    
    virtual void instanceInit(int samplingFreq) {
        fSamplingFreq = samplingFreq;
        fConst0 = min(1.92e+05f, max(1.0f, float(fSamplingFreq)));
        fEntry0 = FAUSTFLOAT(4.4e+02f);
        fHslider0 = FAUSTFLOAT(0.0f);
        fHslider1 = FAUSTFLOAT(4.0f);
        fEntry1 = FAUSTFLOAT(1.0f);
        for (int i0 = 0; (i0 < 2); i0 = (i0 + 1)) {
            iRec2[i0] = 0;
            
        }
        fButton0 = FAUSTFLOAT(0.0f);
        for (int i1 = 0; (i1 < 2); i1 = (i1 + 1)) {
            fVec0[i1] = 0.0f;
            
        }
        fHslider2 = FAUSTFLOAT(512.0f);
        for (int i2 = 0; (i2 < 2); i2 = (i2 + 1)) {
            fRec3[i2] = 0.0f;
            
        }
        IOTA = 0;
        for (int i3 = 0; (i3 < 4096); i3 = (i3 + 1)) {
            fVec1[i3] = 0.0f;
            
        }
        for (int i4 = 0; (i4 < 3); i4 = (i4 + 1)) {
            fRec1[i4] = 0.0f;
            
        }
        for (int i5 = 0; (i5 < 2); i5 = (i5 + 1)) {
            fRec0[i5] = 0.0f;
            
        }
        fHslider3 = FAUSTFLOAT(-1e+01f);
        for (int i6 = 0; (i6 < 2); i6 = (i6 + 1)) {
            fRec4[i6] = 0.0f;
            
        }
        fHslider4 = FAUSTFLOAT(0.0f);
        for (int i7 = 0; (i7 < 2); i7 = (i7 + 1)) {
            fRec5[i7] = 0.0f;
            
        }
        
    }
    
    virtual void init(int samplingFreq) {
        classInit(samplingFreq);
        instanceInit(samplingFreq);
    }
    virtual mydsp* clone() {
        return new mydsp();
    }
    virtual int getSampleRate() {
        return fSamplingFreq;
    }
    
    virtual void buildUserInterface(UI* ui_interface) {
        ui_interface->openVerticalBox("0x00");
        ui_interface->declare(0, "1", "");
        ui_interface->openHorizontalBox("0x00");
        ui_interface->declare(&fHslider4, "midi", "ctrl 8");
        ui_interface->declare(&fHslider4, "style", "knob");
        ui_interface->addHorizontalSlider("pan", &fHslider4, 0.0f, -1.0f, 1.0f, 0.01f);
        ui_interface->declare(&fHslider3, "style", "knob");
        ui_interface->declare(&fHslider3, "unit", "dB");
        ui_interface->addHorizontalSlider("vol", &fHslider3, -1e+01f, -96.0f, 96.0f, 0.1f);
        ui_interface->closeBox();
        ui_interface->declare(0, "2", "");
        ui_interface->openHorizontalBox("0x00");
        ui_interface->declare(&fHslider1, "style", "knob");
        ui_interface->addHorizontalSlider("decay time", &fHslider1, 4.0f, 0.0f, 1e+01f, 0.01f);
        ui_interface->declare(&fHslider2, "style", "knob");
        ui_interface->addHorizontalSlider("samples", &fHslider2, 512.0f, 1.0f, 1024.0f, 1.0f);
        ui_interface->closeBox();
        ui_interface->declare(0, "3", "");
        ui_interface->openVerticalBox("0x00");
        ui_interface->addHorizontalSlider("pitch bend", &fHslider0, 0.0f, -2.0f, 2.0f, 0.01f);
        ui_interface->closeBox();
        ui_interface->addNumEntry("freq", &fEntry0, 4.4e+02f, 2e+01f, 2e+04f, 1.0f);
        ui_interface->addNumEntry("gain", &fEntry1, 1.0f, 0.0f, 1e+01f, 0.01f);
        ui_interface->addButton("gate",&fButton0);
        ui_interface->closeBox();
        
    }
    
    virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
        FAUSTFLOAT* output0 = outputs[0];
        FAUSTFLOAT* output1 = outputs[1];
        float fSlow0 = (float(fEntry0) * powf(2.0f, (0.083333336f * float(fHslider0))));
        float fSlow1 = (fConst0 / fSlow0);
        int iSlow2 = int((fSlow1 - 1.5f));
        float fSlow3 = ((2.5f + float(iSlow2)) - fSlow1);
        float fSlow4 = (0.5f / powf(1e+03f, (1.0f / (fSlow0 * float(fHslider1)))));
        float fSlow5 = (4.656613e-10f * float(fEntry1));
        float fSlow6 = float(fButton0);
        float fSlow7 = (1.0f / float(fHslider2));
        int iSlow8 = (iSlow2 & 4095);
        float fSlow9 = (fSlow1 - (1.5f + float(iSlow2)));
        int iSlow10 = ((1 + iSlow2) & 4095);
        float fSlow11 = (0.01f * powf(1e+01f, (0.05f * float(fHslider3))));
        float fSlow12 = (0.005f * (1.0f + float(fHslider4)));
        for (int i = 0; (i < count); i = (i + 1)) {
            iRec2[0] = (12345 + (1103515245 * iRec2[1]));
            fVec0[0] = fSlow6;
            fRec3[0] = ((float(((fSlow6 - fVec0[1]) > 0.0f)) + fRec3[1]) - (fSlow7 * float((fRec3[1] > 0.0f))));
            float fTemp0 = ((fSlow4 * (fRec1[2] + fRec1[1])) + (fSlow5 * (float(iRec2[0]) * (1.5258789e-05f + float((fRec3[0] > 0.0f))))));
            fVec1[(IOTA & 4095)] = fTemp0;
            fRec1[0] = ((fSlow3 * fVec1[((IOTA - iSlow8) & 4095)]) + (fSlow9 * fVec1[((IOTA - iSlow10) & 4095)]));
            fRec0[0] = (((0.995f * fRec0[1]) + fRec1[0]) - fRec1[1]);
            fRec4[0] = (fSlow11 + (0.99f * fRec4[1]));
            float fTemp1 = (fRec0[0] * fRec4[0]);
            fRec5[0] = ((0.99f * fRec5[1]) + fSlow12);
            output0[i] = FAUSTFLOAT((fTemp1 * (1.0f - fRec5[0])));
            output1[i] = FAUSTFLOAT((fTemp1 * fRec5[0]));
            iRec2[1] = iRec2[0];
            fVec0[1] = fVec0[0];
            fRec3[1] = fRec3[0];
            IOTA = (IOTA + 1);
            fRec1[2] = fRec1[1];
            fRec1[1] = fRec1[0];
            fRec0[1] = fRec0[0];
            fRec4[1] = fRec4[0];
            fRec5[1] = fRec5[0];
            
        }
        
    }
    
    
};



