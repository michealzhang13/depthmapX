INCLUDEPATH += $$PWD/depthmapX $$PWD

Release:DESTDIR = release
Release:OBJECTS_DIR = release/.obj
Release:MOC_DIR = release/.moc
Release:RCC_DIR = release/.rcc
Release:UI_DIR = release/.ui

Debug:DESTDIR = debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc
Debug:UI_DIR = debug/.ui

win32: QMAKE_CXXFLAGS_WARN_ON -= -W3
# set warning level to 4 for MSVC, but disable 4800 (this gets triggered for all std::set<int> calls)
win32: QMAKE_CXXFLAGS_WARN_ON += -W4 -wd4800
