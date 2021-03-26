{
    "targets": [
        {
            "target_name": "mathobj",
            "include_dirs": [
                "<!(node -p \"require('node-addon-api').include_dir\")",
                "deps/native-test/src"
            ],
            "sources": [
                "src/MathWrap.cpp",
                "src/addon.cpp"
            ],
            "dependencies": [
                "builds/libnativetest.gyp:libnative"
            ],
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "xcode_settings": {
                "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
                "CLANG_CXX_LIBRARY": "libc++",
                "MACOSX_DEPLOYMENT_TARGET": "10.7"
            },
            "msvs_settings": {
                "VCCLCompilerTool": {
                    "ExceptionHandling": 1
                }
            },
            "conditions": [
                ["OS==\"mac\"", {
                    "cflags+": ["-fvisibility=hidden"],
                    "xcode_settings": {
                        "GCC_SYMBOLS_PRIVATE_EXTERN": "YES"
                    }
                }]
            ]
        }
    ]
}
