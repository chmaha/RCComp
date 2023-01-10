
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: rccomp.dsp
// Name: RCComp
// Author: Julius O. Smith III, chmaha
// Copyright: Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>
// License: GPLv3
// Version: 0.1.0
//------------------------------------------------------------------------------







#include "RCComp.hpp"



#include <utility>
#include <cmath>

class RCComp::BasicDsp {
public:
    virtual ~BasicDsp() {}
};

//------------------------------------------------------------------------------
// Begin the Faust code section

namespace {

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

class Meta {
public:
    // dummy
    void declare(...) {}
};

class UI {
public:
    // dummy
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
    void addHorizontalBargraph(...) {}
};

typedef RCComp::BasicDsp dsp;

} // namespace

#define FAUSTPP_VIRTUAL // do not declare any methods virtual
#define FAUSTPP_PRIVATE public // do not hide any members
#define FAUSTPP_PROTECTED public // do not hide any members

// define the DSP in the anonymous namespace
#define FAUSTPP_BEGIN_NAMESPACE namespace {
#define FAUSTPP_END_NAMESPACE }


#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#   define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#   define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#   define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#   define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#   define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif


class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec1[2];
	FAUSTFLOAT fHslider3;
	float fRec0[2];
	FAUSTFLOAT fHslider4;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.2");
		m->declare("author", "Julius O. Smith III, chmaha");
		m->declare("basics.lib/bypass2:author", "Julius Smith");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.9");
		m->declare("compile_options", "-a /tmp/tmpp4g2tnqi.cpp -lang cpp -es 1 -mcd 16 -single -ftz 0");
		m->declare("compressors.lib/compression_gain_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compression_gain_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compression_gain_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/compressor_stereo:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_stereo:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_stereo:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "0.4");
		m->declare("copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("description", "A simple compressor");
		m->declare("filename", "rccomp.dsp");
		m->declare("license", "GPLv3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "RCComp");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.3");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "STK-4.3");
		m->declare("signals.lib/version", "0.3");
		m->declare("version", "0.1.0");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 2;
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = 1.0f / std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1e+01f);
		fHslider1 = FAUSTFLOAT(-3e+01f);
		fHslider2 = FAUSTFLOAT(3e+02f);
		fHslider3 = FAUSTFLOAT(1.1f);
		fHslider4 = FAUSTFLOAT(0.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec0[l1] = 0.0f;
		}
	}
	
	FAUSTPP_VIRTUAL void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	FAUSTPP_VIRTUAL void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSampleRate;
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->declare(0, "tooltip", "Reference:         http://en.wikipedia.org/wiki/Dynamic_range_compression");
		ui_interface->openVerticalBox("COMPRESSOR");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("Compression Control");
		ui_interface->declare(&fHslider3, "0", "");
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->declare(&fHslider3, "tooltip", "A compression Ratio of N means that for each N dB increase in input     signal level above Threshold, the output level goes up 1 dB");
		ui_interface->addHorizontalSlider("Ratio", &fHslider3, FAUSTFLOAT(1.1f), FAUSTFLOAT(1.0f), FAUSTFLOAT(2.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->declare(&fHslider1, "tooltip", "When the signal level exceeds the Threshold (in dB), its level     is compressed according to the Ratio");
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("Threshold", &fHslider1, FAUSTFLOAT(-3e+01f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "4", "");
		ui_interface->openHorizontalBox("Compression Response");
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "scale", "log");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->declare(&fHslider0, "tooltip", "Time constant in ms (1/e smoothing time) for the compression gain     to approach (exponentially) a new lower target level (the compression     `kicking in')");
		ui_interface->declare(&fHslider0, "unit", "ms");
		ui_interface->addHorizontalSlider("Attack", &fHslider0, FAUSTFLOAT(1e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "scale", "log");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->declare(&fHslider2, "tooltip", "Time constant in ms (1/e smoothing time) for the compression gain     to approach (exponentially) a new higher target level (the compression     'releasing')");
		ui_interface->declare(&fHslider2, "unit", "ms");
		ui_interface->addHorizontalSlider("Release", &fHslider2, FAUSTFLOAT(3e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(3e+03f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(&fHslider4, "5", "");
		ui_interface->declare(&fHslider4, "tooltip", "The compressed-signal output level is increased by this amount     (in dB) to make up for the level lost due to compression");
		ui_interface->declare(&fHslider4, "unit", "dB");
		ui_interface->addHorizontalSlider("Makeup Gain", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-3e+01f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(fConst0, 0.001f * float(fHslider0));
		float fSlow1 = 0.5f * fSlow0;
		int iSlow2 = std::fabs(fSlow1) < 1.1920929e-07f;
		float fSlow3 = ((iSlow2) ? 0.0f : std::exp(0.0f - fConst0 / ((iSlow2) ? 1.0f : fSlow1)));
		float fSlow4 = 1.0f - fSlow3;
		float fSlow5 = float(fHslider1);
		float fSlow6 = std::max<float>(fConst0, 0.001f * float(fHslider2));
		int iSlow7 = std::fabs(fSlow6) < 1.1920929e-07f;
		float fSlow8 = ((iSlow7) ? 0.0f : std::exp(0.0f - fConst0 / ((iSlow7) ? 1.0f : fSlow6)));
		int iSlow9 = std::fabs(fSlow0) < 1.1920929e-07f;
		float fSlow10 = ((iSlow9) ? 0.0f : std::exp(0.0f - fConst0 / ((iSlow9) ? 1.0f : fSlow0)));
		float fSlow11 = 1.0f / std::max<float>(1.1920929e-07f, float(fHslider3)) + -1.0f;
		float fSlow12 = std::pow(1e+01f, 0.05f * float(fHslider4));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input1[i0]);
			float fTemp1 = float(input0[i0]);
			float fTemp2 = std::fabs(std::fabs(fTemp1) + std::fabs(fTemp0));
			float fTemp3 = ((fTemp2 > fRec1[1]) ? fSlow10 : fSlow8);
			fRec1[0] = fTemp2 * (1.0f - fTemp3) + fRec1[1] * fTemp3;
			fRec0[0] = fSlow11 * std::max<float>(2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec1[0])) - fSlow5, 0.0f) * fSlow4 + fSlow3 * fRec0[1];
			float fTemp4 = std::pow(1e+01f, 0.05f * fRec0[0]);
			float fTemp5 = fTemp1 * fTemp4;
			output0[i0] = FAUSTFLOAT(fSlow12 * fTemp5);
			float fTemp6 = fTemp0 * fTemp4;
			output1[i0] = FAUSTFLOAT(fSlow12 * fTemp6);
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
		}
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




RCComp::RCComp()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

RCComp::~RCComp()
{
}

void RCComp::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void RCComp::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void RCComp::process(
    const float *in0,const float *in1,
    float *out0,float *out1,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        const_cast<float *>(in0),const_cast<float *>(in1),
    };
    float *outputs[] = {
        out0,out1,
    };
    dsp.compute(count, inputs, outputs);

}

const char *RCComp::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Ratio";
    
    case 1:
        return "Threshold";
    
    case 2:
        return "Attack";
    
    case 3:
        return "Release";
    
    case 4:
        return "Makeup Gain";
    
    default:
        return 0;
    }
}

