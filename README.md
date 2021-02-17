# native-test-wrap
node wrapper for the native test lib

# prerequisites
* [Visual Studio 2019](https://visualstudio.microsoft.com/vs/community/) or 2019 build environment for windows (gcc for linux/Mac, haven't tested there yet)
* [NodeJS v14](https://nodejs.org/en/download/) or greater
* [Python v3.9](https://www.python.org/downloads/)

# building

1. ```npm install -g node-gyp```
2. ```npm install``` *this step will pull external native source and build*
3. ```npm run test``` *should succeed with 2 tests run*
