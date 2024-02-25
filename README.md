# c_test
use of c 

## env 

* clang、clangd、lld 都是用的llvm里的，可以使用brew安装llvm
* ninja是按照git的里的方法安装的
* cmake使用了官方的加载器加载源码安装的
  
## run
```
# 1) 根据当前目录下的CMakeLists.txt生成MakeFile
cmake . 
# 2) 使用 make 命令时，就能直接根据这些规则来编译和链接你的代码，生成可执行文件或者库
make
# 3) 运行可执行文件
./c_test


PS:
1)可执行文件
生成的可执行文件通常在Unix或Linux系统中没有后缀，而在Windows系统中通常后缀为.exe

2)生成的可执行文件如何和js混合使用
const { spawn } = require('child_process');
const executable = spawn('./your_executable');
executable.stdout.on('data', (data) => {
  console.log(`stdout: ${data}`);
});
executable.stderr.on('data', (data) => {
  console.error(`stderr: ${data}`);
});
executable.on('close', (code) => {
  console.log(`child process exited with code ${code}`);
});

```