const char *RCComp::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "";
    
    case 4:
        return "";
    
    default:
        return 0;
    }
}

const char *RCComp::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Ratio";
    
    case 1:
        return "Threshold";
    
    case 2:
        return "Attack";
    
    case 3:
        return "Release";
    
    case 4:
        return "Makeup_Gain";
    
    default:
        return 0;
    }
}

const char *RCComp::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "dB";
    
    case 2:
        return "ms";
    
    case 3:
        return "ms";
    
    case 4:
        return "dB";
    
    default:
        return 0;
    }
}

const RCComp::ParameterRange *RCComp::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 1.1, 1.0, 2.5 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { -30.0, -60.0, 0.0 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 10.0, 1.0, 100.0 };
        return &range;
    }
    
    case 3: {
        static const ParameterRange range = { 300.0, 1.0, 3000.0 };
        return &range;
    }
    
    case 4: {
        static const ParameterRange range = { 0.0, -30.0, 30.0 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool RCComp::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool RCComp::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool RCComp::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool RCComp::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    case 2:
        return true;
    
    case 3:
        return true;
    
    default:
        return false;
    }
}

float RCComp::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fHslider3;
    
    case 1:
        return dsp.fHslider1;
    
    case 2:
        return dsp.fHslider0;
    
    case 3:
        return dsp.fHslider2;
    
    case 4:
        return dsp.fHslider4;
    
    default:
        (void)dsp;
        return 0;
    }
}

void RCComp::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fHslider3 = value;
        break;
    
    case 1:
        dsp.fHslider1 = value;
        break;
    
    case 2:
        dsp.fHslider0 = value;
        break;
    
    case 3:
        dsp.fHslider2 = value;
        break;
    
    case 4:
        dsp.fHslider4 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float RCComp::get_Ratio() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider3;
}

float RCComp::get_Threshold() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float RCComp::get_Attack() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}

float RCComp::get_Release() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider2;
}

float RCComp::get_Makeup_Gain() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider4;
}


void RCComp::set_Ratio(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider3 = value;
}

void RCComp::set_Threshold(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void RCComp::set_Attack(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}

void RCComp::set_Release(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider2 = value;
}

void RCComp::set_Makeup_Gain(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider4 = value;
}



