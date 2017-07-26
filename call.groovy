@Grapes(
    @Grab(group='com.sun.jna', module='jna', version='3.0.9')
)

import com.sun.jna.Library
import com.sun.jna.Native
import com.sun.jna.Platform

System.setProperty("jna.platform.library.path", "./")

interface LibHello extends Library {
        void sayHello()
}

class CallGoLang {
        static LibHello INSTANCE = Native.loadLibrary("hello", LibHello.class)
}

CallGoLang.INSTANCE.sayHello()
