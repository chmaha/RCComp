declare name "RCComp";
declare description "A simple compressor";
declare author "Julius O. Smith III, chmaha";
declare copyright "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>";
declare license "GPLv3";
declare version "0.1.0";

import("stdfaust.lib");

rccomp = ba.bypass2(cbp,compressor_stereo_demo)
with{
    comp_group(x) = vgroup("COMPRESSOR [tooltip: Reference:
        http://en.wikipedia.org/wiki/Dynamic_range_compression]", x);

    meter_group(x) = comp_group(hgroup("[0]", x));
    knob_group(x) = comp_group(hgroup("[1]", x));

    cbp = 0;
    gainview = co.compression_gain_mono(ratio,threshold,attack,release) : ba.linear2db :
    meter_group(hbargraph("[1] Compressor Gain [unit:dB] [tooltip: Current gain of
    the compressor in dB]",-50,+10));

    displaygain = _,_ <: _,_,(abs,abs:+) : _,_,_ : _,attach;

    compressor_stereo_demo =
    displaygain(co.compressor_stereo(ratio,threshold,attack,release)) :
    *(makeupgain), *(makeupgain);

    ctl_group(x) = knob_group(hgroup("[3] Compression Control", x));

    ratio = ctl_group(hslider("[0] Ratio [style:knob]
    [tooltip: A compression Ratio of N means that for each N dB increase in input
    signal level above Threshold, the output level goes up 1 dB]",
    1.1, 1, 2.5, 0.01));

    threshold = ctl_group(hslider("[1] Threshold [unit:dB] [style:knob]
    [tooltip: When the signal level exceeds the Threshold (in dB), its level
    is compressed according to the Ratio]",
    -30, -60, 0, 0.1));

    env_group(x) = knob_group(hgroup("[4] Compression Response", x));

    attack = env_group(hslider("[1] Attack [unit:ms] [style:knob] [scale:log]
    [tooltip: Time constant in ms (1/e smoothing time) for the compression gain
    to approach (exponentially) a new lower target level (the compression
    `kicking in')]", 10, 1, 100, 0.1)) : *(0.001) : max(1/ma.SR);

    release = env_group(hslider("[2] Release [unit:ms] [style: knob] [scale:log]
    [tooltip: Time constant in ms (1/e smoothing time) for the compression gain
    to approach (exponentially) a new higher target level (the compression
    'releasing')]", 300, 1, 3000, 0.1)) : *(0.001) : max(1/ma.SR);

    makeupgain = comp_group(hslider("[5] Makeup Gain [unit:dB]
    [tooltip: The compressed-signal output level is increased by this amount
    (in dB) to make up for the level lost due to compression]",
    0, -30, 30, 0.1)) : ba.db2linear;
};

process = _,_ : rccomp : _,_;

