# RCComp ("ReaClassical Compressor")
A compressor suitable for classical music. Available as LV2 and CLAP by default (with optional VST3, VST2 and LADSPA).

![image](https://user-images.githubusercontent.com/120390802/211630373-9e13b6e7-6de0-4898-9194-6fb5f54faabd.png)

#### Controls

Ratio = n:1. Ratio can be set in steps of 0.01 between 1:1 and 2.5:1 making it a fine-grained control suitable for classical music either as an insert or as a parallel compressor (such as transparent parallel as outlined by Bob Katz).  
Threshold = -60 to 0 dB  
Attack = 1 to 100 ms  
Release = 1ms to 3s  
Makeup Gain = -30 to 30 dB  

Defaults are typical for a classical music starting point: 1.1:1 with -30 threshold. Attack and Release should be dialed to taste. For transparent parallel use, suggested settings are 2 or 2.5:1 at -50 dB threshold, 1ms attack, release 250-350ms (up to 500ms for a capella music), makeup gain adjust to taste. 

### Audio Demos

Coming soon...

## Building LV2 and CLAP (On Linux or MacOS)

```
git clone --recursive https://github.com/chmaha/RCComp.git
cd RCComp
make
```
To build a VST3 version at the same time:
```
make BUILD_VST3=true
```
likewise, `BUILD_VST2=true` or `BUILD_LADSPA=true`.

On Linux systems, you can cross-compile LV2/CLAP Windows-x64 binaries as follows:
```
scripts/build-win64.sh
```
To add a VST3 binary at the same time:
```
scripts/build-win64.sh BUILD_VST3=true
```

## Author

This software is by *chmaha*.


## License

This plugin is released under the *GPLv3 License*. Please see the
[LICENSE](./LICENSE) file for details.


## Acknowledgements

The DSP code is generated from the FAUST sources via the faustpp
pre-processor and uses my modified version of the dm.compressor demo from the FAUST library, written
by Julius O. Smith III.

The project is built using the DISTRHO Plugin Framework (DPF) and set up
with the cookiecutter-dpf-faust project template.
