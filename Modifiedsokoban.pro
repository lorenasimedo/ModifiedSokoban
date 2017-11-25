TEMPLATE += app
TARGET = qmlsokoban
QT += quick sensors

# Source files
SOURCES += main.cpp orientation.cpp
HEADERS += orientation.h
RESOURCES += qmlsokoban.qrc

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
