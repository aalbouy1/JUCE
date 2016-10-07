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


#include <math.h>


class mydspSIG0 {
    
private:
    
    
public:
    
    int getNumInputsmydspSIG0() {
        return 0;
        
    }
    int getNumOutputsmydspSIG0() {
        return 1;
        
    }
    int getInputRatemydspSIG0(int channel) {
        int rate;
        switch (channel) {
            default: {
                rate = -1;
                break;
            }
                
        }
        return rate;
        
    }
    int getOutputRatemydspSIG0(int channel) {
        int rate;
        switch (channel) {
            case 0: {
                rate = 0;
                break;
            }
            default: {
                rate = -1;
                break;
            }
                
        }
        return rate;
        
    }
    
    void instanceInitmydspSIG0(int samplingFreq) {
        
    }
    
    void fillmydspSIG0(int count, float* output) {
        for (int i = 0; (i < count); i = (i + 1)) {
            output[i] = 0.0f;
            
        }
        
    }
};

mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

float faustpower2_f(float value) {
    return (value * value);
    
}

#ifndef FAUSTCLASS
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
    
private:
    
    float fVec73[2048];
    float fVec74[2048];
    float fVec75[2048];
    float fVec76[2048];
    float fVec77[2048];
    float fVec78[2048];
    float fVec79[2048];
    float fVec80[2048];
    float fVec85[2048];
    float fVec86[2048];
    float fVec87[2048];
    float fVec88[2048];
    float fVec89[2048];
    float fVec90[2048];
    float fVec91[2048];
    float fVec92[2048];
    float fVec81[1024];
    float fVec93[1024];
    float fVec32[512];
    float fVec36[512];
    float fVec38[512];
    float fVec82[512];
    float fVec83[512];
    float fVec94[512];
    float fVec95[512];
    float fVec29[256];
    float fVec34[256];
    float fVec40[256];
    float fVec42[256];
    float fVec44[256];
    float fVec46[256];
    float fVec48[256];
    float fVec70[256];
    float fVec84[256];
    float fVec96[256];
    float fVec6[128];
    float fVec8[128];
    float fVec10[128];
    float fVec50[128];
    float fVec52[128];
    float fVec54[128];
    float fVec62[128];
    float fVec64[128];
    float fVec66[128];
    float fVec68[128];
    float fVec72[128];
    float fVec12[64];
    float fVec14[64];
    float fVec16[64];
    float fVec18[64];
    float fVec20[64];
    float fVec56[64];
    float fVec58[64];
    float fVec60[64];
    float fVec22[32];
    float fVec24[32];
    float fVec26[32];
    float ftbl0[16];
    float ftbl1[16];
    float ftbl2[16];
    float ftbl3[16];
    float ftbl4[16];
    float ftbl5[16];
    float fRec17[3];
    float fRec23[3];
    float fRec25[3];
    float fRec27[3];
    float fRec29[3];
    float fRec31[3];
    float fRec33[3];
    float fRec35[3];
    float fRec37[3];
    float fRec39[3];
    float fRec41[3];
    float fRec43[3];
    float fRec46[3];
    float fRec49[3];
    float fRec51[3];
    float fRec53[3];
    float fRec55[3];
    float fRec57[3];
    float fRec59[3];
    float fRec61[3];
    float fRec63[3];
    float fRec65[3];
    float fRec67[3];
    float fRec69[3];
    float fRec71[3];
    float fRec73[3];
    float fRec75[3];
    float fRec77[3];
    float fRec79[3];
    float fRec81[3];
    float fRec83[3];
    float fRec85[3];
    float fRec87[3];
    float fRec0[3];
    float fRec103[3];
    int iRec2[2];
    int iVec0[2];
    float fVec1[2];
    float fRec3[2];
    int iRec4[2];
    float fRec1[2];
    float fRec5[2];
    float fRec6[2];
    float fRec16[2];
    int iRec18[2];
    int iVec2[2];
    int iRec19[2];
    int iVec3[2];
    int iRec21[2];
    int iVec4[2];
    float fRec20[2];
    float fVec5[2];
    float fRec22[2];
    int iVec7[2];
    float fRec24[2];
    int iVec9[2];
    float fRec26[2];
    int iVec11[2];
    float fRec28[2];
    int iVec13[2];
    float fRec30[2];
    int iVec15[2];
    float fRec32[2];
    int iVec17[2];
    float fRec34[2];
    int iVec19[2];
    float fRec36[2];
    int iVec21[2];
    float fRec38[2];
    int iVec23[2];
    float fRec40[2];
    int iVec25[2];
    float fRec42[2];
    int iVec27[2];
    int iRec45[2];
    int iVec28[2];
    float fRec44[2];
    int iVec30[2];
    int iRec48[2];
    int iVec31[2];
    float fRec47[2];
    int iVec33[2];
    float fRec50[2];
    int iVec35[2];
    float fRec52[2];
    int iVec37[2];
    float fRec54[2];
    int iVec39[2];
    float fRec56[2];
    int iVec41[2];
    float fRec58[2];
    int iVec43[2];
    float fRec60[2];
    int iVec45[2];
    float fRec62[2];
    int iVec47[2];
    float fRec64[2];
    int iVec49[2];
    float fRec66[2];
    int iVec51[2];
    float fRec68[2];
    int iVec53[2];
    float fRec70[2];
    int iVec55[2];
    float fRec72[2];
    int iVec57[2];
    float fRec74[2];
    int iVec59[2];
    float fRec76[2];
    int iVec61[2];
    float fRec78[2];
    int iVec63[2];
    float fRec80[2];
    int iVec65[2];
    float fRec82[2];
    int iVec67[2];
    float fRec84[2];
    int iVec69[2];
    float fRec86[2];
    int iVec71[2];
    float fRec88[2];
    float fRec15[2];
    float fRec90[2];
    float fRec89[2];
    float fRec92[2];
    float fRec91[2];
    float fRec94[2];
    float fRec93[2];
    float fRec96[2];
    float fRec95[2];
    float fRec98[2];
    float fRec97[2];
    float fRec100[2];
    float fRec99[2];
    float fRec102[2];
    float fRec101[2];
    float fRec13[2];
    float fRec11[2];
    float fRec9[2];
    float fRec7[2];
    float fRec113[2];
    float fRec112[2];
    float fRec115[2];
    float fRec114[2];
    float fRec117[2];
    float fRec116[2];
    float fRec119[2];
    float fRec118[2];
    float fRec121[2];
    float fRec120[2];
    float fRec123[2];
    float fRec122[2];
    float fRec125[2];
    float fRec124[2];
    float fRec127[2];
    float fRec126[2];
    float fRec110[2];
    float fRec108[2];
    float fRec106[2];
    float fRec104[2];
    FAUSTFLOAT fHslider0;
    int fSamplingFreq;
    float fConst0;
    float fConst1;
    int iConst2;
    FAUSTFLOAT fHslider1;
    float fConst3;
    FAUSTFLOAT fHslider2;
    FAUSTFLOAT fVslider0;
    FAUSTFLOAT fVslider1;
    FAUSTFLOAT fHslider3;
    int IOTA;
    FAUSTFLOAT fVslider2;
    FAUSTFLOAT fVslider3;
    
