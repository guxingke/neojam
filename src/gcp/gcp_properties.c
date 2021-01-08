
#include "../jam.h"
#include "../properties.h"

char *classlibDefaultJavaHome() {
    return INSTALL_DIR;
}

void classlibAddDefaultProperties(Object *properties) {
    setProperty(properties, "java.runtime.version", VERSION);
    setProperty(properties, "java.version", JAVA_COMPAT_VERSION);
    setProperty(properties, "java.vendor", "GNU Classpath");
    setProperty(properties, "java.vendor.url", "http://www.classpath.org");
    setProperty(properties, "java.specification.version", "1.5");
    setProperty(properties, "java.specification.vendor",
                "Sun Microsystems Inc.");
    setProperty(properties, "java.specification.name",
                "Java Platform API Specification");
    setProperty(properties, "java.class.version", "48.0");
    setProperty(properties, "java.boot.class.path", getBootClassPath());
    setProperty(properties, "gnu.classpath.boot.library.path",
                getBootDllPath());
    setProperty(properties, "gnu.cpu.endian",
                IS_BIG_ENDIAN ? "big" : "little");
}