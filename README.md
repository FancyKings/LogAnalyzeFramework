# LogAnalyzeFramework

## Compile and dependency management

Use ```[XMake](https://xmake.io/)``` to manage third-party libraries and build compilation rules.

So, you need install xmake on your computer first. you can read this reference [xmake.io](https://xmake.io/#/getting_started).

## Build and run

Build type: ```debug``` or ```release``` is also managed by xmake. if you want to change build target:

```bash
# For release version build
$ xmake f -m release
# For debug version build
$ xmake f -m debug
```

Then, you can build and run the project by:

```bash
clear ; xmake -wvD && xmake run
```