public:
    
    void metadata(Meta* m) {
        m->declare("author", "Yann Orlarey");
        m->declare("effect.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
        m->declare("effect.lib/copyright", "Julius O. Smith III");
        m->declare("effect.lib/exciter_author", "Priyanka Shekar (pshekar@ccrma.stanford.edu)");
        m->declare("effect.lib/exciter_copyright", "Copyright (c) 2013 Priyanka Shekar");
        m->declare("effect.lib/exciter_license", "MIT License (MIT)");
        m->declare("effect.lib/exciter_name", "Harmonic Exciter");
        m->declare("effect.lib/exciter_version", "1.0");
        m->declare("effect.lib/license", "STK-4.3");
        m->declare("effect.lib/name", "Faust Audio Effect Library");
        m->declare("effect.lib/version", "1.33");
        m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
        m->declare("filter.lib/copyright", "Julius O. Smith III");
        m->declare("filter.lib/license", "STK-4.3");
        m->declare("filter.lib/name", "Faust Filter Library");
        m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
        m->declare("filter.lib/version", "1.29");
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
        m->declare("name", "Kisana");
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
        fHslider0 = FAUSTFLOAT(-20.0f);
        fConst0 = min(192000.0f, max(1.0f, float(fSamplingFreq)));
        fConst1 = (1413.71667f / fConst0);
        mydspSIG0* sig0 = newmydspSIG0();
        sig0->instanceInitmydspSIG0(samplingFreq);
        sig0->fillmydspSIG0(16, ftbl0);
        iConst2 = int((0.166666672f * fConst0));
        fHslider1 = FAUSTFLOAT(0.80000000000000004f);
        fConst3 = (2827.43335f / fConst0);
        fHslider2 = FAUSTFLOAT(0.33329999999999999f);
        sig0->instanceInitmydspSIG0(samplingFreq);
        sig0->fillmydspSIG0(16, ftbl1);
        fVslider0 = FAUSTFLOAT(0.0f);
        sig0->instanceInitmydspSIG0(samplingFreq);
        sig0->fillmydspSIG0(16, ftbl2);
        fVslider1 = FAUSTFLOAT(0.0f);
        sig0->instanceInitmydspSIG0(samplingFreq);
        sig0->fillmydspSIG0(16, ftbl3);
        fHslider3 = FAUSTFLOAT(0.0f);
        sig0->instanceInitmydspSIG0(samplingFreq);
        sig0->fillmydspSIG0(16, ftbl4);
        fVslider2 = FAUSTFLOAT(0.0f);
        sig0->instanceInitmydspSIG0(samplingFreq);
        sig0->fillmydspSIG0(16, ftbl5);
        fVslider3 = FAUSTFLOAT(0.0f);
        deletemydspSIG0(sig0);
        instanceClear();
    }
    
    virtual void instanceClear() {
        for (int i0 = 0; (i0 < 2); i0 = (i0 + 1)) {
            iRec2[i0] = 0;
            
        }
        for (int i1 = 0; (i1 < 2); i1 = (i1 + 1)) {
            iVec0[i1] = 0;
            
        }
        for (int i2 = 0; (i2 < 2); i2 = (i2 + 1)) {
            fVec1[i2] = 0.0f;
            
        }
        for (int i3 = 0; (i3 < 2); i3 = (i3 + 1)) {
            fRec3[i3] = 0.0f;
            
        }
        for (int i4 = 0; (i4 < 2); i4 = (i4 + 1)) {
            iRec4[i4] = 0;
            
        }
        for (int i5 = 0; (i5 < 2); i5 = (i5 + 1)) {
            fRec1[i5] = 0.0f;
            
        }
        for (int i6 = 0; (i6 < 2); i6 = (i6 + 1)) {
            fRec5[i6] = 0.0f;
            
        }
        for (int i7 = 0; (i7 < 2); i7 = (i7 + 1)) {
            fRec6[i7] = 0.0f;
            
        }
        for (int i8 = 0; (i8 < 2); i8 = (i8 + 1)) {
            fRec16[i8] = 0.0f;
            
        }
        for (int i9 = 0; (i9 < 2); i9 = (i9 + 1)) {
            iRec18[i9] = 0;
            
        }
        for (int i10 = 0; (i10 < 2); i10 = (i10 + 1)) {
            iVec2[i10] = 0;
            
        }
        for (int i11 = 0; (i11 < 2); i11 = (i11 + 1)) {
            iRec19[i11] = 0;
            
        }
        for (int i12 = 0; (i12 < 2); i12 = (i12 + 1)) {
            iVec3[i12] = 0;
            
        }
        for (int i13 = 0; (i13 < 2); i13 = (i13 + 1)) {
            iRec21[i13] = 0;
            
        }
        for (int i14 = 0; (i14 < 2); i14 = (i14 + 1)) {
            iVec4[i14] = 0;
            
        }
        for (int i15 = 0; (i15 < 2); i15 = (i15 + 1)) {
            fRec20[i15] = 0.0f;
            
        }
        for (int i16 = 0; (i16 < 2); i16 = (i16 + 1)) {
            fVec5[i16] = 0.0f;
            
        }
        for (int i17 = 0; (i17 < 2); i17 = (i17 + 1)) {
            fRec22[i17] = 0.0f;
            
        }
        IOTA = 0;
        for (int i18 = 0; (i18 < 128); i18 = (i18 + 1)) {
            fVec6[i18] = 0.0f;
            
        }
        for (int i19 = 0; (i19 < 3); i19 = (i19 + 1)) {
            fRec17[i19] = 0.0f;
            
        }
        for (int i20 = 0; (i20 < 2); i20 = (i20 + 1)) {
            iVec7[i20] = 0;
            
        }
        for (int i21 = 0; (i21 < 2); i21 = (i21 + 1)) {
            fRec24[i21] = 0.0f;
            
        }
        for (int i22 = 0; (i22 < 128); i22 = (i22 + 1)) {
            fVec8[i22] = 0.0f;
            
        }
        for (int i23 = 0; (i23 < 3); i23 = (i23 + 1)) {
            fRec23[i23] = 0.0f;
            
        }
        for (int i24 = 0; (i24 < 2); i24 = (i24 + 1)) {
            iVec9[i24] = 0;
            
        }
        for (int i25 = 0; (i25 < 2); i25 = (i25 + 1)) {
            fRec26[i25] = 0.0f;
            
        }
        for (int i26 = 0; (i26 < 128); i26 = (i26 + 1)) {
            fVec10[i26] = 0.0f;
            
        }
        for (int i27 = 0; (i27 < 3); i27 = (i27 + 1)) {
            fRec25[i27] = 0.0f;
            
        }
        for (int i28 = 0; (i28 < 2); i28 = (i28 + 1)) {
            iVec11[i28] = 0;
            
        }
        for (int i29 = 0; (i29 < 2); i29 = (i29 + 1)) {
            fRec28[i29] = 0.0f;
            
        }
        for (int i30 = 0; (i30 < 64); i30 = (i30 + 1)) {
            fVec12[i30] = 0.0f;
            
        }
        for (int i31 = 0; (i31 < 3); i31 = (i31 + 1)) {
            fRec27[i31] = 0.0f;
            
        }
        for (int i32 = 0; (i32 < 2); i32 = (i32 + 1)) {
            iVec13[i32] = 0;
            
        }
        for (int i33 = 0; (i33 < 2); i33 = (i33 + 1)) {
            fRec30[i33] = 0.0f;
            
        }
        for (int i34 = 0; (i34 < 64); i34 = (i34 + 1)) {
            fVec14[i34] = 0.0f;
            
        }
        for (int i35 = 0; (i35 < 3); i35 = (i35 + 1)) {
            fRec29[i35] = 0.0f;
            
        }
        for (int i36 = 0; (i36 < 2); i36 = (i36 + 1)) {
            iVec15[i36] = 0;
            
        }
        for (int i37 = 0; (i37 < 2); i37 = (i37 + 1)) {
            fRec32[i37] = 0.0f;
            
        }
        for (int i38 = 0; (i38 < 64); i38 = (i38 + 1)) {
            fVec16[i38] = 0.0f;
            
        }
        for (int i39 = 0; (i39 < 3); i39 = (i39 + 1)) {
            fRec31[i39] = 0.0f;
            
        }
        for (int i40 = 0; (i40 < 2); i40 = (i40 + 1)) {
            iVec17[i40] = 0;
            
        }
        for (int i41 = 0; (i41 < 2); i41 = (i41 + 1)) {
            fRec34[i41] = 0.0f;
            
        }
        for (int i42 = 0; (i42 < 64); i42 = (i42 + 1)) {
            fVec18[i42] = 0.0f;
            
        }
        for (int i43 = 0; (i43 < 3); i43 = (i43 + 1)) {
            fRec33[i43] = 0.0f;
            
        }
        for (int i44 = 0; (i44 < 2); i44 = (i44 + 1)) {
            iVec19[i44] = 0;
            
        }
        for (int i45 = 0; (i45 < 2); i45 = (i45 + 1)) {
            fRec36[i45] = 0.0f;
            
        }
        for (int i46 = 0; (i46 < 64); i46 = (i46 + 1)) {
            fVec20[i46] = 0.0f;
            
        }
        for (int i47 = 0; (i47 < 3); i47 = (i47 + 1)) {
            fRec35[i47] = 0.0f;
            
        }
        for (int i48 = 0; (i48 < 2); i48 = (i48 + 1)) {
            iVec21[i48] = 0;
            
        }
        for (int i49 = 0; (i49 < 2); i49 = (i49 + 1)) {
            fRec38[i49] = 0.0f;
            
        }
        for (int i50 = 0; (i50 < 32); i50 = (i50 + 1)) {
            fVec22[i50] = 0.0f;
            
        }
        for (int i51 = 0; (i51 < 3); i51 = (i51 + 1)) {
            fRec37[i51] = 0.0f;
            
        }
        for (int i52 = 0; (i52 < 2); i52 = (i52 + 1)) {
            iVec23[i52] = 0;
            
        }
        for (int i53 = 0; (i53 < 2); i53 = (i53 + 1)) {
            fRec40[i53] = 0.0f;
            
        }
        for (int i54 = 0; (i54 < 32); i54 = (i54 + 1)) {
            fVec24[i54] = 0.0f;
            
        }
        for (int i55 = 0; (i55 < 3); i55 = (i55 + 1)) {
            fRec39[i55] = 0.0f;
            
        }
        for (int i56 = 0; (i56 < 2); i56 = (i56 + 1)) {
            iVec25[i56] = 0;
            
        }
        for (int i57 = 0; (i57 < 2); i57 = (i57 + 1)) {
            fRec42[i57] = 0.0f;
            
        }
        for (int i58 = 0; (i58 < 32); i58 = (i58 + 1)) {
            fVec26[i58] = 0.0f;
            
        }
        for (int i59 = 0; (i59 < 3); i59 = (i59 + 1)) {
            fRec41[i59] = 0.0f;
            
        }
        for (int i60 = 0; (i60 < 2); i60 = (i60 + 1)) {
            iVec27[i60] = 0;
            
        }
        for (int i61 = 0; (i61 < 2); i61 = (i61 + 1)) {
            iRec45[i61] = 0;
            
        }
        for (int i62 = 0; (i62 < 2); i62 = (i62 + 1)) {
            iVec28[i62] = 0;
            
        }
        for (int i63 = 0; (i63 < 2); i63 = (i63 + 1)) {
            fRec44[i63] = 0.0f;
            
        }
        for (int i64 = 0; (i64 < 256); i64 = (i64 + 1)) {
            fVec29[i64] = 0.0f;
            
        }
        for (int i65 = 0; (i65 < 3); i65 = (i65 + 1)) {
            fRec43[i65] = 0.0f;
            
        }
        for (int i66 = 0; (i66 < 2); i66 = (i66 + 1)) {
            iVec30[i66] = 0;
            
        }
        for (int i67 = 0; (i67 < 2); i67 = (i67 + 1)) {
            iRec48[i67] = 0;
            
        }
        for (int i68 = 0; (i68 < 2); i68 = (i68 + 1)) {
            iVec31[i68] = 0;
            
        }
        for (int i69 = 0; (i69 < 2); i69 = (i69 + 1)) {
            fRec47[i69] = 0.0f;
            
        }
        for (int i70 = 0; (i70 < 512); i70 = (i70 + 1)) {
            fVec32[i70] = 0.0f;
            
        }
        for (int i71 = 0; (i71 < 3); i71 = (i71 + 1)) {
            fRec46[i71] = 0.0f;
            
        }
        for (int i72 = 0; (i72 < 2); i72 = (i72 + 1)) {
            iVec33[i72] = 0;
            
        }
        for (int i73 = 0; (i73 < 2); i73 = (i73 + 1)) {
            fRec50[i73] = 0.0f;
            
        }
        for (int i74 = 0; (i74 < 256); i74 = (i74 + 1)) {
            fVec34[i74] = 0.0f;
            
        }
        for (int i75 = 0; (i75 < 3); i75 = (i75 + 1)) {
            fRec49[i75] = 0.0f;
            
        }
        for (int i76 = 0; (i76 < 2); i76 = (i76 + 1)) {
            iVec35[i76] = 0;
            
        }
        for (int i77 = 0; (i77 < 2); i77 = (i77 + 1)) {
            fRec52[i77] = 0.0f;
            
        }
        for (int i78 = 0; (i78 < 512); i78 = (i78 + 1)) {
            fVec36[i78] = 0.0f;
            
        }
        for (int i79 = 0; (i79 < 3); i79 = (i79 + 1)) {
            fRec51[i79] = 0.0f;
            
        }
        for (int i80 = 0; (i80 < 2); i80 = (i80 + 1)) {
            iVec37[i80] = 0;
            
        }
        for (int i81 = 0; (i81 < 2); i81 = (i81 + 1)) {
            fRec54[i81] = 0.0f;
            
        }
        for (int i82 = 0; (i82 < 512); i82 = (i82 + 1)) {
            fVec38[i82] = 0.0f;
            
        }
        for (int i83 = 0; (i83 < 3); i83 = (i83 + 1)) {
            fRec53[i83] = 0.0f;
            
        }
        for (int i84 = 0; (i84 < 2); i84 = (i84 + 1)) {
            iVec39[i84] = 0;
            
        }
        for (int i85 = 0; (i85 < 2); i85 = (i85 + 1)) {
            fRec56[i85] = 0.0f;
            
        }
        for (int i86 = 0; (i86 < 256); i86 = (i86 + 1)) {
            fVec40[i86] = 0.0f;
            
        }
        for (int i87 = 0; (i87 < 3); i87 = (i87 + 1)) {
            fRec55[i87] = 0.0f;
            
        }
        for (int i88 = 0; (i88 < 2); i88 = (i88 + 1)) {
            iVec41[i88] = 0;
            
        }
        for (int i89 = 0; (i89 < 2); i89 = (i89 + 1)) {
            fRec58[i89] = 0.0f;
            
        }
        for (int i90 = 0; (i90 < 256); i90 = (i90 + 1)) {
            fVec42[i90] = 0.0f;
            
        }
        for (int i91 = 0; (i91 < 3); i91 = (i91 + 1)) {
            fRec57[i91] = 0.0f;
            
        }
        for (int i92 = 0; (i92 < 2); i92 = (i92 + 1)) {
            iVec43[i92] = 0;
            
        }
        for (int i93 = 0; (i93 < 2); i93 = (i93 + 1)) {
            fRec60[i93] = 0.0f;
            
        }
        for (int i94 = 0; (i94 < 256); i94 = (i94 + 1)) {
            fVec44[i94] = 0.0f;
            
        }
        for (int i95 = 0; (i95 < 3); i95 = (i95 + 1)) {
            fRec59[i95] = 0.0f;
            
        }
        for (int i96 = 0; (i96 < 2); i96 = (i96 + 1)) {
            iVec45[i96] = 0;
            
        }
        for (int i97 = 0; (i97 < 2); i97 = (i97 + 1)) {
            fRec62[i97] = 0.0f;
            
        }
        for (int i98 = 0; (i98 < 256); i98 = (i98 + 1)) {
            fVec46[i98] = 0.0f;
            
        }
        for (int i99 = 0; (i99 < 3); i99 = (i99 + 1)) {
            fRec61[i99] = 0.0f;
            
        }
        for (int i100 = 0; (i100 < 2); i100 = (i100 + 1)) {
            iVec47[i100] = 0;
            
        }
        for (int i101 = 0; (i101 < 2); i101 = (i101 + 1)) {
            fRec64[i101] = 0.0f;
            
        }
        for (int i102 = 0; (i102 < 256); i102 = (i102 + 1)) {
            fVec48[i102] = 0.0f;
            
        }
        for (int i103 = 0; (i103 < 3); i103 = (i103 + 1)) {
            fRec63[i103] = 0.0f;
            
        }
        for (int i104 = 0; (i104 < 2); i104 = (i104 + 1)) {
            iVec49[i104] = 0;
            
        }
        for (int i105 = 0; (i105 < 2); i105 = (i105 + 1)) {
            fRec66[i105] = 0.0f;
            
        }
        for (int i106 = 0; (i106 < 128); i106 = (i106 + 1)) {
            fVec50[i106] = 0.0f;
            
        }
        for (int i107 = 0; (i107 < 3); i107 = (i107 + 1)) {
            fRec65[i107] = 0.0f;
            
        }
        for (int i108 = 0; (i108 < 2); i108 = (i108 + 1)) {
            iVec51[i108] = 0;
            
        }
        for (int i109 = 0; (i109 < 2); i109 = (i109 + 1)) {
            fRec68[i109] = 0.0f;
            
        }
        for (int i110 = 0; (i110 < 128); i110 = (i110 + 1)) {
            fVec52[i110] = 0.0f;
            
        }
        for (int i111 = 0; (i111 < 3); i111 = (i111 + 1)) {
            fRec67[i111] = 0.0f;
            
        }
        for (int i112 = 0; (i112 < 2); i112 = (i112 + 1)) {
            iVec53[i112] = 0;
            
        }
        for (int i113 = 0; (i113 < 2); i113 = (i113 + 1)) {
            fRec70[i113] = 0.0f;
            
        }
        for (int i114 = 0; (i114 < 128); i114 = (i114 + 1)) {
            fVec54[i114] = 0.0f;
            
        }
        for (int i115 = 0; (i115 < 3); i115 = (i115 + 1)) {
            fRec69[i115] = 0.0f;
            
        }
        for (int i116 = 0; (i116 < 2); i116 = (i116 + 1)) {
            iVec55[i116] = 0;
            
        }
        for (int i117 = 0; (i117 < 2); i117 = (i117 + 1)) {
            fRec72[i117] = 0.0f;
            
        }
        for (int i118 = 0; (i118 < 64); i118 = (i118 + 1)) {
            fVec56[i118] = 0.0f;
            
        }
        for (int i119 = 0; (i119 < 3); i119 = (i119 + 1)) {
            fRec71[i119] = 0.0f;
            
        }
        for (int i120 = 0; (i120 < 2); i120 = (i120 + 1)) {
            iVec57[i120] = 0;
            
        }
        for (int i121 = 0; (i121 < 2); i121 = (i121 + 1)) {
            fRec74[i121] = 0.0f;
            
        }
        for (int i122 = 0; (i122 < 64); i122 = (i122 + 1)) {
            fVec58[i122] = 0.0f;
            
        }
        for (int i123 = 0; (i123 < 3); i123 = (i123 + 1)) {
            fRec73[i123] = 0.0f;
            
        }
        for (int i124 = 0; (i124 < 2); i124 = (i124 + 1)) {
            iVec59[i124] = 0;
            
        }
        for (int i125 = 0; (i125 < 2); i125 = (i125 + 1)) {
            fRec76[i125] = 0.0f;
            
        }
        for (int i126 = 0; (i126 < 64); i126 = (i126 + 1)) {
            fVec60[i126] = 0.0f;
            
        }
        for (int i127 = 0; (i127 < 3); i127 = (i127 + 1)) {
            fRec75[i127] = 0.0f;
            
        }
        for (int i128 = 0; (i128 < 2); i128 = (i128 + 1)) {
            iVec61[i128] = 0;
            
        }
        for (int i129 = 0; (i129 < 2); i129 = (i129 + 1)) {
            fRec78[i129] = 0.0f;
            
        }
        for (int i130 = 0; (i130 < 128); i130 = (i130 + 1)) {
            fVec62[i130] = 0.0f;
            
        }
        for (int i131 = 0; (i131 < 3); i131 = (i131 + 1)) {
            fRec77[i131] = 0.0f;
            
        }
        for (int i132 = 0; (i132 < 2); i132 = (i132 + 1)) {
            iVec63[i132] = 0;
            
        }
        for (int i133 = 0; (i133 < 2); i133 = (i133 + 1)) {
            fRec80[i133] = 0.0f;
            
        }
        for (int i134 = 0; (i134 < 128); i134 = (i134 + 1)) {
            fVec64[i134] = 0.0f;
            
        }
        for (int i135 = 0; (i135 < 3); i135 = (i135 + 1)) {
            fRec79[i135] = 0.0f;
            
        }
        for (int i136 = 0; (i136 < 2); i136 = (i136 + 1)) {
            iVec65[i136] = 0;
            
        }
        for (int i137 = 0; (i137 < 2); i137 = (i137 + 1)) {
            fRec82[i137] = 0.0f;
            
        }
        for (int i138 = 0; (i138 < 128); i138 = (i138 + 1)) {
            fVec66[i138] = 0.0f;
            
        }
        for (int i139 = 0; (i139 < 3); i139 = (i139 + 1)) {
            fRec81[i139] = 0.0f;
            
        }
        for (int i140 = 0; (i140 < 2); i140 = (i140 + 1)) {
            iVec67[i140] = 0;
            
        }
        for (int i141 = 0; (i141 < 2); i141 = (i141 + 1)) {
            fRec84[i141] = 0.0f;
            
        }
        for (int i142 = 0; (i142 < 128); i142 = (i142 + 1)) {
            fVec68[i142] = 0.0f;
            
        }
        for (int i143 = 0; (i143 < 3); i143 = (i143 + 1)) {
            fRec83[i143] = 0.0f;
            
        }
        for (int i144 = 0; (i144 < 2); i144 = (i144 + 1)) {
            iVec69[i144] = 0;
            
        }
        for (int i145 = 0; (i145 < 2); i145 = (i145 + 1)) {
            fRec86[i145] = 0.0f;
            
        }
        for (int i146 = 0; (i146 < 256); i146 = (i146 + 1)) {
            fVec70[i146] = 0.0f;
            
        }
        for (int i147 = 0; (i147 < 3); i147 = (i147 + 1)) {
            fRec85[i147] = 0.0f;
            
        }
        for (int i148 = 0; (i148 < 2); i148 = (i148 + 1)) {
            iVec71[i148] = 0;
            
        }
        for (int i149 = 0; (i149 < 2); i149 = (i149 + 1)) {
            fRec88[i149] = 0.0f;
            
        }
        for (int i150 = 0; (i150 < 128); i150 = (i150 + 1)) {
            fVec72[i150] = 0.0f;
            
        }
        for (int i151 = 0; (i151 < 3); i151 = (i151 + 1)) {
            fRec87[i151] = 0.0f;
            
        }
        for (int i152 = 0; (i152 < 2048); i152 = (i152 + 1)) {
            fVec73[i152] = 0.0f;
            
        }
        for (int i153 = 0; (i153 < 2); i153 = (i153 + 1)) {
            fRec15[i153] = 0.0f;
            
        }
        for (int i154 = 0; (i154 < 2); i154 = (i154 + 1)) {
            fRec90[i154] = 0.0f;
            
        }
        for (int i155 = 0; (i155 < 2048); i155 = (i155 + 1)) {
            fVec74[i155] = 0.0f;
            
        }
        for (int i156 = 0; (i156 < 2); i156 = (i156 + 1)) {
            fRec89[i156] = 0.0f;
            
        }
        for (int i157 = 0; (i157 < 2); i157 = (i157 + 1)) {
            fRec92[i157] = 0.0f;
            
        }
        for (int i158 = 0; (i158 < 2048); i158 = (i158 + 1)) {
            fVec75[i158] = 0.0f;
            
        }
        for (int i159 = 0; (i159 < 2); i159 = (i159 + 1)) {
            fRec91[i159] = 0.0f;
            
        }
        for (int i160 = 0; (i160 < 2); i160 = (i160 + 1)) {
            fRec94[i160] = 0.0f;
            
        }
        for (int i161 = 0; (i161 < 2048); i161 = (i161 + 1)) {
            fVec76[i161] = 0.0f;
            
        }
        for (int i162 = 0; (i162 < 2); i162 = (i162 + 1)) {
            fRec93[i162] = 0.0f;
            
        }
        for (int i163 = 0; (i163 < 2); i163 = (i163 + 1)) {
            fRec96[i163] = 0.0f;
            
        }
        for (int i164 = 0; (i164 < 2048); i164 = (i164 + 1)) {
            fVec77[i164] = 0.0f;
            
        }
        for (int i165 = 0; (i165 < 2); i165 = (i165 + 1)) {
            fRec95[i165] = 0.0f;
            
        }
        for (int i166 = 0; (i166 < 2); i166 = (i166 + 1)) {
            fRec98[i166] = 0.0f;
            
        }
        for (int i167 = 0; (i167 < 2048); i167 = (i167 + 1)) {
            fVec78[i167] = 0.0f;
            
        }
        for (int i168 = 0; (i168 < 2); i168 = (i168 + 1)) {
            fRec97[i168] = 0.0f;
            
        }
        for (int i169 = 0; (i169 < 2); i169 = (i169 + 1)) {
            fRec100[i169] = 0.0f;
            
        }
        for (int i170 = 0; (i170 < 2048); i170 = (i170 + 1)) {
            fVec79[i170] = 0.0f;
            
        }
        for (int i171 = 0; (i171 < 2); i171 = (i171 + 1)) {
            fRec99[i171] = 0.0f;
            
        }
        for (int i172 = 0; (i172 < 2); i172 = (i172 + 1)) {
            fRec102[i172] = 0.0f;
            
        }
        for (int i173 = 0; (i173 < 2048); i173 = (i173 + 1)) {
            fVec80[i173] = 0.0f;
            
        }
        for (int i174 = 0; (i174 < 2); i174 = (i174 + 1)) {
            fRec101[i174] = 0.0f;
            
        }
        for (int i175 = 0; (i175 < 1024); i175 = (i175 + 1)) {
            fVec81[i175] = 0.0f;
            
        }
        for (int i176 = 0; (i176 < 2); i176 = (i176 + 1)) {
            fRec13[i176] = 0.0f;
            
        }
        for (int i177 = 0; (i177 < 512); i177 = (i177 + 1)) {
            fVec82[i177] = 0.0f;
            
        }
        for (int i178 = 0; (i178 < 2); i178 = (i178 + 1)) {
            fRec11[i178] = 0.0f;
            
        }
        for (int i179 = 0; (i179 < 512); i179 = (i179 + 1)) {
            fVec83[i179] = 0.0f;
            
        }
        for (int i180 = 0; (i180 < 2); i180 = (i180 + 1)) {
            fRec9[i180] = 0.0f;
            
        }
        for (int i181 = 0; (i181 < 256); i181 = (i181 + 1)) {
            fVec84[i181] = 0.0f;
            
        }
        for (int i182 = 0; (i182 < 2); i182 = (i182 + 1)) {
            fRec7[i182] = 0.0f;
            
        }
        for (int i183 = 0; (i183 < 3); i183 = (i183 + 1)) {
            fRec0[i183] = 0.0f;
            
        }
        for (int i184 = 0; (i184 < 2); i184 = (i184 + 1)) {
            fRec113[i184] = 0.0f;
            
        }
        for (int i185 = 0; (i185 < 2048); i185 = (i185 + 1)) {
            fVec85[i185] = 0.0f;
            
        }
        for (int i186 = 0; (i186 < 2); i186 = (i186 + 1)) {
            fRec112[i186] = 0.0f;
            
        }
        for (int i187 = 0; (i187 < 2); i187 = (i187 + 1)) {
            fRec115[i187] = 0.0f;
            
        }
        for (int i188 = 0; (i188 < 2048); i188 = (i188 + 1)) {
            fVec86[i188] = 0.0f;
            
        }
        for (int i189 = 0; (i189 < 2); i189 = (i189 + 1)) {
            fRec114[i189] = 0.0f;
            
        }
        for (int i190 = 0; (i190 < 2); i190 = (i190 + 1)) {
            fRec117[i190] = 0.0f;
            
        }
        for (int i191 = 0; (i191 < 2048); i191 = (i191 + 1)) {
            fVec87[i191] = 0.0f;
            
        }
        for (int i192 = 0; (i192 < 2); i192 = (i192 + 1)) {
            fRec116[i192] = 0.0f;
            
        }
        for (int i193 = 0; (i193 < 2); i193 = (i193 + 1)) {
            fRec119[i193] = 0.0f;
            
        }
        for (int i194 = 0; (i194 < 2048); i194 = (i194 + 1)) {
            fVec88[i194] = 0.0f;
            
        }
        for (int i195 = 0; (i195 < 2); i195 = (i195 + 1)) {
            fRec118[i195] = 0.0f;
            
        }
        for (int i196 = 0; (i196 < 2); i196 = (i196 + 1)) {
            fRec121[i196] = 0.0f;
            
        }
        for (int i197 = 0; (i197 < 2048); i197 = (i197 + 1)) {
            fVec89[i197] = 0.0f;
            
        }
        for (int i198 = 0; (i198 < 2); i198 = (i198 + 1)) {
            fRec120[i198] = 0.0f;
            
        }
        for (int i199 = 0; (i199 < 2); i199 = (i199 + 1)) {
            fRec123[i199] = 0.0f;
            
        }
        for (int i200 = 0; (i200 < 2048); i200 = (i200 + 1)) {
            fVec90[i200] = 0.0f;
            
        }
        for (int i201 = 0; (i201 < 2); i201 = (i201 + 1)) {
            fRec122[i201] = 0.0f;
            
        }
        for (int i202 = 0; (i202 < 2); i202 = (i202 + 1)) {
            fRec125[i202] = 0.0f;
            
        }
        for (int i203 = 0; (i203 < 2048); i203 = (i203 + 1)) {
            fVec91[i203] = 0.0f;
            
        }
        for (int i204 = 0; (i204 < 2); i204 = (i204 + 1)) {
            fRec124[i204] = 0.0f;
            
        }
        for (int i205 = 0; (i205 < 2); i205 = (i205 + 1)) {
            fRec127[i205] = 0.0f;
            
        }
        for (int i206 = 0; (i206 < 2048); i206 = (i206 + 1)) {
            fVec92[i206] = 0.0f;
            
        }
        for (int i207 = 0; (i207 < 2); i207 = (i207 + 1)) {
            fRec126[i207] = 0.0f;
            
        }
        for (int i208 = 0; (i208 < 1024); i208 = (i208 + 1)) {
            fVec93[i208] = 0.0f;
            
        }
        for (int i209 = 0; (i209 < 2); i209 = (i209 + 1)) {
            fRec110[i209] = 0.0f;
            
        }
        for (int i210 = 0; (i210 < 512); i210 = (i210 + 1)) {
            fVec94[i210] = 0.0f;
            
        }
        for (int i211 = 0; (i211 < 2); i211 = (i211 + 1)) {
            fRec108[i211] = 0.0f;
            
        }
        for (int i212 = 0; (i212 < 512); i212 = (i212 + 1)) {
            fVec95[i212] = 0.0f;
            
        }
        for (int i213 = 0; (i213 < 2); i213 = (i213 + 1)) {
            fRec106[i213] = 0.0f;
            
        }
        for (int i214 = 0; (i214 < 256); i214 = (i214 + 1)) {
            fVec96[i214] = 0.0f;
            
        }
        for (int i215 = 0; (i215 < 2); i215 = (i215 + 1)) {
            fRec104[i215] = 0.0f;
            
        }
        for (int i216 = 0; (i216 < 3); i216 = (i216 + 1)) {
            fRec103[i216] = 0.0f;
            
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
        ui_interface->openTabBox("tab1");
        
        ui_interface->openHorizontalBox("Loops");
        ui_interface->openVerticalBox("loop");
        ui_interface->addVerticalSlider("level", &fVslider0, 0.0f, 0.0f, 6.0f, 1.0f);
        ui_interface->closeBox();
        ui_interface->openVerticalBox("loop48");
        ui_interface->declare(&fVslider3, "1", "");
        ui_interface->addVerticalSlider("note", &fVslider3, 0.0f, 0.0f, 11.0f, 1.0f);
        ui_interface->closeBox();
        ui_interface->openVerticalBox("loop60");
        ui_interface->declare(&fVslider2, "1", "");
        ui_interface->addVerticalSlider("note", &fVslider2, 0.0f, 0.0f, 11.0f, 1.0f);
        ui_interface->closeBox();
        ui_interface->openVerticalBox("loop72");
        ui_interface->declare(&fVslider1, "1", "");
        ui_interface->addVerticalSlider("note", &fVslider1, 0.0f, 0.0f, 11.0f, 1.0f);
        ui_interface->closeBox();
        ui_interface->closeBox();
        
        ui_interface->closeBox();
     
        ui_interface->openTabBox("tab2");
        
        ui_interface->openVerticalBox("Effects");
        ui_interface->addHorizontalSlider("Reverb", &fHslider2, 0.333299994f, 0.0f, 1.0f, 0.0250000004f);
        ui_interface->declare(&fHslider1, "1", "");
        ui_interface->addHorizontalSlider("WahWah", &fHslider1, 0.800000012f, 0.0f, 1.0f, 0.00999999978f);
        ui_interface->declare(&fHslider0, "1", "");
        ui_interface->addHorizontalSlider("master", &fHslider0, -20.0f, -60.0f, 0.0f, 0.00999999978f);
        ui_interface->declare(&fHslider3, "2", "");
        ui_interface->addHorizontalSlider("timbre", &fHslider3, 0.0f, 0.0f, 1.0f, 0.00999999978f);
        ui_interface->closeBox();
        
        ui_interface->closeBox();
        
    }

    /*
    virtual void buildUserInterface(UI* ui_interface) {
        ui_interface->openVerticalBox("0x00");
        
        
        ui_interface->openHorizontalBox("Loops");
        
        //ui_interface->openVerticalBox("loop");
        ui_interface->addButton("1", &fVslider0);
         //ui_interface->closeBox();
        
         //ui_interface->openVerticalBox("loop48");
        ui_interface->addButton("2", &fVslider3);
         //ui_interface->closeBox();
        
         //ui_interface->openVerticalBox("loop60");
        ui_interface->addButton("3", &fVslider2);
         //ui_interface->closeBox();
        
         //ui_interface->openVerticalBox("loop72");
        ui_interface->addButton("4", &fVslider1);
         //ui_interface->closeBox();
        
        ui_interface->closeBox();
        
        
         ui_interface->openHorizontalBox("Loops");
        
        ui_interface->addButton("5", &fHslider2);
        ui_interface->declare(&fHslider1, "1", "");
        ui_interface->addButton("6", &fHslider1);
        ui_interface->declare(&fHslider0, "1", "");
        //ui_interface->addButton("7", &fHslider0);
        ui_interface->declare(&fHslider3, "2", "");
        //ui_interface->addButton("8", &fHslider3);
        
        ui_interface->closeBox();
        
        ui_interface->closeBox();
        
    }
    */
    
    virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
        FAUSTFLOAT* output0 = outputs[0];
        FAUSTFLOAT* output1 = outputs[1];
        float fSlow0 = powf(10.0f, (0.0500000007f * float(fHslider0)));
        float fSlow1 = float(fHslider1);
        int iSlow2 = (fSlow1 <= 0.0f);
        float fSlow3 = float(fHslider2);
        int iSlow4 = int(float(fVslider0));
        int iSlow5 = (float(iSlow4) <= 0.0f);
        int iSlow6 = int(float(fVslider1));
        int iSlow7 = (float(iSlow6) <= 0.0f);
        float fSlow8 = float(fHslider3);
        int iSlow9 = (fSlow8 <= 0.0f);
        int iSlow10 = int(float(fVslider2));
        int iSlow11 = (float(iSlow10) <= 0.0f);
        int iSlow12 = int(float(fVslider3));
        int iSlow13 = (float(iSlow12) <= 0.0f);
        float fSlow14 = (1.0f - fSlow3);
        for (int i = 0; (i < count); i = (i + 1)) {
            iRec2[0] = ((1 + iRec2[1]) % iConst2);
            int iTemp0 = (iRec2[0] == 0);
            iVec0[0] = iTemp0;
            fVec1[0] = fSlow1;
            fRec3[0] = (iVec0[1]?0.0f:(fabsf((fSlow1 - fVec1[1])) + fRec3[1]));
            iRec4[0] = ((iTemp0 + iRec4[1]) % 15);
            ftbl0[((iTemp0 & ((fRec3[0] > 0.0f) | iSlow2))?iRec4[0]:15)] = fSlow1;
            float fTemp1 = powf(2.0f, (2.29999995f * ftbl0[iRec4[0]]));
            float fTemp2 = (1.0f - (fConst1 * (fTemp1 / powf(2.0f, (1.0f + (2.0f * (1.0f - ftbl0[iRec4[0]])))))));
            fRec1[0] = ((0.999000013f * fRec1[1]) + (0.00100000005f * (0.0f - (2.0f * (fTemp2 * cosf((fConst3 * fTemp1)))))));
            fRec5[0] = ((0.999000013f * fRec5[1]) + (0.00100000005f * faustpower2_f(fTemp2)));
            fRec6[0] = ((0.999000013f * fRec6[1]) + (9.99999975e-05f * powf(4.0f, ftbl0[iRec4[0]])));
            fRec16[0] = ((0.699999988f * fRec15[1]) + (0.300000012f * fRec16[1]));
            iRec18[0] = (12345 + (1103515245 * iRec18[1]));
            iVec2[0] = iSlow4;
            iRec19[0] = (iVec0[1]?0:(iRec19[1] + abs((iSlow4 - iVec2[1]))));
            ftbl1[((iTemp0 & ((iRec19[0] > 0) | iSlow5))?iRec4[0]:15)] = float(iSlow4);
            float fTemp3 = (float(iRec18[0]) * powf(10.0f, (0.0500000007f * (ftbl1[iRec4[0]] - 6.0f))));
            iVec3[0] = iSlow6;
            iRec21[0] = (iVec0[1]?0:(iRec21[1] + abs((iSlow6 - iVec3[1]))));
            ftbl2[((iTemp0 & ((iRec21[0] > 0) | iSlow7))?iRec4[0]:15)] = float(iSlow6);
            int iTemp4 = (fabsf((ftbl2[iRec4[0]] - 1.0f)) < 0.5f);
            iVec4[0] = iTemp4;
            fRec20[0] = ((fRec20[1] + float((float((iTemp4 - iVec4[1])) > 0.0f))) - (0.0118651045f * float((fRec20[1] > 0.0f))));
            fVec5[0] = fSlow8;
            fRec22[0] = (iVec0[1]?0.0f:(fRec22[1] + fabsf((fSlow8 - fVec5[1]))));
            ftbl3[((iTemp0 & ((fRec22[0] > 0.0f) | iSlow9))?iRec4[0]:15)] = fSlow8;
            float fTemp5 = (1.0f + ftbl3[iRec4[0]]);
            float fTemp6 = (1.0f - ftbl3[iRec4[0]]);
            fVec6[(IOTA & 127)] = ((4.65661287e-10f * (fTemp3 * float((fRec20[0] > 0.0f)))) + (0.498352528f * ((fTemp5 * fRec17[1]) + (fTemp6 * fRec17[2]))));
            fRec17[0] = fVec6[((IOTA - 83) & 127)];
            int iTemp7 = (fabsf((ftbl2[iRec4[0]] - 2.0f)) < 0.5f);
            iVec7[0] = iTemp7;
            fRec24[0] = ((fRec24[1] + float((float((iTemp7 - iVec7[1])) > 0.0f))) - (0.0133181298f * float((fRec24[1] > 0.0f))));
            fVec8[(IOTA & 127)] = ((4.65661287e-10f * (fTemp3 * float((fRec24[0] > 0.0f)))) + (0.498531997f * ((fTemp5 * fRec23[1]) + (fTemp6 * fRec23[2]))));
            fRec23[0] = fVec8[((IOTA - 74) & 127)];
            int iTemp8 = (fabsf((ftbl2[iRec4[0]] - 3.0f)) < 0.5f);
            iVec9[0] = iTemp8;
            fRec26[0] = ((fRec26[1] + float((float((iTemp8 - iVec9[1])) > 0.0f))) - (0.0149490954f * float((fRec26[1] > 0.0f))));
            fVec10[(IOTA & 127)] = ((4.65661287e-10f * (fTemp3 * float((fRec26[0] > 0.0f)))) + (0.498691946f * ((fTemp5 * fRec25[1]) + (fTemp6 * fRec25[2]))));
            fRec25[0] = fVec10[((IOTA - 65) & 127)];
            int iTemp9 = (fabsf((ftbl2[iRec4[0]] - 4.0f)) < 0.5f);
            iVec11[0] = iTemp9;
            fRec28[0] = ((fRec28[1] + float((float((iTemp9 - iVec11[1])) > 0.0f))) - (0.0177775715f * float((fRec28[1] > 0.0f))));
            fVec12[(IOTA & 63)] = ((4.65661287e-10f * (fTemp3 * float((fRec28[0] > 0.0f)))) + (0.498899847f * ((fTemp5 * fRec27[1]) + (fTemp6 * fRec27[2]))));
            fRec27[0] = fVec12[((IOTA - 55) & 63)];
            int iTemp10 = (fabsf((ftbl2[iRec4[0]] - 5.0f)) < 0.5f);
            iVec13[0] = iTemp10;
            fRec30[0] = ((fRec30[1] + float((float((iTemp10 - iVec13[1])) > 0.0f))) - (0.0199546479f * float((fRec30[1] > 0.0f))));
            fVec14[(IOTA & 63)] = ((4.65661287e-10f * (fTemp3 * float((fRec30[0] > 0.0f)))) + (0.499019742f * ((fTemp5 * fRec29[1]) + (fTemp6 * fRec29[2]))));
            fRec29[0] = fVec14[((IOTA - 49) & 63)];
            int iTemp11 = (fabsf((ftbl2[iRec4[0]] - 6.0f)) < 0.5f);
            iVec15[0] = iTemp11;
            fRec32[0] = ((fRec32[1] + float((float((iTemp11 - iVec15[1])) > 0.0f))) - (0.0237302091f * float((fRec32[1] > 0.0f))));
            fVec16[(IOTA & 63)] = ((4.65661287e-10f * (fTemp3 * float((fRec32[0] > 0.0f)))) + (0.499175578f * ((fTemp5 * fRec31[1]) + (fTemp6 * fRec31[2]))));
            fRec31[0] = fVec16[((IOTA - 41) & 63)];
            float fTemp12 = (0.707106769f * fRec31[0]);
            int iTemp13 = (fabsf((ftbl2[iRec4[0]] - 7.0f)) < 0.5f);
            iVec17[0] = iTemp13;
            fRec34[0] = ((fRec34[1] + float((float((iTemp13 - iVec17[1])) > 0.0f))) - (0.0266362596f * float((fRec34[1] > 0.0f))));
            fVec18[(IOTA & 63)] = ((4.65661287e-10f * (fTemp3 * float((fRec34[0] > 0.0f)))) + (0.499265462f * ((fTemp5 * fRec33[1]) + (fTemp6 * fRec33[2]))));
            fRec33[0] = fVec18[((IOTA - 36) & 63)];
            int iTemp14 = (fabsf((ftbl2[iRec4[0]] - 8.0f)) < 0.5f);
            iVec19[0] = iTemp14;
            fRec36[0] = ((fRec36[1] + float((float((iTemp14 - iVec19[1])) > 0.0f))) - (0.0298981909f * float((fRec36[1] > 0.0f))));
            fVec20[(IOTA & 63)] = ((4.65661287e-10f * (fTemp3 * float((fRec36[0] > 0.0f)))) + (0.499345541f * ((fTemp5 * fRec35[1]) + (fTemp6 * fRec35[2]))));
            fRec35[0] = fVec20[((IOTA - 32) & 63)];
            int iTemp15 = (fabsf((ftbl2[iRec4[0]] - 9.0f)) < 0.5f);
            iVec21[0] = iTemp15;
            fRec38[0] = ((fRec38[1] + float((float((iTemp15 - iVec21[1])) > 0.0f))) - (0.0355551429f * float((fRec38[1] > 0.0f))));
            fVec22[(IOTA & 31)] = ((4.65661287e-10f * (fTemp3 * float((fRec38[0] > 0.0f)))) + (0.499449611f * ((fTemp5 * fRec37[1]) + (fTemp6 * fRec37[2]))));
            fRec37[0] = fVec22[((IOTA - 27) & 31)];
            int iTemp16 = (fabsf((ftbl2[iRec4[0]] - 10.0f)) < 0.5f);
            iVec23[0] = iTemp16;
            fRec40[0] = ((fRec40[1] + float((float((iTemp16 - iVec23[1])) > 0.0f))) - (0.0399092957f * float((fRec40[1] > 0.0f))));
            fVec24[(IOTA & 31)] = ((4.65661287e-10f * (fTemp3 * float((fRec40[0] > 0.0f)))) + (0.499509633f * ((fTemp5 * fRec39[1]) + (fTemp6 * fRec39[2]))));
            fRec39[0] = fVec24[((IOTA - 24) & 31)];
            int iTemp17 = (fabsf((ftbl2[iRec4[0]] - 11.0f)) < 0.5f);
            iVec25[0] = iTemp17;
            fRec42[0] = ((fRec42[1] + float((float((iTemp17 - iVec25[1])) > 0.0f))) - (0.0474604182f * float((fRec42[1] > 0.0f))));
            fVec26[(IOTA & 31)] = ((4.65661287e-10f * (fTemp3 * float((fRec42[0] > 0.0f)))) + (0.499587625f * ((fTemp5 * fRec41[1]) + (fTemp6 * fRec41[2]))));
            fRec41[0] = fVec26[((IOTA - 20) & 31)];
            float fTemp18 = (((((((((((0.977008402f * fRec17[0]) + (0.929320395f * fRec23[0])) + (0.879049063f * fRec25[0])) + (0.825722814f * fRec27[0])) + (0.768706143f * fRec29[0])) + fTemp12) + (0.639602125f * fRec33[0])) + (0.564076066f * fRec35[0])) + (0.4767313f * fRec37[0])) + (0.369274467f * fRec39[0])) + (0.213200718f * fRec41[0]));
            float fTemp19 = ((0.977008402f * fRec41[0]) + ((0.929320395f * fRec39[0]) + ((0.879049063f * fRec37[0]) + ((0.825722814f * fRec35[0]) + ((0.768706143f * fRec33[0]) + (fTemp12 + ((((0.4767313f * fRec25[0]) + ((0.369274467f * fRec23[0]) + (0.213200718f * fRec17[0]))) + (0.564076066f * fRec27[0])) + (0.639602125f * fRec29[0]))))))));
            iVec27[0] = iSlow10;
            iRec45[0] = (iVec0[1]?0:(iRec45[1] + abs((iSlow10 - iVec27[1]))));
            ftbl4[((iTemp0 & ((iRec45[0] > 0) | iSlow11))?iRec4[0]:15)] = float(iSlow10);
            int iTemp20 = (fabsf((ftbl4[iRec4[0]] - 2.0f)) < 0.5f);
            iVec28[0] = iTemp20;
            fRec44[0] = ((fRec44[1] + float((float((iTemp20 - iVec28[1])) > 0.0f))) - (0.00665906491f * float((fRec44[1] > 0.0f))));
            fVec29[(IOTA & 255)] = ((4.65661287e-10f * (fTemp3 * float((fRec44[0] > 0.0f)))) + (0.497068316f * ((fTemp5 * fRec43[1]) + (fTemp6 * fRec43[2]))));
            fRec43[0] = fVec29[((IOTA - 149) & 255)];
            iVec30[0] = iSlow12;
            iRec48[0] = (iVec0[1]?0:(iRec48[1] + abs((iSlow12 - iVec30[1]))));
            ftbl5[((iTemp0 & ((iRec48[0] > 0) | iSlow13))?iRec4[0]:15)] = float(iSlow12);
            int iTemp21 = (fabsf((ftbl5[iRec4[0]] - 2.0f)) < 0.5f);
            iVec31[0] = iTemp21;
            fRec47[0] = ((fRec47[1] + float((float((iTemp21 - iVec31[1])) > 0.0f))) - (0.00332953245f * float((fRec47[1] > 0.0f))));
            fVec32[(IOTA & 511)] = ((4.65661287e-10f * (fTemp3 * float((fRec47[0] > 0.0f)))) + (0.494153798f * ((fTemp5 * fRec46[1]) + (fTemp6 * fRec46[2]))));
            fRec46[0] = fVec32[((IOTA - 299) & 511)];
            int iTemp22 = (fabsf((ftbl4[iRec4[0]] - 1.0f)) < 0.5f);
            iVec33[0] = iTemp22;
            fRec50[0] = ((fRec50[1] + float((float((iTemp22 - iVec33[1])) > 0.0f))) - (0.00593255227f * float((fRec50[1] > 0.0f))));
            fVec34[(IOTA & 255)] = ((0.496710479f * ((fRec49[1] * fTemp5) + (fRec49[2] * fTemp6))) + (4.65661287e-10f * (fTemp3 * float((fRec50[0] > 0.0f)))));
            fRec49[0] = fVec34[((IOTA - 167) & 255)];
            int iTemp23 = (fabsf((ftbl5[iRec4[0]] - 1.0f)) < 0.5f);
            iVec35[0] = iTemp23;
            fRec52[0] = ((fRec52[1] + float((float((iTemp23 - iVec35[1])) > 0.0f))) - (0.00296627614f * float((fRec52[1] > 0.0f))));
            fVec36[(IOTA & 511)] = ((4.65661287e-10f * (fTemp3 * float((fRec52[0] > 0.0f)))) + (0.493442565f * ((fTemp5 * fRec51[1]) + (fTemp6 * fRec51[2]))));
            fRec51[0] = fVec36[((IOTA - 336) & 511)];
            int iTemp24 = (fabsf((ftbl5[iRec4[0]] - 3.0f)) < 0.5f);
            iVec37[0] = iTemp24;
            fRec54[0] = ((fRec54[1] + float((float((iTemp24 - iVec37[1])) > 0.0f))) - (0.00373727386f * float((fRec54[1] > 0.0f))));
            fVec38[(IOTA & 511)] = ((4.65661287e-10f * (fTemp3 * float((fRec54[0] > 0.0f)))) + (0.494788289f * ((fTemp5 * fRec53[1]) + (fTemp6 * fRec53[2]))));
            fRec53[0] = fVec38[((IOTA - 266) & 511)];
            int iTemp25 = (fabsf((ftbl5[iRec4[0]] - 4.0f)) < 0.5f);
            iVec39[0] = iTemp25;
            fRec56[0] = ((fRec56[1] + float((float((iTemp25 - iVec39[1])) > 0.0f))) - (0.00444439286f * float((fRec56[1] > 0.0f))));
            fVec40[(IOTA & 255)] = ((4.65661287e-10f * (fTemp3 * float((fRec56[0] > 0.0f)))) + (0.495613843f * ((fTemp5 * fRec55[1]) + (fTemp6 * fRec55[2]))));
            fRec55[0] = fVec40[((IOTA - 224) & 255)];
            int iTemp26 = (fabsf((ftbl5[iRec4[0]] - 5.0f)) < 0.5f);
            iVec41[0] = iTemp26;
            fRec58[0] = ((fRec58[1] + float((float((iTemp26 - iVec41[1])) > 0.0f))) - (0.00498866197f * float((fRec58[1] > 0.0f))));
            fVec42[(IOTA & 255)] = ((4.65661287e-10f * (fTemp3 * float((fRec58[0] > 0.0f)))) + (0.496090502f * ((fTemp5 * fRec57[1]) + (fTemp6 * fRec57[2]))));
            fRec57[0] = fVec42[((IOTA - 199) & 255)];
            int iTemp27 = (fabsf((ftbl5[iRec4[0]] - 6.0f)) < 0.5f);
            iVec43[0] = iTemp27;
            fRec60[0] = ((fRec60[1] + float((float((iTemp27 - iVec43[1])) > 0.0f))) - (0.00593255227f * float((fRec60[1] > 0.0f))));
            fVec44[(IOTA & 255)] = ((4.65661287e-10f * (fTemp3 * float((fRec60[0] > 0.0f)))) + (0.496710479f * ((fTemp5 * fRec59[1]) + (fTemp6 * fRec59[2]))));
            fRec59[0] = fVec44[((IOTA - 167) & 255)];
            int iTemp28 = (fabsf((ftbl5[iRec4[0]] - 7.0f)) < 0.5f);
            iVec45[0] = iTemp28;
            fRec62[0] = ((fRec62[1] + float((float((iTemp28 - iVec45[1])) > 0.0f))) - (0.00665906491f * float((fRec62[1] > 0.0f))));
            fVec46[(IOTA & 255)] = ((4.65661287e-10f * (fTemp3 * float((fRec62[0] > 0.0f)))) + (0.497068316f * ((fTemp5 * fRec61[1]) + (fTemp6 * fRec61[2]))));
            fRec61[0] = fVec46[((IOTA - 149) & 255)];
            int iTemp29 = (fabsf((ftbl5[iRec4[0]] - 8.0f)) < 0.5f);
            iVec47[0] = iTemp29;
            fRec64[0] = ((fRec64[1] + float((float((iTemp29 - iVec47[1])) > 0.0f))) - (0.00747454772f * float((fRec64[1] > 0.0f))));
            fVec48[(IOTA & 255)] = ((4.65661287e-10f * (fTemp3 * float((fRec64[0] > 0.0f)))) + (0.49738732f * ((fTemp5 * fRec63[1]) + (fTemp6 * fRec63[2]))));
            fRec63[0] = fVec48[((IOTA - 132) & 255)];
            int iTemp30 = (fabsf((ftbl5[iRec4[0]] - 9.0f)) < 0.5f);
            iVec49[0] = iTemp30;
            fRec66[0] = ((fRec66[1] + float((float((iTemp30 - iVec49[1])) > 0.0f))) - (0.00888878573f * float((fRec66[1] > 0.0f))));
            fVec50[(IOTA & 127)] = ((4.65661287e-10f * (fTemp3 * float((fRec66[0] > 0.0f)))) + (0.497802079f * ((fTemp5 * fRec65[1]) + (fTemp6 * fRec65[2]))));
            fRec65[0] = fVec50[((IOTA - 111) & 127)];
            int iTemp31 = (fabsf((ftbl5[iRec4[0]] - 10.0f)) < 0.5f);
            iVec51[0] = iTemp31;
            fRec68[0] = ((fRec68[1] + float((float((iTemp31 - iVec51[1])) > 0.0f))) - (0.00997732393f * float((fRec68[1] > 0.0f))));
            fVec52[(IOTA & 127)] = ((4.65661287e-10f * (fTemp3 * float((fRec68[0] > 0.0f)))) + (0.498041421f * ((fTemp5 * fRec67[1]) + (fTemp6 * fRec67[2]))));
            fRec67[0] = fVec52[((IOTA - 99) & 127)];
            int iTemp32 = (fabsf((ftbl5[iRec4[0]] - 11.0f)) < 0.5f);
            iVec53[0] = iTemp32;
            fRec70[0] = ((fRec70[1] + float((float((iTemp32 - iVec53[1])) > 0.0f))) - (0.0118651045f * float((fRec70[1] > 0.0f))));
            fVec54[(IOTA & 127)] = ((0.498352528f * ((fTemp5 * fRec69[1]) + (fTemp6 * fRec69[2]))) + (4.65661287e-10f * (fTemp3 * float((fRec70[0] > 0.0f)))));
            fRec69[0] = fVec54[((IOTA - 83) & 127)];
            int iTemp33 = (fabsf((ftbl4[iRec4[0]] - 11.0f)) < 0.5f);
            iVec55[0] = iTemp33;
            fRec72[0] = ((fRec72[1] + float((float((iTemp33 - iVec55[1])) > 0.0f))) - (0.0237302091f * float((fRec72[1] > 0.0f))));
            fVec56[(IOTA & 63)] = ((4.65661287e-10f * (fTemp3 * float((fRec72[0] > 0.0f)))) + (0.499175578f * ((fTemp5 * fRec71[1]) + (fTemp6 * fRec71[2]))));
            fRec71[0] = fVec56[((IOTA - 41) & 63)];
            int iTemp34 = (fabsf((ftbl4[iRec4[0]] - 10.0f)) < 0.5f);
            iVec57[0] = iTemp34;
            fRec74[0] = ((fRec74[1] + float((float((iTemp34 - iVec57[1])) > 0.0f))) - (0.0199546479f * float((fRec74[1] > 0.0f))));
            fVec58[(IOTA & 63)] = ((4.65661287e-10f * (fTemp3 * float((fRec74[0] > 0.0f)))) + (0.499019742f * ((fTemp5 * fRec73[1]) + (fTemp6 * fRec73[2]))));
            fRec73[0] = fVec58[((IOTA - 49) & 63)];
            int iTemp35 = (fabsf((ftbl4[iRec4[0]] - 9.0f)) < 0.5f);
            iVec59[0] = iTemp35;
            fRec76[0] = ((fRec76[1] + float((float((iTemp35 - iVec59[1])) > 0.0f))) - (0.0177775715f * float((fRec76[1] > 0.0f))));
            fVec60[(IOTA & 63)] = ((4.65661287e-10f * (fTemp3 * float((fRec76[0] > 0.0f)))) + (0.498899847f * ((fTemp5 * fRec75[1]) + (fTemp6 * fRec75[2]))));
            fRec75[0] = fVec60[((IOTA - 55) & 63)];
            int iTemp36 = (fabsf((ftbl4[iRec4[0]] - 8.0f)) < 0.5f);
            iVec61[0] = iTemp36;
            fRec78[0] = ((fRec78[1] + float((float((iTemp36 - iVec61[1])) > 0.0f))) - (0.0149490954f * float((fRec78[1] > 0.0f))));
            fVec62[(IOTA & 127)] = ((4.65661287e-10f * (fTemp3 * float((fRec78[0] > 0.0f)))) + (0.498691946f * ((fTemp5 * fRec77[1]) + (fTemp6 * fRec77[2]))));
            fRec77[0] = fVec62[((IOTA - 65) & 127)];
            int iTemp37 = (fabsf((ftbl4[iRec4[0]] - 7.0f)) < 0.5f);
            iVec63[0] = iTemp37;
            fRec80[0] = ((fRec80[1] + float((float((iTemp37 - iVec63[1])) > 0.0f))) - (0.0133181298f * float((fRec80[1] > 0.0f))));
            fVec64[(IOTA & 127)] = ((4.65661287e-10f * (fTemp3 * float((fRec80[0] > 0.0f)))) + (0.498531997f * ((fTemp5 * fRec79[1]) + (fTemp6 * fRec79[2]))));
            fRec79[0] = fVec64[((IOTA - 74) & 127)];
            int iTemp38 = (fabsf((ftbl4[iRec4[0]] - 6.0f)) < 0.5f);
            iVec65[0] = iTemp38;
            fRec82[0] = ((fRec82[1] + float((float((iTemp38 - iVec65[1])) > 0.0f))) - (0.0118651045f * float((fRec82[1] > 0.0f))));
            fVec66[(IOTA & 127)] = ((4.65661287e-10f * (fTemp3 * float((fRec82[0] > 0.0f)))) + (0.498352528f * ((fTemp5 * fRec81[1]) + (fTemp6 * fRec81[2]))));
            fRec81[0] = fVec66[((IOTA - 83) & 127)];
            int iTemp39 = (fabsf((ftbl4[iRec4[0]] - 5.0f)) < 0.5f);
            iVec67[0] = iTemp39;
            fRec84[0] = ((fRec84[1] + float((float((iTemp39 - iVec67[1])) > 0.0f))) - (0.00997732393f * float((fRec84[1] > 0.0f))));
            fVec68[(IOTA & 127)] = ((4.65661287e-10f * (fTemp3 * float((fRec84[0] > 0.0f)))) + (0.498041421f * ((fTemp5 * fRec83[1]) + (fTemp6 * fRec83[2]))));
            fRec83[0] = fVec68[((IOTA - 99) & 127)];
            int iTemp40 = (fabsf((ftbl4[iRec4[0]] - 3.0f)) < 0.5f);
            iVec69[0] = iTemp40;
            fRec86[0] = ((fRec86[1] + float((float((iTemp40 - iVec69[1])) > 0.0f))) - (0.00747454772f * float((fRec86[1] > 0.0f))));
            fVec70[(IOTA & 255)] = ((4.65661287e-10f * (fTemp3 * float((fRec86[0] > 0.0f)))) + (0.49738732f * ((fTemp6 * fRec85[2]) + (fTemp5 * fRec85[1]))));
            fRec85[0] = fVec70[((IOTA - 132) & 255)];
            int iTemp41 = (fabsf((ftbl4[iRec4[0]] - 4.0f)) < 0.5f);
            iVec71[0] = iTemp41;
            fRec88[0] = ((fRec88[1] + float((float((iTemp41 - iVec71[1])) > 0.0f))) - (0.00888878573f * float((fRec88[1] > 0.0f))));
            fVec72[(IOTA & 127)] = ((4.65661287e-10f * (fTemp3 * float((fRec88[0] > 0.0f)))) + (0.497802079f * ((fTemp5 * fRec87[1]) + (fTemp6 * fRec87[2]))));
            fRec87[0] = fVec72[((IOTA - 111) & 127)];
            float fTemp42 = ((0.951189756f * (fRec43[0] + ((((((((((fRec46[0] + ((1.05131495f * fRec49[0]) + (1.05131495f * fRec51[0]))) + (0.945905328f * fRec53[0])) + (0.88852334f * fRec55[0])) + (0.827170193f * fRec57[0])) + (0.760885894f * fRec59[0])) + (0.688247204f * fRec61[0])) + (0.606976986f * fRec63[0])) + (0.512989163f * fRec65[0])) + (0.397359699f * fRec67[0])) + (0.22941573f * fRec69[0])))) + ((0.218217894f * fRec71[0]) + ((0.377964467f * fRec73[0]) + ((0.487950027f * fRec75[0]) + ((0.577350259f * fRec77[0]) + ((0.654653668f * fRec79[0]) + ((0.723746836f * fRec81[0]) + ((0.786795795f * fRec83[0]) + ((0.899735391f * fRec85[0]) + (0.845154226f * fRec87[0]))))))))));
            float fTemp43 = ((1.73205078f * (fRec43[0] + ((((((((((fRec46[0] + ((0.577350259f * fRec49[0]) + (0.577350259f * fRec51[0]))) + (1.29099441f * fRec53[0])) + (1.52752519f * fRec55[0])) + (1.73205078f * fRec57[0])) + (1.91485417f * fRec59[0])) + (2.08166599f * fRec61[0])) + (2.23606801f * fRec63[0])) + (2.38047624f * fRec65[0])) + (2.51661158f * fRec67[0])) + (2.64575124f * fRec69[0])))) + ((4.5825758f * fRec71[0]) + ((4.35889912f * fRec73[0]) + ((4.12310553f * fRec75[0]) + ((3.87298346f * fRec77[0]) + ((3.60555124f * fRec79[0]) + ((3.31662488f * fRec81[0]) + ((3.0f * fRec83[0]) + ((2.23606801f * fRec85[0]) + (2.64575124f * fRec87[0]))))))))));
            float fTemp44 = (0.0225000009f * (((fTemp18 + fTemp19) + (0.651338935f * fTemp42)) + (0.142133817f * fTemp43)));
            fVec73[(IOTA & 2047)] = ((0.924000025f * fRec16[0]) + fTemp44);
            fRec15[0] = fVec73[((IOTA - 1116) & 2047)];
            fRec90[0] = ((0.699999988f * fRec89[1]) + (0.300000012f * fRec90[1]));
            fVec74[(IOTA & 2047)] = ((0.924000025f * fRec90[0]) + fTemp44);
            fRec89[0] = fVec74[((IOTA - 1188) & 2047)];
            fRec92[0] = ((0.699999988f * fRec91[1]) + (0.300000012f * fRec92[1]));
            fVec75[(IOTA & 2047)] = ((0.924000025f * fRec92[0]) + fTemp44);
            fRec91[0] = fVec75[((IOTA - 1277) & 2047)];
            fRec94[0] = ((0.699999988f * fRec93[1]) + (0.300000012f * fRec94[1]));
            fVec76[(IOTA & 2047)] = ((0.924000025f * fRec94[0]) + fTemp44);
            fRec93[0] = fVec76[((IOTA - 1356) & 2047)];
            fRec96[0] = ((0.699999988f * fRec95[1]) + (0.300000012f * fRec96[1]));
            fVec77[(IOTA & 2047)] = ((0.924000025f * fRec96[0]) + fTemp44);
            fRec95[0] = fVec77[((IOTA - 1422) & 2047)];
            fRec98[0] = ((0.699999988f * fRec97[1]) + (0.300000012f * fRec98[1]));
            fVec78[(IOTA & 2047)] = ((0.924000025f * fRec98[0]) + fTemp44);
            fRec97[0] = fVec78[((IOTA - 1491) & 2047)];
            fRec100[0] = ((0.699999988f * fRec99[1]) + (0.300000012f * fRec100[1]));
            fVec79[(IOTA & 2047)] = ((0.924000025f * fRec100[0]) + fTemp44);
            fRec99[0] = fVec79[((IOTA - 1557) & 2047)];
            fRec102[0] = ((0.699999988f * fRec101[1]) + (0.300000012f * fRec102[1]));
            fVec80[(IOTA & 2047)] = ((0.924000025f * fRec102[0]) + fTemp44);
            fRec101[0] = fVec80[((IOTA - 1617) & 2047)];
            fVec81[(IOTA & 1023)] = (fRec15[0] + (fRec89[0] + (fRec91[0] + (fRec93[0] + (fRec95[0] + (fRec97[0] + (fRec99[0] + ((0.5f * fRec13[1]) + fRec101[0]))))))));
            fRec13[0] = fVec81[((IOTA - 556) & 1023)];
            float fRec14 = (0.0f - ((fRec15[0] + (fRec89[0] + (fRec91[0] + (fRec93[0] + (fRec95[0] + (fRec97[0] + (fRec101[0] + fRec99[0]))))))) - fRec13[1]));
            fVec82[(IOTA & 511)] = ((0.5f * fRec11[1]) + fRec14);
            fRec11[0] = fVec82[((IOTA - 441) & 511)];
            float fRec12 = (fRec11[1] - fRec14);
            fVec83[(IOTA & 511)] = ((0.5f * fRec9[1]) + fRec12);
            fRec9[0] = fVec83[((IOTA - 341) & 511)];
            float fRec10 = (fRec9[1] - fRec12);
            fVec84[(IOTA & 255)] = ((0.5f * fRec7[1]) + fRec10);
            fRec7[0] = fVec84[((IOTA - 225) & 255)];
            float fRec8 = (fRec7[1] - fRec10);
            fRec0[0] = (0.0f - (((fRec0[1] * fRec1[0]) + (fRec0[2] * fRec5[0])) - (fRec6[0] * ((fSlow3 * fRec8) + (fSlow14 * ((1.5f * fTemp18) + (0.977008402f * fTemp42)))))));
            output0[i] = FAUSTFLOAT((fSlow0 * (fRec0[0] - fRec0[1])));
            fRec113[0] = ((0.699999988f * fRec112[1]) + (0.300000012f * fRec113[1]));
            fVec85[(IOTA & 2047)] = ((0.924000025f * fRec113[0]) + fTemp44);
            fRec112[0] = fVec85[((IOTA - 1300) & 2047)];
            fRec115[0] = ((0.699999988f * fRec114[1]) + (0.300000012f * fRec115[1]));
            fVec86[(IOTA & 2047)] = ((0.924000025f * fRec115[0]) + fTemp44);
            fRec114[0] = fVec86[((IOTA - 1211) & 2047)];
            fRec117[0] = ((0.699999988f * fRec116[1]) + (0.300000012f * fRec117[1]));
            fVec87[(IOTA & 2047)] = ((0.924000025f * fRec117[0]) + fTemp44);
            fRec116[0] = fVec87[((IOTA - 1139) & 2047)];
            fRec119[0] = ((0.699999988f * fRec118[1]) + (0.300000012f * fRec119[1]));
            fVec88[(IOTA & 2047)] = ((0.924000025f * fRec119[0]) + fTemp44);
            fRec118[0] = fVec88[((IOTA - 1379) & 2047)];
            fRec121[0] = ((0.699999988f * fRec120[1]) + (0.300000012f * fRec121[1]));
            fVec89[(IOTA & 2047)] = ((0.924000025f * fRec121[0]) + fTemp44);
            fRec120[0] = fVec89[((IOTA - 1445) & 2047)];
            fRec123[0] = ((0.699999988f * fRec122[1]) + (0.300000012f * fRec123[1]));
            fVec90[(IOTA & 2047)] = ((0.924000025f * fRec123[0]) + fTemp44);
            fRec122[0] = fVec90[((IOTA - 1514) & 2047)];
            fRec125[0] = ((0.699999988f * fRec124[1]) + (0.300000012f * fRec125[1]));
            fVec91[(IOTA & 2047)] = ((0.924000025f * fRec125[0]) + fTemp44);
            fRec124[0] = fVec91[((IOTA - 1580) & 2047)];
            fRec127[0] = ((0.699999988f * fRec126[1]) + (0.300000012f * fRec127[1]));
            fVec92[(IOTA & 2047)] = ((0.924000025f * fRec127[0]) + fTemp44);
            fRec126[0] = fVec92[((IOTA - 1640) & 2047)];
            fVec93[(IOTA & 1023)] = (fRec112[0] + (fRec114[0] + (fRec116[0] + (fRec118[0] + (fRec120[0] + (fRec122[0] + (fRec124[0] + ((0.5f * fRec110[1]) + fRec126[0]))))))));
            fRec110[0] = fVec93[((IOTA - 579) & 1023)];
            float fRec111 = (0.0f - ((fRec112[0] + (fRec114[0] + (fRec116[0] + (fRec118[0] + (fRec120[0] + (fRec122[0] + (fRec126[0] + fRec124[0]))))))) - fRec110[1]));
            fVec94[(IOTA & 511)] = ((0.5f * fRec108[1]) + fRec111);
            fRec108[0] = fVec94[((IOTA - 464) & 511)];
            float fRec109 = (fRec108[1] - fRec111);
            fVec95[(IOTA & 511)] = ((0.5f * fRec106[1]) + fRec109);
            fRec106[0] = fVec95[((IOTA - 364) & 511)];
            float fRec107 = (fRec106[1] - fRec109);
            fVec96[(IOTA & 255)] = ((0.5f * fRec104[1]) + fRec107);
            fRec104[0] = fVec96[((IOTA - 248) & 255)];
            float fRec105 = (fRec104[1] - fRec107);
            fRec103[0] = (0.0f - (((fRec5[0] * fRec103[2]) + (fRec1[0] * fRec103[1])) - (fRec6[0] * ((fSlow3 * fRec105) + (fSlow14 * ((1.5f * fTemp19) + (0.213200718f * fTemp43)))))));
            output1[i] = FAUSTFLOAT((fSlow0 * (fRec103[0] - fRec103[1])));
            iRec2[1] = iRec2[0];
            iVec0[1] = iVec0[0];
            fVec1[1] = fVec1[0];
            fRec3[1] = fRec3[0];
            iRec4[1] = iRec4[0];
            fRec1[1] = fRec1[0];
            fRec5[1] = fRec5[0];
            fRec6[1] = fRec6[0];
            fRec16[1] = fRec16[0];
            iRec18[1] = iRec18[0];
            iVec2[1] = iVec2[0];
            iRec19[1] = iRec19[0];
            iVec3[1] = iVec3[0];
            iRec21[1] = iRec21[0];
            iVec4[1] = iVec4[0];
            fRec20[1] = fRec20[0];
            fVec5[1] = fVec5[0];
            fRec22[1] = fRec22[0];
            IOTA = (IOTA + 1);
            fRec17[2] = fRec17[1];
            fRec17[1] = fRec17[0];
            iVec7[1] = iVec7[0];
            fRec24[1] = fRec24[0];
            fRec23[2] = fRec23[1];
            fRec23[1] = fRec23[0];
            iVec9[1] = iVec9[0];
            fRec26[1] = fRec26[0];
            fRec25[2] = fRec25[1];
            fRec25[1] = fRec25[0];
            iVec11[1] = iVec11[0];
            fRec28[1] = fRec28[0];
            fRec27[2] = fRec27[1];
            fRec27[1] = fRec27[0];
            iVec13[1] = iVec13[0];
            fRec30[1] = fRec30[0];
            fRec29[2] = fRec29[1];
            fRec29[1] = fRec29[0];
            iVec15[1] = iVec15[0];
            fRec32[1] = fRec32[0];
            fRec31[2] = fRec31[1];
            fRec31[1] = fRec31[0];
            iVec17[1] = iVec17[0];
            fRec34[1] = fRec34[0];
            fRec33[2] = fRec33[1];
            fRec33[1] = fRec33[0];
            iVec19[1] = iVec19[0];
            fRec36[1] = fRec36[0];
            fRec35[2] = fRec35[1];
            fRec35[1] = fRec35[0];
            iVec21[1] = iVec21[0];
            fRec38[1] = fRec38[0];
            fRec37[2] = fRec37[1];
            fRec37[1] = fRec37[0];
            iVec23[1] = iVec23[0];
            fRec40[1] = fRec40[0];
            fRec39[2] = fRec39[1];
            fRec39[1] = fRec39[0];
            iVec25[1] = iVec25[0];
            fRec42[1] = fRec42[0];
            fRec41[2] = fRec41[1];
            fRec41[1] = fRec41[0];
            iVec27[1] = iVec27[0];
            iRec45[1] = iRec45[0];
            iVec28[1] = iVec28[0];
            fRec44[1] = fRec44[0];
            fRec43[2] = fRec43[1];
            fRec43[1] = fRec43[0];
            iVec30[1] = iVec30[0];
            iRec48[1] = iRec48[0];
            iVec31[1] = iVec31[0];
            fRec47[1] = fRec47[0];
            fRec46[2] = fRec46[1];
            fRec46[1] = fRec46[0];
            iVec33[1] = iVec33[0];
            fRec50[1] = fRec50[0];
            fRec49[2] = fRec49[1];
            fRec49[1] = fRec49[0];
            iVec35[1] = iVec35[0];
            fRec52[1] = fRec52[0];
            fRec51[2] = fRec51[1];
            fRec51[1] = fRec51[0];
            iVec37[1] = iVec37[0];
            fRec54[1] = fRec54[0];
            fRec53[2] = fRec53[1];
            fRec53[1] = fRec53[0];
            iVec39[1] = iVec39[0];
            fRec56[1] = fRec56[0];
            fRec55[2] = fRec55[1];
            fRec55[1] = fRec55[0];
            iVec41[1] = iVec41[0];
            fRec58[1] = fRec58[0];
            fRec57[2] = fRec57[1];
            fRec57[1] = fRec57[0];
            iVec43[1] = iVec43[0];
            fRec60[1] = fRec60[0];
            fRec59[2] = fRec59[1];
            fRec59[1] = fRec59[0];
            iVec45[1] = iVec45[0];
            fRec62[1] = fRec62[0];
            fRec61[2] = fRec61[1];
            fRec61[1] = fRec61[0];
            iVec47[1] = iVec47[0];
            fRec64[1] = fRec64[0];
            fRec63[2] = fRec63[1];
            fRec63[1] = fRec63[0];
            iVec49[1] = iVec49[0];
            fRec66[1] = fRec66[0];
            fRec65[2] = fRec65[1];
            fRec65[1] = fRec65[0];
            iVec51[1] = iVec51[0];
            fRec68[1] = fRec68[0];
            fRec67[2] = fRec67[1];
            fRec67[1] = fRec67[0];
            iVec53[1] = iVec53[0];
            fRec70[1] = fRec70[0];
            fRec69[2] = fRec69[1];
            fRec69[1] = fRec69[0];
            iVec55[1] = iVec55[0];
            fRec72[1] = fRec72[0];
            fRec71[2] = fRec71[1];
            fRec71[1] = fRec71[0];
            iVec57[1] = iVec57[0];
            fRec74[1] = fRec74[0];
            fRec73[2] = fRec73[1];
            fRec73[1] = fRec73[0];
            iVec59[1] = iVec59[0];
            fRec76[1] = fRec76[0];
            fRec75[2] = fRec75[1];
            fRec75[1] = fRec75[0];
            iVec61[1] = iVec61[0];
            fRec78[1] = fRec78[0];
            fRec77[2] = fRec77[1];
            fRec77[1] = fRec77[0];
            iVec63[1] = iVec63[0];
            fRec80[1] = fRec80[0];
            fRec79[2] = fRec79[1];
            fRec79[1] = fRec79[0];
            iVec65[1] = iVec65[0];
            fRec82[1] = fRec82[0];
            fRec81[2] = fRec81[1];
            fRec81[1] = fRec81[0];
            iVec67[1] = iVec67[0];
            fRec84[1] = fRec84[0];
            fRec83[2] = fRec83[1];
            fRec83[1] = fRec83[0];
            iVec69[1] = iVec69[0];
            fRec86[1] = fRec86[0];
            fRec85[2] = fRec85[1];
            fRec85[1] = fRec85[0];
            iVec71[1] = iVec71[0];
            fRec88[1] = fRec88[0];
            fRec87[2] = fRec87[1];
            fRec87[1] = fRec87[0];
            fRec15[1] = fRec15[0];
            fRec90[1] = fRec90[0];
            fRec89[1] = fRec89[0];
            fRec92[1] = fRec92[0];
            fRec91[1] = fRec91[0];
            fRec94[1] = fRec94[0];
            fRec93[1] = fRec93[0];
            fRec96[1] = fRec96[0];
            fRec95[1] = fRec95[0];
            fRec98[1] = fRec98[0];
            fRec97[1] = fRec97[0];
            fRec100[1] = fRec100[0];
            fRec99[1] = fRec99[0];
            fRec102[1] = fRec102[0];
            fRec101[1] = fRec101[0];
            fRec13[1] = fRec13[0];
            fRec11[1] = fRec11[0];
            fRec9[1] = fRec9[0];
            fRec7[1] = fRec7[0];
            fRec0[2] = fRec0[1];
            fRec0[1] = fRec0[0];
            fRec113[1] = fRec113[0];
            fRec112[1] = fRec112[0];
            fRec115[1] = fRec115[0];
            fRec114[1] = fRec114[0];
            fRec117[1] = fRec117[0];
            fRec116[1] = fRec116[0];
            fRec119[1] = fRec119[0];
            fRec118[1] = fRec118[0];
            fRec121[1] = fRec121[0];
            fRec120[1] = fRec120[0];
            fRec123[1] = fRec123[0];
            fRec122[1] = fRec122[0];
            fRec125[1] = fRec125[0];
            fRec124[1] = fRec124[0];
            fRec127[1] = fRec127[0];
            fRec126[1] = fRec126[0];
            fRec110[1] = fRec110[0];
            fRec108[1] = fRec108[0];
            fRec106[1] = fRec106[0];
            fRec104[1] = fRec104[0];
            fRec103[2] = fRec103[1];
            fRec103[1] = fRec103[0];
            
        }
        
    }
    
    
};


