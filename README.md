# RCComp ("ReaClassical Compressor")
A compressor suitable for classical music based on a Faust demo compressor. Available as LV2 and CLAP by default (with optional VST3, VST2 and LADSPA).

![image](https://user-images.githubusercontent.com/120390802/211630373-9e13b6e7-6de0-4898-9194-6fb5f54faabd.png)

#### Controls


### Audio Demos


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
