
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






#pragma once
#ifndef RCComp_Faust_pp_Gen_HPP_
#define RCComp_Faust_pp_Gen_HPP_

#include <memory>

class RCComp {
public:
    RCComp();
    ~RCComp();

    void init(float sample_rate);
    void clear() noexcept;

    void process(
        const float *in0,const float *in1,
        float *out0,float *out1,
        unsigned count) noexcept;

    enum { NumInputs = 2 };
    enum { NumOutputs = 2 };
    enum { NumActives = 5 };
    enum { NumPassives = 0 };
    enum { NumParameters = 5 };

    enum Parameter {
        p_Ratio,
        p_Threshold,
        p_Attack,
        p_Release,
        p_Makeup_Gain,
        
    };

    struct ParameterRange {
        float init;
        float min;
        float max;
    };

    static const char *parameter_label(unsigned index) noexcept;
    static const char *parameter_short_label(unsigned index) noexcept;
    static const char *parameter_symbol(unsigned index) noexcept;
    static const char *parameter_unit(unsigned index) noexcept;
    static const ParameterRange *parameter_range(unsigned index) noexcept;
    static bool parameter_is_trigger(unsigned index) noexcept;
    static bool parameter_is_boolean(unsigned index) noexcept;
    static bool parameter_is_integer(unsigned index) noexcept;
    static bool parameter_is_logarithmic(unsigned index) noexcept;

    float get_parameter(unsigned index) const noexcept;
    void set_parameter(unsigned index, float value) noexcept;

    
    float get_Ratio() const noexcept;
    
    float get_Threshold() const noexcept;
    
    float get_Attack() const noexcept;
    
    float get_Release() const noexcept;
    
    float get_Makeup_Gain() const noexcept;
    
    
    void set_Ratio(float value) noexcept;
    
    void set_Threshold(float value) noexcept;
    
    void set_Attack(float value) noexcept;
    
    void set_Release(float value) noexcept;
    
    void set_Makeup_Gain(float value) noexcept;
    

public:
    class BasicDsp;

private:
    std::unique_ptr<BasicDsp> fDsp;



};




#endif // RCComp_Faust_pp_Gen_HPP_