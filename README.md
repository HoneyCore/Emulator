## HoneyCore Emulator
This emulator is meant to let people try HoneyCore without the need for a physical HoneyCore CPU (which for now doesn't even exists)
### Installation:
Simply clone the repo
```sh
git clone git@github.com:HoneyCore/Emulator.git
```

Then create a build folder
```sh
mkdir build
```

And run the Makefile
```sh
make
```

This should create you an `emulator.bin` file that you can run to try the emulator.
Note: for now you'll have to create your own ROM file to load on the emulator for it to work.
