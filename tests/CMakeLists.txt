add_executable(tst_qmlcoffee test.cpp ../main.h)
qt5_use_modules(tst_qmlcoffee Core Test)
add_test(tst_qmlcoffee tst_qmlcoffee)

file(GLOB QML *.qml.coffee)
file(GLOB JS *.js.coffee)
add_custom_target(ide_dummy SOURCES ${QML} ${JS})
