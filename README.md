# c_test
use of c 

## env 

* clang、clangd、lld 都是用的llvm里的，可以使用brew安装llvm
* ninja是按照git的里的方法安装的
* cmake使用了官方的加载器加载源码安装的

在M1芯片的Mac上使用VS Code编写C代码，你需要按照以下步骤操作：
1. 如果你还没有安装VS Code，可以从其官方网站下载适用于Apple Silicon的版本。

2. 打开VS Code，然后安装C/C++扩展。这可以通过VS Code的扩展商店来完成，你只需在商店中搜索“c++”，然后直接装pack

3. 在VS Code的设置中，你需要将clang设定为默认的C/C++编译器。你可以在VS Code的设置中搜索“c++”，然后找到“C_Cpp > Default Compiler Path”设置项，将其设置为"/usr/bin/clang"，或者其他clang路径，可以在Default Compiler Path的setting.json中直接设置
"C_Cpp.default.compilerPath": "/usr/bin/clang",
"C_Cpp.default.cStandard": "c99"

以上步骤完成后，你就可以开始在你的M1 Mac上通过VS Code和clang编写C代码了。 

  
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

