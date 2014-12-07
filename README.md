# qmlcoffee

This program makes it possible to use [CoffeeScript](http://coffeescript.org/) in QML files. For plain JavaScript files it just passes them through to the CoffeeScript compiler, otherwise it only passes those parts through that can actually be CoffeeScript, like property bindings and functions.

### Compiling

Standard cmake building:

```
git clone https://github.com/02JanDal/qmlcoffee.git
cd qmlcoffee
mkdir build && cd build
cmake ..
make
```

### Usage

```
qmlcoffee -i MyItem.qml.coffee -o MyItem.qml
```

Type `qmlcoffee --help` for a full list of commands.